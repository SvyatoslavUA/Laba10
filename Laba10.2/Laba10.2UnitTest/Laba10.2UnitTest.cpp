#include "pch.h"
#include "CppUnitTest.h"
#include "../Laba10.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Laba102UnitTest
{
	TEST_CLASS(Laba102UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			ofstream fout("d.txt");
			fout << "a b ( c";
			fout.close();

			double actual;
			double exp = 4;

			actual = GetOpenBrecketIndex("d.txt");
			Assert::AreEqual(actual, exp);
		}
	};
}
