#include "Item.h"
#include "MouseHandler.h"
#include <iostream>
#include <vector>
#include "Container.h"

extern MouseHandler m;

Container::Container()
{

}
Container::Container(int spaX, int spaY, int size, int x, int y, int rowX)
{
	this->x = x;
	this->y = y;
	this->spacingX = spaX;
	this->spacingY = spaY;
	this->rowX = rowX;
	this->size = size;
	this->rowY = this->size / this->rowX;
	for(int j=0; j<this->size; j++)
	{
		this->items.insert(this->items.begin()+j, new Item(0));
		this->containerSlot.insert(this->containerSlot.begin()+j, 0);
	}
}
//Make an assignItem func that


// A: Checks if the space is empty and applies the item drop

// B: If occupied by another item, the item space will request an Container::deltaSlot.

// This delta slot can belong to any container class, including itself

// Function like normal

// THINK ABOUT 0 SWITCH BITCHz
bool Container::checkIfInBounds()
{
	if(m.x > this->x && m.x < (this->x + (this->size/this->rowY)*48+((this->size/this->rowY)-1)*this->spacingX) && m.y > this->y && m.y < (this->y + (this->size/this->rowX)*48+((this->size/this->rowX)-1)*this->spacingY))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*void Container::assignItem(int b, int stack)
{
	if(this->checkIfInBounds())
	{
	Container::j = 0;
	for(int i = 0; i < this->size; i++)
	{
		if(this->items[i]->selectItem()==0)
		{
			Container::j++;
			if(Container::j == Container::size)
			{
				this->items[this->deltaItem]->iD = b;
				this->items[this->deltaItem]->stack = stack;
				this->modifyItem(this->deltaItem, 0, b);
			}
		}
		if(this->items[i]->selectItem()==1)
		{
			if(this->items[i]->iD == 0)
			{
				this->items[i]->iD = b;
				this->items[i]->stack = stack;
				this->modifyItem(i, 0, b);
			}
			else
			{
				if(this->items[i]->iD == b)
				{
					this->items[i]->stack = this->items[i]->stack+stack;
					this->items[i]->iD = b;
					this->modifyItem(i, 0, b);
				}
				else
				{
				this->items[this->deltaItem]->iD = this->items[i]->iD;
				this->items[this->deltaItem]->stack = this->items[i]->stack;
				this->modifyItem(this->deltaItem, 0, this->items[i]->iD);
				this->items[i]->iD = b;
				this->items[i]->stack = stack;
				this->modifyItem(i, 0, b);
				}
			}
			break;
		}
	}
	}
	else
	{
		this->items[this->deltaItem]->iD = b;
		this->modifyItem(this->deltaItem, 0, b);
	}

}

void Container::modifyItem(int i, int b, int flag)
{
	for(int j = 0; j < this->rowY; j++)
	{
		for(int k = 0; k < this->rowX; k++)
		{
			if(b == i)
			{
				if(flag > 0)
				{
					this->slot[j][k] = this->items[i]->iD;
				}
				else
				{
				this->deltaItem = b;
				this->items[i]->iD=0;
				this->items[i]->init();
				this->slot[j][k] = 0;
				//delete b;
				}
			}
			b++;
		}
	}
	
}


int Container::getItemId()
{
	return this->items[this->loopContainerSpace()]->iD;
}

int Container::isItemClicked()
{
	if(this->items[this->loopContainerSpace()]->selectItem() == 3)
	{
		return 2;
	}
	else if(this->items[this->loopContainerSpace()]->selectItem()== 4)
	{
		return 3;
	}
}


int Container::loopContainerSpace()
{
	for(int i=0; i<this->size; i++)
	{
		if(this->items[i]->iD == 0)
		{
			continue;		
		}	
		else
		{
			if(this->items[i]->selectItem()==1 || this->items[i]->selectItem()==2 || this->items[i]->selectItem()==3)
			{
				return i;
			}
		}
	}
	return -1;
}
void Container::selectItem()
{
	if(this->loopContainerSpace() != -1 && this->checkIfInBounds()==true)
	{
		items[this->loopContainerSpace()]->drawDescription();
	}		
}



void Container::update(ALLEGRO_BITMAP *item[])
{
	this->s=-1;
	for(int i=0; i<this->rowY; i++)
	{
		for(int j=0; j<this->rowX; j++)
		{
			this->s++;	
			this->items[this->s]->iD = this->slot[i][j];
			this->items[this->s]->init();
			//this->items.erase(this->items.begin()+s);
			//this->items.insert(this->items.begin()+s, new Item(this->slot[i][j]));	
			this->items[this->s]->x = (this->x)+(j*48) + (j*(this->spacingX));
			this->items[this->s]->y = (this->y)+(i*48) + (i*(this->spacingY));
			if(this->slot[i][j] == 0)
			{	
				if(this->items[this->s]->iD != 0)
				{
					this->items[this->s]->iD = 0;
					
				}
				continue;
			}
			else
			{	

				//Item *tempItem = new Item(this->slot[i][j]);
				//this->items[s] = (tempItem);
				//this->items[s]->x = this->x+(j*48) + (j*this->spacingX);
			//	this->items[s]->y = this->y+(i*48) + (i*this->spacingY);

				this->items[this->s]->update(item[this->items[this->s]->rarity[0]+170]);
				this->items[this->s]->update(item[this->slot[i][j]]);
				this->items[this->s]->drawQuantity();
				//al_draw_bitmap(item[tempItem->rarity[0]+170], this->x+(j*48)+(j*this->spacingX), this->y+(i*48)+(i*this->spacingY), 0);
				//al_draw_bitmap(item[slot[i][j]], this->x+(j*48)+(j*this->spacingX), this->y+(i*48)+(i*this->spacingY), 0);
				
			}
			
		}
	}
}

*/

void Container::initate()
{
	for(int i = 0; i < this->size; i++)
	{
		this->items[i]->iD = this->containerSlot[i];
		this->items[i]->init();
	}
	this->s=-1;
	for(int k=0; k<this->rowY; k++)
	{
		for(int j=0; j<this->rowX; j++)
		{
			this->s++;
			this->items[this->s]->x = (this->x)+(j*48) + (j*(this->spacingX));
			this->items[this->s]->y = (this->y)+(k*48) + (k*(this->spacingY));
		}
	}
}

void Container::deallocate()
{
	for(int i = 0; i < this->size; i++)
	{
		this->items[i]->Delete();
	}
}

void Container::updateDraw(ALLEGRO_BITMAP *item[])
{
	//drawContainerHud
	for(int i = 0; i < this->size; i++)
	{
		if(this->items[i]->iD == 0)
		{
			continue;
		}
		else
		{
			this->items[i]->update(item[this->items[i]->rarity[0]+170]);
			this->items[i]->update(item[this->items[i]->iD]);
			this->items[i]->drawQuantity();
		}
	}
	for(int i = 0; i < this->size; i++)
	{
		if(m.x > this->items[i]->x && m.x < (this->items[i]->x+48) && m.y > this->items[i]->y && m.y < (this->items[i]->y+48))
		{
			this->items[i]->drawDescription();
		}
	}
}
/*

void Container::selectItem()
{
	for(int i = 0; i < this->size; i++)
	{
		if(m.x > this->items[i]->x && m.x < (this->items[i]->x+48) && m.y > this->items[i]->y && m.y < (this->items[i]->y+48))
		{
			if(m.state == 1 && heldItem.itemSelected == false && this->items[i]->iD != 0 && heldItem.click == false && heldItem.activeClick == false)
			{
				heldItem.accessButton = m.state;
				heldItem.originCont = this;
				heldItem.itemSelected=true;
				heldItem.activeClick=true;
				heldItem.click=true;
				heldItem.containerSlot=i;
				heldItem.holdingItem->stack = this->items[i]->stack;
				heldItem.holdingItem->iD = this->items[i]->iD;
				heldItem.holdingItem->init();
				this->setId(i, 0);
			}
			if (m.state == 2 && this->items[i]->stack > 0 && heldItem.itemSelected == true && this->items[i]->iD == heldItem.holdingItem->iD)
			{
				heldItem.holdingItem->stack++;
				this->items[i]->stack--;
				if(this->items[i]->stack==0)
				{
					this->setId(i, 0);
				}
				/*heldItem.accessButton = m.state;
				heldItem.originCont = this;
				heldItem.itemSelected=true;
				heldItem.containerSlot=i;
				heldItem.holdingItem->stack = 1;
				this->items[i]->stack--;
				if(this->items[i]->stack==0)
				{
					this->setId(i, 0);
				}
				heldItem.holdingItem->iD = this->items[i]->iD;
				heldItem.holdingItem->init();
			}
		}
	}
}
*/


void Container::update()
{
	for(int i=0; i < this->size; i++)
	{
		this->containerSlot[i] = this->items[i]->iD;
	}
}
void Container::setId(int i, int b)
{
	this->containerSlot[i]=b;
	this->items[i]->iD = b;
	this->items[i]->init();
}

void Container::setStack(int i, int b)
{
	this->items[i]->stack = b;
}
