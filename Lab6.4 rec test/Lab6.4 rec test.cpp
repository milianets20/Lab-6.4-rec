#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.4 rec/Lab 6.4 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab64rectest
{
	TEST_CLASS(Lab64rectest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double t = 0;
			double arr[7] = { -7.8, 9.1, 4.2, 0.7, 9.4, -9.9, 1.2 };
			double imin = arr[0];
			t = find_min(arr, 7, 0, imin);
			Assert::AreEqual(t, -9.9);
		}
	};
}
