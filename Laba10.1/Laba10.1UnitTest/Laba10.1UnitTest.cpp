#include "pch.h"
#include "CppUnitTest.h"
#include "../Laba10.11/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Laba101UnitTest
{
	TEST_CLASS(Laba101UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			ofstream fout("d.txt");
			fout << "a , , ,";
			fout.close();

			double actual;
			double exp = 6;

			actual = GetThirdComma("d.txt");
			Assert::AreEqual(actual, exp);
		}
	};
}
