#include "Underground.h"

//
//Hole::Hole(int x, int y) :x(x),y(y)
//{
//	//symbol = HOLE;
//	//this->x = x;
//	//this->y = y;
//}
//
//int Hole::get_x() const
//{
//	return x;
//}
//
//int Hole::get_y() const
//{
//	return y;
//}
//
//char Hole::get_symbol() const
//{
//	return symbol;
//}
//
//bool Hole::is_at_position(int x, int y) const
//{
//	return this->x == x && this->y == y;
//}

// number of holes in underground
//static const int MAXHOLES(3);

Underground::Underground()
{
	//holes.push_back(Hole(4, 3));
	//holes.push_back(Hole(15, 10));
	//holes.push_back(Hole(7, 15));

}

//Hole Underground::get_hole_no(int no) const
//{
//	// pre-condition: valid hole number
//	assert(is_valid_hole_number(no));
//
//	return holes.at(no);
//}

//void Underground::set_hole_no_at_position(int no, int x, int y)
//{
//	// pre-condition: valid hole number
//	assert(is_valid_hole_number(no));
//
//	Hole h(x, y);
//
//	switch (no)
//	{
//		case 0: holes.at(0) = h; break;
//		case 1: holes.at(1) = h; break;
//		case 2: holes.at(2) = h; break;
//	}
//}

bool Underground::is_valid_hole_number(const int no) const
{
	return no >= 0 && no < (int)holes.size();
}

//vector<Hole> Underground::getHoles()
//{
//	return holes;
//}

//const int Underground::getNumberOfHoles() const
//{
//	return holes.size();
//}

bool Underground::is_at_hole(const int x,const int y) const
{
	for (int i = 0; i < holes.size(); i++)
	{
		if (holes[i].is_at_position(x,y))
			return true;
	}
	return false;
}

vector<int> Underground::get_next_hole_coordinates(const int x, const int y)
{
	vector<int> temp = { 0,0 };
	
	for (int i = 0; i < holes.size(); i++)
	{
		if (holes[i].get_x() == x && holes[i].get_y()==y)
		{
			temp[0] = holes[(i + 1) % 3].get_x();
			temp[1] = holes[(i + 1) % 3].get_y();
		}
	}
}