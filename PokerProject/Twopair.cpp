#include "Twopair.h"
#include <vector>
#include "Power.h"
#include <string>
#include "Result.h"
#include "PokerHandType.h"
#include "Utility.h"


Twopair::Twopair(std::vector <char> cards) : Power(cards)
{
    sila = TWOPAIR;
}

//The function takes parameter of type Power and returns parameter of type Result.
Result Twopair::Compare(Power& other)
{
    if (other.sila != sila) return other.sila < sila ? Result::Win : Result::Loss;
    for (int i = 4; i >= 0; i--)
    {
        if (cards[i] != other.cards[i]) return LessThan(cards[i], other.cards[i]) ? Result::Loss : Result::Win;
    }
    return Result::Tie;
}
