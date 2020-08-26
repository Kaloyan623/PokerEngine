#pragma once
#include <vector>
#include "Result.h"
#include "PokerHandType.h"
class Power
{
public:
    PokerHandType sila;
    std::vector<char> cards;
public:
    Power(std::vector<char> org);
    virtual Result Compare(Power& other) = 0;
};
