#include "TYPES.h"
#include "SHIP.h"


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

}
bool Ship::moveRand(unsigned int lineMin, unsigned int columnMin, unsigned int lineMax, unsigned int columnMax) // moves the ship randomly
{

}
bool Ship::attack(size_t partNumber) //partNumber = {0,1,…, size-1}
{

}
bool Ship::isDestroyed() const // checks whether the ship is destroyed
{

}
void Ship::show() const // shows the attributes of the ship (for debugging)
{

}