#include <iostream>
#include <string>
#include "PLAYER.h"
#include "BOMB.h"
#include "TYPES.h"

char askCoord()
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

Bomb getBomb() 
{
	char lin, col;
	PositionChar target;

	cout << "Introduza as letras correspondentes as coordenadas do alvo: " << endl;
	cout << "Linha: ";
	lin = askCoord();
	cout << "Coluna: ";
	col = askCoord();

	// falta verificar as coordenadas (se estao contidas no tabuleiro ou nao)

	target.lin = lin;
	target.col = col;

	Bomb bomba = Bomb(target);

	return bomba;
}
