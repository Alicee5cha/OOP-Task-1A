#pragma once
#include "Constants.h"

class GridItem {
protected:
	const char symbol;
public:
	const char get_symbol() const;
	GridItem(const char symbol);
};