#include "four.h"
#include <vector>
#include <string>
#include "Power.h"
#include "Result.h"
#include "Utility.h"

four::four(std::vector <char> cards) : Power(cards)
{
    sila = FOUR;
}

Result four::Compare(Power& other)
{
    if (other.sila != sila) return other.sila < sila ? Result::Win : Result::Loss;
    for (int i = 4; i >= 0; i--)
    {
        if (cards[i] != other.cards[i]) return LessThan(cards[i], other.cards[i]) ? Result::Loss : Result::Win;
    }
    return Result::Tie;
}