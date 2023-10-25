#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\USER\source\repos\NaturalFraction\NaturalFraction\NaturalFraction.h"
#include "string" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		    NaturalFraction a(3, 2, 4);
			NaturalFraction b(-1, 1, -2);
			NaturalFraction d(1, -1, 2);
			NaturalFraction t, g, h;
			NaturalFraction c = a + b;
			t = b - b;
			c += b;
			c -= b;
			c += 5;
			c -= 12;
			c = c * d;
			c = c / d;
			c *= d;
			c /= d;
			c *= 5;
			c /= 5;
			++c;
			--c;
			t = g++;
			c += t;
			c += g;
			t = g--;
			c -= t;
			c -= g;
			h = c + 3;
			h = c - 2;
			h = c * 2;
			h = c / 2;
			c = h;

			Assert::AreEqual(-1, c.getIntPart());
		}

		TEST_METHOD(TestMethod2)
		{
			NaturalFraction a(12, -3, 4);
			Assert::AreEqual(-12.75, a.toDouble());
		}

		TEST_METHOD(TestMethod3)
		{
			NaturalFraction a(3, 2, 4);
			NaturalFraction b(-1, 1, -2);
			NaturalFraction c(3, 2, 4);
			NaturalFraction e(0, 2, 4);
			NaturalFraction f(4, 0, 1);
			int d = 0;
			if (a > 3 && a > b && a >= c && a >= b && f >= 4 && a >= 3 && b < 2 && b < a && a <= c && a <= f && f <= 4 && a <= 4 && f == 4 && a == c && a != 4 && a != f ) d = 1;
		    Assert::AreEqual(1, d);
		}

		TEST_METHOD(TestMethod4)
		{   
			NaturalFraction a(3, 2, 4);

			Assert::AreEqual(3, a.getIntPart());
			Assert::AreEqual(1, a.getNumerator());
			Assert::AreEqual(2, a.getDenominator());
		}

		TEST_METHOD(TestMethod5)
		{
			NaturalFraction a(3, 2, 4);
			a.setNaturalFraction(8,3,7);

			Assert::AreEqual(8, a.getIntPart());
			Assert::AreEqual(3, a.getNumerator());
			Assert::AreEqual(7, a.getDenominator());


		}

		TEST_METHOD(TestMethod6)
		{
			NaturalFraction a(3, 1, 2);
			a.putAwayIntPart(a);

			Assert::AreEqual(7, a.getNumerator());

		}
        
	};
}
