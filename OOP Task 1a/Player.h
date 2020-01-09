#pragma once
#include <string>
#include "Score.h"
using namespace std;
class Player
{
public:
	Player();
	//Query
	string get_name() const;
	int get_score() const;
	//Update
	void update_score(int amount);
	void set_name();
private://Data
	string name;
	Score score;

};