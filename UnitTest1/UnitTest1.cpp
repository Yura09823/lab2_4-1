#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2_4_1/Matrix.h"
#include "../lab2_4_1/Matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Matrix m1;
            Assert::AreEqual(100, m1.getSize());
            Assert::AreEqual(0, m1.getRows());
            Assert::AreEqual(0, m1.getCols());

            Matrix m2(2, 3, 7);
            Assert::AreEqual(2, m2.getRows());
            Assert::AreEqual(3, m2.getCols());
            Assert::AreEqual(6, m2.getCount());
            Assert::AreEqual(7, m2[0][0]);
            Assert::AreEqual(7, m2[1][2]);

            Matrix m3("10 20 30");
            Assert::AreEqual(1, m3.getRows());
            Assert::AreEqual(3, m3.getCols());
            Assert::AreEqual(10, m3[0][0]);
            Assert::AreEqual(30, m3[0][2]);
		}
	};
}
