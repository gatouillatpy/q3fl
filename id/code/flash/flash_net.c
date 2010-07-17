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

#include "../qcommon/qcommon.h"

#define	MAX_IPS 16
static int numIP;
static byte localIP[MAX_IPS][4];

/*
==================
Sys_IsLANAddress

LAN clients will have their rate var ignored
==================
*/
qboolean	Sys_IsLANAddress (netadr_t adr) {
	int		i;

	if( adr.type == NA_LOOPBACK ) {
		return qtrue;
	}

	if( adr.type == NA_IPX ) {
		return qtrue;
	}

	if( adr.type != NA_IP ) {
		return qfalse;
	}

	// choose which comparison to use based on the class of the address being tested
	// any local adresses of a different class than the address being tested will fail based on the first byte

	// Class A
	if( (adr.ip[0] & 0x80) == 0x00 ) {
		for ( i = 0 ; i < numIP ; i++ ) {
			if( adr.ip[0] == localIP[i][0] ) {
				return qtrue;
			}
		}
		// the RFC1918 class a block will pass the above test
		return qfalse;
	}

	// Class B
	if( (adr.ip[0] & 0xc0) == 0x80 ) {
		for ( i = 0 ; i < numIP ; i++ ) {
			if( adr.ip[0] == localIP[i][0] && adr.ip[1] == localIP[i][1] ) {
				return qtrue;
			}
			// also check against the RFC1918 class b blocks
			if( adr.ip[0] == 172 && localIP[i][0] == 172 && (adr.ip[1] & 0xf0) == 16 && (localIP[i][1] & 0xf0) == 16 ) {
				return qtrue;
			}
		}
		return qfalse;
	}

	// Class C
	for ( i = 0 ; i < numIP ; i++ ) {
		if( adr.ip[0] == localIP[i][0] && adr.ip[1] == localIP[i][1] && adr.ip[2] == localIP[i][2] ) {
			return qtrue;
		}
		// also check against the RFC1918 class c blocks
		if( adr.ip[0] == 192 && localIP[i][0] == 192 && adr.ip[1] == 168 && localIP[i][1] == 168 ) {
			return qtrue;
		}
	}
	return qfalse;
}

/*
==================
Sys_ShowIP
==================
*/
void Sys_ShowIP(void) {
	int i;

	for (i = 0; i < numIP; i++) {
		Com_Printf( "IP: %i.%i.%i.%i\n", localIP[i][0], localIP[i][1], localIP[i][2], localIP[i][3] );
	}
}

/*
=====================
NET_GetLocalAddress
=====================
*/
void NET_GetLocalAddress( void ) {
	numIP = 0;
	localIP[numIP][0] = 127;
	localIP[numIP][1] = 0;
	localIP[numIP][2] = 0;
	localIP[numIP][3] = 1;
}

/*
====================
NET_Init
====================
*/
void NET_Init( void )
{
}

/*
==================
Sys_SendPacket
==================
*/
void Sys_SendPacket( int length, const void *data, netadr_t to ) {
}

/*
==================
Sys_GetPacket

Never called by the game logic, just the system event queing
==================
*/
qboolean	Sys_GetPacket ( netadr_t *net_from, msg_t *net_message ) {
	return qfalse;
}
