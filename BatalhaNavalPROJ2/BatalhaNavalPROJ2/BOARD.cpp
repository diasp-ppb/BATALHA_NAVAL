#include "BOARD.h"
#include <string>
#include <fstream>
#include "SHIP.h"

Board::Board(const string &filename)
{
	
	ifstream ReadConfig(filename);

		if (ReadConfig.is_open())
		{	 
			//leitura das dimensoes do tabuleiro
			string absor; // usada para absorver "Tabuleiro: "
			char XX;
			getline(ReadConfig, absor, ' ');
			ReadConfig >> numLines >> XX >> numColumns;
			ReadConfig.ignore(1000, '\n');
			//leitura dos navios
			if (!ReadConfig.eof)
			{
				unsigned int ship_size, ship_colour;
				PositionChar ship_position;
				char ship_symbol,ship_orientation;
				ReadConfig >> ship_symbol >> ship_size >> ship_position.lin >> ship_position.col >> ship_orientation >> ship_colour;

				Ship::Ship()

				
			}
		}
	
}