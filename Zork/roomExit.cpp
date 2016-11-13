#include "stdafx.h"
#include "roomExit.h"


roomExit::roomExit(room* endA, room* endB): endA(endA), endB(endB)
{
	type = EXIT;
}


roomExit::~roomExit()
{
}
