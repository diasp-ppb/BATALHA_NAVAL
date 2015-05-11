#include "TYPES.h"

//=============================================================================
#ifndef _BOMB
#define _BOMB

using namespace std;

class Bomb
{
public:
	Bomb(PositionChar targetPosition);
	PositionChar getTargetPosition() const;
	PositionChar getActualPosition() const;
	// OTHER METHODS, if necessary
	// ...
	void show() const; // shows the attributes of the bomb (for debugging)
private:
	char targetLine, targetColumn;
	char actualLine, actualColumn;
};
//=============================================================================
#endif // !_BOMB


