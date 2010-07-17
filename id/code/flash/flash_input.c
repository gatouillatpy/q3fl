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

#include "../client/client.h"

byte _asToQKey[256];

int mouse_x, mouse_y;

extern void Sys_QueEvent( int time, sysEventType_t type, int value, int value2, int ptrLength, void *ptr );

void IN_Init( void )
{
	// ASCII	String			Code
	/* 9		(Tab)		*/	_asToQKey[9] = K_TAB;
	/* 27		(Escape)	*/	_asToQKey[27] = K_ESCAPE;
	/* 8		(Backspace)	*/	_asToQKey[8] = K_BACKSPACE;
	/* 0		(CapsLock)	*///_asToQKey[20] = 
	/* 0		(Shift)		*/	_asToQKey[16] = K_SHIFT;
	/* 0		(Alt)		*/	_asToQKey[18] = K_ALT;
	/* 0		(Ctrl)		*/	_asToQKey[17] = K_CTRL;
	/* 13		(Enter)		*/	_asToQKey[13] = K_ENTER;
	/* 32		(Space)		*/	_asToQKey[32] = K_SPACE;
	/* 0		(F1)		*/	_asToQKey[112] = K_F1;
	/* 0		(F2)		*/	_asToQKey[113] = K_F2;
	/* 0		(F3)		*/	_asToQKey[114] = K_F3;
	/* 0		(F4)		*/	_asToQKey[115] = K_F4;
	/* 0		(F5)		*/	_asToQKey[116] = K_F5;
	/* 0		(F6)		*/	_asToQKey[117] = K_F6;
	/* 0		(F7)		*/	_asToQKey[118] = K_F7;
	/* 0		(F8)		*/	_asToQKey[119] = K_F8;
	/* 0		(F9)		*/	_asToQKey[120] = K_F9;
	/* 0		(F10)		*/	_asToQKey[121] = K_F10;
	/* 0		(F11)		*/	_asToQKey[122] = K_F11;
	/* 0		(F12)		*/	_asToQKey[123] = K_F12;
	/* 126		~			*/	_asToQKey[192] = '~';
	/* 33		!			*/	_asToQKey[49] = '!';
	/* 64		@			*/	_asToQKey[50] = '@';
	/* 35		#			*/	_asToQKey[51] = '#';
	/* 36		$			*/	_asToQKey[52] = '$';
	/* 37		%			*/	_asToQKey[53] = '%';
	/* 94		^			*/	_asToQKey[54] = '^';
	/* 38		&			*/	_asToQKey[55] = '&';
	/* 42		*			*/	_asToQKey[56] = '*';
	/* 40		(			*/	_asToQKey[57] = '(';
	/* 41		)			*/	_asToQKey[48] = ')';
	/* 95		_			*/	_asToQKey[189] = '_';
	/* 43		+			*/	_asToQKey[187] = '+';
	/* 124		|			*/	_asToQKey[220] = '|';
	/* 81		Q			*/	_asToQKey[81] = 'Q';
	/* 87		W			*/	_asToQKey[87] = 'W';
	/* 69		E			*/	_asToQKey[69] = 'E';
	/* 82		R			*/	_asToQKey[82] = 'R';
	/* 84		T			*/	_asToQKey[84] = 'T';
	/* 89		Y			*/	_asToQKey[89] = 'Y';
	/* 85		U			*/	_asToQKey[85] = 'U';
	/* 73		I			*/	_asToQKey[73] = 'I';
	/* 79		O			*/	_asToQKey[79] = 'O';
	/* 80		P			*/	_asToQKey[80] = 'P';
	/* 123		{			*/	_asToQKey[219] = '{';
	/* 125		}			*/	_asToQKey[221] = '}';
	/* 65		A			*/	_asToQKey[65] = 'A';
	/* 83		S			*/	_asToQKey[83] = 'S';
	/* 68		D			*/	_asToQKey[68] = 'D';
	/* 70		F			*/	_asToQKey[70] = 'F';
	/* 71		G			*/	_asToQKey[71] = 'G';
	/* 72		H			*/	_asToQKey[72] = 'H';
	/* 74		J			*/	_asToQKey[74] = 'J';
	/* 75		K			*/	_asToQKey[75] = 'K';
	/* 76		L			*/	_asToQKey[76] = 'L';
	/* 58		:			*/	_asToQKey[186] = ':';
	/* 34		"			*/	_asToQKey[222] = '"';
	/* 90		Z			*/	_asToQKey[90] = 'Z';
	/* 88		X			*/	_asToQKey[88] = 'X';
	/* 67		C			*/	_asToQKey[67] = 'C';
	/* 86		V			*/	_asToQKey[86] = 'V';
	/* 66		B			*/	_asToQKey[66] = 'B';
	/* 78		N			*/	_asToQKey[78] = 'N';
	/* 77		M			*/	_asToQKey[77] = 'M';
	/* 60		<			*/	_asToQKey[188] = '<';
	/* 62		>			*/	_asToQKey[190] = '>';
	/* 63		?			*/	_asToQKey[191] = '?';
	/* 96		`			*/	_asToQKey[223] = '`';
	/* 49		1			*/	_asToQKey[49] = '1';
	/* 50		2			*/	_asToQKey[50] = '2';
	/* 51		3			*/	_asToQKey[51] = '3';
	/* 52		4			*/	_asToQKey[52] = '4';
	/* 53		5			*/	_asToQKey[53] = '5';
	/* 54		6			*/	_asToQKey[54] = '6';
	/* 55		7			*/	_asToQKey[55] = '7';
	/* 56		8			*/	_asToQKey[56] = '8';
	/* 57		9			*/	_asToQKey[57] = '9';
	/* 48		0			*/	_asToQKey[48] = '0';
	/* 45		-			*/	_asToQKey[189] = '-';
	/* 61		=			*/	_asToQKey[187] = '=';
	/* 92		\			*/	_asToQKey[220] = '\\';
	/* 113		q			*/	_asToQKey[81] = 'q';
	/* 119		w			*/	_asToQKey[87] = 'w';
	/* 101		e			*/	_asToQKey[69] = 'e';
	/* 114		r			*/	_asToQKey[82] = 'r';
	/* 116		t			*/	_asToQKey[84] = 't';
	/* 121		y			*/	_asToQKey[89] = 'y';
	/* 117		u			*/	_asToQKey[85] = 'u';
	/* 105		i			*/	_asToQKey[73] = 'i';
	/* 111		o			*/	_asToQKey[79] = 'o';
	/* 112		p			*/	_asToQKey[80] = 'p';
	/* 91		[			*/	_asToQKey[219] = '[';
	/* 93		]			*/	_asToQKey[221] = ']';
	/* 97		a			*/	_asToQKey[65] = 'a';
	/* 115		s			*/	_asToQKey[83] = 's';
	/* 100		d			*/	_asToQKey[68] = 'd';
	/* 102		f			*/	_asToQKey[70] = 'f';
	/* 103		g			*/	_asToQKey[71] = 'g';
	/* 104		h			*/	_asToQKey[72] = 'h';
	/* 106		j			*/	_asToQKey[74] = 'j';
	/* 107		k			*/	_asToQKey[75] = 'k';
	/* 108		l			*/	_asToQKey[76] = 'l';
	/* 59		;			*/	_asToQKey[186] = ';';
	/* 39		'			*/	_asToQKey[222] = '\'';
	/* 122		z			*/	_asToQKey[90] = 'z';
	/* 120		x			*/	_asToQKey[88] = 'x';
	/* 99		c			*/	_asToQKey[67] = 'c';
	/* 118		v			*/	_asToQKey[86] = 'v';
	/* 98		b			*/	_asToQKey[66] = 'b';
	/* 110		n			*/	_asToQKey[78] = 'n';
	/* 109		m			*/	_asToQKey[77] = 'm';
	/* 44		,			*/	_asToQKey[188] = ',';
	/* 46		.			*/	_asToQKey[190] = '.';
	/* 47		/			*/	_asToQKey[191] = '/';
	/* 47		/			*/	_asToQKey[111] = '/';
	/* 42		*			*/	_asToQKey[106] = '*';
	/* 45		-			*/	_asToQKey[109] = '-';
	/* 55		7			*/	_asToQKey[103] = '7';
	/* 56		8			*/	_asToQKey[104] = '8';
	/* 57		9			*/	_asToQKey[105] = '9';
	/* 52		4			*/	_asToQKey[100] = '4';
	/* 53		5			*/	_asToQKey[101] = '5';
	/* 54		6			*/	_asToQKey[102] = '6';
	/* 49		1			*/	_asToQKey[97] = '1';
	/* 50		2			*/	_asToQKey[98] = '2';
	/* 51		3			*/	_asToQKey[99] = '3';
	/* 48		0			*/	_asToQKey[96] = '0';
	/* 46		.			*/	_asToQKey[110] = '.';
	/* 13					*/	_asToQKey[13] = '3';
	/* 43		+			*/	_asToQKey[107] = '+';
	/* 47		/			*/	_asToQKey[111] = '/';
	/* 42		*			*/	_asToQKey[106] = '*';
	/* 45		-			*/	_asToQKey[109] = '-';
	/* 0		(Home)		*/	_asToQKey[36] = K_HOME;
	/* 0		(Up)		*/	_asToQKey[38] = K_UPARROW;
	/* 0		(PgUp)		*/	_asToQKey[33] = K_PGUP;
	/* 0		(Left)		*/	_asToQKey[37] = K_LEFTARROW;
	/* 0					*/	_asToQKey[12] = 
	/* 0		(Right)		*/	_asToQKey[39] = K_RIGHTARROW;
	/* 0		(End)		*/	_asToQKey[35] = K_END;
	/* 0		(Down)		*/	_asToQKey[40] = K_DOWNARROW;
	/* 0		(PgDown)	*/	_asToQKey[34] = K_PGUP;
	/* 0		(Ins)		*/	_asToQKey[45] = K_INS;
	/* 127		(Del)		*/	_asToQKey[46] = K_DEL;
	/* 13		(Enter)		*/	_asToQKey[13] = K_ENTER;
	/* 43		+			*/	_asToQKey[107] = '+';
	/* 0		(ScrollLock)*///_asToQKey[145] = 
	/* 0		(Pause)		*/	_asToQKey[19] = K_PAUSE;
	/* 0		(Ins)		*/	_asToQKey[45] = K_INS;
	/* 0		(Home)		*/	_asToQKey[36] = K_HOME;
	/* 0		(PageUp)	*/	_asToQKey[33] = K_PGUP;
	/* 127		(Delete)	*/	_asToQKey[46] = K_DEL;
	/* 0		(End)		*/	_asToQKey[35] = K_END;
	/* 0		(PageDown)	*/	_asToQKey[34] = K_PGDN;
	/* 0		(Left)		*/	_asToQKey[37] = K_LEFTARROW;
	/* 0		(Up)		*/	_asToQKey[38] = K_UPARROW;
	/* 0		(Down)		*/	_asToQKey[40] = K_DOWNARROW;
	/* 0		(Right) 	*/	_asToQKey[39] = K_RIGHTARROW;
}

void IN_KeybUp( int keycode )
{
	Sys_QueEvent( 0, SE_KEY, keycode, qtrue, 0, NULL );
}

void IN_KeybDown( int keycode )
{
	Sys_QueEvent( 0, SE_KEY, keycode, qfalse, 0, NULL );
	
	if ( keycode >= 0x20 && keycode <= 0x7E )
		Sys_QueEvent( 0, SE_CHAR, keycode, 0, 0, NULL );
}

void IN_MouseUp( int button )
{
	Sys_QueEvent( 0, SE_KEY, K_MOUSE1 + button, qfalse, 0, NULL );
}

void IN_MouseDown( int button )
{
	Sys_QueEvent( 0, SE_KEY, K_MOUSE1 + button, qtrue, 0, NULL );
}

void IN_MouseMove( void )
{
	if ( mouse_x && mouse_y )
	{
		Sys_QueEvent( 0, SE_MOUSE, mouse_x, mouse_y, 0, NULL );
	}
	
	mouse_x = 0;
	mouse_y = 0;
}

void IN_Frame( void )
{
	IN_MouseMove();
}

void IN_Shutdown( void )
{
}

void Sys_SendKeyEvents( void )
{
}

