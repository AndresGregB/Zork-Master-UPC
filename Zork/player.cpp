#include "stdafx.h"
#include "player.h"

player::player(room* containedIn)
{
	this->containedIn = containedIn;
	inventory.push_back(new entity());
	foundKey = false;
	lockedinCell = true;
	inventoryItems = 0;
}


player::~player()
{
}

void player::addToInventory(entity* item) 
{
	inventory.push_back(item);
	inventoryItems++;
}