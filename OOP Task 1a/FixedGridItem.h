#pragma once
#include "GridItem.h"
class FixedGridItem:public GridItem {
protected:
	const int x, y;
public:
	const int get_x()const;
	const int get_y()const;
	bool is_at_position(int x, int y) const;
	FixedGridItem(const int x, const int y, const char symbol);
};