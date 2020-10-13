#pragma once
#include "Power.h"


#ifdef POCKERPROJECT_CMPL
#define POCKERPROJECT_API __declspec(dllexport)
#else
#define POCKERPROJECT_API __declspec(dllimport)
#endif


 struct PokerHand
{
	Power* myPower;
	POCKERPROJECT_API PokerHand(const char* pokerhand);
};

