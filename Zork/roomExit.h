#pragma once
#include "entity.h"
class room;

class roomExit :
	public entity
{
public:
	roomExit(room* endA, room* endB);
	~roomExit();

	room* endA;
	room* endB;
};

