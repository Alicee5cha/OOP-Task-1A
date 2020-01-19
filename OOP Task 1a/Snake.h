#pragma once
#include "Mouse.h"
#include "RandomNumberGenerator.h"
#include <vector>
#include "MoveableGridItem.h"

class Snake:public MoveableGridItem {
public:
	Snake();
	bool has_caught_mouse() const;
	void spot_mouse(Mouse* const p_mouse);
	void chase_mouse();
	void undo_snake();

	RandomNumberGenerator getRNG() const;


private: // util functions
	void set_direction(int& dx, int& dy);
	void update_position(int dx, int dy);
	void position_at_random();
	void move_tail();


private: // data
	Mouse* p_mouse;
	static RandomNumberGenerator rng;
	vector<MoveableGridItem> tail;
	MoveableGridItem tail_piece = MoveableGridItem(x,y,SNAKETAIL);


};