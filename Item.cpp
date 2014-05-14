
#include "Item.h"
#include "MouseHandler.h"
#include "Container.h"
#include <allegro5\allegro5.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include "DynamicItem.h"
#include <string>
extern ALLEGRO_FONT *font;
extern MouseHandler m;
extern DynamicItem heldItem;
Item::Item()
{
	Item::iD=0;
}
Item::Item(int i)
{
	Item::iD = i;
	this->stack=1;
	Item::init();
}

bool Item::checkInBounds()
{
	if(m.x > Item::x && m.x < Item::x+48 && m.y > Item::y && m.y < Item::y+48)
	{
		return true;
	}
	else
	{
		return false;
	}
		/*if(m.state==1)
		{
			this->state=2;
			return 2;
		}
		else if(m.state==2)
		{
			this->state=3;
			return 3;
		}
		else if(m.state==3)
		{
			this->state=4;
			return 4;
		}
		else if(m.state==0)
		{
			this->state=1;
			return 1;
		}
	}
	return 0;*/
}
void Item::update(ALLEGRO_BITMAP *a)
{
	al_draw_bitmap(a, Item::x, Item::y, 0); 
}

void Item::drawQuantity()
{	
	al_draw_text(font, al_map_rgb(0, 0, 0), this->x+34, this->y+38, 0, std::to_string(static_cast<long long>(this->stack)).c_str());
}

void Item::pickUp()
{
	if(this->checkInBounds() == true)
	{
		if(m.state == 1)
		{
			heldItem.accessButton = m.state;
			heldItem.itemSelected=true;
			heldItem.activeClick=true;
			heldItem.click=true;		
			heldItem.holdingItem->iD = this->iD;			
			heldItem.holdingItem->init();
			heldItem.holdingItem->stack = this->stack;
			this->iD = 0;
			this->stack = 0;
			this->init();
		}
	}
}

void Item::updateStack()
{
	if(this->stack == 0)
	{
		this->iD = 0;
		this->init();
	}
	if(this->stack > this->maxStack && this->iD != 0)
	{
		
		heldItem.itemSelected=true;
		heldItem.activeClick=true;
		heldItem.click=true;
		heldItem.holdingItem->stack = (this->stack-this->maxStack);
		this->stack = this->maxStack;
	}
}

