#include "Nut.h"

Nut::Nut():MoveableGridItem(10,5,NUT),collected(false)
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
