#pragma once
#include "GridItem.h"

class MoveableGridItem:public GridItem
{
protected:
	int x, y, px, py;

public:
	//Query
	int get_x() const;
	int get_y() const;
	int get_px() const;
	int get_py() const;
	bool is_at_position(int x, int y)const;
	//Update
	MoveableGridItem(int x, int y, const char symbol);
	void reset_position(int x, int y);
	void update_position(int dx, int dy);
	void undo_position(int dx, int dy);
	void set_px_set_py(int px, int py);

};