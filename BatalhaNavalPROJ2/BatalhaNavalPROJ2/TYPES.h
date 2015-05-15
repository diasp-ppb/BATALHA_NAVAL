#ifndef _TYPES
#define _TYPES

template <typename T>
struct Position
{
	T lin, col;
};

//=============================================================================
struct PositionChar // to store a board position in char format
{ // example: 'B','d'
	char lin, col; // ranges: lin - ['A'..'Z']; col - ['a'..'z']
};//-----------------------------------------------------------------------------
struct PositionInt // to store a board position in unsig. integer format
{ // example: 7,0
	unsigned int lin, col; // ranges: lin - [0..26]; col - [0..26]
};

#endif 