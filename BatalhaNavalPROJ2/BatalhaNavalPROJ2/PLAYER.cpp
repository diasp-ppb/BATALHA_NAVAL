#include <iostream>
#include <string>
#include "PLAYER.h"
#include "BOMB.h"
#include "BOARD.h"
#include "TYPES.h"
#include <fstream>
#include <ctime>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool checkExistence(std::string filename)
{
	ifstream f;
	f.open(filename);

	return f.is_open();
}

string Select_file()
{
	string a;

	bool invalido = false;

	do
	{
		if (invalido)
		{
			invalido = false;
			cout << "O ficheiro pretendido nao existe. Introduza novamente:" << endl;
			cin.clear();
		}
		cout << "Nome do ficheiro de configuracao (incluindo extensao): ";
		getline(cin, a);
		if (cin.eof())
			exit(1);
		if (!checkExistence(a))
			invalido = true;
	} while (cin.fail() || invalido); // realiza o ciclo enquanto o ficheiro introduzido n�o for v�lido ou n�o existir;
	return a;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Player::Player(string playerName, string boardFilename)
{
	name = playerName;
	board = Board(boardFilename);
	time = 0;
}

Player::Player(size_t num)
{
	bool valido = true;
	bool maior = false;
	do
	{
		cin.clear();
		if (maior)
			cout << "Introduza um nome com 10 ou menos caracteres: ";
		else if (!valido)
			cout << "Introduza um nome nao vazio: ";
		else
			cout << "Qual o nome do player " << num << "? ";

		getline(cin, name);

		valido = false;

		for (size_t i = 0; i < name.size(); i++)
			if (name[i] != ' ')
				valido = true;

		if (valido)
			if (name.size() > 10)
				maior = true;
			else
				maior = false;

	} while (cin.eof() || !valido || maior);

	board = Board(Select_file());
	//board = Board("configBN.txt");
	time = 0;
}

char Player::askCoord()
{
	string linha = "";
	char coord;

	while (linha.length() != 1)
	{
		getline(cin, linha);
		if (cin.eof())
			cin.clear();

		if (linha.length() == 1)
			coord = linha[0];
		else
			cout << "Valores invalidos. Introduza novamente os dados: ";
	}

	return coord;
}

bool Player::isContained(char value, int max)
{
	bool contido = true;

	if ((int)value >= max || (int)value < 0)
		contido = false;

	return contido;
}

Bomb Player::getBomb()
{
	char lin, col;
	Position<char> target;

	cout << "Introduza as letras correspondentes as coordenadas do alvo: " << endl;
	cout << "Linha: ";
	lin = askCoord();
	while (!isContained(lin - 65, board.getLines()))
	{
		cout << "A linha introduzida nao esta contida no tabuleiro.\n" << "Linha: ";
		lin = askCoord();
	}
	cout << "Coluna: ";
	col = askCoord();
	while (!isContained(col - 97, board.getColumns()))
	{
		cout << "A coluna introduzida nao esta contida no tabuleiro.\n" << "Coluna: ";
		col = askCoord();
	}

	target.lin = lin;
	target.col = col;

	Bomb bomba = Bomb(target);

	return bomba;
}

Bomb Player::getBombCPU(Player &DOIS)
{

	char lin, col;
	Position<char> target;
	vector<Ship> navios = DOIS.get_board().getShips();
	bool coord = false;
	for (int i = 0; i < navios.size() && !coord; i++)
	{
		if (!navios[i].isDestroyed())
		{
			for (int j = 0; j < navios[i].get_ship_size() && !coord; j++)
			{
				if (navios[i].get_ship_status()[j] < 'a')
				{
					if (navios[i].get_ship_orientation() == 'H')
					{
						col = navios[i].getColumn() + j;
						lin = navios[i].getLine();
					}
					else
					{
						lin = navios[i].getLine() + j;
						col = navios[i].getColumn();
					}
					coord = true;
				}
			}
		}
	}

	target.lin = lin + 65;
	target.col = col + 97;

	Bomb bomba = Bomb(target);

	return bomba;
}

void Player::attackBoard(const Bomb &b)
{
	board.moveShips();
	board.attack(b);
}

void Player::showBoard() const
{
	cout << board;
}

bool Player::Player_DEAD() const
{
	return board.allShipsDead();
}

string Player::get_player_name() const
{
	return name;
}

Board Player::get_board() const
{
	return board;
}

double Player::get_time() const
{
	return time;
}

void Player::set_time(double _time)
{
	time = _time;
}

ostream& operator<<(ostream& os, const Player& player)
{
	os << "Jogador : " << player.name << endl
		<< "Tempo : " << player.time << endl
		<< "Tabuleiro " << endl << player.board << endl;

	return os;
}