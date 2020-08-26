#pragma once
#include <vector>
#include "Power.h"

class Straightflush:public Power
{
public:
	Straightflush(std::vector <char> cards);
	virtual Result Compare(Power& other);
};

