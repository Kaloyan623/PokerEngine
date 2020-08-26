#pragma once
#include "Power.h"
#include <vector>

class tree:public Power
{
public:
	tree(std::vector <char> cards);
	Result Compare(Power& other);
};

