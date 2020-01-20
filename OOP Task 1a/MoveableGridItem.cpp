#include "MoveableGridItem.h"

MoveableGridItem::MoveableGridItem(int x, int y, const char symbol) :x(x),y(y),px(x),py(y),GridItem(symbol)
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

int MoveableGridItem::get_px() const
{
	return px;
}

int MoveableGridItem::get_py() const
{
	return py;
}

void MoveableGridItem::set_px_set_py(int px, int py)
{
	this->px = px;
	this->py = py;
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

void MoveableGridItem::undo_position(int dx, int dy)
{
	this->x -= dx;
	this->y -= dy;
}
}

void MoveableGridItem::move_to_position(int x, int y)
{
	this->x = x;
	this->y = y;
}