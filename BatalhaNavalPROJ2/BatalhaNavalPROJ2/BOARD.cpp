#include "BOARD.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "COLOR_MOD.h"

Ship Board::return_ship(size_t index) const
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

bool Board::allShipsDead() const
{
	bool dead = true;
	for (size_t i = 0; i < ships.size(); i++)
	{
		if (!ships[i].isDestroyed())
		{
			dead = false;
		}
	}

	return dead;
}

int Board::get_ships_size() const
{
	int a = 0;
	for (size_t i = 0; i < ships.size(); i++)
	{
		a = a + ships[i].get_ship_size();
	}
	return a;
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

	size_t i = 0;
	while (!ReadConfig.eof()) // enquanto nao chega ao fim do ficheiro;
	{
		char type, orientation;
		Position<char> position;
		unsigned int color, syze;
		ReadConfig >> type >> syze >> position.lin >> position.col >> orientation >> color;// obtem as carateristicas do navio;
		ships.push_back(Ship(type, position, orientation, syze, color, i)); // ATENCAO OPERACAO A VERIFICAR
		i++;
	}

	ReadConfig.close();

	resize_board();
	place_all_the_ships();
	set_default_status_all_ships();
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
	if (s.getColumn() < 0 ||
		(int)s.getColumn() > numColumns - 1 ||
		s.getLine() < 0 ||
		(int)s.getLine() > numLines - 1 ||
		(s.get_ship_orientation() == 'H' && (int)(s.getColumn() + s.get_ship_size() - 1) >  numColumns) ||
		(s.get_ship_orientation() == 'V' && (int)(s.getLine() + s.get_ship_size() - 1) > numLines))
	{
		return false;
	}
	else if (s.get_ship_orientation() == 'H') // horizontal
	{
		for (size_t i = 0; i < (int)s.get_ship_size(); i++) // ve se  é tudo '-1'
		{
			if (get_board_position(s.getLine(), s.getColumn() + i) != -1)
				return false;
		}
		for (size_t i = 0; i < (int)s.get_ship_size(); i++) // ve se  é tudo '-1'
		{
			board[s.getLine()][s.getColumn() + i] = s.get_ship_pos();
		}
	}
	else // vertical
	{
		for (size_t i = 0; i < s.get_ship_size(); i++)
		{
			if (get_board_position((s.getLine() + i), s.getColumn()) != -1)
				return false;
		}
		for (size_t i = 0; i < s.get_ship_size(); i++)
		{
			board[s.getLine() + i][s.getColumn()] = s.get_ship_pos();
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
			if (board[ship.getLine()][ship.getColumn() + i] != -1)
			{
				return true;
			}
		}
	}
	else if (ship.get_ship_orientation() == 'V')
	{
		for (size_t i = 0; i < ship.get_ship_size(); i++)
		{
			if (board[ship.getLine() + i][ship.getColumn()] != -1)
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
		if (ships[i].isDestroyed() == false)
		{
			int linha = ships[i].getLine(), coluna = ships[i].getColumn();
			char ori = ships[i].get_ship_orientation();
			remove_ship(coluna, linha, ships[i].get_ship_size(), ships[i].get_ship_orientation());
			if (!ships[i].moveRand(0, 0, numLines, numColumns) ||
				check_over_position_ship(ships[i]))
				ships[i].modifyPosition(linha, coluna, ori);
			putShip(ships[i]);
		}
	}
}

bool Board::attack(const Bomb &b) // NOT DONE
{
	bool valid;
	int linha = b.getActualPosition().lin - 65;
	int coluna = b.getActualPosition().col - 97;
	// ve a posicao do tabu
	if (linha >= 0 && linha < numLines &&
		coluna >= 0 && coluna < numColumns)
	{
		int posicao = board[linha][coluna];
		if (posicao == -1
			|| (ships[posicao].get_ship_orientation() == 'H' && islower(ships[posicao].get_ship_status()[coluna - ships[posicao].getColumn()]))
			|| (ships[posicao].get_ship_orientation() == 'V' && islower(ships[posicao].get_ship_status()[linha - ships[posicao].getLine()])))
			cout << "Miss!" << endl;
		else
		{
			setcolor(ships[posicao].get_ship_color(), BLACK);
			cout << "Hit!" << endl;
			setcolor(WHITE, BLACK);
			if (ships[posicao].get_ship_orientation() == 'H')
				ships[posicao].attack(coluna - ships[posicao].getColumn());
			else
				ships[posicao].attack(linha - ships[posicao].getLine());
			if (ships[posicao].isDestroyed() == true)
			{
				cout << "O navio ";
				for (size_t i = 0; i < ships[posicao].get_ship_size(); i++)
				{
					cout << ships[posicao].get_ship_symbol();
				}
				cout << " afundou!!" << endl;
				remove_ship(ships[posicao].getColumn(), ships[posicao].getLine(), ships[posicao].get_ship_size(), ships[posicao].get_ship_orientation());
			}
		}
		valid = true;
	}
	valid = false;
	system("pause");
	return valid;
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
			gotoxy(2 * (ships[i].getColumn() + 1 + j), ships[i].getLine() + 1);  //formula col = (Distancia � margem)+ 2*col
			cout << ships[i].get_ship_status()[j];
			}
		else
			for (size_t j = 0; j < ships[i].get_ship_size(); j++)
			{
			setcolor(ships[i].get_ship_color(), LIGHTGRAY);
			gotoxy(ships[i].getColumn() + 3, ships[i].getLine() + 1 + j);// formula lin= distancia ao topo + 1 + lin
			cout << ships[i].get_ship_status()[j];
			}
	}
	setcolor(WHITE, BLACK);
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
	os << "   "; // alinhas tabuleiro;
	setcolor(LIGHTGRAY, BLACK);
	for (int i = 0; i < board.getColumns(); i++)
		os << static_cast <char> (97 + i) << " ";
	os << endl;
	for (int i = 0; i < board.getLines(); i++)//linhas
	{
		setcolor(LIGHTGRAY, BLACK);
		os << static_cast<char> (65 + i) << " ";
		for (int j = 0; j < board.getColumns(); j++) // colunas
		{
			int posicao = board.get_board_position(i, j);
			if (posicao == -1)
			{
				setcolor(BLUE, LIGHTGRAY);
				os << " .";
			}
			else
			{
				setcolor(board.return_ship(posicao).get_ship_color(), LIGHTGRAY);
				if (board.return_ship(posicao).get_ship_orientation() == 'H')
				{
					os << " " << board.return_ship(posicao).get_ship_partition(j - board.return_ship(posicao).getColumn());
				}
				else
				{
					os << " " << board.return_ship(posicao).get_ship_partition(i - board.return_ship(posicao).getLine());
				}
			}
			if (j == (board.getColumns() - 1))
				os << " ";
		}

		os << endl;
	}
	setcolor(WHITE, BLACK);
	return os;
}