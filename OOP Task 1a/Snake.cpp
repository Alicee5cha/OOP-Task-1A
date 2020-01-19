#include "Snake.h"
#include "Mouse.h"
#include "RandomNumberGenerator.h"

RandomNumberGenerator Snake::rng = RandomNumberGenerator();


Snake::Snake():p_mouse(nullptr),MoveableGridItem(rng.get_random_value(SIZE), rng.get_random_value(SIZE),SNAKEHEAD)
{
	for (int i = 0; i < 3; i++)
	{
		MoveableGridItem tail_piece = MoveableGridItem(x,y,SNAKETAIL);
		tail.push_back(tail_piece);
	}

}

bool Snake::has_caught_mouse() const
{
	return is_at_position(p_mouse->get_x(), p_mouse->get_y());
}

void Snake::spot_mouse(Mouse* const p_mouse)
{
	// pre-condition: the mouse needs to exist 
	assert(p_mouse != nullptr);

	this->p_mouse = p_mouse;
}

void Snake::chase_mouse()
{
	int snake_dx, snake_dy;

	//identify direction of travel
	set_direction(snake_dx, snake_dy);

	//go in that direction
	update_position(snake_dx, snake_dy);

}

void Snake::set_direction(int& dx, int& dy)
{
	// pre-condition: The snake needs to know where the mouse is 
	assert(p_mouse != nullptr);

	// assume snake only moves when necessary
	dx = 0; dy = 0;

	// update coordinate if necessary
	if (x < p_mouse->get_x())         // if snake on left of mouse
		dx = 1;                        // snake should move right
	else if (x > p_mouse->get_x())    // if snake on left of mouse
		dx = -1;						       // snake should move left

	if (y < p_mouse->get_y())         // if snake is above mouse
		dy = 1;                        // snake should move down
	else if (y > p_mouse->get_y())    // if snake is below mouse
		dy = -1;						       // snake should move up
}

void Snake::update_position(int dx, int dy)
{
	move_tail();
	x += dx;
	y += dy;
}

void Snake::position_at_random()
{
	// WARNING: this may place on top of other things
	x = rng.get_random_value(SIZE);
	y = rng.get_random_value(SIZE);
}

void Snake::move_tail()
{
	for (int i = 2; i > 0; i--)
	{
		tail[i].update_position(tail[i - 1].get_x(), tail[i - 1].get_y());
	}

	tail[0].update_position(x, y);

}

RandomNumberGenerator Snake::getRNG() const
{
	return rng;
}