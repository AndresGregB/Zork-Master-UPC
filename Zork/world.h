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
};

