#include <iostream>
#include "BOMB.h"
#include "TYPES.h"

// returns target position, using the private values
Position<char> Bomb::getTargetPosition() const
{
	Position<char> target;
	target.col = targetColumn;
	target.lin = targetLine;

	return target;
}

// returns actual position, using the private values
Position<char> Bomb::getActualPosition() const
{
	Position<char> actual;
	actual.col = actualColumn;
	actual.lin = actualLine;

	return actual;
}

// Bomb Constructor
Bomb::Bomb(Position<char> targetPosition)
{
	int offset = (rand() % 6);
	int line = targetPosition.lin, column = targetPosition.col;

	targetLine = line;
	targetColumn = column;

	// fazer condiçao de calhar fora do tabuleiro

	if (offset == 0) // 1/6
	{
		int direction = (rand() % 4); // generates direction of offset
		if (direction == 0) // Norte
			line--;
		else if (direction == 1) // Este
			column++;
		else if (direction == 2) // Sul
			line++;
		else if (direction == 3) // Oeste
			column--;
	}

	actualLine = line; // stores final line
	actualColumn = column; // stores final column
}

void Bomb::show() const
{
	cout << "Linha pretendida: " << targetLine << "\nLinha final: " << actualLine << endl;
	cout << "Coluna pretendida: " << targetColumn << "\nColuna final: " << actualColumn << endl;
}
