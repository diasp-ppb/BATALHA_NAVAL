#include "TYPES.h"
#include "SHIP.h"
#include <iostream>


//==========================FUNCOES ADICIONAIS ==========================
char Ship::get_ship_symbol()
{
	return symbol;
}
unsigned int Ship::get_ship_position_col()
{
	return position.col;
}
unsigned int Ship::get_ship_position_lin()
{
	return position.lin;
}
char  Ship::get_ship_orientation()
{
	return orientation;
}
unsigned int  Ship::get_ship_size()
{
	return size;
}
unsigned int  Ship::get_ship_color()
{
	return color;
}


//=============================================================================
bool Ship::move(char direction, bool rotate, unsigned int lineMin, unsigned int columnMin, unsigned int lineMax, unsigned int columnMax)// moves the boat 
{
	int col = position.col;
	int lin = position.lin;
	char ori = orientation;
	switch (direction) // faz o calculo para verificar se o deslocamento na direcao é possivel.
	{
		case 'N':
				lin--;
				break;
		case 'S':
				lin++;
				break;
		case 'O':
				col--;
				break;
		case 'E':
				col++;
				break;
	}
	//se houver rotacao
	if (rotate == true)
	{    // troca orientacao
		if (ori == 'H')
		{
			ori = 'V';
			col = col - size;
			lin = lin + size;
		}
		else
		{
			ori = 'H';
			col = col + size;
			lin = lin - size;
		}
	}

	if (lin < lineMin || lin >lineMax || col < columnMin || col > columnMax) //verifica se sai fora do tabuleiro
	{
		return false;
	}
	return true;
}
bool Ship::moveRand(unsigned int lineMin, unsigned int columnMin, unsigned int lineMax, unsigned int columnMax) // moves the ship randomly
{
	unsigned int  move = rand() % 4;
	switch (move)
	{
	default:
	case 1 :

	}

}
bool Ship::attack(size_t partNumber) //partNumber = {0,1,…, size-1}
{
	bool valid_shot = false;
	if (partNumber < size)
	{
		status[partNumber] = tolower(symbol);
		valid_shot = true;
	}
	
	return valid_shot;
}
bool Ship::isDestroyed() const // checks whether the ship is destroyed
{
	bool valid = false;
	unsigned int counter;
	for (size_t i = 0; i < size; i++) // ciclo para percorrer a string status 
	{
		if (islower(status[i]))
			counter++;
	}
	if (counter >= (size / 2.0))// verifica -se metade do navio esta destruido 
		valid = true;
	return valid;
}
void Ship::show() const // shows the attributes of the ship (for debugging)
{
	cout << "Ship size: " << size << "\n Orientation: " << orientation << "\n Ship color: " << color << "\n Ship Status: " << status << "\n Ship Position: " << position.lin << position.col << endl;
}