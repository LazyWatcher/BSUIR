#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Student\source\repos\AOIS_lab1_\AOIS_lab1_\Header.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int n = 9, k = 2, p = 0;
			float b = 4.5, c = 2.25;
			int arr[8], arr2[8], arr3[8], arr4[8], arr5[8];
			ToBin(n, arr);
			ToReverse(arr, arr3);
			ToExtraBin(arr, arr4);
			ToBin(k, arr2);
			Addition(arr, arr2, arr5);
			p = ToTen(arr5);
			Assert::AreEqual(11, p);

		}
		TEST_METHOD(TestMethod2)
		{
			int n = 9, k = 2, p = 0;
			float b = 4.5, c = 2.25;
			int arr[8], arr2[8], arr3[8], arr4[8], arr5[8];
			ToBin(n, arr);
			ToReverse(arr, arr3);
			ToExtraBin(arr, arr4);
			ToBin(k, arr2);
			Subtraction(arr, arr2, arr5);
			p = ToTen(arr5);
			Assert::AreEqual(7, p);

		}
		TEST_METHOD(TestMethod3)
		{
			int n = 9, k = 2, p = 0;
			float b = 4.5, c = 2.25;
			int arr[8], arr2[8], arr3[8], arr4[8], arr5[8];
			ToBin(n, arr);
			ToReverse(arr, arr3);
			ToExtraBin(arr, arr4);
			ToBin(k, arr2);
			Multiplication(arr, arr2, arr5);
			p = ToTen(arr5);
			Assert::AreEqual(18, p);

		}
		TEST_METHOD(TestMethod4)
		{
			int n = 9, k = 2;
			double b = 4.5, c = 2.25;
			double p = 0;
			int arr[8], arr2[8], arr3[8], arr4[8], arr5[13];
			ToBin(n, arr);
			ToReverse(arr, arr3);
			ToExtraBin(arr, arr4);
			ToBin(k, arr2);
			Division(arr, arr2, arr5);
			p = ForFloatBin(arr5);
			Assert::AreEqual(4.5, b);

		}

		TEST_METHOD(TestMethod5)
		{
			int n = 7, k = 2, p = 0;
			float b = 6.5, c = 2.25;
			int arr[8], arr2[8], arr3[8], arr4[8], arr5[8], arr6[8], arr7[8], arr8[13], arr10[13], arr11[13], arr12[32] = { 0 }, arr13[32] = { 0 }, arr14[32] = { 0 };
			ToBin(n, arr);
			ToReverse(arr, arr3);
			ToExtraBin(arr, arr4);
			ToBin(k, arr2);
			Addition(arr, arr2, arr5);
			Subtraction(arr, arr2, arr6);
			Multiplication(arr, arr2, arr7);
			Division(arr, arr2, arr8);
			p = ForFloatBin(arr8);
			ToFloatBin(b, arr10);
			ToFloatBin(c, arr11);
			To32bit(arr10, arr12);
			To32bit(arr11, arr13);
			bit32Addition(arr12, arr13, arr14);

		}

		TEST_METHOD(TestMethod6)
		{
			int n = 7, k = 2, p = 0;
			float b = 2.25, c = 6.5;
			int arr[8], arr2[8], arr3[8], arr4[8], arr5[8], arr6[8], arr7[8], arr8[13], arr10[13], arr11[13], arr12[32] = { 0 }, arr13[32] = { 0 }, arr14[32] = { 0 };
			ToBin(n, arr);
			ToReverse(arr, arr3);
			ToExtraBin(arr, arr4);
			ToBin(k, arr2);
			Addition(arr, arr2, arr5);
			Subtraction(arr, arr2, arr6);
			Multiplication(arr, arr2, arr7);
			Division(arr, arr2, arr8);
			p = ForFloatBin(arr8);
			ToFloatBin(b, arr10);
			ToFloatBin(c, arr11);
			To32bit(arr10, arr12);
			To32bit(arr11, arr13);
			bit32Addition(arr12, arr13, arr14);

		}

		TEST_METHOD(TestMethod7)
		{
			int n = 7, k = 4, p = 0;
			float b = 2.25, c = 6.5;
			int arr[8], arr2[8], arr3[8], arr4[8], arr5[8], arr6[8], arr7[8], arr8[13], arr10[13], arr11[13], arr12[32] = { 0 }, arr13[32] = { 0 }, arr14[32] = { 0 };
			ToBin(n, arr);
			ToReverse(arr, arr3);
			ToExtraBin(arr, arr4);
			ToBin(k, arr2);
			Addition(arr, arr2, arr5);
			Subtraction(arr, arr2, arr6);
			Multiplication(arr, arr2, arr7);
			Division(arr, arr2, arr8);
			p = ForFloatBin(arr8);
			ToFloatBin(b, arr10);
			ToFloatBin(c, arr11);
			To32bit(arr10, arr12);
			To32bit(arr11, arr13);
			bit32Addition(arr12, arr13, arr14);

		}


		
	};
}
