#include "pch.h"
#include "CppUnitTest.h"
#include "../lab64it/lab64it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64it
{
	TEST_CLASS(UnitTest64it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double arr[] = { 3.2, -1.5, 5.7, -10.4, 7.9 };
			int size = sizeof(arr) / sizeof(arr[0]);
			int expectedMinIndex = 3; 

			Assert::AreEqual(expectedMinIndex, findMinIndex(arr, size));
		}
	};
}
