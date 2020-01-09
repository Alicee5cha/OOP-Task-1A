#pragma once

#include "Mouse.h"
#include "RandomNumberGenerator.h"

class Snake {
public:
	Snake();
	bool has_caught_mouse() const;
	void spot_mouse(Mouse* const p_mouse);
	void chase_mouse();

	int getY() const;
	int getX() const;
	char getSymbol() const;
	RandomNumberGenerator getRNG() const;

private: // util functions
	bool is_at_position(const int x, const int y) const;
	void set_direction(int& dx, int& dy);
	void update_position(int dx, int dy);
	void position_at_random();

private: // data
	const char symbol = SNAKEHEAD;
	Mouse* p_mouse;
	int x, y;
	static RandomNumberGenerator rng;
};