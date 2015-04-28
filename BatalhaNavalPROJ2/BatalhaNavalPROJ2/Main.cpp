#include "BOARD.h"
#include "PLAYER.h"
#include "BOARD.h"
#include "SHIP.h"
#include <string>
#include <iostream>

using namespace std;

string Select_file()
{
	cout << "Qual e o ficheiro de configuracao? ";
	string File_name;
	cin >> File_name;
	return File_name;

}

void main()
{
	Board TABU =  Board(Select_file());
	TABU.show();
}