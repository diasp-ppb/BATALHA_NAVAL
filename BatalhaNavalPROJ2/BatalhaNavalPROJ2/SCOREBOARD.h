
#include <vector>
#include <string>
class scoreboard
{
public:
	scoreboard();
	void update_scoreboard();
	bool top_scores(size_t & sc) const;
	void show_scores();
private:
	std::vector <string> names;
	std::vector <size_t> scores;
};