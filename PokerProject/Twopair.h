#pragma once
#include <vector>
#include "Power.h"

class Twopair :public Power
{
public:
    Twopair(std::vector <char> cards);
    virtual Result Compare(Power& other);
};