void Item::drawDescription()
{
	const char * description = this->c.c_str();
	const char * name = this->n.c_str();
	int descSize = (strlen(description));
	int k = 0;
	int length = 0;
	while(descSize > 0)
	{
		descSize-=28;
		k++;
	}
	if((48+strlen(description)*10) > 320)
	{
		length = 320;
	}
	else
	{
		length = (48+strlen(description)*10);
	}
	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < 40+(19*k); j++)
		{
			if(length+this->x > 640)
			{
				al_draw_pixel((640-length)+i, this->y+24+j, al_map_rgb(40, 40, 40));
			}
			else
			{
				al_draw_pixel(this->x+20+i, this->y+24+j, al_map_rgb(40, 40, 40));
			}
		}
		
	}
	if(length+this->x > 640)
	{		
		al_draw_text(font, this->color, (640-length+4), (this->y+24), 0, name );
		if(k > 1)
		{
			for(int c = 0; c < k; c++)
			{
				if(strlen(description)-(c*28)<0)
				{
					al_draw_text(font, al_map_rgb(180, 180, 180), (640-length+24), (this->y+48+(c*20)), 0, this->c.substr(c*28, (c*28-strlen(description))).c_str());
					break;
				}
				else
				{
					al_draw_text(font, al_map_rgb(180, 180, 180), (640-length+24), (this->y+48+(c*20)), 0, this->c.substr(c*28, 28).c_str());
				}
			}
		}
		else
		{
			al_draw_text(font, al_map_rgb(180, 180, 180), (640-length+24), (this->y+48), 0, description );	
		}
	}
	else
	{
		al_draw_text(font, this->color, (this->x+24), (this->y+24), 0, name );
		if(k > 1)
		{
			for(int c = 0; c < k; c++)
			{
				if(strlen(description)-(c*28)<0)
				{
					al_draw_text(font, al_map_rgb(180, 180, 180), (this->x+48), (this->y+48+(c*20)), 0, this->c.substr(c*28, (c*28-strlen(description))).c_str());
					break;
				}
				else
				{
					al_draw_text(font, al_map_rgb(180, 180, 180), (this->x+48), (this->y+48+(c*20)), 0, this->c.substr(c*28, 28).c_str());
				}
			}
		}
		else
		{
			al_draw_text(font, al_map_rgb(180, 180, 180), (this->x+48), (this->y+48), 0, description );
		}
		
		
	}
	//delete description;
	//delete name;
}
int Item::init()
{
	
	/*	
	Item *timsVirginity = new Item(1, 2, 0, 5, 6900);

	Item *atomicEnergy = new Item(2, 1, 0, 8, 120);

	Item *scrapMetal = new Item(3, 1, 0, 2, 12); 

	Item *scrapWood = new Item(4, 1, 0, 2, 4); 

	Item *scrapCloth = new Item(5, 1, 0, 2, 8); 

	Item *plastic = new Item(6, 1, 0, 2, 8);

	Item *mineralCommon = new Item(7, 1, 0, 2, 25);

	Item *mineral = new Item(8, 1, 0, 2, 75);

	Item *mineralRare = new Item(9, 1, 0, 8, 225);

	Item *mineralAncient = new Item(10, 1, 0, 6, 890);

	Item *mechanism = new Item(11, 1, 0, 2, 25);

	Item *electricMechanism = new Item(12, 1, 0, 8, 40); 

	Item *threads = new Item(13, 1, 0, 2, 8);

	Item *CPU = new Item(14, 1, 0, 8, 70);

	Item *glass = new Item(15, 1, 0, 2, 15);

	Item *display = new Item(16, 1, 0, 8, 50);	

	Item *computer = new Item(17, 5, 0, 4, 200);

	Item *navigator = new Item(18, 5, 0, 4, 350);

	Item *glasses = new Item(19, 5, 0, 1, 40);

	Item *aimbot = new Item(19, 5, 0, 4, 300);

	Item *color = new Item(20, 1, 0, 2, 20);

	Item *food = new Item(13, 6, 0, 3, 20);

	Item *nuclearPotato = new Item(18, 1, 0, 2, 25); */
	// i = ID, j = type, k = flags, r = raritytype, r = gold, b = iscraftable, c = isquestitem, d = description

	//Types: 1 = Normal Item/Crafting Item || 2 = Quest Item || 3 = Equip Weapon || 4 = Equip Armor || 5 = Equip Acc || 6 = Consumable
	//Flags:
	//RarityType: 1 = Normal Item, 2 = Crafting Item, 3 = Consumable, 4 = HighValue/Rare, 5 = Special/Quest, 6 = Crafting+Rare / High Tier crafting, 7 = Crafting+Consumable, 8 = Medium Tier crafting item

	
	switch(Item::iD)
	{
	case 0:
		this->type=1;
		this->rarity[0]=1;
		this->rarity[1]=1;
		this->x = 0;
		this->y = 0;
		this->maxStack=1;
		this->fill("Unknown", "Unknown Item");
		break;
	case 1:
		this->type=2;
		this->rarity[0]=5;
		this->rarity[1]=6900;
		this->maxStack=1;
		this->fill("A cardboard box containing Tim's virginity.", "Tim's virginity"); 
		break;
	case 2:
		this->type=1;
		this->rarity[0]=2;
		this->rarity[1]=180;
		this->maxStack=99;
		this->fill("Volatile shit to keep in your backpack", "Nuclear energy"); 
		break;
	case 3:
		this->type=1;
		this->rarity[0]=2;
		this->rarity[1]=20;
		this->maxStack=99;
		this->fill("Eco-friendly and recyclable", "Scrap metal"); 
		break;
	case 4:
		this->type=1;
		this->rarity[0]=2;
		this->rarity[1]=10;
		this->maxStack=99;
		this->fill("If you had enough of these, you could maybe build a house?", "Scrap wood"); 
		break;
	case 5:
		this->type=1;
		this->rarity[0]=2;
		this->rarity[1]=15;
		this->maxStack=99;
		this->fill("Better than walking naked", "Scrap cloth"); 
		break;
	case 6:
		this->type=1;
		this->rarity[0]=2;
		this->rarity[1]=40;
		this->maxStack=99;
		this->fill("A plastic like material", "Plastik"); 
		break;
	case 7:
		this->type=1;
		this->rarity[0]=2;
		this->rarity[1]=20;
		this->maxStack=9;
		this->fill("Its super glue.", "Super glue"); 
		break;
	case 8:
		this->type=1;
		this->rarity[0]=2;
		this->rarity[1]=50;
		this->maxStack=9;
		this->fill("A more superior version of super glue", "Super super glue"); 
		break;

	case 9:
		this->type=1;
		this->rarity[0]=2;
		this->rarity[1]=150;
		this->maxStack=9;
		this->fill("A more super superior version of super super glue", "Super super super glue"); 
		break;
	case 10:
		this->type=1;
		this->rarity[0]=2;
		this->rarity[1]=400;
		this->maxStack=9;
		this->fill("The most superior version of super glue", "Super super super super glue"); 
		break;
	case 11:
		this->type=1;
		this->rarity[0]=2;
		this->rarity[1]=50;
		this->maxStack=99;
		this->fill("Beware of springs that come into contact with your eyes", "Mechanism");
		break;
	case 12:
		this->type=5;
		this->rarity[0]=4;
		this->rarity[1]=400;
		this->maxStack=1;
		this->fill("May use the skill 'Protection' during your turn", "Mech-named-ISM"); 
		break;
	case 13:
		this->type=1;
		this->rarity[0]=2;
		this->rarity[1]=80;
		this->maxStack=99;
		this->fill("Used to make all kinds of useful shit", "Electrical mechanism"); 
		break;
	case 14:
		this->type=1;
		this->rarity[0]=2;
		this->rarity[1]=40;
		this->maxStack=99;
		this->fill("Strings tired around a spool", "Threads"); 
		break;
	case 15:
		this->type=1;
		this->rarity[0]=2;
		this->rarity[1]=110;
		this->maxStack=99;
		this->fill("The 'CP' stands for 'Crafting Pun'", "CPU"); 
		break;
	case 16:
		this->type=1;
		this->rarity[0]=2;
		this->rarity[1]=20;
		this->maxStack=99;
		this->fill("Upon death, carbon entities have a chance of dropping glass", "Glass"); 
		break;
	case 17:
		this->type=1;
		this->rarity[0]=8;
		this->rarity[1]=80;
		this->maxStack=99;
		this->fill("Playdis", "Display"); 
		break;
	case 18:
		this->type=5;
		this->rarity[0]=4;
		this->rarity[1]=200;
		this->maxStack=1;
		this->fill("yo dawge i herd u liek playin timpOng-duhvideo gaem so i puet a computer so you can timpang te video game whiel u tim pang te video game", "Computer"); 
		break;
	case 19:
		this->type=5;
		this->rarity[0]=4;
		this->rarity[1]=50;
		this->maxStack=1;
		this->fill("Increases accuracy when equipped", "Glasses"); 
		break;
	case 20:
		this->type=5;
		this->rarity[0]=4;
		this->rarity[1]=250;
		this->maxStack=1;
		this->fill("Displays a map when equipped", "Navigator");
		break;
	case 21:
		this->type=5;
		this->rarity[0]=4;
		this->rarity[1]=110;
		this->maxStack=1;
		this->fill("Greatly increases accuracy and increase critical chance when equipped", "Aimbot");
		break;
	case 22:
		this->type=1;
		this->rarity[0]=2;
		this->rarity[1]=110;
		this->maxStack=99;
		this->fill("Its paper!", "Paper");
		break;
	case 23:
		this->type=6;
		this->rarity[0]=3;
		this->rarity[1]=110;
		this->maxStack=99;
		this->fill("Its book!", "Book");
		break;
	}
	switch(this->rarity[0])
	{
		case 1:
			this->color = al_map_rgb(50, 50, 50);
			break;
		case 2:
			this->color = al_map_rgb(120, 120, 120);
			break;
		case 3:
			this->color = al_map_rgb(50, 70, 170);
			break;
		case 4:
			this->color = al_map_rgb(170, 180, 30);
			break;
		case 5:
			this->color = al_map_rgb(170, 10, 170);
			break;
		case 6:
			this->color = al_map_rgb(230, 160, 20);
			break;
		case 7:
			this->color = al_map_rgb(120, 90, 170);
			break;
		case 8:
			this->color = al_map_rgb(10, 180, 30);
			break;
	}
	return 0;
}

void Item::fill(std::string d, std::string n)
{
	this->c = d;
	this->n = n;
}
int Item::getID()
{
	return Item::iD;
}
void Item::Delete()
{
	delete this;
}
