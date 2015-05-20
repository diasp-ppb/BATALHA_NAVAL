#include "BOARD.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "COLOR_MOD.h"

int Board::get_board_position(unsigned int lin, unsigned int col)
{
	return board[lin][col];
}

void Board::set_board_position(unsigned int lin, unsigned int col, int mark)
{
	board[lin][col] = mark;
}

void Board::resize_board()
{
	board.resize(numLines); //n� de linhas
	for (int i = 0; i < numLines; i++) //n � de colunas
	{
		board[i].resize(numLines, -1);
	}
}

void Board::place_all_the_ships()
{

	for (size_t i = 0; i < ships.size(); i++)
	{
		Board::putShip(ships[i]);
	}
}

int Board::getLines() const
{
	return numLines;
}

int Board::getColumns() const
{
	return numColumns;
}

bool Board::allShipsDead()
{
	bool dead = true;
	for (size_t i = 0; i < ships.size(); i++)
	{
		if (!ships[i].isDestroyed())
			dead = false;
	}

	return dead;
}

Board::Board()
{
	numLines = 0;
	numColumns = 0;
}

Board::Board(const string &filename)
{

	ifstream ReadConfig(filename);
	// ler as dimendoes do tab
	char absorv; // elemento absorvente;
	ReadConfig >> numLines >> absorv >> numColumns;


	while (!ReadConfig.eof()) // enquanto nao chega ao fim do ficheiro;
	{
		char type, orientation;
		Position<char> position;
		unsigned int color, syze;
		ReadConfig >> type >> syze >> position.lin >> position.col >> orientation >> color;// obtem as carateristicas do navio;
		ships.push_back(Ship(type, position, orientation, syze, color)); // ATENCAO OPERACAO A VERIFICAR
	}

	ReadConfig.close();
} 

void Board::remove_ship(unsigned int col, unsigned int lin, unsigned int size, char orientation)
{
	if (orientation == 'H')
		for (size_t i = 0; i < size; i++)
		{
		board[lin][col + i] = -1;
		}
	else // Vertical
		for (size_t i = 0; i < size; i++)
		{
		board[lin + i][col] = -1;
		}
}

