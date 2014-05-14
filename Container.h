 
#ifndef CONTAINER_H

#include "Item.h"
#include <allegro5\allegro5.h>
#include <iostream>
#include <vector>


#define CONTAINER_H


class Container
{
public:
	std::vector<Item *> items;
	std::vector<int> containerSlot;
	Container();
	Container(int spaX, int spaY, int size, int x, int y, int rowX);	
	int rowX, rowY, spacingX, spacingY, size, x, y, hudX, hudY, deltaItem, s, j, isItemClicked(), loopContainerSpace(), getItemId();
	/*void update(ALLEGRO_BITMAP *item[]);
	void modifyItem(int i, int b, int flag);
	void assignItem(int b, int stack);*/
	bool checkIfInBounds();
	/*void selectItem();	
	ALLEGRO_BITMAP *containerHUD;*/
	void initate();
	void selectItem();
	void deallocate();
	void updateDraw(ALLEGRO_BITMAP *item[]);
	void update();
	void setStack(int i, int b);
	void setId(int i, int b);
private:
	
protected:
};
#endif
