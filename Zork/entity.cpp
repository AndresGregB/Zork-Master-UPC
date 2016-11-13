#include "stdafx.h"
#include <iostream>
#include "entity.h"


entity::entity(const char* name, const char* description, entity* containedIn):name(name), description(description), containedIn(containedIn)
{
	type = ENTITY;
}
entity::entity() {}

entity::~entity()
{
	for (std::list<entity*>::iterator iter = contains.begin(); iter != contains.end(); ++iter)
		delete *iter;
	contains.clear();
}

void entity::look() const
{
	std::cout << description << "\n";
}
void entity::changeContainedIn(entity* newContainedIn)
{
	containedIn = newContainedIn;
}