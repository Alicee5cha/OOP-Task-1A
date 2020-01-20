#pragma once

#include <cassert>
#include <vector>
#include "Hole.h"
using namespace std;


class Underground
{
private:
	//data
	const vector<Hole> holes = { Hole(4,3),Hole(15,10),Hole(7,15) };

	//fun
	bool is_valid_hole_number(const int n) const;

	public:
		Underground();
		//Hole get_hole_no(int no) const;
		vector<int> get_next_hole_coordinates(const int x, const int y);
		//void set_hole_no_at_position(int no, int x, int y);
		//const int getNumberOfHoles() const;
		bool is_at_hole(const int x, const int y) const;
	
};