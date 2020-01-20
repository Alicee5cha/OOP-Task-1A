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
		void reset();
	private:
		// data members
		bool alive;
		bool escaped;
		int mouse_dx;
		int mouse_dy;

};