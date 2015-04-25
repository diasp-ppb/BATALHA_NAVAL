#include "BOARD.h"
#include <string>
#include <fstream>
#include "SHIP.h"
#include <iostream>

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
				unsigned int ship_size, ship_color;
				PositionChar ship_position;
				char ship_symbol,ship_orientation;
				ReadConfig >> ship_symbol >> ship_size >> ship_position.lin >> ship_position.col >> ship_orientation >> ship_color;

				ships.push_back(Ship::Ship(ship_symbol, ship_position, ship_orientation, ship_size, ship_color));
				if (ReadConfig.fail()) // Erro de leitura
				{
					cerr << "Erro de leitura do ficheiro de configuracao." << endl;
					exit(0000001);
				}
			}	
		}
		ReadConfig.close();
}

bool Board::putShip(const Ship &s) // adds ship to the board, if possible
{
	char orientation = s.get_ship_orientation;
	//verifica se a posicao esta vazia
	if(orientation == 'N')
	{ }
	
}
void moveShips(); // tries to randmonly move all the ships of the fleet
bool attack(const Bomb &b);
void display() const; // displays the colored board during the game
void show() const; // shows the attributes of the board (for debugging)