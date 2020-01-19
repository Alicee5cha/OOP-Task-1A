#pragma once
class Score
{
public:
	//Constructor
	Score();
	//Query
	int get_amount() const;
	//Update
	void update_amount(int amount);
private://Data
	int amount = 0;
};