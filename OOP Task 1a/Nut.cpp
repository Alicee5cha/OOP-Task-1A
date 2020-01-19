#include "Nut.h"

Nut::Nut():collected(false),MoveableGridItem(10,5,NUT)
{

}

bool Nut::has_been_collected() const
{
	return collected;
}

void Nut::disappear()
{
	collected = true;
}
