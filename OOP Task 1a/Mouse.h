#pragma once

#include "Underground.h"
#include "MoveableGridItem.h"
#include "Nut.h"
#include "RandomNumberGenerator.h"

class Mouse:public MoveableGridItem
{
	public:
		// constructor
		Mouse();

		// accessors
		bool is_alive() const;
		bool has_escaped() const;
		bool has_reached_a_hole(const Underground ug) const;
		bool can_collect_nut(Nut nut)const;
		// mutators
		void die();
		void escape_into_hole();
		void scamper(int key);

	private:
		// data members
		bool alive = true;
		bool escaped = false;
		int mouse_dx = 0;
		int mouse_dy = 0;
		static RandomNumberGenerator rng;

		// supporting functions 
		void position_in_middle_of_grid();
		void update_position(int dx, int dy);


};