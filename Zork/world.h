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
};

