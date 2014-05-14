

#include "DynamicItem.h"
#include "Item.h"
#include "Container.h"


void DynamicItem::init()
{
	this->accessButton = 0;
	this->containerSlot=0;
	this->holdingItem = new Item(0);
	this->itemSelected=false;
	this->rightClick=false;
	this->activeClick=false;
	this->click=false;
}
