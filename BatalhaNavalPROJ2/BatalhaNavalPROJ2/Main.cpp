#include "COLOR_MOD.h"
#include "BOARD.h"
#include "PLAYER.h"
#include "BOARD.h"
#include "SHIP.h"
#include "SCOREBOARD.h"
//#include "MENU.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include <iomanip>


using namespace std;

void print_boards(Player &UM, Player &DOIS);
void player_turn(Player &UM, Player &DOIS);
//int menu();

void main()
{
	srand((unsigned int)time(NULL)); // nao alterar

	
	scoreboard tabel = scoreboard();
	tabel.show_scores();
	tabel.update_scoreboard("joao", 12);
	tabel.update_scoreboard("joao", 12);
	tabel.update_scoreboard("joao", 12);
	tabel.update_scoreboard("joao", 100);
	tabel.show_scores();
	system("pause");





	Player UM = Player(1);
	Player DOIS = Player(2);

	do
	{
		system("cls");
		print_boards(UM, DOIS);
		player_turn(UM, DOIS); // turno PL 1

		if (DOIS.Player_DEAD() == true) break;

		// gotoxy(0, 4 + UM.get_board().getLines());
		system("cls");
		print_boards(UM, DOIS);
		player_turn(DOIS, UM); // turno PL 2

		//gotoxy(0, 0);
		//UM.showBoard();
		//gotoxy(0, 8 + UM.get_board().getLines());

		if (UM.Player_DEAD() == true) break;
		print_boards(UM, DOIS);
	} while (UM.Player_DEAD() != true || DOIS.Player_DEAD() != true);

	///////////////////////////////////////////////////////////////////////
	/*
	Beep(330, 100); Sleep(100);
	Beep(330, 100); Sleep(300);
	Beep(330, 100); Sleep(300);
	Beep(262, 100); Sleep(100);
	Beep(330, 100); Sleep(300);
	Beep(392, 100); Sleep(700);
	Beep(196, 100); Sleep(700);
	Beep(262, 300); Sleep(300);
	Beep(196, 300); Sleep(300);
	Beep(164, 300); Sleep(300);
	Beep(220, 300); Sleep(100);
	Beep(246, 100); Sleep(300);
	Beep(233, 200);
	Beep(220, 100); Sleep(300);
	Beep(196, 100); Sleep(150);
	Beep(330, 100); Sleep(150);
	Beep(392, 100); Sleep(150);
	Beep(440, 100); Sleep(300);
	Beep(349, 100); Sleep(100);
	Beep(392, 100); Sleep(300);
	Beep(330, 100); Sleep(300);
	Beep(262, 100); Sleep(100);
	Beep(294, 100); Sleep(100);
	Beep(247, 100); Sleep(500);
	Beep(262, 300); Sleep(300);
	Beep(196, 300); Sleep(300);
	Beep(164, 300); Sleep(300);
	Beep(220, 300); Sleep(100);
	Beep(246, 100); Sleep(300);
	Beep(233, 200);
	Beep(220, 100); Sleep(300);
	Beep(196, 100); Sleep(150);
	Beep(330, 100); Sleep(150);
	Beep(392, 100); Sleep(150);
	Beep(440, 100); Sleep(300);
	Beep(349, 100); Sleep(100);
	Beep(392, 100); Sleep(300);
	Beep(330, 100); Sleep(300);
	Beep(262, 100); Sleep(100);
	Beep(294, 100); Sleep(100);
	Beep(247, 100); Sleep(900);
	Beep(392, 100); Sleep(100);
	Beep(370, 100); Sleep(100);
	Beep(349, 100); Sleep(100);
	Beep(311, 100); Sleep(300);
	Beep(330, 100); Sleep(300);
	Beep(207, 100); Sleep(100);
	Beep(220, 100); Sleep(100);
	Beep(262, 100); Sleep(300);
	Beep(220, 100); Sleep(100);
	Beep(262, 100); Sleep(100);
	Beep(294, 100); Sleep(500);
	Beep(392, 100); Sleep(100);
	Beep(370, 100); Sleep(100);
	Beep(349, 100); Sleep(100);
	Beep(311, 100); Sleep(300);
	Beep(330, 100); Sleep(300);
	Beep(523, 100); Sleep(300);
	Beep(523, 100); Sleep(100);
	Beep(523, 100); Sleep(1100);
	Beep(392, 100); Sleep(100);
	Beep(370, 100); Sleep(100);
	Beep(349, 100); Sleep(100);
	Beep(311, 100); Sleep(300);
	Beep(330, 100); Sleep(300);
	Beep(207, 100); Sleep(100);
	Beep(220, 100); Sleep(100);
	Beep(262, 100); Sleep(300);
	Beep(220, 100); Sleep(100);
	Beep(262, 100); Sleep(100);
	Beep(294, 100); Sleep(500);
	Beep(311, 300); Sleep(300);
	Beep(296, 300); Sleep(300);
	Beep(262, 300); Sleep(1300);
	Beep(262, 100); Sleep(100);
	Beep(262, 100); Sleep(300);
	Beep(262, 100); Sleep(300);
	Beep(262, 100); Sleep(100);
	Beep(294, 100); Sleep(300);
	Beep(330, 200); Sleep(50);
	Beep(262, 200); Sleep(50);
	Beep(220, 200); Sleep(50);
	Beep(196, 100); Sleep(700);
	Beep(262, 100); Sleep(100);
	Beep(262, 100); Sleep(300);
	Beep(262, 100); Sleep(300);
	Beep(262, 100); Sleep(100);
	Beep(294, 100); Sleep(100);
	Beep(330, 100); Sleep(700);
	Beep(440, 100); Sleep(300);
	Beep(392, 100); Sleep(500);
	Beep(262, 100); Sleep(100);
	Beep(262, 100); Sleep(300);
	Beep(262, 100); Sleep(300);
	Beep(262, 100); Sleep(100);
	Beep(294, 100); Sleep(300);
	Beep(330, 200); Sleep(50);
	Beep(262, 200); Sleep(50);
	Beep(220, 200); Sleep(50);
	Beep(196, 100); Sleep(700);
	/*Intro*/
	/*
	Beep(330, 100); Sleep(100);
	Beep(330, 100); Sleep(300);
	Beep(330, 100); Sleep(300);
	Beep(262, 100); Sleep(100);
	Beep(330, 100); Sleep(300);
	Beep(392, 100); Sleep(700);
	Beep(196, 100); Sleep(700);
	Beep(196, 100); Sleep(125);
	Beep(262, 100); Sleep(125);
	Beep(330, 100); Sleep(125);
	Beep(392, 100); Sleep(125);
	Beep(523, 100); Sleep(125);
	Beep(660, 100); Sleep(125);
	Beep(784, 100); Sleep(575);
	Beep(660, 100); Sleep(575);
	Beep(207, 100); Sleep(125);
	Beep(262, 100); Sleep(125);
	Beep(311, 100); Sleep(125);
	Beep(415, 100); Sleep(125);
	Beep(523, 100); Sleep(125);
	Beep(622, 100); Sleep(125);
	Beep(830, 100); Sleep(575);
	Beep(622, 100); Sleep(575);
	Beep(233, 100); Sleep(125);
	Beep(294, 100); Sleep(125);
	Beep(349, 100); Sleep(125);
	Beep(466, 100); Sleep(125);
	Beep(587, 100); Sleep(125);
	Beep(698, 100); Sleep(125);
	Beep(932, 100); Sleep(575);
	Beep(932, 100); Sleep(125);
	Beep(932, 100); Sleep(125);
	Beep(932, 100); Sleep(125);
	Beep(1046, 675);*/
	/////////////////////////////////////////////////////////////////////// 

}
/*
int menu()
{
	cout << "    Batalha Naval" << endl;
	cout << "1 - Jogar " << endl;
	cout << "2 - Pontuacao" << endl;
	cout << "3 - Sair " << endl;
}
*/


void print_boards(Player &UM, Player &DOIS)
{
	gotoxy(0, 0);
	cout << setw(15) << UM.get_player_name() << endl;
	UM.showBoard();
	cout << endl;
	cout << endl;
	cout << setw(15) << DOIS.get_player_name() << endl;
	DOIS.showBoard();
	cout << endl;
	cout << endl;
	UM.get_board().show();
	DOIS.get_board().show();
}
void player_turn(Player &UM, Player &DOIS)
{
	cout << "Jogador: " << UM.get_player_name() << endl;
	DOIS.attackBoard(UM.getBomb());
}
