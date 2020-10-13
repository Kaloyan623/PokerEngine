#include "Fullhouse.h"
#include <vector>
#include <string>
#include "Power.h"
#include "PokerHandType.h"
#include "Result.h"
#include "Utility.h"

Fullhouse::Fullhouse(std::vector <char> cards) : Power(cards)
{
    sila = FULLHOUSE;
}

//The function is expecting parameter of type Power and returns parameter of type Result.
 Result Fullhouse::Compare(Power& other)
{
    if (other.sila != sila) return other.sila < sila ? Result::Win : Result::Loss;
    for (int i = 0; i < 5; i++)
    {
        if (cards[i] != other.cards[i]) return LessThan(cards[i], other.cards[i]) ? Result::Loss : Result::Win;
    }
    return Result::Tie;
}
