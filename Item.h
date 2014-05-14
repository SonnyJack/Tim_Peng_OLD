 


#ifndef ITEM_H
#define ITEM_H

#include <allegro5\allegro5.h>
#include <string>
class Item
{
public:
	Item();
	Item(int i);
	int iD, type, flag, rarity[2], x, y, state, maxStack, stack;
	void Delete(), fill(std::string d, std::string n), update(ALLEGRO_BITMAP *a), drawDescription(), drawQuantity();
	std::string c, n;
	ALLEGRO_COLOR color;
	bool checkInBounds();
	void pickUp();
	void updateStack();
		int getID(), init(), checkStack(int i);
private: 
	bool craftable, isQuestItem;
};

#endif
