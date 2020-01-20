#pragma once
#include "GridItem.h"
#include "RandomNumberGenerator.h"
class MoveableGridItem:public GridItem
{
protected:
	int x, y;
	static RandomNumberGenerator rng;

public:
	//Query
	int get_x() const;
	int get_y() const;
	bool is_at_position(int x, int y)const;
	//Update
	MoveableGridItem(int x, int y, const char symbol);
	void reset_position();
	void update_position(int dx, int dy);
	void move_to_position(int x, int y);

};