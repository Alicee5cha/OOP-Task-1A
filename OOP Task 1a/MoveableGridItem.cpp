#include "MoveableGridItem.h"

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

void MoveableGridItem::reset_position(int x, int y)
{
	this->x = x;
	this->y = y;
}

void MoveableGridItem::update_position(int dx, int dy)
{
	this->x += dx;
	this->y += dy;
}