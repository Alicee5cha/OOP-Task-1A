#pragma once
#include <string>
#include "Score.h"
using namespace std;
class Player
{
public:
	Player(string name);
	//Query
	const string get_name() const;
	int get_score() const;
	//Update
	void update_score(int amount);
private://Data
	const string name;
	Score score;

};