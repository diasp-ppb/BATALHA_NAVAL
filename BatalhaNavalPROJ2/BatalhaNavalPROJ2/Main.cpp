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

		if (DOIS.Player_DEAD() == true)
		{
				double end_time = UM.get_time() / CLOCKS_PER_SEC; // resultado em segundos;
				player_win(DOIS, UM, end_time);
		}


		system("cls");
		print_boards(UM, DOIS);
		//tempo PL2
		clock_t begin_time2 = clock();

		player_turn(DOIS, UM); // turno PL 2

		DOIS.set_time(DOIS.get_time() + (clock() - begin_time2));   // tempo gasto + ( tempo inicio de turno  - tempo fianl do turno)


		if (UM.Player_DEAD() == true)
		{
			
				double end_time = DOIS.get_time() / CLOCKS_PER_SEC; // resultado em segundos;
				player_win(UM, DOIS, end_time);
			
		}
		print_boards(UM, DOIS);
	} while (UM.Player_DEAD() != true || DOIS.Player_DEAD() != true);

}

void menu()
{
	cout << "    Batalha Naval" << endl;
	cout << "1 - Jogar " << endl;
	cout << "2 - Pontuacao" << endl;
	cout << "3 - Sair " << endl;
	cout << "\nIntroduza a opcao pretendida: ";

	switch (select_menu())
	{
	case '1':
		playgame();
		break;
	case '2':
		shoW_scoreboard();
		break;
	case '3':
		exit(0);
		break;
	}
	system("pause");
}

int select_menu()
{
	string linha = "";
	
	while (linha.length() != 1)
	{
		getline(cin, linha);
		if (cin.eof())
			cin.clear();

		if (linha.length() != 1 || (linha.length() == 1 && linha[0] != '1' && linha[0] != '2' && linha[0] != '3'))
		{
			cout << "Opcao invalida. Introduza a opcao pretendida: ";
			linha = "";
		}
	}
	return linha[0];
}

void print_boards(Player &UM, Player &DOIS)
{
	gotoxy(0, 0);
	setcolor(WHITE, BLACK);
	cout << setw(15) << UM.get_player_name() << endl;
	UM.showBoard();
	cout << endl;
	cout << endl;
	cout << setw(15) << DOIS.get_player_name() << endl;
	DOIS.showBoard();

	// formula lado a lado: (2 * UM.get_board().getColumns()) + 2 + 5
}
void player_turn(Player &UM, Player &DOIS)
{
	cout << "Jogador: " << UM.get_player_name() << endl;
	DOIS.attackBoard(UM.getBomb());
}
void player_win(Player &UM, Player &DOIS, double &endtime)
{
	system("cls");
	setcolor(GREEN, BLACK);
	cout << "========================================================" << endl;
	cout << "=  PARABENS " << DOIS.get_player_name() << ", ganhaste!!!" << endl;
	cout << "========================================================" << endl;
	setcolor(WHITE, BLACK);
	size_t Area = DOIS.get_board().getColumns() * DOIS.get_board().getLines();
	size_t score = endtime * (DOIS.get_board().get_ships_size() / Area);
	scoreboard TAB = scoreboard();
	if (TAB.top_scores(score))
	{
		setcolor(RED, BLACK);
		cout << "ESTAS NO TOP 10!!" << endl;
		setcolor(WHITE, BLACK);
		system("pause");
		TAB.update_scoreboard(DOIS.get_player_name(), score);
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