	#include "TYPES.h"
#include "SHIP.h"
#include <iostream>
#include "BOARD.h"



//==========================FUNCOES ADICIONAIS ==========================

char Ship::get_ship_symbol()
{
	return symbol;
}
unsigned int Ship::get_ship_position_col() const
{
	return position.col;
}
unsigned int Ship::get_ship_position_lin() const
{
	return position.lin;
}
char  Ship::get_ship_orientation() const
{
	return orientation;
}
unsigned int  Ship::get_ship_size() const
{
	return size;
}
unsigned int  Ship::get_ship_color() const
{
	return color;
}
string Ship::get_ship_status() const
{
	return status;
}
void Ship::set_default_status()
{
	string a;
	a.resize(size);
	for (size_t i = 0; i < size; i++)//cria o default do status tipo "PPPPP"
	{
		a[i]= symbol;
	}
	status = a;

}

char Ship::get_ship_partition(size_t index) const
{
	return status.at(index);
}

size_t Ship::get_ship_pos() const
{
	return pos;
}
//=============================================================================
Ship::Ship(char symbol, Position<char> position, char orientation, unsigned int size,	unsigned int color,size_t pos)
{
	this->symbol = symbol;
	this->position.col = position.col - 97;
	this->position.lin = position.lin - 65;
	this->orientation = orientation;
	this->size = size;
	this->color = color;
	this->pos = pos;
}

bool Ship::move(char direction, bool rotate, unsigned int lineMin, unsigned int columnMin, unsigned int lineMax, unsigned int columnMax)// moves the boat 
{
	unsigned int col = position.col;
	unsigned int lin = position.lin;
	unsigned int maxcol;
	unsigned int maxlin;
	char ori = orientation;
	if (orientation == 'H')
	{
		maxcol = col + size;
		maxlin = lin;
	}
	else // 'V'
	{
		maxcol = col;
		maxlin = lin + size;
	}
	
	switch (direction) // o deslocamento na direcao
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
			maxcol = col;
			maxlin = lin + size;
		}
		else
		{
			ori = 'H';
			maxcol = col + size;
			maxlin = lin;
		}
	}

	if (lin < lineMin || maxlin >= lineMax || col < columnMin || maxcol >= columnMax) // verifica se sai fora do tabuleiro
	{
		return false;
	}
	
	position.col = col;
	position.col = lin;
	orientation = ori;

	return true;
}
bool Ship::moveRand(unsigned int lineMin, unsigned int columnMin, unsigned int lineMax, unsigned int columnMax) // moves the ship randomly
{
	unsigned int  move = rand() % 4;
	unsigned int rota = rand() % 1; // true or false;
	bool rotation = true;
	if (rota == 0) rotation = false;

	if (move == 1)	return Ship::move('N', rotation, lineMin, columnMax, lineMax, columnMax);
	else if (move == 2)	return Ship::move('S', rotation, lineMin, columnMax, lineMax, columnMax);
	else if (move == 3)	return Ship::move('E', rotation, lineMin, columnMax, lineMax, columnMax);
	else if (move == 4)	return Ship::move('O', rotation, lineMin, columnMax, lineMax, columnMax);
	else if (move == 0)	return true;

	return false;
}
bool Ship::attack(size_t partNumber) //partNumber = {0,1,…, size-1}
{
	
	if (partNumber < size)
	{
		status[partNumber] = tolower(symbol);
		return true;
	}
	
	return false;
}
bool Ship::isDestroyed() const // checks whether the ship is destroyed
{
	bool valid = false;
	unsigned int counter = 0;
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