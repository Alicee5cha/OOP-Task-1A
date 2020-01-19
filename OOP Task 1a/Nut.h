#pragma once
class Nut
{
private:
	int x;
	int y;
	char symbol;
	bool collected;

public:
	Nut(int x, int y);
	int get_x();
	int get_y();
	char get_symbol();
	bool has_been_collected();
	bool is_at_position(int x, int y);
	void disappear();

};

