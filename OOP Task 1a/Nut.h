#pragma once
#include "MoveableGridItem.h"
#include "RandomNumberGenerator.h"

class Nut:public MoveableGridItem
{
private:
	bool collected = false;
	static RandomNumberGenerator rng;
public:
	Nut();
	bool has_been_collected() const;
	void disappear();
	RandomNumberGenerator getRNG() const;

};

