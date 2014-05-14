 

#include "allegro5\allegro.h"
#ifndef MOUSEHANDLER_H
#define MOUSEHANDLER_H


class MouseHandler
{
	public:
		MouseHandler();
		int x, y, state;
		void handleMouse();
		void isClicked();
		bool activeClick, Click, rightClick, activeRightClick;
		ALLEGRO_MOUSE_STATE mState;
	private:
};

#endif
