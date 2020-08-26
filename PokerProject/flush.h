#pragma once
#include <vector>
#include "Power.h"

class flush:public Power
{
public:
	flush(std::vector <char> cards);
	virtual Result Compare(Power& other);
};

