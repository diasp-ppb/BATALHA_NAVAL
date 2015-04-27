#include <iostream>
#include "PLAYER.h"
#include "BOMB.h"
#include "TYPES.h"

char askCoord()
{
	char coord;

	do
	{
		if (cin.fail())
		{
			cout << "Valores invalidos. Introduza novamente os dados: ";
			cin.clear();
		}
		cin >> coord;
	} while (cin.fail());

	return coord;
}

Bomb getBomb() const
{
	char lin, col;

	cout << "Introduza as letras correspondentes as coordenadas do alvo: " << endl;
	cout << "Linha: ";
	lin = askCoord();
	cout << "Coluna: ";
	col = askCoord();
}
