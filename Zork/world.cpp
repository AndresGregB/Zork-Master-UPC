#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include "world.h"
#include "room.h"
#include "roomExit.h"
#include "player.h"
#include "item.h"
#include <vector>

world::world()
{
	type = WORLD;

	// Rooms
	/*-------------------------------------------------------//
		Exterior
		__|  |__ <- Way out (win)
	   |        |					N
	   |Entrance|				  W   E
	   |__    __|				    S
		__|  |__    ______
	   |        |__|      |
	   |  Mid    __ Extra |	<- Key is here
	   |__    __|  |______|
		__|  |__
	   |        |
	   |  Deep  | <- You start here
	   |________|
	//-------------------------------------------------------*/
	room* deep = new room("Captive Cell", "When you wake up you find yourself in a prisoner cell. You feel the urge to escape. After a while you notice a rusted key on the floor \n", this);
	room* mid = new room("Mid Room", "This room seems to be the main room of the dungeon. There are exits at North, South and East. \n", this);
	room* entrance = new room("Entrance to Dungeon", "There is a door by the north side of the room, its probably closed, there is also an exit to the south \n", this);
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

	// Items
	item* cellKey = new item("Cell Key", "It's a really used key, many people have used it, you can gess many people have been trapped just like you were","With a soft crack the cell opens...");
	item* dungeonKey = new item("Dungeon Key", "The use of this key seems obvious, hurry up! get out of here!", "As you open the heavy door you feel the warm light of the sun on your skin, oh boy it feels great to be free!");
	item* pots = new item("Pots", "They are dusty and not really used, there is a key in one of them", "You broke it!");

	deep->contains.push_back(cellKey);
	cellKey->containedIn = deep;

	pots->contains.push_back(dungeonKey);
	dungeonKey->containedIn = pots;

	extra->contains.push_back(pots);
	pots->containedIn = extra;

	contains.push_back(cellKey);
	contains.push_back(dungeonKey);
	contains.push_back(pots);
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
void world::processCommand(const char* command) 
{
	std::string aux(command);
	std::stringstream stream(aux);
	std::string buffer;
	std::vector<std::string> arguments;
	while (stream >> buffer) {
		arguments.push_back(buffer.c_str());
	} 
	if (arguments.size() > 2) 
	{
		std::cout << "To many arguments, please use commands with only two arguments\n";
	}
	else {
		if (arguments[0].compare("look") == 0) {
			lookAt(arguments[1].c_str());
		}
		else if (arguments[0].compare("take") == 0) {
			takeThat(arguments[1].c_str());
		}
		else if (arguments[0].compare("use") == 0) {
			useThat(arguments[1].c_str());
		}
		else if (arguments[0].compare("drop") == 0) {
			dropThat(arguments[1].c_str());
		}
		else {
			std::cout << "That command is not valid! Try using help for a list of commands\n";
		}
	}
}
void world::help() 
{
		std::cout << "The lists of commands you can use are: \n";
		std::cout << "help \n";
		std::cout << "look \n";
		std::cout << "take \n";
		std::cout << "use \n";
		std::cout << "quit \n";
}
void world::lookAt(const char* argument) 
{
	// acceder a la lista de elementos de la habitacion y buscar uno con el mismo nombre que el argumento
	// Si se encuentra mostrar su descripcion
	// Si no se encuentra printar "there is no such thing on sight"
}
void world::takeThat(const char* argument)
{
	// acceder a la lista de elementos de la habitacion
	// buscar elemento con nombre de argumento
	//  si se encuentra añadir elemento al inventario del jugador y eliminarlo de la lista de elementos en la habitacion, cambiar el "contained in" del elemento
	// si no se encuentra mensaje de fallo
}
void world::useThat(const char* argument)
{
	// buscar en la lista del inventario del jugador
	// si se encuentra usar (solo se podran usar las llaves en la celda y la salida)
	// si no se encuentra dar mensaje de error
}
void world::dropThat(const char* argument)
{
	// buscar item en inventario
	// dejarlo en la habitacion
	bool found = false;
	std::list<entity*>::iterator iter;
	for (iter = character->inventory.begin(); iter != character->inventory.end(); ++iter) {
		std::cout << *iter;
	}
}