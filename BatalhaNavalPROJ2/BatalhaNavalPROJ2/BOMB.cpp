#include <iostream>
#include "BOMB.h"
#include "TYPES.h"

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

// returns target position, using the private values
PositionChar Bomb::getTargetPosition() const 
{
	PositionChar target;
	target.col = targetLine;
	target.lin = targetColumn;

	return target;
}

void show() const
{

}
