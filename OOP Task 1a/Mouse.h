#pragma once

#include "constants.h"
#include "Underground.h"

class Mouse
{
	public:
		// constructor
		Mouse();

		// accessors
		int get_x() const;
		int get_y() const;
		char get_symbol() const;
		bool is_alive() const;
		bool has_escaped() const;
		bool has_reached_a_hole(const Underground ug) const;

		// mutators
		void die();
		void escape_into_hole();
		void scamper(int key);



	private:
		// data members
		int  x, y;
		const char symbol = MOUSE;
		bool alive;
		bool escaped;
		bool is_at_position(int x, int y);
		int mouse_dx;
		int mouse_dy;

		// supporting functions 
		void position_in_middle_of_grid();
		void update_position(int dx, int dy);

};