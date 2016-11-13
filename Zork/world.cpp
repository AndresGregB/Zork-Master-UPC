#include "stdafx.h"
#include <iostream>
#include "world.h"
#include "room.h"
#include "roomExit.h"
#include "player.h"


world::world()
{
	type = WORLD;
	
	room* deep = new room("Captive Cell", "When you wake up you find yourselve in a prisoner cell. You feel the urge to escape", this);
	room* mid = new room("Mid Room", "When you wake up you find yourselve in a prisioner cell", this);
	room* entrance = new room("Entrance to Dungeon", "There is a door in the other side of the room, its probably closed", this);
	room* extra = new room("Utility Room", "There is only one way in and one way out, this room is empty except for some pots, a table and a chair", this);
	room* exterior = new room("Exterior of the Dungeon", "Congratulations!! you have escaped the dungeon", this);
	
	character = new player(deep);
	std::cout << character->description;

	roomExit *deepMid = new roomExit(deep,mid);
	roomExit *midEntrance = new roomExit(mid,entrance);
	roomExit *midExtra = new roomExit(mid, extra);
	roomExit *entranceExterior = new roomExit(entrance, exterior);

	deep->north = mid->south = deepMid;
	mid->north = entrance->south = midEntrance;
	mid->east =	extra->west	= midExtra;
	entrance->north = exterior->south = entranceExterior;

	contains.push_back(deep);
	contains.push_back(mid);
	contains.push_back(entrance);
	contains.push_back(extra);
	contains.push_back(exterior);

}


world::~world()
{
}
void world::playerLook() 
{
	std::cout << "\n" << character->containedIn->description;
}