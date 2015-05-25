#include "SCOREBOARD.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "COLOR_MOD.h"

using namespace std;

scoreboard::scoreboard()
{
	if (!ifstream("ScoreBoard.txt"))
	{
		ofstream CriaFicheiro("ScoreBoard.txt");
		for (int i = 0; i < 10; i++)
			CriaFicheiro << setw(14) << left << "Vazio" << setw(8) << 100000 << setw(8) << 100 << setw(8) << 30 << "\n";
	}

	ifstream Readscore("ScoreBoard.txt");

	while (!Readscore.eof())
	{
		PL newone;
		Readscore >> newone.name >> newone.score >> newone.boardArea >> newone.shipsArea;
		if (scores.size() < 10)
			scores.push_back(newone);
	} 
}

void scoreboard::update_scoreboard(string playername, int score, int boardArea, int shipsArea)
{
	PL newhighscore; 
	newhighscore.name = playername;  
	newhighscore.score = score;
	newhighscore.boardArea = boardArea;
	newhighscore.shipsArea = shipsArea;

	size_t i;

	for (i = 0; i < scores.size(); i++)
	{
		if (scores[i].score > score)
			break;
	}

	vector<PL> newscores;

	for (size_t j = 0; j < i; j++)
	{
		newscores.push_back(scores[j]);
	}

	newscores.push_back(newhighscore);

	for (i = i; i < scores.size(); i++)
	{
		newscores.push_back(scores[i]);
	}
	if (newscores.size() > 10)
	{
		newscores.resize(10);
	}
	scores = newscores;

	ofstream savefile("ScoreBoard.txt");
	
	for (size_t i = 0; i < scores.size(); i++)
	{
		savefile << setw(14) << left << scores[i].name << setw(8) << scores[i].score << setw(8) << scores[i].boardArea << setw(8) << scores[i].shipsArea << "\n";
	}
}

bool scoreboard::top_scores(int &sc) const
{
	for (size_t i = 0; i < scores.size(); i++)
	{
		if (scores[i].score > sc)
			return true;
	}
	return false;
}

void scoreboard::show_scores()
{
	setcolor(GREEN, BLACK);
	cout << "====================================================================" << endl
		<< setw(29) << " " << setw(10) << "SCOREBOARD" << endl
		<< endl;
	setcolor(WHITE, BLACK);
	cout << setw(12) << left << "Nomes" << setw(8) << "----->" << setw(8) << "Score" << setw(8) << "----->" << setw(12) << "Board Area" << setw(8) << "----->" << setw(12) << "Ships Area" << "\n\n";
	for (size_t i = 0; i < scores.size(); i++)
	{
		cout << setw(12) << left << scores[i].name << setw(8) << "----->" << setw(8) << scores[i].score << setw(8) << "----->" << setw(12) << scores[i].boardArea << setw(8) << "----->" << setw(12) << scores[i].shipsArea << endl;
	}
	setcolor(GREEN, BLACK);
	cout << endl << "====================================================================" << endl;
	setcolor(WHITE, BLACK);
}
