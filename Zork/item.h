#pragma once
#include "entity.h"
class item :
	public entity
{
public:
	item(const char* name, const char* desc, const char* use);
	~item();
	void item::useitem();
	std::string useItemDesc;
};

