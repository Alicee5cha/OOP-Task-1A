#pragma once

#include <cassert>
#include <vector>
#include "Hole.h"
using namespace std;

//class Hole
//{
//	public:
//		// constructors
//		Hole(int x, int y);
//
//		// accessors
//		int get_x() const;
//		int get_y() const;
//		char get_symbol() const;
//		bool is_at_position(int x, int y) const;
//
//	private:
//		// data members
//		const char symbol = HOLE;
//		int x, y;
//};

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
		//vector<Hole> getHoles();
		//void set_hole_no_at_position(int no, int x, int y);
		//const int getNumberOfHoles() const;
		bool isAtHole(const int x, const int y) const;
	
};