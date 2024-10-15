#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.4_ITER/Lab6.4_ITER.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64ITER
{
	TEST_CLASS(UnitTest64ITER)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr[] = { 1, 2, 3, 4, 5 };
			printA(arr, 5);
			Assert::AreEqual(0, 0);
		}
	};
}