bool Board::putShip(const Ship &s) // adds ship to the board, if possible
{   //verifica se esta dentro do tabuleiro
	if (s.getShipPosition().col;() < 0 ||
		(int)s.getShipPosition().col;() > numColumns - 1 ||
		s.getShipPosition().lin;() < 0 ||
		(int)s.getShipPosition().col;() > numLines - 1 ||
		((int)(s.getShipPosition().col;() + s.get_ship_size() - 1) >  numColumns && s.get_ship_orientation() == 'H') ||
		((int)(s.getShipPosition().lin;() + s.get_ship_size() - 1) > numLines && s.get_ship_orientation() == 'V'))
	{
		return false;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	if (s.get_ship_orientation() == 'H')
	{
		for (size_t i = 0; i < (int)s.get_ship_size(); i++) // ve se  � tudo '-1'
		{
			if (get_board_position(s.getShipPosition().lin;(), s.getShipPosition().col;() + i) != -1)
			{
				return false;
			}
		}
	}
	else // se for vertical
		for (size_t i = 0; i < s.get_ship_size(); i++) // ve se  � tudo '-1'
		{
		if (get_board_position((s.getShipPosition().lin;() + i), s.getShipPosition().col;()) != -1)
		{
			return false;
		}
		}
	///////////////////DEPOIS DE VERIFICAR SE � POSSIVEL ADD AO TABULEIRO//////////////////////////////////////////
	if (s.get_ship_orientation() == 'H')
	{
		for (size_t i = 0; i < s.get_ship_size(); i++)
		{
			board[s.getShipPosition().lin;()][s.getShipPosition().col;() + i] = i;
		}
	}
	else
	{
		for (size_t i = 0; i < s.get_ship_size(); i++)
		{
			board[s.getShipPosition().lin;() + i][s.getShipPosition().col;()] = i;
		}
	}
	return true;
}

void Board::set_default_status_all_ships()
{
	for (size_t i = 0; i < ships.size(); i++)
	{
		ships[i].set_default_status();
	}
}

bool Board::check_over_position_ship(Ship &ship)
{
	if (ship.get_ship_orientation() == 'H')
	{
		for (size_t i = 0; i < ship.get_ship_size(); i++)
		{
			if (board[ship.getShipPosition().lin;()][ship.getShipPosition().col;() + i] != -1)
			{
				return true;
			}
		}
	}
	else if (ship.get_ship_orientation() == 'V')
	{
		for (size_t i = 0; i < ship.get_ship_size(); i++)
		{
			if (board[ship.getShipPosition().lin;()+ i][ship.getShipPosition().col;()] != -1)
			{
				return true;
			}
		}
	}
	return false;
}

void Board::moveShips() // tries to randmonly move all the ships of the fleet
{

}

bool Board::attack(const Bomb &b) 
{
	bool kaboom = true;
	Position<int> coordinates = b.getActualPosition();
	coordinates.lin = (int)(coordinates.lin - 'A');
	coordinates.col = (int)(coordinates.col - 'a');

	size_t partNumber;
	Ship barco = ships[board[coordinates.lin][coordinates.col]];

	if (coordinates.lin > getLines() || coordinates.col > getColumns())
		kaboom = false;
	else if (board[coordinates.lin][coordinates.col] != -1)
	{
		if (!barco.isDestroyed())
		{
			if (barco.get_ship_orientation() = 'H')
				partNumber = coordinates.col - barco.getShipPosition().col;
			else
				partNumber = coordinates.lin - barco.getShipPosition().lin;
		}
	}

	barco.attack(partNumber);

	return kaboom;
}

void Board::display() const // displays the colored board during the game  
{
	cout << "  "; // alinhas tabuleiro;
	setcolor(LIGHTGRAY, BLACK);
	for (int i = 0; i < numColumns; i++)
		cout << static_cast <char> (97 + i) << " ";
	cout << endl;
	for (int i = 0; i < numLines; i++)//linhas
	{
		setcolor(LIGHTGRAY, BLACK);
		cout << static_cast<char> (65 + i) << " ";
		setcolor(BLUE, LIGHTGRAY);
		for (int j = 0; j < numColumns; j++) // colunas
		{
			cout << ". ";
		}
		cout << endl;
	}
	for (size_t i = 0; i < ships.size(); i++)
	{
		if (ships[i].get_ship_orientation() == 'H')
			for (size_t j = 0; j < ships[i].get_ship_size(); j++)
			{
			setcolor(ships[i].get_ship_color(), LIGHTGRAY);
			gotoxy(2 * (ships[i].getShipPosition().col;() + 1 + j), ships[i].getShipPosition().lin;() + 1);  //formula col = (Distancia � margem)+ 2*col
			cout << ships[i].get_ship_status()[j];
			}
		else
			for (size_t j = 0; j < ships[i].get_ship_size(); j++)
			{
			setcolor(ships[i].get_ship_color(), LIGHTGRAY);
			gotoxy(ships[i].getShipPosition().col;() + 3,ships[i].getShipPosition().lin;() + 1 + j );// formula lin= distancia ao topo + 1 + lin
			cout << ships[i].get_ship_status()[j];
			}
	}
	setcolor(LIGHTGRAY, BLACK);
	gotoxy(0, numLines + 3);
}

void Board::show() const // falta navios e a info do tabuleiro;
{
	cout << "COL: " << numColumns << "\nLIN: " << numLines;
	cout << "\n TABULEIRO EM INT" << endl;
	for (int i = 0; i < numLines; i++)
	{
		for (int j = 0; j < numColumns; j++)
		{
			cout << setw(3) << board[i][j];
		}
		cout << '\n';
	}
	cout << '\n' << ships.size() << endl;
}