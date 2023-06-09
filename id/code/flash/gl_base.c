extern void glClearIndex( GLfloat c );
extern void glIndexMask( GLuint mask );
extern void glColorMask( GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha );
extern void glLogicOp( GLenum opcode );
extern void glFrontFace( GLenum mode );
extern void glPointSize( GLfloat size );
extern void glLineWidth( GLfloat width );
extern void glLineStipple( GLint factor, GLushort pattern );
extern void glPolygonStipple( GLubyte *mask );
extern void glGetPolygonStipple( GLubyte *mask );
extern void glEdgeFlag( GLboolean flag );
extern void glEdgeFlagv( GLboolean *flag );
extern void glClipPlane( GLenum plane, GLdouble *equation );
extern void glGetClipPlane( GLenum plane, GLdouble *equation );
extern void glReadBuffer( GLenum mode );
extern GLboolean glIsEnabled( GLenum cap );
extern void glGetBooleanv( GLenum pname, GLboolean *params );
extern void glGetDoublev( GLenum pname, GLdouble *params );
extern void glGetFloatv( GLenum pname, GLfloat *params );
extern void glPushAttrib( GLbitfield mask );
extern void glPopAttrib();
extern void glPushClientAttrib( GLbitfield mask );
extern void glPopClientAttrib();
extern GLint glRenderMode( GLenum mode );
extern void glHint( GLenum target, GLenum mode );
extern void glClearAccum( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha );
extern void glAccum( GLenum op, GLfloat value );
extern void glFrustum( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val );
extern void glPushMatrix();
extern void glPopMatrix();
extern void glLoadMatrixd( GLdouble *m );
extern void glMultMatrixd( GLdouble *m );
extern void glMultMatrixf( GLfloat *m );
extern void glRotated( GLdouble angle, GLdouble x, GLdouble y, GLdouble z );
extern void glRotatef( GLfloat angle, GLfloat x, GLfloat y, GLfloat z );
extern void glScaled( GLdouble x, GLdouble y, GLdouble z );
extern void glScalef( GLfloat x, GLfloat y, GLfloat z );
extern void glTranslated( GLdouble x, GLdouble y, GLdouble z );
extern void glTranslatef( GLfloat x, GLfloat y, GLfloat z );
extern GLboolean glIsList( GLuint list );
extern void glDeleteLists( GLuint list, GLsizei range );
extern GLuint glGenLists( GLsizei range );
extern void glNewList( GLuint list, GLenum mode );
extern void glEndList();
extern void glCallList( GLuint list );
extern void glCallLists( GLsizei n, GLenum type, GLvoid *lists );
extern void glListBase( GLuint base );
extern void glVertex2d( GLdouble x, GLdouble y );
extern void glVertex2i( GLint x, GLint y );
extern void glVertex2s( GLshort x, GLshort y );
extern void glVertex3d( GLdouble x, GLdouble y, GLdouble z );
extern void glVertex3f( GLfloat x, GLfloat y, GLfloat z );
extern void glVertex3i( GLint x, GLint y, GLint z );
extern void glVertex3s( GLshort x, GLshort y, GLshort z );
extern void glVertex4d( GLdouble x, GLdouble y, GLdouble z, GLdouble w );
extern void glVertex4f( GLfloat x, GLfloat y, GLfloat z, GLfloat w );
extern void glVertex4i( GLint x, GLint y, GLint z, GLint w );
extern void glVertex4s( GLshort x, GLshort y, GLshort z, GLshort w );
extern void glVertex2dv( GLdouble *v );
extern void glVertex2fv( GLfloat *v );
extern void glVertex2iv( GLint *v );
extern void glVertex2sv( GLshort *v );
extern void glVertex3dv( GLdouble *v );
extern void glVertex3iv( GLint *v );
extern void glVertex3sv( GLshort *v );
extern void glVertex4dv( GLdouble *v );
extern void glVertex4fv( GLfloat *v );
extern void glVertex4iv( GLint *v );
extern void glVertex4sv( GLshort *v );
extern void glNormal3b( GLbyte nx, GLbyte ny, GLbyte nz );
extern void glNormal3d( GLdouble nx, GLdouble ny, GLdouble nz );
extern void glNormal3f( GLfloat nx, GLfloat ny, GLfloat nz );
extern void glNormal3i( GLint nx, GLint ny, GLint nz );
extern void glNormal3s( GLshort nx, GLshort ny, GLshort nz );
extern void glNormal3bv( GLbyte *v );
extern void glNormal3dv( GLdouble *v );
extern void glNormal3fv( GLfloat *v );
extern void glNormal3iv( GLint *v );
extern void glNormal3sv( GLshort *v );
extern void glIndexd( GLdouble c );
extern void glIndexf( GLfloat c );
extern void glIndexi( GLint c );
extern void glIndexs( GLshort c );
extern void glIndexub( GLubyte c );
extern void glIndexdv( GLdouble *c );
extern void glIndexfv( GLfloat *c );
extern void glIndexiv( GLint *c );
extern void glIndexsv( GLshort *c );
extern void glIndexubv( GLubyte *c );
extern void glColor3b( GLbyte red, GLbyte green, GLbyte blue );
extern void glColor3d( GLdouble red, GLdouble green, GLdouble blue );
extern void glColor3i( GLint red, GLint green, GLint blue );
extern void glColor3s( GLshort red, GLshort green, GLshort blue );
extern void glColor3ub( GLubyte red, GLubyte green, GLubyte blue );
extern void glColor3ui( GLuint red, GLuint green, GLuint blue );
extern void glColor3us( GLushort red, GLushort green, GLushort blue );
extern void glColor4b( GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha );
extern void glColor4d( GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha );
extern void glColor4i( GLint red, GLint green, GLint blue, GLint alpha );
extern void glColor4s( GLshort red, GLshort green, GLshort blue, GLshort alpha );
extern void glColor4ub( GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha );
extern void glColor4ui( GLuint red, GLuint green, GLuint blue, GLuint alpha );
extern void glColor4us( GLushort red, GLushort green, GLushort blue, GLushort alpha );
extern void glColor3bv( GLbyte *v );
extern void glColor3dv( GLdouble *v );
extern void glColor3fv( GLfloat *v );
extern void glColor3iv( GLint *v );
extern void glColor3sv( GLshort *v );
extern void glColor3ubv( GLubyte *v );
extern void glColor3uiv( GLuint *v );
extern void glColor3usv( GLushort *v );
extern void glColor4bv( GLbyte *v );
extern void glColor4dv( GLdouble *v );
extern void glColor4fv( GLfloat *v );
extern void glColor4iv( GLint *v );
extern void glColor4sv( GLshort *v );
extern void glColor4uiv( GLuint *v );
extern void glColor4usv( GLushort *v );
extern void glTexCoord1d( GLdouble s );
extern void glTexCoord1f( GLfloat s );
extern void glTexCoord1i( GLint s );
extern void glTexCoord1s( GLshort s );
extern void glTexCoord2d( GLdouble s, GLdouble t );
extern void glTexCoord2i( GLint s, GLint t );
extern void glTexCoord2s( GLshort s, GLshort t );
extern void glTexCoord3d( GLdouble s, GLdouble t, GLdouble r );
extern void glTexCoord3f( GLfloat s, GLfloat t, GLfloat r );
extern void glTexCoord3i( GLint s, GLint t, GLint r );
extern void glTexCoord3s( GLshort s, GLshort t, GLshort r );
extern void glTexCoord4d( GLdouble s, GLdouble t, GLdouble r, GLdouble q );
extern void glTexCoord4f( GLfloat s, GLfloat t, GLfloat r, GLfloat q );
extern void glTexCoord4i( GLint s, GLint t, GLint r, GLint q );
extern void glTexCoord4s( GLshort s, GLshort t, GLshort r, GLshort q );
extern void glTexCoord1dv( GLdouble *v );
extern void glTexCoord1fv( GLfloat *v );
extern void glTexCoord1iv( GLint *v );
extern void glTexCoord1sv( GLshort *v );
extern void glTexCoord2dv( GLdouble *v );
extern void glTexCoord2iv( GLint *v );
extern void glTexCoord2sv( GLshort *v );
extern void glTexCoord3dv( GLdouble *v );
extern void glTexCoord3fv( GLfloat *v );
extern void glTexCoord3iv( GLint *v );
extern void glTexCoord3sv( GLshort *v );
extern void glTexCoord4dv( GLdouble *v );
extern void glTexCoord4fv( GLfloat *v );
extern void glTexCoord4iv( GLint *v );
extern void glTexCoord4sv( GLshort *v );
extern void glRasterPos2d( GLdouble x, GLdouble y );
extern void glRasterPos2f( GLfloat x, GLfloat y );
extern void glRasterPos2i( GLint x, GLint y );
extern void glRasterPos2s( GLshort x, GLshort y );
extern void glRasterPos3d( GLdouble x, GLdouble y, GLdouble z );
extern void glRasterPos3f( GLfloat x, GLfloat y, GLfloat z );
extern void glRasterPos3i( GLint x, GLint y, GLint z );
extern void glRasterPos3s( GLshort x, GLshort y, GLshort z );
extern void glRasterPos4d( GLdouble x, GLdouble y, GLdouble z, GLdouble w );
extern void glRasterPos4f( GLfloat x, GLfloat y, GLfloat z, GLfloat w );
extern void glRasterPos4i( GLint x, GLint y, GLint z, GLint w );
extern void glRasterPos4s( GLshort x, GLshort y, GLshort z, GLshort w );
extern void glRasterPos2dv( GLdouble *v );
extern void glRasterPos2fv( GLfloat *v );
extern void glRasterPos2iv( GLint *v );
extern void glRasterPos2sv( GLshort *v );
extern void glRasterPos3dv( GLdouble *v );
extern void glRasterPos3fv( GLfloat *v );
extern void glRasterPos3iv( GLint *v );
extern void glRasterPos3sv( GLshort *v );
extern void glRasterPos4dv( GLdouble *v );
extern void glRasterPos4fv( GLfloat *v );
extern void glRasterPos4iv( GLint *v );
extern void glRasterPos4sv( GLshort *v );
extern void glRectd( GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2 );
extern void glRectf( GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2 );
extern void glRecti( GLint x1, GLint y1, GLint x2, GLint y2 );
extern void glRects( GLshort x1, GLshort y1, GLshort x2, GLshort y2 );
extern void glRectdv( GLdouble *v1, GLdouble *v2 );
extern void glRectfv( GLfloat *v1, GLfloat *v2 );
extern void glRectiv( GLint *v1, GLint *v2 );
extern void glRectsv( GLshort *v1, GLshort *v2 );
extern void glNormalPointer( GLenum type, GLsizei stride, GLvoid *ptr );
extern void glIndexPointer( GLenum type, GLsizei stride, GLvoid *ptr );
extern void glEdgeFlagPointer( GLsizei stride, GLvoid *ptr );
extern void glGetPointerv( GLenum pname, GLvoid **params );
extern void glDrawArrays( GLenum mode, GLint first, GLsizei count );
extern void glInterleavedArrays( GLenum format, GLsizei stride, GLvoid *pointer );
extern void glLightf( GLenum light, GLenum pname, GLfloat param );
extern void glLighti( GLenum light, GLenum pname, GLint param );
extern void glLightfv( GLenum light, GLenum pname, GLfloat *params );
extern void glLightiv( GLenum light, GLenum pname, GLint *params );
extern void glGetLightfv( GLenum light, GLenum pname, GLfloat *params );
extern void glGetLightiv( GLenum light, GLenum pname, GLint *params );
extern void glLightModelf( GLenum pname, GLfloat param );
extern void glLightModeli( GLenum pname, GLint param );
extern void glLightModelfv( GLenum pname, GLfloat *params );
extern void glLightModeliv( GLenum pname, GLint *params );
extern void glMaterialf( GLenum face, GLenum pname, GLfloat param );
extern void glMateriali( GLenum face, GLenum pname, GLint param );
extern void glMaterialfv( GLenum face, GLenum pname, GLfloat *params );
extern void glMaterialiv( GLenum face, GLenum pname, GLint *params );
extern void glGetMaterialfv( GLenum face, GLenum pname, GLfloat *params );
extern void glGetMaterialiv( GLenum face, GLenum pname, GLint *params );
extern void glColorMaterial( GLenum face, GLenum mode );
extern void glPixelZoom( GLfloat xfactor, GLfloat yfactor );
extern void glPixelStoref( GLenum pname, GLfloat param );
extern void glPixelStorei( GLenum pname, GLint param );
extern void glPixelTransferf( GLenum pname, GLfloat param );
extern void glPixelTransferi( GLenum pname, GLint param );
extern void glPixelMapfv( GLenum map, GLsizei mapsize, GLfloat *values );
extern void glPixelMapuiv( GLenum map, GLsizei mapsize, GLuint *values );
extern void glPixelMapusv( GLenum map, GLsizei mapsize, GLushort *values );
extern void glGetPixelMapfv( GLenum map, GLfloat *values );
extern void glGetPixelMapuiv( GLenum map, GLuint *values );
extern void glGetPixelMapusv( GLenum map, GLushort *values );
extern void glBitmap( GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, GLubyte *bitmap );
extern void glReadPixels( GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels );
extern void glDrawPixels( GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels );
extern void glCopyPixels( GLint x, GLint y, GLsizei width, GLsizei height, GLenum type );
extern void glStencilFunc( GLenum func, GLint ref, GLuint mask );
extern void glStencilMask( GLuint mask );
extern void glStencilOp( GLenum fail, GLenum zfail, GLenum zpass );
extern void glClearStencil( GLint s );
extern void glTexGend( GLenum coord, GLenum pname, GLdouble param );
extern void glTexGenf( GLenum coord, GLenum pname, GLfloat param );
extern void glTexGeni( GLenum coord, GLenum pname, GLint param );
extern void glTexGendv( GLenum coord, GLenum pname, GLdouble *params );
extern void glTexGenfv( GLenum coord, GLenum pname, GLfloat *params );
extern void glTexGeniv( GLenum coord, GLenum pname, GLint *params );
extern void glGetTexGendv( GLenum coord, GLenum pname, GLdouble *params );
extern void glGetTexGenfv( GLenum coord, GLenum pname, GLfloat *params );
extern void glGetTexGeniv( GLenum coord, GLenum pname, GLint *params );
extern void glTexEnvi( GLenum target, GLenum pname, GLint param );
extern void glTexEnvfv( GLenum target, GLenum pname, GLfloat *params );
extern void glTexEnviv( GLenum target, GLenum pname, GLint *params );
extern void glGetTexEnvfv( GLenum target, GLenum pname, GLfloat *params );
extern void glGetTexEnviv( GLenum target, GLenum pname, GLint *params );
extern void glTexParameteri( GLenum target, GLenum pname, GLint param );
extern void glTexParameteriv( GLenum target, GLenum pname, GLint *params );
extern void glGetTexParameterfv( GLenum target, GLenum pname, GLfloat *params );
extern void glGetTexParameteriv( GLenum target, GLenum pname, GLint *params );
extern void glGetTexLevelParameterfv( GLenum target, GLint level, GLenum pname, GLfloat *params );
extern void glGetTexLevelParameteriv( GLenum target, GLint level, GLenum pname, GLint *params );
extern void glTexImage1D( GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid *pixels );
extern void glGetTexImage( GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels );
extern void glGenTextures( GLsizei n, GLuint *textures );
extern void glDeleteTextures( GLsizei n, GLuint *textures );
extern void glPrioritizeTextures( GLsizei n, GLuint *textures, GLclampf *priorities );
extern GLboolean glAreTexturesResident( GLsizei n, GLuint *textures, GLboolean *residences );
extern GLboolean glIsTexture( GLuint texture );
extern void glTexSubImage1D( GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid *pixels );
extern void glCopyTexImage1D( GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border );
extern void glCopyTexImage2D( GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border );
extern void glCopyTexSubImage1D( GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width );
extern void glCopyTexSubImage2D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height );
extern void glMap1d( GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, GLdouble *points );
extern void glMap1f( GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, GLfloat *points );
extern void glMap2d( GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble *points );
extern void glMap2f( GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat *points );
extern void glGetMapdv( GLenum target, GLenum query, GLdouble *v );
extern void glGetMapfv( GLenum target, GLenum query, GLfloat *v );
extern void glGetMapiv( GLenum target, GLenum query, GLint *v );
extern void glEvalCoord1d( GLdouble u );
extern void glEvalCoord1f( GLfloat u );
extern void glEvalCoord1dv( GLdouble *u );
extern void glEvalCoord1fv( GLfloat *u );
extern void glEvalCoord2d( GLdouble u, GLdouble v );
extern void glEvalCoord2f( GLfloat u, GLfloat v );
extern void glEvalCoord2dv( GLdouble *u );
extern void glEvalCoord2fv( GLfloat *u );
extern void glMapGrid1d( GLint un, GLdouble u1, GLdouble u2 );
extern void glMapGrid1f( GLint un, GLfloat u1, GLfloat u2 );
extern void glMapGrid2d( GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2 );
extern void glMapGrid2f( GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2 );
extern void glEvalPoint1( GLint i );
extern void glEvalPoint2( GLint i, GLint j );
extern void glEvalMesh1( GLenum mode, GLint i1, GLint i2 );
extern void glEvalMesh2( GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2 );
extern void glFogf( GLenum pname, GLfloat param );
extern void glFogi( GLenum pname, GLint param );
extern void glFogfv( GLenum pname, GLfloat *params );
extern void glFogiv( GLenum pname, GLint *params );
extern void glFeedbackBuffer( GLsizei size, GLenum type, GLfloat *buffer );
extern void glPassThrough( GLfloat token );
extern void glSelectBuffer( GLsizei size, GLuint *buffer );
extern void glInitNames();
extern void glLoadName( GLuint name );
extern void glPushName( GLuint name );
extern void glPopName();
extern void glDrawRangeElements( GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid *indices );
extern void glTexImage3D( GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid *pixels );
extern void glTexSubImage3D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid *pixels );
extern void glCopyTexSubImage3D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height );
extern void glColorTable( GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid *table );
extern void glColorSubTable( GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, GLvoid *data );
extern void glColorTableParameteriv( GLenum target, GLenum pname, GLint *params );
extern void glColorTableParameterfv( GLenum target, GLenum pname, GLfloat *params );
extern void glCopyColorSubTable( GLenum target, GLsizei start, GLint x, GLint y, GLsizei width );
extern void glCopyColorTable( GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width );
extern void glGetColorTable( GLenum target, GLenum format, GLenum type, GLvoid *table );
extern void glGetColorTableParameterfv( GLenum target, GLenum pname, GLfloat *params );
extern void glGetColorTableParameteriv( GLenum target, GLenum pname, GLint *params );
extern void glBlendEquation( GLenum mode );
extern void glBlendColor( GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha );
extern void glHistogram( GLenum target, GLsizei width, GLenum internalformat, GLboolean sink );
extern void glResetHistogram( GLenum target );
extern void glGetHistogram( GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values );
extern void glGetHistogramParameterfv( GLenum target, GLenum pname, GLfloat *params );
extern void glGetHistogramParameteriv( GLenum target, GLenum pname, GLint *params );
extern void glMinmax( GLenum target, GLenum internalformat, GLboolean sink );
extern void glResetMinmax( GLenum target );
extern void glGetMinmax( GLenum target, GLboolean reset, GLenum format, GLenum types, GLvoid *values );
extern void glGetMinmaxParameterfv( GLenum target, GLenum pname, GLfloat *params );
extern void glGetMinmaxParameteriv( GLenum target, GLenum pname, GLint *params );
extern void glConvolutionFilter1D( GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid *image );
extern void glConvolutionFilter2D( GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *image );
extern void glConvolutionParameterf( GLenum target, GLenum pname, GLfloat params );
extern void glConvolutionParameterfv( GLenum target, GLenum pname, GLfloat *params );
extern void glConvolutionParameteri( GLenum target, GLenum pname, GLint params );
extern void glConvolutionParameteriv( GLenum target, GLenum pname, GLint *params );
extern void glCopyConvolutionFilter1D( GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width );
extern void glCopyConvolutionFilter2D( GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height );
extern void glGetConvolutionFilter( GLenum target, GLenum format, GLenum type, GLvoid *image );
extern void glGetConvolutionParameterfv( GLenum target, GLenum pname, GLfloat *params );
extern void glGetConvolutionParameteriv( GLenum target, GLenum pname, GLint *params );
extern void glSeparableFilter2D( GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *row, GLvoid *column );
extern void glGetSeparableFilter( GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span );
extern void glActiveTexture( GLenum texture );
extern void glClientActiveTexture( GLenum texture );
extern void glCompressedTexImage1D( GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid *data );
extern void glCompressedTexImage2D( GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid *data );
extern void glCompressedTexImage3D( GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid *data );
extern void glCompressedTexSubImage1D( GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid *data );
extern void glCompressedTexSubImage2D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid *data );
extern void glCompressedTexSubImage3D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid *data );
extern void glGetCompressedTexImage( GLenum target, GLint lod, GLvoid *img );
extern void glMultiTexCoord1d( GLenum target, GLdouble s );
extern void glMultiTexCoord1dv( GLenum target, GLdouble *v );
extern void glMultiTexCoord1f( GLenum target, GLfloat s );
extern void glMultiTexCoord1fv( GLenum target, GLfloat *v );
extern void glMultiTexCoord1i( GLenum target, GLint s );
extern void glMultiTexCoord1iv( GLenum target, GLint *v );
extern void glMultiTexCoord1s( GLenum target, GLshort s );
extern void glMultiTexCoord1sv( GLenum target, GLshort *v );
extern void glMultiTexCoord2d( GLenum target, GLdouble s, GLdouble t );
extern void glMultiTexCoord2dv( GLenum target, GLdouble *v );
extern void glMultiTexCoord2f( GLenum target, GLfloat s, GLfloat t );
extern void glMultiTexCoord2fv( GLenum target, GLfloat *v );
extern void glMultiTexCoord2i( GLenum target, GLint s, GLint t );
extern void glMultiTexCoord2iv( GLenum target, GLint *v );
extern void glMultiTexCoord2s( GLenum target, GLshort s, GLshort t );
extern void glMultiTexCoord2sv( GLenum target, GLshort *v );
extern void glMultiTexCoord3d( GLenum target, GLdouble s, GLdouble t, GLdouble r );
extern void glMultiTexCoord3dv( GLenum target, GLdouble *v );
extern void glMultiTexCoord3f( GLenum target, GLfloat s, GLfloat t, GLfloat r );
extern void glMultiTexCoord3fv( GLenum target, GLfloat *v );
extern void glMultiTexCoord3i( GLenum target, GLint s, GLint t, GLint r );
extern void glMultiTexCoord3iv( GLenum target, GLint *v );
extern void glMultiTexCoord3s( GLenum target, GLshort s, GLshort t, GLshort r );
extern void glMultiTexCoord3sv( GLenum target, GLshort *v );
extern void glMultiTexCoord4d( GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q );
extern void glMultiTexCoord4dv( GLenum target, GLdouble *v );
extern void glMultiTexCoord4f( GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q );
extern void glMultiTexCoord4fv( GLenum target, GLfloat *v );
extern void glMultiTexCoord4i( GLenum target, GLint s, GLint t, GLint r, GLint q );
extern void glMultiTexCoord4iv( GLenum target, GLint *v );
extern void glMultiTexCoord4s( GLenum target, GLshort s, GLshort t, GLshort r, GLshort q );
extern void glMultiTexCoord4sv( GLenum target, GLshort *v );
extern void glLoadTransposeMatrixd( GLdouble m[16] );
extern void glLoadTransposeMatrixf( GLfloat m[16] );
extern void glMultTransposeMatrixd( GLdouble m[16] );
extern void glMultTransposeMatrixf( GLfloat m[16] );
extern void glSampleCoverage( GLclampf value, GLboolean invert );
