// PokerProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

enum class Result { Win, Loss, Tie };

enum PokerHandType
{
    NONE = 0,
    ONEPAIR = 1,
    TWOPAIR = 2,
    TREE = 3,
    STRAIGHT = 4,
    FLUSH = 5,
    FULLHOUSE = 6,
    FOUR = 7,
    STRAIGHTFLUSH = 8 

};

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
    static string karti = "23456789TJQKA";
    int ileft = indexOf(karti, a);
    int iright = indexOf(karti, b);
    return ileft < iright;
}


class Power
{
public:
    PokerHandType sila;
    vector<char> cards;
public:
    Power(vector<char> org) : cards(org)
    {
        sort(cards.begin(), cards.end(), LessThan);
    };
    virtual Result Compare(Power& other) = 0;
};

class NonePower :public Power
{

public:
    NonePower(vector<char> cards) : Power(cards)
    {
        sila = NONE;
    }
    virtual Result Compare(Power& other)
    {
        if (other.sila != sila) return other.sila < sila ? Result::Win : Result::Loss;
        for (int i = 4; i >= 0; i--)
        {
            if (cards[i] != other.cards[i]) return LessThan(cards[i], other.cards[i]) ? Result::Loss : Result::Win;
        }
        return Result::Tie;
    }
};

class OnePair :public Power
{
public:
    OnePair(vector <char> cards) : Power(cards)
    {
        sila = ONEPAIR;
    }
    virtual Result Compare(Power& other)
    {
        if (other.sila != sila) return other.sila < sila ? Result::Win : Result::Loss;
        for (int i = 4; i >= 0; i--)
        {
            if (cards[i] != other.cards[i]) return LessThan(cards[i], other.cards[i]) ? Result::Loss : Result::Win;
        }
        return Result::Tie;
    }
};

class TwoPair :public Power
{
public:
    TwoPair(vector <char> cards) : Power(cards)
    {
        sila = TWOPAIR;
    }
    virtual Result Compare(Power& other)
    {
        if (other.sila != sila) return other.sila < sila ? Result::Win : Result::Loss;
        for (int i = 4; i >= 0; i--)
        {
            if (cards[i] != other.cards[i]) return LessThan(cards[i], other.cards[i]) ? Result::Loss : Result::Win;
        }
        return Result::Tie;
    }
};

class Tree : public Power
{
public:
    Tree(vector <char> cards) : Power(cards)
    {
        sila = TREE;
    }
    virtual Result Compare(Power& other)
    {
        if (other.sila != sila) return other.sila < sila ? Result::Win : Result::Loss;
        for (int i = 4; i >= 0; i--)
        {
            if (cards[i] != other.cards[i]) return LessThan(cards[i], other.cards[i]) ? Result::Loss : Result::Win;
        }
        return Result::Tie;
    }

};

class Straight : public Power
{
public:
    Straight(vector <char> cards) : Power(cards)
    {
        sila = STRAIGHT;
    }
    virtual Result Compare(Power& other)
    {
        if (other.sila != sila) return other.sila < sila ? Result::Win : Result::Loss;
        for (int i = 0; i < 5; i++)
        {
            if (cards[i] != other.cards[i]) return LessThan(cards[i], other.cards[i]) ? Result::Loss : Result::Win;
        }
        return Result::Tie;
    }

};

class Flush : public Power
{
public:
    Flush(vector <char> cards) : Power(cards)
    {
        sila = FLUSH;
    }
    virtual Result Compare(Power& other)
    {
        if (other.sila != sila) return other.sila < sila ? Result::Win : Result::Loss;
        for (int i = 4; i >= 0; i--)
        {
            if (cards[i] != other.cards[i]) return LessThan(cards[i], other.cards[i]) ? Result::Loss : Result::Win;
        }
        return Result::Tie;
    }
};

class Four : public Power
{
public:
    Four(vector <char> cards) : Power(cards)
    {
        sila = FOUR;
    }
    virtual Result Compare(Power& other)
    {
        if (other.sila != sila) return other.sila < sila ? Result::Win : Result::Loss;
        for (int i = 4; i >= 0; i--)
        {
            if (cards[i] != other.cards[i]) return LessThan(cards[i], other.cards[i]) ? Result::Loss : Result::Win;
        }
        return Result::Tie;
    }

};

class FullHouse :public Power
{
public:
    FullHouse(vector <char> cards) : Power(cards)
    {
        sila = FULLHOUSE;
    }
    virtual Result Compare(Power& other)
    {
        if (other.sila != sila) return other.sila < sila ? Result::Win : Result::Loss;
        for (int i = 0; i < 5; i++)
        {
            if (cards[i] != other.cards[i]) return LessThan(cards[i], other.cards[i]) ? Result::Loss : Result::Win;
        }
        return Result::Tie;
    }
};

class StraightFlush : public Power
{
public:
    StraightFlush(vector <char> cards) : Power(cards)
    {
        sila = STRAIGHTFLUSH;
    }
    virtual Result Compare(Power& other)
    {
        if (other.sila != sila) return other.sila < sila ? Result::Win : Result::Loss;
        for (int i = 4; i >= 0; i--)
        {
            if (cards[i] != other.cards[i]) return LessThan(cards[i], other.cards[i]) ? Result::Loss : Result::Win;
        }
        return Result::Tie;
    }
};
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

struct PokerHand {
    Power* myPower;
    PokerHand(const char* pokerhand) {
        for (int i = 0; i < strlen(pokerhand); i++)
        {
            cerr << pokerhand[i];
            cerr << ' ';
        }
        cerr << endl;
        vector <char> values;
        vector <char> suits;
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

        sort(values.begin(), values.end(), LessThan);
        if (IsStraightFlush(values, suits))
        {
            myPower = new StraightFlush(values);
        }
        else if (IsFlush(suits))
        {
            myPower = new Flush(values);
        }
        else if (IsFullHouse(values))
        {
            myPower = new FullHouse(values);
        }
        else if (isFour(values))
        {
            myPower = new Four(values);
        }
        else if (IsStraight(values))
        {
            myPower = new Straight(values);
        }
        else if (IsTree(values))
        {
            myPower = new Tree(values);
        }
        else if (IsTwoPairs(values))
        {
            myPower = new TwoPair(values);
        }
        else if (IsPair(values))
        {
            myPower = new OnePair(values);
        }
        else
        {
            myPower = new NonePower(values);
        }
    }


};


Result compare(const PokerHand& player, const PokerHand& opponent)
{
    return player.myPower->Compare(*opponent.myPower);
}

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
