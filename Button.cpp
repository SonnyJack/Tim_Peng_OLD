#include "Button.h"
#include <allegro5\allegro5.h>
#include "MouseHandler.h"
extern MouseHandler m;

bool isHovered;

int Button::init()
{
	
	al_install_mouse();
	isDestroyed=false;
	isHovered=false;
	Button::state = 0;
	Button::hasClicked=false;
	return 0;
}

void Button::holdButton()
{
	Button::state=2;
}

int Button::returnState()
{
	return Button::state;
}
void Button::update()
{
	al_draw_bitmap(Button::buttonState[Button::state], Button::xpos, Button::ypos, 0);
}

void Button::updateScale(int scaleW, int scaleH, int dX, int dY, int h, int w)
{
	al_draw_scaled_bitmap(Button::buttonState[Button::state], 0, 0, h, w, dX, dY, scaleW, scaleH, 0);
}
int Button::isClicked()
{
		/*if(mousestate.buttons == 0)
		{
			Button::hasClicked = false;
		}*/
		if(m.x > Button::xpos && m.x < (Button::xpos+Button::width) && m.y > Button::ypos && m.y < (Button::ypos+Button::height))
		{
			if(m.state == 1)
			{		
				Button::state = 2;				
				return 2;
				//Button::hasClicked = true;
			}
			else if(m.state == 2)
			{
				
				return 3;
				
			}
			else
			{
				Button::state = 1;
				return 1;
			}
		}
		else
		{
			isHovered = false;
			Button::state = 0;
			return 0;
		}
	}

Button::Button(int x, int y, int h, int w, ALLEGRO_BITMAP *a, ALLEGRO_BITMAP *b, ALLEGRO_BITMAP *c)
{
	Button::xpos=x;
	Button::ypos=y;
	Button::height=h;
	Button::width=w;
	Button::buttonState[0] = a;
	Button::buttonState[1] = b;
	Button::buttonState[2] = c;
	
	init();
}

void Button::deleteButton()
{
	delete this;
}
