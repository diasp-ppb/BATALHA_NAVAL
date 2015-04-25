#include "SHIP.h"
#include "TYPES.h"

Ship::Ship(char symbol, PositionChar position, char orientation, unsigned int size,unsigned int color)
{
	this->color = color;
	this->orientation = orientation;
	this->size = size;
	this->symbol = symbol;
	this->position.col = position.col;
	this->position.lin = position.lin;
}
//____________________FUNCOES_ADICIONADAS_____________________________
char Ship::get_ship_orientation()
{
	return orientation;
}
char Ship::get_ship_position_lin()
{
	return position.lin;
}
char Ship::get_ship_position_col()
{
	return position.col;
}
char Ship::get_ship_symbol()
{
	return symbol;
}
unsigned int Ship::get_ship_size()
{
	return size;
}
unsigned int Ship::get_ship_color()
{
	return color;
}
//_____________________________________________________________________________
bool Ship::move(char direction, bool rotate, unsigned int lineMin, unsigned int
	columnMin, unsigned int lineMax, unsigned int columnMax)// moves the boat 
{
	
}
	
bool moveRand(unsigned int lineMin, unsigned int columnMin, unsigned int
	lineMax, unsigned int columnMax); // moves the ship randomly
bool attack(size_t partNumber); //partNumber = {0,1,…, size-1}
bool isDestroyed() const; // checks whether the ship is destroyed
void show() const; // shows the attributes of the ship (for debugging)
