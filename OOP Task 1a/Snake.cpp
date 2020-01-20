#include "Snake.h"
#include "Mouse.h"
#include "RandomNumberGenerator.h"

//RandomNumberGenerator Snake::rng = RandomNumberGenerator();


Snake::Snake(Mouse* const p_mouse) :p_mouse(p_mouse), MoveableGridItem(rng.get_random_value(SIZE), rng.get_random_value(SIZE), SNAKEHEAD)
{
	add_parts_to_tail();
}

void Snake::add_parts_to_tail()
{
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

			//identify direction of travel
			set_direction(snake_dx, snake_dy);
			
			//Move tail
			if (!(snake_dx==0 && snake_dy==0))
				move_tail();

			//Save current location
			set_px_set_py(x, y);

			//go in the direction of travel
			update_position(snake_dx, snake_dy);
}


void Snake::set_direction(int& dx, int& dy)
{
	// pre-condition: The snake needs to know where the mouse is 
	assert(p_mouse != nullptr);

	// assume snake only moves when necessary
	dx = 0; dy = 0;

	// update coordinate if necessary
	if (x < p_mouse->get_x() )         // if snake on left of mouse and a tail isn't immediately to the right
		dx = 1;                        // snake should move right
	else if (x > p_mouse->get_x())    // if snake on right of mouse and a tail isn't immediately to the left
		dx = -1;						       // snake should move left

	if (y < p_mouse->get_y())         // if snake is above mouse and a tail isn't immediately below
		dy = 1;                        // snake should move down
	else if (y > p_mouse->get_y())    // if snake is below mouse and a tail isn't immediately above
		dy = -1;						       // snake should move up

	if (is_at_tail(x + dx, y + dy))
	{
		dy = 0; 
		dx = 0;
	}
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
		tail[t].set_px_set_py(tail[t].get_x(), tail[t].get_y());
		tail[t].move_to_position(tail[t-1].get_x(), tail[t-1].get_y());
	}
	tail[0].set_px_set_py(tail[0].get_x(),tail[0].get_y());
	tail[0].move_to_position(x, y);
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



void Snake::undo_tail()
{
	for (int i = tail.size()-1;i>=0;i--)
		tail[i].undo_actions();
	//for each (MoveableGridItem t in tail)
	//{
	//	t.undo_actions();
	//}
}