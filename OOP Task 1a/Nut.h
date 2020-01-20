#pragma once
#include "MoveableGridItem.h"
class Nut:public MoveableGridItem
{
private:
	bool collected = false;
public:
	Nut();
	bool has_been_collected() const;
	void disappear();
};

