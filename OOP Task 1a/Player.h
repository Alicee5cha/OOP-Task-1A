#pragma once
#include <string>
#include "Score.h"
using namespace std;
class Player
{
public:
	Player(string name);
	//Query
	string get_name() const;
	int get_score() const;
	//Update
	void update_score(int amount);
private://Data
	string name;
	Score score;

};