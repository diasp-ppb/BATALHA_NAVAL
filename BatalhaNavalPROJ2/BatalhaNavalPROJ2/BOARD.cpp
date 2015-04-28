#include "BOARD.h"
#include <string>
#include <fstream>
#include <iostream>


int Board::get_board_position(unsigned int lin, unsigned int col)
{
	return board[lin][col];
}
void Board::set_board_position(unsigned int lin, unsigned int col,int mark)
{
	board[lin][col] = mark;
}
void Board::resize_board()
{
	board.resize(numLines); //nº de linhas
	for (int i = 0; i < numLines; i++) //n º de colunas
	{
		board[i].resize(numLines,-1);
	}
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
		PositionChar position;
		unsigned int color, syze;
		ReadConfig >> type >> syze >> position.lin >> position.col >> orientation >> color;// obtem cas carateristicas do navio;
		PositionChar intposition;
		intposition.col = (int)position.col - 64; //codigo 1º linha A -> 65;
		intposition.lin = (int)position.lin - 96; //codigo 1º col a -> 97;
		ships.push_back(Ship(type, intposition, orientation, syze, color)); // ATENCAO OPERACAO A VERIFICAR
	}
	
	ReadConfig.close();
}

bool Board::putShip(const Ship &s) // adds ship to the board, if possible
{   //verifica se esta dentro do tabuleiro
	if (s.get_ship_position_col() < 0 ||(int) s.get_ship_position_col() > numColumns || s.get_ship_position_lin() < 0 ||(int) s.get_ship_position_col() > numLines)
		return false;
	///////////////////////////////////////////////////////////////////////////////////////////////
	if (s.get_ship_orientation() == 'H')
	{ for (size_t i = 0; i <(int) s.get_ship_size(); i++) // ve se  é tudo '-1'
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
			board[s.get_ship_position_lin()][s.get_ship_position_lin() + i] = 0 + i;
		}
	}
	else 
	{
		for (size_t i = 0; i < s.get_ship_size(); i++)
		{
			board[s.get_ship_position_lin() + i][s.get_ship_position_lin() ] = 0 + i;
		}
	}
return true;
}

void Board::moveShips() // tries to randmonly move all the ships of the fleet
{

}
bool Board::attack(const Bomb &b)
{
	return true;
}
void Board::display() const // displays the colored board during the game  
{
	/*cout << "    "; // alinhas tabuleiro;
	for (size_t i = 0; i < numColumns; i++)
	{
		cout << static_cast <char> (97 + i);
	}
	for (size_t i = 0; i < numLines; i++)//linhas
	{ 
		cout << static_cast<char> (65 + i) << ' ';
		for (size_t j = 0; j < numColumns; j++) // colunas
		{
			if (board[i][j] == -1) cout << '.';   
		}
		cout << endl;
	}*/
}
void Board::show() const // falta navios e a info do tabuleiro;
{
	cout << "COL: " << numColumns << "\n LIN: " << numLines;
	cout << "\n TABULEIRO EM INT" << endl;
		for (int i = 0; i < numLines; i++)
		{
			for (int j = 0; j < numColumns; j++)
			{
				cout << board[i][j] << endl;
			}
		}
}