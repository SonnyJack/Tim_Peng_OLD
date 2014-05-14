 
#include "Container.h"
#include "Item.h"
#define DYNAMICITEM_H
#ifdef DYNAMICITEM_H

class DynamicItem
{
	public:
		void init();
		Item *holdingItem;
		bool itemSelected, activeClick, click, rightClick;
		int accessButton, containerSlot;
};


#endif
