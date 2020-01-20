#pragma once
#include "Mouse.h"
#include "RandomNumberGenerator.h"
#include <vector>
#include "MoveableGridItem.h"

class Snake:public MoveableGridItem {
public:
	Snake(Mouse* const p_mouse);
	bool has_caught_mouse() const;
	//void spot_mouse(Mouse* const p_mouse);
	void chase_mouse();
	//RandomNumberGenerator getRNG() const;
	bool is_at_tail(const int x, const int y) const;
	bool has_cheated();
	bool undo_move();
	void undo_actions();

private: // util functions
	void set_direction(int& dx, int& dy);
	void position_at_random();
	void move_tail();

private: // data
	Mouse* p_mouse;
	//static RandomNumberGenerator rng;
	vector<MoveableGridItem> tail;
	bool cheated;
	bool undo_key;
	void add_parts_to_tail();

};