#include <iostream>
#include "BOMB.h"
#include "TYPES.h"

// sets target position values
void Bomb::setValues(char lin, char col)
{
	targetLine = lin;
	targetColumn = col;
}

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

	// fazer condiçao de calhar fora do tabuleiro

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
}

void show() const
{

}
