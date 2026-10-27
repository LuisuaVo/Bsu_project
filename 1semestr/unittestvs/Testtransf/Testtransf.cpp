#include "CppUnitTest.h"
#include "D:\\Bsu_project\1semestr\unittestvs\unittestvs\laba2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testtransf
{
	TEST_CLASS(Testtransf)
	{
	public:
		
		TEST_METHOD(Zero)
		{
			Assert::AreEqual(-1ll, transform(0ll));
		}

		TEST_METHOD(single)
		{
			Assert::AreEqual(777ll, transform(7ll));
		}

		TEST_METHOD(chetn)
		{
			Assert::AreEqual(2222ll, transform(2222ll));
		}

		TEST_METHOD(nechet_3)
		{
			Assert::AreEqual(21232ll, transform(123ll));
		}

		TEST_METHOD(nechet_5)
		{
			Assert::AreEqual(6456786ll, transform(45678ll));
		}

		TEST_METHOD(otr_chetn)
		{
			Assert::AreEqual(-1ll, transform(-2244ll));
		}

		TEST_METHOD(dev_9_digits) 
		{
			Assert::AreEqual(5123456ll, transform(123456789ll));
		}

		TEST_METHOD(otr_nechet) 
		{
			Assert::AreEqual(-1ll, transform(-123ll));
		}
	};
}
