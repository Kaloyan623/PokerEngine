#include "Utility.h"
#include <string>
#include <vector>
using namespace std;

int indexOf(std::string& text, char pattern)
{
    // where appears the pattern in the text?
    std::string::size_type loc = text.find(pattern, 0);
    if (loc != std::string::npos)
    {
        return loc;
    }
    else
    {
        return -1;
    }
}

bool LessThan(const char& a, const char& b)
{
    static std::string karti = "23456789TJQKA";
    int ileft = indexOf(karti, a);
    int iright = indexOf(karti, b);
    return ileft < iright;
}

bool Podred(char left, char right)
{
    if (left == 'A' && right == '2')
    {
        return true;
    }
    static string karti = "23456789TJQKA";
    int ileft = indexOf(karti, left);
    int iright = indexOf(karti, right);
    return ileft == iright - 1;

};


bool IsStraightFlush(vector<char> cards, vector<char> boi)
{
    // priemame che cards sa sortnati
    for (int i = 0; i < 4; i++)
    {
        if (boi[i] != boi[i + 1]) return false;
        if (!Podred(cards[i], cards[i + 1])) return false;
    }
    return true;

};

bool IsFlush(vector <char> boi)
{
    for (int i = 0; i < 4; i++)
    {
        if (boi[i] != boi[i + 1]) return false;
    }
    return true;
};

bool IsFullHouse(vector <char> cards)
{
    bool isPair = false;
    bool isTree = false;
    for (int i = 0; i < cards.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < cards.size(); j++)
        {
            if (i != j && cards[i] == cards[j])
            {
                count++;
            }
        }
        if (count == 1)
        {
            isPair = true;
        }
        if (count == 2)
        {
            isTree = true;
        }
    }
    if (isPair && isTree)
    {
        return true;
    }
    return false;
};

bool isFour(vector <char> cards)
{
    for (int i = 0; i < cards.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < cards.size(); j++)
        {
            if (cards[i] == cards[j] && i != j)
            {
                count++;
            }
        }
        if (count == 3)
        {
            return true;
        }
    }
    return false;
};

bool IsStraight(vector <char> cards)
{
    if (cards[0] == '2' && cards[1] == '3' && cards[2] == '4' && cards[3] == '5' && cards[4] == 'A')
    {
        return true;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!Podred(cards[i], cards[i + 1])) return false;
    }
    return true;
};

bool IsTree(vector <char> cards)
{
    for (int i = 0; i < cards.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < cards.size(); j++)
        {
            if (i != j && cards[i] == cards[j])
            {
                count++;
            }
        }
        if (count == 2)
        {
            return true;
        }
    }
    return false;
};

bool IsTwoPairs(vector <char> cards)
{
    int count = 0;
    for (int i = 0; i < cards.size(); i++)
    {
        for (int j = i + 1; j < cards.size(); j++)
        {
            if (i != j && cards[i] == cards[j])
            {
                count++;
            }
        }
        if (count == 2)
        {
            return true;
        }
    }
    return false;
};

bool IsPair(vector <char> cards)
{
    for (int i = 0; i < cards.size(); i++)
    {
        for (int j = 0; j < cards.size(); j++)
        {
            if (i != j && cards[i] == cards[j])
            {
                return true;
            }
        }
    }
    return false;
};