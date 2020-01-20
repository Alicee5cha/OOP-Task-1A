#include "Underground.h"

Underground::Underground()
{

}


bool Underground::is_valid_hole_number(const int no) const
{
	return (no >= 0 && no < (int)holes.size());
}


bool Underground::is_at_hole(const int x,const int y) const
{
	for (int i = 0; i < (int)holes.size(); i++)
	{
		if (holes[i].is_at_position(x,y))
			return true;
	}
	return false;
}

vector<int> Underground::get_next_hole_coordinates(const int x, const int y)
{
	vector<int> temp = { 0,0 };
	
	for (int i = 0; i < (int)holes.size(); i++)
	{
		if (holes[i].get_x() == x && holes[i].get_y() == y)
		{
			temp[0] = holes[(i + 1) % 3].get_x();
			temp[1] = holes[(i + 1) % 3].get_y();
			return temp;
		}
	}
	return temp;
}