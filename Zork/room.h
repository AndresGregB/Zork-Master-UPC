
#include "entity.h"

class roomExit;
class room :
	public entity
{
public:
	room(const char* name, const char* description, entity* containedIn);
	~room();

	roomExit* north;
	roomExit* south;
	roomExit* east;
	roomExit* west;

};

