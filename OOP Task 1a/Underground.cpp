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
