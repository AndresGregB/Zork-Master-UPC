#include "stdafx.h"
#include "world.h"
#include "room.h"


world::world()
{
	type = WORLD;
	
	room* deep = new room("Captive Cell", "When you wake up you find yourselve in a prisioner cell. You fell the urge to escape", this);
	room* mid = new room("Mid Cell", "When you wake up you find yourselve in a prisioner cell", this);
	room* entrance = new room("Entrance to Dungeon", "There is a door in the other side of the room, its probably closed", this);

	contains.push_back(deep);
	contains.push_back(mid);
	contains.push_back(entrance);

}


world::~world()
{
}
