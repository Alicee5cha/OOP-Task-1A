#include "Nut.h"

Nut::Nut(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Nut::get_x()
{
	return x;
}

int Nut::get_y()
{
	return y;
}

char Nut::get_symbol()
{
	return symbol;

}

bool Nut::has_been_collected()
{
	return true;
}

bool Nut::is_at_position(int x, int y) 
{
	return (this->x == x) && (this->y == y);
}

void Nut::disappear()
{

}
