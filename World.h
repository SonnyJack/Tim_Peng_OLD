 

#include "EntityCharacter.h"

#ifndef WORLD_H
class World
{
	public:
		int defineSegment(int i, int j, int k, int a[]);
		void init();
		int drawWorld(EntityCharacter character);
		int getTileId(int i, int j, EntityCharacter character);
	protected:
	private:
		struct map;
};

#endif
