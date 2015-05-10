#include <iostream>
#include "BOMB.h"
#include "TYPES.h"

// returns target position, using the private values
PositionChar Bomb::getTargetPosition() const 
{
	PositionChar target;
	target.col = targetLine;
	target.lin = targetColumn;

	return target;
}

// Bomb Constructor
Bomb::Bomb(PositionChar targetPosition)
{
	unsigned int offset = (rand() % 3); // generates 0, 1 or 2 randomly. 
	unsigned int line = targetPosition.lin, column = targetPosition.col;

	targetLine = line;
	targetColumn = column;

	// fazer condi�ao de calhar fora do tabuleiro

	if (offset == 0) // 1/3 chance
	{
		unsigned int direction = (rand() % 4); // generates direction of offset
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
