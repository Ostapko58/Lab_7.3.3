#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.3.3/Lab_7.3.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int s = 0;
			bool minus_element = false, are = true;
			int** a = new int* [4];
			for (int i = 0; i < 4; i++)
				a[i] = new int[4];

			int b[][6]
			{ {0,8,9,15},
				{4,-54,9,99},
				{4,8,9,3},
				{9,15,100,-16},
			};

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					a[i][j] = b[i][j];
				}
			}
			Assert::AreEqual(Sum(a, 0, 0, 4, 4, minus_element, s) , 144);
			for (int i = 0; i < 4; i++)
				delete[] a[i];
			delete[] a;

		}
	};
}
