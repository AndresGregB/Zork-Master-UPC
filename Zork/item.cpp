#include "stdafx.h"
#include "item.h"


item::item(const char* name, const char* desc, const char* use)
{
	type = ITEM;
	description = desc;
	useItemDesc = use;
	this->name = name;
}


item::~item()
{
}

void item::useitem() 
{
}