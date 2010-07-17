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

#include "../renderer/tr_local.h"

qboolean ( * qwglSwapIntervalEXT)( int interval );
void ( * qglMultiTexCoord2fARB )( GLenum texture, float s, float t );
void ( * qglActiveTextureARB )( GLenum texture );
void ( * qglClientActiveTextureARB )( GLenum texture );

void ( * qglLockArraysEXT)( int, int);
void ( * qglUnlockArraysEXT) ( void );

void GLimp_EndFrame( void )
{
	qglFlush();
}

void GLimp_Init( void )
{
	ri.Printf( PRINT_ALL, "Initializing OpenGL wrapper for Flash\n" );

	glConfig.driverType = GLDRV_STANDALONE;
	glConfig.isFullscreen = qfalse;
	glConfig.maxActiveTextures = 1;
	glConfig.vidWidth = 640;
	glConfig.vidHeight = 480;
	glConfig.colorBits = 32;
	glConfig.depthBits = 24;
	glConfig.stencilBits = 8;
	glConfig.displayFrequency = 60;
	glConfig.deviceSupportsGamma = 0;

	Q_strncpyz( glConfig.vendor_string, qglGetString(GL_VENDOR), sizeof( glConfig.vendor_string ) );
	Q_strncpyz( glConfig.renderer_string, qglGetString(GL_RENDERER), sizeof( glConfig.renderer_string ) );
	Q_strncpyz( glConfig.version_string, qglGetString(GL_VERSION), sizeof( glConfig.version_string ) );
	Q_strncpyz( glConfig.extensions_string, qglGetString(GL_EXTENSIONS), sizeof( glConfig.extensions_string ) );

	ri.Cvar_Set( "r_lastValidRenderer", glConfig.renderer_string );
}

void GLimp_Shutdown( void )
{
}

void GLimp_EnableLogging( qboolean enable )
{
}

void GLimp_LogComment( char *comment )
{
}

qboolean QGL_Init( const char *dllname )
{
	return qtrue;
}

void QGL_Shutdown( void )
{
}
