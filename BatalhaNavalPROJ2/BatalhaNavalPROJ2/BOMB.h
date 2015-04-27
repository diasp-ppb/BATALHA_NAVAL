#include "TYPES.h"

//=============================================================================
#ifndef _BOMB
#define _BOMB

class Bomb
{
public:
	Bomb(PositionChar targetPosition);
	PositionChar getTargetPosition() const;
	void setValues(char lin, char col);
	// OTHER METHODS, if necessary
	// ...
	void show() const; // shows the attributes of the bomb (for debugging)
private:
	char targetLine, targetColumn;
};
//=============================================================================
#endif // !_BOMB


