#include "pch.h"
#include "CppUnitTest.h"
#include "..\PokerProject\PokerHand.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


__declspec(dllimport) Result compare(const PokerHand& player, const PokerHand& opponent);


namespace PockerProjectTest
{
	TEST_CLASS(PockerProjectTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			PokerHand player("KH KD 2H 2D 6H");
			PokerHand oponent("AH AD 3H 3D 4H");
			Assert::IsTrue(compare(player, oponent)== Result::Tie,L"Acces beats kings");
		}

		TEST_METHOD(TestMethod2)
		{
			PokerHand player("AS AH AD 7S 4D");
			PokerHand oponent("KD KS QS QH 9S");
			Assert::IsTrue(compare(player, oponent) == Result::Win, L"Tree beats Twopairs");
		}

		TEST_METHOD(TestMethod3)
		{
			PokerHand player("KH KS KD TH JS");
			PokerHand oponent("TH JS QS KD AS");
			Assert::IsTrue(compare(player, oponent) == Result::Loss, L"Straight beats Tree");
		}
	};
}
