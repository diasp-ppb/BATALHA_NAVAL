#ifndef _PLAYER
#define _PLAYER
#include <string>
#include "TYPES.h"
#include "BOMB.h"
#include "BOARD.h"

using namespace std;

class Player
{
public:
	Player(string playerName, string boardFilename);
	Player(size_t i);
	void showBoard() const; // shows the player’s board 
	Bomb getBomb(); // asks bomb target coordinates and creates the bomb
	void attackBoard(const Bomb &b); // "receives" a bomb from the opponent;
	// updates own board taking into account the damages
	// caused by the bomb; BEFORE THAT… moves the ships
	char askCoord(); // asks coordinates and validates input
	bool isContained(char value, int max); // checks if value is within the limits
	bool Player_DEAD() const;
	Board get_board() const;
	string get_player_name() const;
	clock_t get_time() const;
	void set_time(clock_t _time);

private:
	string name; // name of the player
	Board board; // board of the player
	clock_t time;
};

#endif