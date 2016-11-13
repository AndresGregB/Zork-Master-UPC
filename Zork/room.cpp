#include "stdafx.h"
#include "room.h"


room::room(const char* name, const char* description, entity* containedIn):entity(name, description, containedIn)
{
	type = ROOM;
	north = NULL;
	south = NULL;
	east = NULL;
	west = NULL;
}


room::~room()
{
}
