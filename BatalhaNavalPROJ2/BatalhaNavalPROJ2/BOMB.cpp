#include <iostream>
#include "BOMB.h"
#include "TYPE.h"

Bomb::Bomb(PositionChar targetPosition)
{
	unsigned int offset = (rand() % 2); // gera offset de 0 ou 1 aleatoriamente
	unsigned int direction = (rand() % 4); // gera dire��o do offset (0, 1, 2, 3) aleatoriamente
	unsigned int linha = targetPosition.lin, coluna = targetPosition.col; 

	// fazer condi��o de

	if (offset == 1)
	{
		if (direction == 0) // dire��o Norte
			linha--;
		else if (direction == 1) // dire��o Este
			coluna++;
		else if (direction == 2) // dire��o Sul
			linha++;
		else if (direction == 3) // dire��o Oeste
	}

}