#pragma once
#include <list>
#include <string>
enum types
{
	ENTITY,
	WORLD,
	ROOM,
	ITEM,
	EXIT,
	PLAYER

};
class entity
{
public :
	entity(const char* name, const char* description, entity* containedIn);
	entity();
	virtual ~entity();
	virtual void look() const;
	void changeContainedIn(entity* newContainedIn);

	std::string description;
	std::string name;

	entity* containedIn;
	std::list<entity*> contains;
	types type;
};

