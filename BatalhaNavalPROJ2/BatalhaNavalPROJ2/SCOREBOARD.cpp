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

	ifstream Readscore("ScoreBoard.txt");

	while (!Readscore.eof())
	{
		PL newone;
		Readscore >> newone.name >> newone.score;
		scores.push_back(newone);
	}
}
void scoreboard::update_scoreboard(string playername, size_t score)
{
	PL newhighscore; newhighscore.name = playername;  newhighscore.score = score;
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
		savefile << scores[i].name << setw(10) << scores[i].score << "\n";
	}
}
bool scoreboard::top_scores(size_t &sc) const
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
	cout << "=================================" << endl
		<< "             SCOREBOARD            " << endl
		<< endl;
	setcolor(WHITE, BLACK);
	for (size_t i = 0; i < scores.size(); i++)
	{
		cout << setw(10) << left << scores[i].name << setw(12) << right << "--------->" << setw(10) << right << scores[i].score << endl;
	}
	setcolor(GREEN, BLACK);
	cout << endl << "=================================" << endl;
	setcolor(WHITE, BLACK);
}
