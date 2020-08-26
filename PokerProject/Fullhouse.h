#pragma once
#include "Power.h"
#include <vector>

class Fullhouse:public Power
{
public:
	Fullhouse(std::vector <char> cards);
	virtual Result Compare(Power& other);
};

