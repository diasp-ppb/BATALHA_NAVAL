#ifndef _SCOREBOARD
#define _SCORREBOARD

#include <vector>
#include <string>

using namespace std;

struct PL
{
	string name;
	int score;
	int boardArea;
	int shipsArea;
};

class scoreboard
{
public:
	scoreboard();
	void update_scoreboard(string playername, int score, int boardArea, int shipsArea);
	bool top_scores(int &sc) const;
	void show_scores();
	void save_scores();
private:
	vector<PL> scores;
};

#endif