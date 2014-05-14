#include "EntityCharacter.h"
#include "World.h"
#include <string.h>
#include <allegro5\allegro5.h>
#include <iostream>

struct map
{
	struct segment
	{
		int mapCoord[20][15];
	} segment[16];
} area[12];

ALLEGRO_BITMAP *tileId[256];


int World::defineSegment(int i, int j, int k, int a[])
{
	for(int l=0; l < 15; l++)
	{
		area[i].segment[j].mapCoord[k][l] = a[l];
		//std::cout << area[i].segment[j].mapCoord[k][l];
	}
	return 0;
}
void World::init()
{
	tileId[0]=al_load_bitmap("terrainTile1.png");
	tileId[1]=al_load_bitmap("terrainTile2.png");
	tileId[2]=al_load_bitmap("terrainTile3.png");
	tileId[3]=al_load_bitmap("terrainTile4.png");
	tileId[4]=al_load_bitmap("terrainTile5.png");
	tileId[5]=al_load_bitmap("terrainTile6.png");
	tileId[6]=al_load_bitmap("terrainTile7.png");
	tileId[7]=al_load_bitmap("terrainTile8.png");
	tileId[8]=al_load_bitmap("terrainTile9.png");
	tileId[9]=al_load_bitmap("terrainTile10.png");
	tileId[10]=al_load_bitmap("terrainTile11.png");
	tileId[11]=al_load_bitmap("terrainTile12.png");
	tileId[12]=al_load_bitmap("terrainTile13.png");
	
	//for(int i=0; i < 256; i++)
	//{ 
		//str = string("terrainTile")+i+(".png");
		//tileId[i]=al_load_bitmap("terrainTile" + i + ".png");
	//}
	//map area0segment0

	//will eventually load from files but is lazhy to od iso so. oc, a c
	int tempArray[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int tempArray1[] = {5, 6, 5, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	defineSegment(0, 0, 0, tempArray1);
	int tempArray2[] = {10, 10, 10, 8, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	defineSegment(0, 0, 1, tempArray2);
	int tempArray3[] = {6, 7, 7, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	defineSegment(0, 0, 2, tempArray3);
	int tempArray4[] = {6, 5, 7, 9, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	defineSegment(0, 0, 3, tempArray4);
	int tempArray5[] = {6, 5, 6, 9, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	defineSegment(0, 0, 4, tempArray5);
	int tempArray6[] = {10, 10, 10, 8, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	defineSegment(0, 0, 5, tempArray6);
	int tempArray7[] = {7, 6, 6, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	int tempArray8[] = {7, 6, 6, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	int tempArray9[] = {7, 6, 6, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	int tempArray10[] = {10, 10, 10, 8, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	int tempArray11[] = {7, 6, 6, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	int tempArray12[] = {7, 6, 6, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	int tempArray13[] = {7, 6, 6, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	int tempArray14[] = {10, 10, 10, 8, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	int tempArray15[] = {7, 6, 6, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};

	int tempArray16[] = {12, 12, 12, 11, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	int tempArray17[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	int tempArray18[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	int tempArray19[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	int tempArray20[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	defineSegment(0, 0, 6, tempArray7);
	defineSegment(0, 0, 7, tempArray8);
	defineSegment(0, 0, 8, tempArray9);
	defineSegment(0, 0, 9, tempArray10);
	defineSegment(0, 0, 10, tempArray11);
	defineSegment(0, 0, 11, tempArray12);
	defineSegment(0, 0, 12, tempArray13);
	defineSegment(0, 0, 13, tempArray14);
	defineSegment(0, 0, 14, tempArray15);
	defineSegment(0, 0, 15, tempArray16);
	defineSegment(0, 0, 16, tempArray17);
	defineSegment(0, 0, 17, tempArray18);
	defineSegment(0, 0, 18, tempArray19);
	defineSegment(0, 0, 19, tempArray20);





}


int World::getTileId(int j, int k, EntityCharacter character)
{
	//int tempArea = character.getCharacterLocation(0);
	//int tempSegment = character.getCharacterLocation(1);
	return area[0].segment[0].mapCoord[j][k];
}

int World::drawWorld(EntityCharacter character)
{
	for(int j=0; j < 20; j++)
	{
		for(int k=0; k < 15; k++)
		{
			al_draw_bitmap(tileId[getTileId(j, k, character)], 32*j, 32*k, 0);
		}
	}
	return 0;
}
