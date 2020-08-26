#pragma once
#include <vector>
#include "Power.h"


class Onepair:public Power
{
public:
    Onepair(std::vector <char> cards);
    virtual Result Compare(Power& other);
};

