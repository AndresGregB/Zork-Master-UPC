#pragma once
#include "entity.h"
class room;

class player :
	public entity
{
public:
	player(room* containedIn);
	~player();
	void player::addToInventory(entity* item);
	bool foundKey;
	bool lockedinCell;
	std::list<entity*> inventory;
	room* containedIn;
	int inventoryItems;
};

