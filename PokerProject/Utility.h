#pragma once
#include <vector>
#include <string>

int indexOf(std::string& text, char pattern);
bool LessThan(const char& a, const char& b);
bool IsStraightFlush(std::vector<char> cards, std::vector<char> boi);
bool Podred(char left, char right);
bool IsFlush(std::vector <char> boi);
bool IsFullHouse(std::vector <char> cards);
bool isFour(std::vector <char> cards);
bool IsStraight(std::vector <char> cards);
bool IsTree(std::vector <char> cards);
bool IsTwoPairs(std::vector <char> cards);
bool IsPair(std::vector <char> cards);

