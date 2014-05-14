 
#include "allegro5\allegro5.h"
//#include "Entity.h"

#ifndef ENTITYCHARACTER_H
#define ENTITYCHARACTER_H

class EntityCharacter
{
public:
	EntityCharacter();
	int deltaX, deltaY, segmentC, areaC;
	void moveCharacter(int dir);
	void update();
private:
	int xPos, Ypos;
protected:
};

#endif
