/*
===========================================================================
Copyright (C) 1999-2005 Id Software, Inc.

This file is part of Quake III Arena source code.

Quake III Arena source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Quake III Arena source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Foobar; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/

// snddma_null.c
// all other sound mixing is portable

#include "AS3.h"

int _soundTime;
float _soundSamples[16384];

short buffer[16384];

#include "../client/snd_local.h"

qboolean SNDDMA_Init( void )
{
	extern void trace( char* fmt, ... );
	trace( "SNDDMA_Init()" );
	
	memset( (void*)&dma, 0, sizeof(dma) );
	dma.speed = 44100;
	dma.channels = 2;
	dma.samplebits = 16;
	dma.samples = 16384;
	dma.submission_chunk = 1;
	dma.buffer = buffer;
	
	return qtrue;
}

int	SNDDMA_GetDMAPos( void )
{
	extern void trace( char* fmt, ... );
	trace( "SNDDMA_GetDMAPos() _soundTime=%d", _soundTime * 2 );
	
	return _soundTime * 2;
}

void SNDDMA_Shutdown( void )
{
	extern void trace( char* fmt, ... );
	trace( "SNDDMA_Shutdown()" );

	memset( (void*)&dma, 0, sizeof(dma) );
}

void SNDDMA_BeginPainting( void ) 
{
	extern void trace( char* fmt, ... );
	trace( "SNDDMA_BeginPainting()" );
}

inline static float __FloatSwap__( float f )
{
	union
	{
		float f;
		byte b[4];
	} d0, d1;
	
	d0.f = f;
	d1.b[0] = d0.b[3];
	d1.b[1] = d0.b[2];
	d1.b[2] = d0.b[1];
	d1.b[3] = d0.b[0];
	return d1.f;
}

void SNDDMA_Submit( void )
{
	extern int s_soundtime;
	extern int s_paintedtime;

	extern void trace( char* fmt, ... );
	trace( "SNDDMA_Submit() s_paintedtime=%d s_soundtime=%d diff=%d dma.submission_chunk=%d", s_paintedtime, s_soundtime, s_paintedtime - s_soundtime, dma.submission_chunk );
	
	//int k;
	//for ( k = 0 ; k < 16384 ; k += 8 )
	//	trace( "[%04.4X] %04.4X %04.4X %04.4X %04.4X %04.4X %04.4X %04.4X %04.4X", k, _soundSamples[k+0], _soundSamples[k+1], _soundSamples[k+2], _soundSamples[k+3], _soundSamples[k+4], _soundSamples[k+5], _soundSamples[k+6], _soundSamples[k+7] );
	
	/*int i; float f; float p = 1.0f / 6.2831853f;
	for( i = 0 ; i < 8192 ; i++ )
	{
		f = sin( ( i + _soundTime ) * p ) * 0.25;
		f = __FloatSwap__(f);
		_soundSamples[2*i+0] = f;
		_soundSamples[2*i+1] = f;
	}*/
	
	int i; float f; float p = 1.0f / 32768.0f;
	for( i = 0 ; i < 16384 ; i++ )
	{
		f = buffer[i] * p;
		f = __FloatSwap__(f);
		_soundSamples[i] = f;
	}
}