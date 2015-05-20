#include <iostream>
#include <string>
#include "PLAYER.h"
#include "BOMB.h"
#include "BOARD.h"
#include "TYPES.h"

Player::Player(string playerName, string boardFilename)
{
	name = playerName;
	board = Board(boardFilename);
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

	if ((int)value > max)
		contido = false;

	return contido;
}

Bomb Player::getBomb() 
{
	char lin, col;
	Position<char> target;


	cout << "Inctroduza as letras correspondentes as coordenadas do alvo: " << endl;
	cout << "Linha: ";
	lin = askCoord();
	while (!isContained(lin - 65, board.getLines()))
	{
		cout << "A linha introduzida não está contida no tabuleiro.\n" << "Linha: ";
		lin = askCoord();
	}
	cout << "Coluna: ";
	col = askCoord();
	while (!isContained(col - 97, board.getColumns()))
	{
		cout << "A coluna introduzida não está contida no tabuleiro.\n" << "Coluna: ";
		col = askCoord();
	}

	target.lin = lin;
	target.col = col;

	Bomb bomba = Bomb(target);

	return bomba;
}

/*
Method attackBoard() "receives" a bomb that was sent by the opponent player and updates the
own board and ships, taking into account the damages caused by the bomb, but, before accounting
for the damages, it moves his / her own ships, in a random way, trying to escape from the bomb.
It may be necessary to use an auxiliary board to make a preview of the displacement of the ships.
*/

void Player::attackBoard(const Bomb &b)
{
	Position<char> local = b.getActualPosition();

}