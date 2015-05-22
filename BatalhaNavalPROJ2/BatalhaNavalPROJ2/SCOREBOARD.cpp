#include "SCOREBOARD.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
scoreboard::scoreboard()
{
	ifstream Readscore("ScoreBoard.txt");

	while (!Readscore.eof())
	{
		string nn;
		int sc;
		Readscore >> nn >> sc;

		names.push_back(nn);
		scores.push_back(sc);
	}



}
void scoreboard::update_scoreboard()
{
}
bool scoreboard::top_scores(size_t &sc) const
{
	for (size_t i = 0; i < scores.size(); i++)
	{
		if (scores[i] < sc)
			return true;
	}
	return false;
}
void scoreboard::show_scores()
{

}
