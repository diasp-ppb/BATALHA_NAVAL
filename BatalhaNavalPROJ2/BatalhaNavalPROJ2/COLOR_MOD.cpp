#include "COLOR_MOD.h"

// Set text color & background
void setcolor(unsigned int color, unsigned int background_color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); if (background_color == BLACK)
		SetConsoleTextAttribute(hCon, color); else
		SetConsoleTextAttribute(hCon, color | background_color * 16 + color);
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
