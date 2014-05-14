 
#ifndef BUTTON_H
#define BUTTON_H
#include <allegro5\allegro.h>
#include "MouseHandler.h"
class Button
{
public:
	Button(int x, int y, int width, int height, ALLEGRO_BITMAP *a, ALLEGRO_BITMAP *b, ALLEGRO_BITMAP *c);
	int init();
	void update();
	void updateScale(int scaleW, int scaleH, int dX, int dY, int h, int w);
	int isClicked(),  returnState();
	bool hasClicked;
	int state, xpos, ypos, height, width;
	void deleteButton(), holdButton();
	bool isDestroyed;
	ALLEGRO_BITMAP *buttonState[3];
private:
protected:
};

#endif
