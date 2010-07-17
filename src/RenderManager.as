package  
{
	import flash.display.Bitmap;
	import flash.display.Bitmap3D;
	import flash.display.BitmapData;
	import flash.display.Program3D;
	import flash.display.IndexBuffer3D;
	import flash.display.Texture3D;
	import flash.display.VertexBuffer3D;
	import flash.events.TimerEvent;
	import flash.geom.Matrix3D;
	import flash.geom.Rectangle;
	import flash.geom.Vector3D;
	import flash.utils.ByteArray;
	import flash.utils.Endian;
	import flash.utils.Timer;
	import flash.utils.getTimer;

	/**
	 * ...
	 * @author Pierre-Yves Gatouillat
	 */
	public class RenderManager extends Bitmap3D
	{
		/**********************************************************************************************************/
		/** CONSTANTS                                                                                            **/
		/**********************************************************************************************************/

		private const MOLEHILL_BEGIN : uint						= 0x00010000;
		private const MOLEHILL_END : uint						= 0x00020000;

		private const MOLEHILL_CLEAR : uint						= 0x00110000;
		private const MOLEHILL_CLEAR_EX : uint					= 0x00120000;
		private const MOLEHILL_FLUSH : uint						= 0x00130000;

		private const MOLEHILL_BIND : uint						= 0x00210000;

		private const MOLEHILL_SET_DEPTHWRITE : uint			= 0x00310000;
		private const MOLEHILL_SET_DEPTHFUNC : uint				= 0x00320000;
		private const MOLEHILL_SET_BLENDING : uint				= 0x00330000;
		private const MOLEHILL_SET_VIEWPORT : uint				= 0x00340000;
		private const MOLEHILL_SET_CULLING : uint				= 0x00350000;
		private const MOLEHILL_SET_ALPHATEST : uint				= 0x00360000;
		private const MOLEHILL_SET_ALPHAFUNC : uint				= 0x00370000;

		private const MOLEHILL_MATRIX : uint					= 0x00410000;
		private const MOLEHILL_VERTICES : uint					= 0x00420000;
		private const MOLEHILL_INDICES : uint					= 0x00430000;
		private const MOLEHILL_VERTEX_POINTER : uint			= 0x00440000;
		private const MOLEHILL_COLOR_POINTER : uint				= 0x00450000;
		private const MOLEHILL_TEXCOORD_POINTER : uint			= 0x00460000;
		private const MOLEHILL_INDEX_POINTER : uint				= 0x00470000;

		private const MOLEHILL_DRAW : uint						= 0x00510000;
		private const MOLEHILL_DRAW_FAST : uint					= 0x00520000;

		private const MOLEHILL_UPLOAD_CACHE : uint				= 0x00610000;
		private const MOLEHILL_DRAW_CACHE : uint				= 0x00620000;

		private const MOLEHILL_TRIANGLE_LIST : uint				= 0x00000001;
		private const MOLEHILL_TRIANGLE_STRIP : uint			= 0x00000002;
		private const MOLEHILL_TRIANGLE_FAN : uint				= 0x00000003;
		private const MOLEHILL_QUAD_LIST : uint					= 0x00000011;
		private const MOLEHILL_POLYGON : uint					= 0x00000024;

		private const MOLEHILL_FALSE : uint						= 0x00000000;
		private const MOLEHILL_TRUE : uint						= 0x00000001;

		private const MOLEHILL_ALWAYS : uint					= 0x00000001;
		private const MOLEHILL_LESS_OR_EQUAL : uint				= 0x00000002;
		private const MOLEHILL_EQUAL : uint						= 0x00000003;
		private const MOLEHILL_GREATER_OR_EQUAL : uint			= 0x00000004;

		private const MOLEHILL_ONE : uint						= 0x00000001;
		private const MOLEHILL_ZERO : uint						= 0x00000002;
		private const MOLEHILL_SRC_ALPHA : uint					= 0x00000011;
		private const MOLEHILL_SRC_COLOR : uint					= 0x00000012;
		private const MOLEHILL_ONE_MINUS_SRC_ALPHA : uint		= 0x00000021;
		private const MOLEHILL_ONE_MINUS_SRC_COLOR : uint		= 0x00000022;
		private const MOLEHILL_DST_ALPHA : uint					= 0x00000031;
		private const MOLEHILL_DST_COLOR : uint					= 0x00000032;
		private const MOLEHILL_ONE_MINUS_DST_ALPHA : uint		= 0x00000041;
		private const MOLEHILL_ONE_MINUS_DST_COLOR : uint		= 0x00000042;

		private const MOLEHILL_NONE : uint						= 0x00000001;
		private const MOLEHILL_FRONT : uint						= 0x00000002;
		private const MOLEHILL_BACK : uint						= 0x00000003;

		/**********************************************************************************************************/
		/** MEMBERS                                                                                              **/
		/**********************************************************************************************************/

		private var engine : Quake3;
		
		private var sp0 : Program3D;
		private var sp1 : Program3D;
		private var ib : IndexBuffer3D; 
		private var vb0 : VertexBuffer3D; 
		private var vb1 : VertexBuffer3D;
		
		private var vertices_fvb : VertexBuffer3D; 
		private var colors_fvb : VertexBuffer3D; 
		private var texcoords_fvb : VertexBuffer3D; 
		private var indices_fib : IndexBuffer3D; 

		private var spc : Program3D;
		private var ibc : IndexBuffer3D; 
		private var vbc : VertexBuffer3D;

		private var vertex_count : int;
		private var index_count : int;
		
		private var vertex_offset : int;
		private var index_offset : int;
		
		private var caches : Array;
		
		private var matrix : Matrix3D;
		
		private var center : Vector.<Number>;
		private var factor : Vector.<Number>;
		private var offset : Vector.<Number>;
		
		private var ram : ByteArray;
		
		private var textures : Array;
		private var tid : int;

		private var matrix_values : Vector.<Number>;

		private var vertices : Vector.<Number>;
		private var indices : Vector.<uint>;
		
		private var use_texturing : Boolean;
		
		private var old_time : int;
		
		private var depth_write : Boolean;
		private var depth_func : String;
		
		private var blend_src_op : String;
		private var blend_dst_op : String;

		private var alpha_test : Boolean;
		private var alpha_func : String;
		private var alpha_ref : Number;

		/**********************************************************************************************************/
		/** CONSTRUCTOR                                                                                          **/
		/**********************************************************************************************************/

		public function RenderManager( _engine : Quake3 ) 
		{
			super( "DIRECTX9" );
			
			engine = _engine;
			
			ram = engine.ram;

			init(); 
		}
		
		/**********************************************************************************************************/
		/** METHODS                                                                                              **/
		/**********************************************************************************************************/

		private function getTimeStamp() : String
		{
			var new_time : int = getTimer();
			
			var delta : int = new_time - old_time;
			
			old_time = new_time;
			
			return "[" + new_time + " | " + delta + " ms]";
		}
		
		public function init() : void 
		{
			getTimeStamp();
			
			setupBackbuffer( 640, 480, 0, true );
			
			matrix_values = new Vector.<Number>();
			
			vertices = new Vector.<Number>();
			indices = new Vector.<uint>();
			
			vertex_count = 0;
			index_count = 0;

			vertex_offset = 0;
			index_offset = 0;
			
			caches = new Array();
			
			depth_write = true;
			depth_func = "LESS_EQUAL";

			alpha_test = false;
			alpha_func = "GREATER_EQUAL";

			textures = new Array();
			tid = 0;
			
			center = Vector.<Number>( [1.0, 1.0, 0.0, 0.0] );
			factor = Vector.<Number>( [1.0, 1.0, 1.0, 1.0] );
			offset = Vector.<Number>( [0.0, 0.0, 0.0, 0.0] );

			x = 0;
			y = 0;
			
			var vs0 : AGALMiniAssembler = new AGALMiniAssembler();
			vs0.Assemble
			(
				"VERTEX",
				"dp4 vt0.x, va0, vc0		\n" +
				"dp4 vt0.y, va0, vc1		\n" +
				"dp4 vt0.z, va0, vc2		\n" +
				"dp4 vt0.w, va0, vc3		\n" +
				////////////////////////////////////
				"rcp vt1.w, vt0.w			\n" + //
				"mul vt1.x, vt0.x, vt1.w	\n" + //
				"mul vt1.y, vt0.y, vt1.w	\n" + //
				"mul vt1.z, vt0.z, vt1.w	\n" + //
				"add vt2, vt1, vc4			\n" + // ugly hack to simulate the effect of glViewport
				"mul vt3, vt2, vc5			\n" + //
				"mov vt3.w, vc5.w			\n" + //
				"sub vt4, vt3, vc4			\n" + //
				"add op, vt4, vc6			\n" + //
				////////////////////////////////////
				"mov v0, va1.xyzw       	\n" +
				"mov v1, va2.xyzw       	\n"
			);
			
			var ps0 : AGALMiniAssembler = new AGALMiniAssembler(); 
			ps0.Assemble
			(
				"FRAGMENT",		
				"mov ft1, v1						\n" +
				"tex ft2, ft1, fs1 [2d,linear,wrap]	\n" +
				"mul ft0, ft2, v0					\n" +
				"mov oc, ft0						\n"
			);
			
			sp0 = createProgram();
			sp0.upload( vs0.agalcode, ps0.agalcode );

			var vs1 : AGALMiniAssembler = new AGALMiniAssembler();
			vs1.Assemble
			(
				"VERTEX",
				"dp4 vt0.x, va0, vc0		\n" +
				"dp4 vt0.y, va0, vc1		\n" +
				"dp4 vt0.z, va0, vc2		\n" +
				"dp4 vt0.w, va0, vc3		\n" +
				////////////////////////////////////
				"rcp vt1.w, vt0.w			\n" + //
				"mul vt1.x, vt0.x, vt1.w	\n" + //
				"mul vt1.y, vt0.y, vt1.w	\n" + //
				"mul vt1.z, vt0.z, vt1.w	\n" + //
				"add vt2, vt1, vc4			\n" + // ugly hack to simulate the effect of glViewport
				"mul vt3, vt2, vc5			\n" + //
				"mov vt3.w, vc5.w			\n" + //
				"sub vt4, vt3, vc4			\n" + //
				"add op, vt4, vc6			\n" + //
				////////////////////////////////////
				"mov v0, va1.xyzw			\n"
			);
			
			var ps1 : AGALMiniAssembler = new AGALMiniAssembler(); 
			ps1.Assemble
			(
				"FRAGMENT",		
				"mov oc, v0							\n"
			);
			
			sp1 = createProgram();
			sp1.upload( vs1.agalcode, ps1.agalcode );
			
			ib = createIndexBuffer( 4096 );
			
			vb0 = createVertexBuffer( 16384, 10 ); // vertex + color + texcoord
			vb1 = createVertexBuffer( 16384, 8 ); // vertex + color
			
			vertices_fvb = createVertexBuffer( 16384, 4 );
			colors_fvb = createVertexBuffer( 16384, 4 );
			texcoords_fvb = createVertexBuffer( 16384, 2 );
			indices_fib = createIndexBuffer( 4096 );

			var vsc : AGALMiniAssembler = new AGALMiniAssembler();
			vsc.Assemble
			(
				"VERTEX",
				"mov op, va0				\n" +
				"mov v0, va1.xyzw			\n"
			);
			
			var psc : AGALMiniAssembler = new AGALMiniAssembler(); 
			psc.Assemble
			(
				"FRAGMENT",		
				"mov oc, v0					\n"
			);
			
			spc = createProgram();
			spc.upload( vsc.agalcode, psc.agalcode );
			
			var indices_c : Vector.<uint> = Vector.<uint>(
			[
				0, 1, 2,
				3, 2, 1
			] );
			
			ibc = createIndexBuffer( 6 );
			ibc.upload( indices_c, 0, 6 );
			
			var vertices_c : Vector.<Number> = Vector.<Number>(
			[
				-2048, -2048, 2048, 2048, 0.0, 0.0, 0.0, 0.0,
				+2048, -2048, 2048, 2048, 0.0, 0.0, 0.0, 0.0,
				-2048, +2048, 2048, 2048, 0.0, 0.0, 0.0, 0.0,
				+2048, +2048, 2048, 2048, 0.0, 0.0, 0.0, 0.0
			] );

			vbc = createVertexBuffer( 4, 8 ); // vertex + color
			vbc.upload( vertices_c, 0, 4 );
		}
		
		private function clearDepthStencil( depth_value : Number, stencil_value : int ) : void
		{
			//setColorWriteMask( false, false, false, false );
			
			//trace( getTimeStamp() + " clearDepthStencil( " + depth_value + ", " + stencil_value + " )" );

			setDepthTest( true, "ALWAYS" );
			setBlending( "SRC_ALPHA", "ONE_MINUS_SRC_ALPHA" );
			
			setProgram( spc );
			
			setVertexStream( 0, vbc, 0, "FLOAT_4" );
			setVertexStream( 1, vbc, 4, "FLOAT_4" );
				
			drawTriangles( ibc, 0, 2 );

			setBlending( blend_src_op, blend_dst_op );
			setDepthTest( depth_write, depth_func );
			
			//setColorWriteMask( true, true, true, true );
		}
		
		public function execute( data_ptr : uint ) : void
		{
			trace( getTimeStamp() + " begin execute( " + data_ptr + " )" );
			
			ram.position = data_ptr;
			
			var last_opcode : uint;
			var opcode : uint;
			var count : uint = 0;
			
			if ( ( opcode = ram.readUnsignedInt() ) == MOLEHILL_BEGIN )
			{
				while ( ( opcode = ram.readUnsignedInt() ) != MOLEHILL_END )
				{
					count++;
					
					var red : Number;
					var green : Number;
					var blue : Number;
					var alpha : Number;
					var depth : Number;
					var stencil : int;
					var id : int;
					var ptr : uint;
					
					if ( opcode == MOLEHILL_CLEAR )
					{
						red = ram.readFloat();
						green = ram.readFloat();
						blue = ram.readFloat();
						alpha = ram.readFloat();
						depth = ram.readFloat();
						stencil = ram.readInt();
						
						clear( red, green, blue, alpha, depth, stencil );
					}
					if ( opcode == MOLEHILL_CLEAR_EX )
					{
						depth = ram.readFloat();
						stencil = ram.readInt();
						
						clearDepthStencil( depth, stencil );
					}
					else if ( opcode == MOLEHILL_FLUSH )
					{
						flush();
					}
					else if ( opcode == MOLEHILL_MATRIX )
					{
						for ( var k : int = 0 ; k < 16 ; k++ )
							matrix_values[k] = ram.readFloat();
						
						matrix = new Matrix3D( matrix_values );
						matrix.transpose();
					}
					else if ( opcode == MOLEHILL_VERTICES + 0x0A )
					{
						use_texturing = true;
						
						vertex_count += ram.readInt();

						for ( var i : int = vertex_offset * 10 ; i < vertex_count * 10 ; i++ )
							vertices[i] = ram.readFloat();
						
						vertex_offset = vertex_count;
					}
					else if ( opcode == MOLEHILL_VERTICES + 0x08 )
					{
						use_texturing = false;

						vertex_count += ram.readInt();
						
						for ( var j : int = vertex_offset * 8 ; j < vertex_count * 8 ; j++ )
							vertices[j] = ram.readFloat();
						
						vertex_offset = vertex_count;
					}
					else if ( opcode == MOLEHILL_INDICES )
					{
						index_count += ram.readInt();
						
						for ( var n : int = index_offset ; n < index_count ; n++ )
							indices[n] = ram.readInt();
						
						index_offset = index_count;
					}
					else if ( opcode == MOLEHILL_VERTEX_POINTER )
					{
						ptr = ram.readUnsignedInt();
						
						vertices_fvb.uploadBytes( ram, ptr, 0, 1000 );
					}
					else if ( opcode == MOLEHILL_COLOR_POINTER )
					{
						ptr = ram.readUnsignedInt();
						
						colors_fvb.uploadBytes( ram, ptr, 0, 1000 );
					}
					else if ( opcode == MOLEHILL_TEXCOORD_POINTER )
					{
						use_texturing = true;
						
						ptr = ram.readUnsignedInt();
						
						texcoords_fvb.uploadBytes( ram, ptr, 0, 1000 );
					}
					else if ( opcode == MOLEHILL_INDEX_POINTER )
					{
						ptr = ram.readUnsignedInt();
						
						indices_fib.uploadBytes( ram, ptr, 0, 1000 );
					}
					else if ( opcode == MOLEHILL_UPLOAD_CACHE )
					{
						id = ram.readInt();
						
						uploadCache( id );
					}
					else if ( opcode == MOLEHILL_DRAW_CACHE )
					{
						id = ram.readInt();
						
						drawCache( id );
					}
					else if ( opcode == MOLEHILL_DRAW )
					{
						draw();
					}
					else if ( opcode == MOLEHILL_DRAW_FAST )
					{
						index_offset = 0;
						index_count = ram.readInt();
						
						drawFast();
					}
					else if ( opcode == MOLEHILL_BIND )
					{
						id = ram.readInt();
						
						bindTexture( id );
					}
					else if ( opcode == MOLEHILL_SET_BLENDING + (MOLEHILL_ONE << 8) + (MOLEHILL_ZERO << 0) )
					{
						blend_src_op = "ONE";
						blend_dst_op = "ZERO";
						
						setBlending( blend_src_op, blend_dst_op );
					}
					else if ( opcode == MOLEHILL_SET_BLENDING + (MOLEHILL_ONE << 8) + (MOLEHILL_ONE << 0) )
					{
						blend_src_op = "ONE";
						blend_dst_op = "ONE";
						
						setBlending( blend_src_op, blend_dst_op );
					}
					else if ( opcode == MOLEHILL_SET_BLENDING + (MOLEHILL_SRC_ALPHA << 8) +( MOLEHILL_ONE_MINUS_SRC_ALPHA << 0) )
					{
						blend_src_op = "SRC_ALPHA";
						blend_dst_op = "ONE_MINUS_SRC_ALPHA";
						
						setBlending( blend_src_op, blend_dst_op );
					}
					else if ( opcode == MOLEHILL_SET_BLENDING + (MOLEHILL_ZERO << 8) + (MOLEHILL_ONE_MINUS_SRC_COLOR << 0) )
					{
						blend_src_op = "ZERO";
						blend_dst_op = "ONE_MINUS_SRC_COLOR";
						
						setBlending( blend_src_op, blend_dst_op );
					}
					else if ( opcode == MOLEHILL_SET_BLENDING + (MOLEHILL_DST_COLOR << 8) + (MOLEHILL_ZERO << 0) )
					{
						blend_src_op = "DST_COLOR";
						blend_dst_op = "ZERO";
						
						setBlending( blend_src_op, blend_dst_op );
					}
					else if ( opcode == MOLEHILL_SET_BLENDING + (MOLEHILL_DST_COLOR << 8) + (MOLEHILL_SRC_COLOR << 0) )
					{
						blend_src_op = "DST_COLOR";
						blend_dst_op = "SRC_COLOR";
						
						setBlending( blend_src_op, blend_dst_op );
					}
					else if ( opcode == MOLEHILL_SET_BLENDING + (MOLEHILL_DST_COLOR << 8) + (MOLEHILL_ONE_MINUS_DST_ALPHA << 0) )
					{
						blend_src_op = "DST_COLOR";
						blend_dst_op = "ONE_MINUS_DST_ALPHA";
						
						setBlending( blend_src_op, blend_dst_op );
					}
					else if ( opcode == MOLEHILL_SET_BLENDING + (MOLEHILL_DST_COLOR << 8) + (MOLEHILL_ONE << 0) )
					{
						blend_src_op = "DST_COLOR";
						blend_dst_op = "ONE";
						
						setBlending( blend_src_op, blend_dst_op );
					}
					else if ( opcode == MOLEHILL_SET_BLENDING + (MOLEHILL_DST_COLOR << 8) + (MOLEHILL_SRC_ALPHA << 0) )
					{
						blend_src_op = "DST_COLOR";
						blend_dst_op = "SRC_ALPHA";
						
						setBlending( blend_src_op, blend_dst_op );
					}
					else if ( opcode == MOLEHILL_SET_DEPTHWRITE + MOLEHILL_FALSE )
					{
						depth_write = false;
						
						setDepthTest( depth_write, depth_func );
					}
					else if ( opcode == MOLEHILL_SET_DEPTHWRITE + MOLEHILL_TRUE )
					{
						depth_write = true;
						
						setDepthTest( depth_write, depth_func );
					}
					else if ( opcode == MOLEHILL_SET_ALPHATEST + MOLEHILL_FALSE )
					{
						alpha_test = false;
					}
					else if ( opcode == MOLEHILL_SET_ALPHATEST + MOLEHILL_TRUE )
					{
						alpha_test = true;
					}
					else if ( opcode == MOLEHILL_SET_DEPTHFUNC + MOLEHILL_ALWAYS )
					{
						depth_func = "ALWAYS";
						
						setDepthTest( depth_write, depth_func );
					}
					else if ( opcode == MOLEHILL_SET_DEPTHFUNC + MOLEHILL_EQUAL )
					{
						depth_func = "EQUAL";
						
						setDepthTest( depth_write, depth_func );
					}
					else if ( opcode == MOLEHILL_SET_DEPTHFUNC + MOLEHILL_LESS_OR_EQUAL )
					{
						depth_func = "LESS_EQUAL";
						
						setDepthTest( depth_write, depth_func );
					}
					else if ( opcode == MOLEHILL_SET_ALPHAFUNC + MOLEHILL_GREATER_OR_EQUAL )
					{
						alpha_func = "GREATER_EQUAL";
						alpha_ref = ram.readFloat();
					}
					else if ( opcode == MOLEHILL_SET_VIEWPORT )
					{
						var vx : int = ram.readInt();
						var vy : int = ram.readInt();
						var vw : int = ram.readInt();
						var vh : int = ram.readInt();

						setViewport( vx, vy, vw, vh );
					}
					else if ( opcode == MOLEHILL_SET_CULLING + MOLEHILL_NONE )
					{
						setCulling( "NONE" );
					}
					else if ( opcode == MOLEHILL_SET_CULLING + MOLEHILL_FRONT )
					{
						setCulling( "FRONT" );
					}
					else if ( opcode == MOLEHILL_SET_CULLING + MOLEHILL_BACK )
					{
						setCulling( "BACK" );
					}
					else
					{
						trace( "invalid masm opcode : " + opcode + " last_opcode : " + last_opcode );
					}
					
					last_opcode = opcode;
				}
			}
			
			trace( getTimeStamp() + " end execute( " + data_ptr + " ) " + count + " instructions, " + (ram.position - data_ptr) + " bytes read." );
		}
		
		private function uploadCache( id : int ) : void
		{
			trace( getTimeStamp() + " uploadCache( " + id + " )" );
			
			var index_buffer : IndexBuffer3D;
			var vertex_buffer : VertexBuffer3D;
			
			if ( index_count > 0 )
			{
				index_buffer = createIndexBuffer( index_count );
				index_buffer.upload( indices, 0, index_count );
				
				if ( use_texturing )
				{
					vertex_buffer = createVertexBuffer( vertex_count, 10 ); // vertex + color + texcoord
					vertex_buffer.upload( vertices, 0, vertex_count );
				}
				else
				{
					vertex_buffer = createVertexBuffer( vertex_count, 8 ); // vertex + color
					vertex_buffer.upload( vertices, 0, vertex_count );
				}

				var cache : Object =
				{
					vertex_count : vertex_count,
					index_count : index_count,
					
					vertex_buffer : vertex_buffer,
					index_buffer : index_buffer,
					
					use_texturing : use_texturing
				};
				
				caches[id] = cache;
			}
		}
		
		private function drawCache( id : int ) : void
		{
			trace( getTimeStamp() + " drawCache( " + id + " )" );
			
			var index_buffer : IndexBuffer3D;
			var vertex_buffer : VertexBuffer3D;
			
			var cache : Object = caches[id];
			
			if ( cache )
			{
				use_texturing = cache.use_texturing;
				
				vertex_count = cache.vertex_count;
				index_count = cache.index_count;
				
				vertex_buffer = cache.vertex_buffer;
				index_buffer = cache.index_buffer;
				
				if ( use_texturing )
				{
					if ( textures[tid] == null ) trace( "invalid texture id=" + tid );
					
					setTexture( 1, textures[tid] );
					
					setProgram( sp0 );
					
					setVertexStream( 0, vertex_buffer, 0, "FLOAT_4" );
					setVertexStream( 1, vertex_buffer, 4, "FLOAT_4" );
					setVertexStream( 2, vertex_buffer, 8, "FLOAT_2" );
				}
				else
				{
					setProgram( sp1 );
					
					setVertexStream( 0, vertex_buffer, 0, "FLOAT_4" );
					setVertexStream( 1, vertex_buffer, 4, "FLOAT_4" );
				}

				setProgramConstantsMatrixTransposed( "VERTEX", 0, matrix );
				setProgramConstants( "VERTEX", 4, 4, center );
				setProgramConstants( "VERTEX", 5, 4, factor );
				setProgramConstants( "VERTEX", 6, 4, offset );
				
				drawTriangles( index_buffer, 0, index_count / 3 );
			}
			
			vertex_count = 0;
			index_count = 0;

			vertex_offset = 0;
			index_offset = 0;
		}
		
		private function draw() : void
		{
			//trace( getTimeStamp() + " draw()" );
			
			if ( index_count > 0 )
			{
				ib.upload( indices, 0, index_count );
				
				if ( use_texturing )
				{
					vb0.upload( vertices, 0, vertex_count );
					
					if ( textures[tid] == null ) trace( "invalid texture id=" + tid );
					
					setTexture( 1, textures[tid] );
					
					setProgram( sp0 );
					
					setVertexStream( 0, vb0, 0, "FLOAT_4" );
					setVertexStream( 1, vb0, 4, "FLOAT_4" );
					setVertexStream( 2, vb0, 8, "FLOAT_2" );
				}
				else
				{
					vb1.upload( vertices, 0, vertex_count );
					
					setProgram( sp1 );
					
					setVertexStream( 0, vb1, 0, "FLOAT_4" );
					setVertexStream( 1, vb1, 4, "FLOAT_4" );
				}

				setProgramConstantsMatrixTransposed( "VERTEX", 0, matrix );
				setProgramConstants( "VERTEX", 4, 4, center );
				setProgramConstants( "VERTEX", 5, 4, factor );
				setProgramConstants( "VERTEX", 6, 4, offset );
				
				drawTriangles( ib, 0, index_count / 3 );
			}
			
			vertex_count = 0;
			index_count = 0;

			vertex_offset = 0;
			index_offset = 0;
		}
		
		private function drawFast() : void
		{
			trace( getTimeStamp() + " drawFast()" );
			
			if ( index_count > 0 )
			{
				if ( use_texturing )
				{
					if ( textures[tid] == null ) trace( "invalid texture id=" + tid );
					
					setTexture( 1, textures[tid] );
					
					setProgram( sp0 );
					
					setVertexStream( 0, vertices_fvb, 0, "FLOAT_4" );
					setVertexStream( 1, colors_fvb, 0, "FLOAT_4" );
					setVertexStream( 2, texcoords_fvb, 0, "FLOAT_2" );
				}
				else
				{
					setProgram( sp1 );
					
					setVertexStream( 0, vertices_fvb, 0, "FLOAT_4" );
					setVertexStream( 1, colors_fvb, 0, "FLOAT_4" );
				}

				setProgramConstantsMatrixTransposed( "VERTEX", 0, matrix );
				setProgramConstants( "VERTEX", 4, 4, center );
				setProgramConstants( "VERTEX", 5, 4, factor );
				setProgramConstants( "VERTEX", 6, 4, offset );
				
				drawTriangles( indices_fib, 0, index_count / 3 );
			}
			
			vertex_count = 0;
			index_count = 0;

			vertex_offset = 0;
			index_offset = 0;
			
			use_texturing = false;
		}

		public function bindTexture( id : int ) : void
		{
			//trace( getTimeStamp() + " bindTexture( " + id + " )" );
			
			tid = id;
		}

		public function uploadTexture( level : int, width : int, height : int, data_ptr : uint ) : void
		{
			//trace( getTimeStamp() + " uploadTexture( " + level + ", " + width + ", " + height + ", " + data_ptr + " )" );
			
			if ( width <= 1 || height <= 1 ) return; // prevent the FP11 to crash in OpenGL mode
			
			var bitmapData : BitmapData = new BitmapData( width, height, true, 0x00 );
			var rect : Rectangle = new Rectangle( 0, 0, width, height );
			var last_position : uint = ram.position;
			var texture : Texture3D = (level == 0) ? createTexture( width, height, "RGBA", false ) : textures[tid];
			
			ram.position = data_ptr;
			bitmapData.setPixels( rect, ram );
			ram.position = last_position;
			texture.upload( bitmapData, level );
			bitmapData.dispose();
			
			textures[tid] = texture;
		}
		
		public function setViewport( left : int, top : int, width : int, height : int ) : void
		{
			var fx : Number = width / 640;
			var fy : Number = height / 480;
			
			var ox : Number = left / 320;
			var oy : Number = top / 240;

			factor = Vector.<Number>( [fx, fy, 1.0, 1.0] );
			offset = Vector.<Number>( [ox, oy, 0.0, 0.0] );
		}
	}

}