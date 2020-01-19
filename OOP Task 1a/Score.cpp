#include "Score.h"

Score::Score():amount(0)
{

}

int Score::get_amount() const
{
	return amount;
}

void Score::update_amount(int addamount)
{
	amount += addamount;
}