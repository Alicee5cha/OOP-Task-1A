#include "GridItem.h"

GridItem::GridItem(const char symbol) :symbol(symbol)
{

}

const char GridItem::get_symbol() const
{
	return symbol;
}