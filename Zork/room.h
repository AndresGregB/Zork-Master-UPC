#pragma once
#include "entity.h"
class room :
	public entity
{
public:
	room(const char* name, const char* description, entity* containedIn);
	~room();
};

