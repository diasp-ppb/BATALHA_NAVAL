#include <iostream>
#include "BOMB.h"
#include "TYPE.h"

Bomb::Bomb(PositionChar targetPosition)
{
	unsigned int offset = (rand() % 2); // gera offset de 0 ou 1 aleatoriamente
	unsigned int direction = (rand() % 4); // gera diree�ao do offset (0, 1, 2, 3) aleatoriamente
	unsigned int linha = targetPosition.lin, coluna = targetPosition.col;

	// fazer condi�ao de calhar fora do tabuleiro

	if (offset == 1)
	{
		if (direction == 0) // dire�ao Norte
			linha--;
		else if (direction == 1) // dire�ao Este
			coluna++;
		else if (direction == 2) // diree�ao Sul
			linha++;
		else if (direction == 3) // diree�ao Oeste
	}

}