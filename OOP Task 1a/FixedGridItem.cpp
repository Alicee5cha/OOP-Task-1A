#include "FixedGridItem.h"

FixedGridItem::FixedGridItem(const int x, const int y, const char symbol) :x(x),y(y),GridItem(symbol)
{

}

const int FixedGridItem::get_x() const
{
	return x;
}
const int FixedGridItem::get_y() const
{
	return y;
}
bool FixedGridItem::is_at_position(int x, int y) const
{
	return (this->x == x && this->y == y);
}