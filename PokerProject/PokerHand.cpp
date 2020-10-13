#include "PokerHand.h"
#include "Utility.h"
#include "Power.h"
#include <vector>
#include <algorithm>
#include "Straightflush.h"
#include "flush.h"
#include "Fullhouse.h"
#include "four.h"
#include "straight.h"
#include "Nonepower.h"
#include "tree.h"
#include "Twopair.h"
#include "Onepair.h"

PokerHand::PokerHand(const char* pokerhand)
{
    std::vector <char> values;            //This is the vector for the values of the cards.
    std::vector <char> suits;             //This is the vector for the suits of the cards.
    char k1 = pokerhand[0];                  
    char b1 = pokerhand[1];
    char k2 = pokerhand[3];
    char b2 = pokerhand[4];
    char k3 = pokerhand[6];
    char b3 = pokerhand[7];
    char k4 = pokerhand[9];
    char b4 = pokerhand[10];
    char k5 = pokerhand[12];
    char b5 = pokerhand[13];
    values.push_back(k1);              
    values.push_back(k2);
    values.push_back(k3);
    values.push_back(k4);
    values.push_back(k5);
    suits.push_back(b1);
    suits.push_back(b2);
    suits.push_back(b3);
    suits.push_back(b4);
    suits.push_back(b5);

    sort(values.begin(), values.end(), LessThan);   //I am sorting the vector.
    if (IsStraightFlush(values, suits))
    {
        myPower = new Straightflush(values);
    }
    else if (IsFlush(suits))
    {
        myPower = new flush(values);
    }
    else if (IsFullHouse(values))
    {
        myPower = new Fullhouse(values);
    }
    else if (isFour(values))
    {
        myPower = new four(values);
    }
    else if (IsStraight(values))
    {
        myPower = new straight(values);
    }
    else if (IsTree(values))
    {
        myPower = new tree(values);
    }
    else if (IsTwoPairs(values))
    {
        myPower = new Twopair(values);
    }
    else if (IsPair(values))
    {
        myPower = new Onepair(values);
    }
    else
    {
        myPower = new Nonepower(values);
    }
}