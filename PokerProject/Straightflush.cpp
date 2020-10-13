#include "Straightflush.h"
#include <vector>
#include <string>
#include "Power.h"
#include "PokerHandType.h"
#include "Result.h"
#include "Utility.h"


Straightflush::Straightflush(std::vector <char> cards) : Power(cards) {
	sila = STRAIGHTFLUSH;
};

//The function takes parameter of type Power and returns parameter of type Result.
Result Straightflush::Compare(Power& other)
{
    if (other.sila != sila) return other.sila < sila ? Result::Win : Result::Loss;
    for (int i = 4; i >= 0; i--)
    {
        if (cards[i] != other.cards[i]) return LessThan(cards[i], other.cards[i]) ? Result::Loss : Result::Win;
    }
    return Result::Tie;
}


