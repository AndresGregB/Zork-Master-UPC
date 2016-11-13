#include "stdafx.h"
#include "player.h"

player::player(room* containedIn)
{
	this->containedIn = containedIn;
	inventory = new entity[5];
	inventoryItems = 0;
}


player::~player()
{
}

void player::addToInventory(entity* item) 
{
	inventory[inventoryItems] = *item;
	inventoryItems++;
}