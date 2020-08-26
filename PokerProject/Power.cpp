// Power.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include "Power.h"
#include "PokerHandType.h"
#include "Result.h"
#include "Utility.h"
using namespace std;



Power::Power(std::vector<char> org) : cards(org)
{
    sort(cards.begin(), cards.end(), LessThan);
};