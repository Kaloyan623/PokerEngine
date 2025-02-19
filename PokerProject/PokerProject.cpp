// PokerProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include "PokerHandType.h"
#include "flush.h"
#include "four.h"
#include "Fullhouse.h"
#include "Nonepower.h"
#include "Onepair.h"
#include "Power.h"
#include "Result.h"
#include "straight.h"
#include "Straightflush.h"
#include "tree.h"
#include "Twopair.h"
#include "Utility.h"
#include "PokerHand.h"
using namespace std;

//The function takes two parameters of type PokerHand and returns parameter of type Result.
__declspec(dllexport) Result compare(const PokerHand& player, const PokerHand& opponent)
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
