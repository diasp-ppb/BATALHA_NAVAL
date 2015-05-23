#ifndef _SCOREBOARD
#define _SCORREBOARD

#include <vector>
#include <string>

using namespace std;
struct PL
{
	string name;
	size_t score;
};

class scoreboard
{
public:
	scoreboard();
	void update_scoreboard(string playername, size_t score);
	bool top_scores(size_t & sc) const;
	void show_scores();
	void save_scores();
private:
	vector < PL > scores;
};

#endif