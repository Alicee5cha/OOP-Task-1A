#include "Nut.h"

Nut::Nut(int x, int y):MoveableGridItem(x,y,NUT)
{

}

bool Nut::has_been_collected() const
{
	return true;
}

void Nut::disappear()
{

}
