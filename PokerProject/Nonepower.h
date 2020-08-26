#pragma once
#include <vector>
#include "Power.h"

class Nonepower:public Power
{
public:
    Nonepower(std::vector<char> cards);
    virtual Result Compare(Power& other);
};

