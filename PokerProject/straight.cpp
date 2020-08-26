#include "straight.h"
#include <vector>
#include <string>
#include "Power.h"
#include "PokerHandType.h"
#include "Result.h"
#include "Utility.h"


straight::straight(std::vector <char> cards) : Power(cards)
{
    sila = STRAIGHT;
}

Result straight::Compare(Power& other)
{
    if (other.sila != sila) return other.sila < sila ? Result::Win : Result::Loss;
    for (int i = 0; i < 5; i++)
    {
        if (cards[i] != other.cards[i]) return LessThan(cards[i], other.cards[i]) ? Result::Loss : Result::Win;
    }
    return Result::Tie;
}