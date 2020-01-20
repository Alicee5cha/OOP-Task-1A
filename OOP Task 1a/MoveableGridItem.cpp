#include "MoveableGridItem.h"

RandomNumberGenerator MoveableGridItem::rng = RandomNumberGenerator();


MoveableGridItem::MoveableGridItem(int x, int y, const char symbol) :x(x),y(y),GridItem(symbol)
{

}

int MoveableGridItem::get_x() const
{
	return x;
}

int MoveableGridItem::get_y() const
{
	return y;
}

bool MoveableGridItem::is_at_position(int x, int y)const
{
	return (this->x == x && this->y == y);
}

void MoveableGridItem::reset_position()
{
	x = rng.get_random_value(SIZE);
	y = rng.get_random_value(SIZE);
}


void MoveableGridItem::update_position(int dx, int dy)
{
	this->x += dx;
	this->y += dy;
}

void MoveableGridItem::move_to_position(int x, int y)
{
	this->x = x;
	this->y = y;
}