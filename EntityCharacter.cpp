#include <allegro5\allegro.h>
#include "EntityCharacter.h"
#include "World.h"

bool isDead;

extern World world;


EntityCharacter::EntityCharacter()
{

}

void EntityCharacter::moveCharacter(int dir)
{
	switch(dir)
	{
		// 1 = <-- LEFT
		// 2 = --> RIGHT
		// 3 = DOWN
		// 4 = UP
	case 1:
		this->xPos--;
	case 2:
		this->xPos++;
	case 3:
		this->Ypos--;
	case 4:
		this->Ypos++;
	}
}
