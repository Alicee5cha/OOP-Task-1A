#include "Nut.h"

Nut::Nut():MoveableGridItem(10,5,NUT)
{

}

bool Nut::has_been_collected() const
{
	return true;
}

void Nut::disappear()
{
	collected = true;
}
