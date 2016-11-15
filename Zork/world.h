#pragma once
#include "entity.h"
class player;
class world :
	public entity
{
public:
	world();
	~world();
	void playerLook();

	player* character;
	std::list<entity*> entities;

	void world::goNorth();
	void world::goWest();
	void world::goEast();
	void world::goSouth();
	void world::processCommand(const char* command);
	void world::help();
	void world::lookAt(const char* argument);
	void world::takeThat(const char* argument);
	void world::useThat(const char* argument);
	void world::dropThat(const char* argument);
};

