#include "Nut.h"

Nut::Nut():MoveableGridItem(rng.get_random_value(SIZE), rng.get_random_value(SIZE),NUT)
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
