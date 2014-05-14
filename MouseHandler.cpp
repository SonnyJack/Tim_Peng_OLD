

#include "MouseHandler.h"
#include "allegro5\allegro5.h"


MouseHandler::MouseHandler()
{
	MouseHandler::x = 0;
	MouseHandler::y = 0;
	MouseHandler::activeClick=false;
	MouseHandler::Click=false;
	MouseHandler::rightClick=false;
	MouseHandler::activeRightClick=false;
	MouseHandler::state = 0;
}


void MouseHandler::handleMouse()
{
	al_get_mouse_state(&(MouseHandler::mState));
	switch(MouseHandler::mState.buttons)
	{
	case 0:
		MouseHandler::state=0;
		break;
	case 1:
		MouseHandler::state=1;
		break;
	case 2:
		MouseHandler::state=2;
		break;
	}
	MouseHandler::x = MouseHandler::mState.x;
	MouseHandler::y = MouseHandler::mState.y;

}

void MouseHandler::isClicked()
{
	/*if(this->state==1 && this->Click == false)
	{
		this->activeClick=true;
		this->Click = true;
	}
	if(this->state==0 && this->activeClick == true)
	{
		this->activeClick = false;
	}
	if(activeClick == false && this->state==1 && this->Click == true)
	{
		this->Click = false;
	}
	if(this->state==2)
	{
		//this->activeRightClick=true;
		this->rightClick = true;
	}
	if(this->rightClick == true && this->state == 0)
	{
		this->rightClick=false;
	}*/
}
