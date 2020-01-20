#include "Snake.h"
#include "Mouse.h"
#include "RandomNumberGenerator.h"

//RandomNumberGenerator Snake::rng = RandomNumberGenerator();


Snake::Snake(Mouse* const p_mouse) :p_mouse(p_mouse), MoveableGridItem(rng.get_random_value(SIZE), rng.get_random_value(SIZE), SNAKEHEAD), cheated(false), undo_key(false)
{
	
}

void Snake::add_parts_to_tail()
{
	MoveableGridItem* me = this;
	tail.push_back(*me);
	for (int i = 0; i < 3; i++)
	{
		MoveableGridItem t(x, y, SNAKETAIL);
		tail.push_back(t);
	}
}

bool Snake::has_caught_mouse() const
{
	return is_at_position(p_mouse->get_x(), p_mouse->get_y());
}

//void Snake::spot_mouse(Mouse* const p_mouse)
//{
//	// pre-condition: the mouse needs to exist 
//	assert(p_mouse != nullptr);
//
//	this->p_mouse = p_mouse;
//}

void Snake::chase_mouse()
{
	int snake_dx, snake_dy;

			//Move tail
			move_tail();

			//identify direction of travel
			set_direction(snake_dx, snake_dy);

			//go in that direction
			update_position(snake_dx, snake_dy);
}

bool Snake::has_cheated()
{
	cheated = true;
	return cheated;
}

bool Snake::undo_move()
{
	undo_key = true;
	return undo_key;
}

void Snake::undo_actions()
{
	//undo_position(snake_dx, snake_dy);
}

void Snake::set_direction(int& dx, int& dy)
{
	// pre-condition: The snake needs to know where the mouse is 
	assert(p_mouse != nullptr);

	// assume snake only moves when necessary
	dx = 0; dy = 0;

	// update coordinate if necessary
	if (x < p_mouse->get_x() && !is_at_tail(x+1,y))         // if snake on left of mouse and a tail isn't immediately to the right
		dx = 1;                        // snake should move right
	else if (x > p_mouse->get_x() && !is_at_tail(x - 1, y))    // if snake on right of mouse and a tail isn't immediately to the left
		dx = -1;						       // snake should move left

	if (y < p_mouse->get_y() && !is_at_tail(x, y+1))         // if snake is above mouse and a tail isn't immediately below
		dy = 1;                        // snake should move down
	else if (y > p_mouse->get_y() && !is_at_tail(x,y-1))    // if snake is below mouse and a tail isn't immediately above
		dy = -1;						       // snake should move up
}

void Snake::position_at_random()
{
	// WARNING: this may place on top of other things
	x = rng.get_random_value(SIZE);
	y = rng.get_random_value(SIZE);
}

void Snake::move_tail()
{
	for (int t = (int) (tail.size())-1; t > 0;t--)
	{
		tail[t].move_to_position(tail[t-1].get_x(), tail[t-1].get_y());
	}
}

bool Snake::is_at_tail(const int x,const int y)const
{
	// is a snaketail at this position?
	for each (MoveableGridItem t in tail)
	{
		if (t.is_at_position(x,y))
		{
			return true;
		}
	}
	return false;
}


//RandomNumberGenerator Snake::getRNG() const
//{
//	return rng;
//}