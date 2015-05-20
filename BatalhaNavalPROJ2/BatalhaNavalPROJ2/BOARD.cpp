#include "BOARD.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "COLOR_MOD.h"

Ship Board::get_ship(size_t index) const
{
	return ships[index];
}
int Board::get_board_position(unsigned int lin, unsigned int col) const
{
	return board[lin][col];
}
void Board::set_board_position(unsigned int lin, unsigned int col, int mark)
{
	board[lin][col] = mark;
}
void Board::resize_board()
{
	board.resize(numLines); //nº de linhas
	for (int i = 0; i < numLines; i++) //n º de colunas
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
	if (s.get_ship_position_col() < 0 ||
		(int)s.get_ship_position_col() > numColumns - 1 ||
		s.get_ship_position_lin() < 0 ||
		(int)s.get_ship_position_col() > numLines - 1 ||
		((int)(s.get_ship_position_col() + s.get_ship_size() - 1) >  numColumns && s.get_ship_orientation() == 'H') ||
		((int)(s.get_ship_position_lin() + s.get_ship_size() - 1) > numLines && s.get_ship_orientation() == 'V'))
	{
		return false;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	if (s.get_ship_orientation() == 'H')
	{
		for (size_t i = 0; i < (int)s.get_ship_size(); i++) // ve se  é tudo '-1'
		{
			if (get_board_position(s.get_ship_position_lin(), s.get_ship_position_col() + i) != -1)
			{
				return false;
			}
		}
	}
	else // se for vertical
		for (size_t i = 0; i < s.get_ship_size(); i++) // ve se  é tudo '-1'
		{
		if (get_board_position((s.get_ship_position_lin() + i), s.get_ship_position_col()) != -1)
		{
			return false;
		}
		}
	///////////////////DEPOIS DE VERIFICAR SE È POSSIVEL ADD AO TABULEIRO//////////////////////////////////////////
	if (s.get_ship_orientation() == 'H')
	{
		for (size_t i = 0; i < s.get_ship_size(); i++)
		{
			board[s.get_ship_position_lin()][s.get_ship_position_col() + i] = i;
		}
	}
	else
	{
		for (size_t i = 0; i < s.get_ship_size(); i++)
		{
			board[s.get_ship_position_lin() + i][s.get_ship_position_col()] = i;
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
			if (board[ship.get_ship_position_lin()][ship.get_ship_position_col() + i] != -1)
			{
				return true;
			}
		}
	}
	else if (ship.get_ship_orientation() == 'V')
	{
		for (size_t i = 0; i < ship.get_ship_size(); i++)
		{
			if (board[ship.get_ship_position_lin()+ i][ship.get_ship_position_col()] != -1)
			{
				return true;
			}
		}
	}
	return false;
}

void Board::moveShips() // tries to randmonly move all the ships of the fleet
{
	for (size_t i = 0; i < ships.size(); i++)
	{
		ships[i].moveRand(0, 0, numLines, numColumns);
	}
}
bool Board::attack(const Bomb &b) // NOT DONE
{
	return true;
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
			gotoxy(2 * (ships[i].get_ship_position_col() + 1 + j), ships[i].get_ship_position_lin() + 1);  //formula col = (Distancia á margem)+ 2*col
			cout << ships[i].get_ship_status()[j];
			}
		else
			for (size_t j = 0; j < ships[i].get_ship_size(); j++)
			{
			setcolor(ships[i].get_ship_color(), LIGHTGRAY);
			gotoxy(ships[i].get_ship_position_col() + 3,ships[i].get_ship_position_lin() + 1 + j );// formula lin= distancia ao topo + 1 + lin
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

ostream& operator<<(ostream& os, const Board& board)
{
	os <<  "  "; // alinhas tabuleiro;
	setcolor(LIGHTGRAY, BLACK);
	for (int i = 0; i < board.getColumns(); i++)
		os << static_cast <char> (97 + i) << " " << endl;
	for (int i = 0; i < board.getLines(); i++)//linhas
	{
		setcolor(LIGHTGRAY, BLACK);
		os << static_cast<char> (65 + i) << " ";
		for (int j = 0; j < board.getColumns(); j++) // colunas
		{	setcolor(BLUE, LIGHTGRAY);
			if (board.get_board_position(j, i) == '-1')
			{
				os << ' .';
			}
			else 
			{
				setcolor(board.get_ship(board.get_board_position(j, i)).get_ship_color(), LIGHTGRAY);
				//calculo da posicao atual na status
				if (board.get_ship[board.get_board_position(j, i)].get_ship_oritentation() == 'H')
				os << setw(2) << board.get_ship[board.get_board_position(j, i)].get_ship_status()[j - board.get_ship[board.get_board_position(j, i)].get_position_lin()];
				
				if (board.get_ship[board.get_board_position(j, i)].get_ship_oritentation() == 'V')
				os << setw(2) << board.get_ship[board.get_board_position(j, i)].get_ship_status()[j - board.get_ship[board.get_board_position(j, i)].get_position_col()];

			}
		}
		cout << endl;
}