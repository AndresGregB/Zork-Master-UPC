#include "stdafx.h"
#include <iostream>
#include "world.h"
#include "room.h"
#include "roomExit.h"
#include "player.h"


world::world()
{
	type = WORLD;

	room* deep = new room("Captive Cell", "When you wake up you find yourselve in a prisoner cell. You feel the urge to escape \n", this);
	room* mid = new room("Mid Room", "When you wake up you find yourselve in a prisioner cell \n", this);
	room* entrance = new room("Entrance to Dungeon", "There is a door in the other side of the room, its probably closed \n", this);
	room* extra = new room("Utility Room", "There is only one way in and one way out, this room is empty except for some pots, a table and a chair \n", this);
	room* exterior = new room("Exterior of the Dungeon", "Congratulations!! you have escaped the dungeon \n", this);
	
	character = new player(deep);
	entities.push_back(character);

	entities.push_back(deep);
	entities.push_back(mid);
	entities.push_back(entrance);
	entities.push_back(extra);
	entities.push_back(exterior);

	
	// Room Exits
	roomExit *deepMid = new roomExit(deep,mid);
	entities.push_back(deepMid);
	roomExit *midEntrance = new roomExit(mid,entrance);
	entities.push_back(midEntrance);
	roomExit *midExtra = new roomExit(mid, extra);
	entities.push_back(midExtra);
	roomExit *entranceExterior = new roomExit(entrance, exterior);
	entranceExterior->locked = true;
	entities.push_back(entranceExterior);

	// Linking room exits with their rooms
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
void world::goNorth() 
{
	// Check exit exists
	if (character->containedIn->north == NULL) {
		std::cout << "\n You can not go anywhere in that direction\n";
	}
	else if (character->containedIn->north->locked == true)
	{
		std::cout << "That door is locked! \n";
	}
	else 
	{
		if (character->containedIn->north->endA->name.compare(character->containedIn->name) == 0)
		{
			character->containedIn = character->containedIn->north->endB;
		}
		else 
		{
			character->containedIn = character->containedIn->north->endA;
		}

		world::playerLook();
	}
}
void world::goSouth()
{
	// Check exit exists
	if (character->containedIn->south == NULL) {
		std::cout << "\n You can not go anywhere in that direction\n";
	}
	else if (character->containedIn->south->locked == true)
	{
		std::cout << "That door is locked! \n";
	}
	else
	{
		if (character->containedIn->south->endA->name.compare(character->containedIn->name) == 0)
		{
			character->containedIn = character->containedIn->south->endB;
		}
		else
		{
			character->containedIn = character->containedIn->south->endA;
		}

		world::playerLook();
	}
}
void world::goWest()
{
	// Check exit exists
	if (character->containedIn->west == NULL) {
		std::cout << "\n You can not go anywhere in that direction\n";
	}
	else if (character->containedIn->west->locked == true)
	{
		std::cout << "That door is locked! \n";
	}
	else
	{
		if (character->containedIn->west->endA->name.compare(character->containedIn->name) == 0)
		{
			character->containedIn = character->containedIn->west->endB;
		}
		else
		{
			character->containedIn = character->containedIn->west->endA;
		}

		world::playerLook();
	}
}
void world::goEast()
{
	// Check exit exists
	if (character->containedIn->east == NULL) {
		std::cout << "\n You can not go anywhere in that direction\n";
	}
	else if (character->containedIn->east->locked == true)
	{
		std::cout << "That door is locked! \n";
	}
	else
	{
		if (character->containedIn->east->endA->name.compare(character->containedIn->name) == 0)
		{
			character->containedIn = character->containedIn->east->endB;
		}
		else
		{
			character->containedIn = character->containedIn->east->endA;
		}

		world::playerLook();
	}
}