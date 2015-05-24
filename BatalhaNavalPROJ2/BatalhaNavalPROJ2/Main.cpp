#include "COLOR_MOD.h"
#include "BOARD.h"
#include "PLAYER.h"
#include "BOARD.h"
#include "SHIP.h"
#include "SCOREBOARD.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <ctime>


using namespace std;

void print_boards(Player &UM, Player &DOIS);
void player_turn(Player &UM, Player &DOIS);
void menu();
int select_menu();
void playgame();
void player_win(Player &UM, Player &DOIS, double &endtime);
void shoW_scoreboard();

void main()
{
	srand((unsigned int)time(NULL)); // nao alterar

	menu();
}

void playgame()
{

	Player UM = Player(1);
	Player DOIS = Player(2);

	do
	{
		system("cls");
		print_boards(UM, DOIS);
		//tempo PL1
		clock_t begin_time = clock();

		player_turn(UM, DOIS); // turno PL 1
		// atualiza o tempo
		UM.set_time(UM.get_time() + (clock() - begin_time));   // tempo gasto + ( tempo inicio de turno  - tempo fianl do turno)

		if (DOIS.Player_DEAD() == true) break;


		system("cls");
		print_boards(UM, DOIS);
		//tempo PL2
		clock_t begin_time2 = clock();

		player_turn(DOIS, UM); // turno PL 2

		DOIS.set_time(DOIS.get_time() + (clock() - begin_time2));   // tempo gasto + ( tempo inicio de turno  - tempo fianl do turno)


		if (UM.Player_DEAD() == true) break;
		print_boards(UM, DOIS);
	} while (UM.Player_DEAD() != true || DOIS.Player_DEAD() != true);


	if (UM.Player_DEAD())
	{
		double end_time = DOIS.get_time() / CLOCKS_PER_SEC; // resultado em segundos;
		player_win(UM, DOIS, end_time);

	}

	else if (DOIS.Player_DEAD())
	{
		double end_time = UM.get_time() / CLOCKS_PER_SEC; // resultado em segundos;
		player_win(DOIS, UM, end_time);
	}


}

void menu()
{
	cout << "    Batalha Naval" << endl;
	cout << "1 - Jogar " << endl;
	cout << "2 - Pontuacao" << endl;
	cout << "3 - Sair " << endl;
	cout << endl << endl;

	switch (select_menu())
	{
	case 1:
		playgame();
		break;
	case 2:
		shoW_scoreboard();
		break;
	case 3:
		exit(0);
		break;
	}
	system("pause");



}

int select_menu()
{
	int a;
	bool invalid = false;
	do
	{
		invalid = false;
		cout << "Qual e a opcao? ";

		cin >> a;
		if (cin.fail())
		{
			cin.clear();
		}
		else if (a < 1 || a > 3)
		{
			invalid = true;
			cout << "Introduza uma das opcoes.... Por favor!" << endl;

		}
		cin.ignore(1000, '\n');
	} while (cin.fail() || invalid);

	return a;

}

void print_boards(Player &UM, Player &DOIS)
{
	gotoxy(0, 0);
	cout << setw(15) << UM.get_player_name() << endl;
	UM.showBoard();
	cout << endl;
	cout << endl;
	cout << setw(15) << DOIS.get_player_name() << endl;
	DOIS.showBoard();

}
void player_turn(Player &UM, Player &DOIS)
{
	cout << "Jogador: " << UM.get_player_name() << endl;
	DOIS.attackBoard(UM.getBomb());
}
void player_win(Player &UM, Player &DOIS, double &endtime)
{
	system("cls");
	cout << "PARABENS!" << DOIS.get_player_name() << "ganhas-te!!!" << endl;
	size_t Area = DOIS.get_board().getColumns() * DOIS.get_board().getLines();
	size_t score = endtime * (DOIS.get_board().get_ships_size() / Area);
	scoreboard TAB = scoreboard();
	if (TAB.top_scores(score))
	{
		cout << "ESTAS NO TOP 10!!" << endl;
		system("pause");
		TAB.update_scoreboard(UM.get_player_name(), score);
		system("cls");
	}
	TAB.show_scores();
	system("pause");
	menu();
}
void shoW_scoreboard()
{
	system("cls");
	scoreboard TAB = scoreboard();
	TAB.show_scores();
	system("pause");
	system("cls");
	menu();
}