#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_12_1.6\Rational.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Rational r1;
			r1.Init(14, 7);
			Rational r2;
			r2.Init(7, 14);

			Rational r = mult(r1, r2);
			Assert::IsTrue(r.getPair().getA() == 1 && r.getPair().getB());
		}
	};
}
