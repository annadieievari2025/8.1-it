#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>
#include "../8.1 rec/8.1rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RecursiveTests
{
	TEST_CLASS(HasAllWhileLettersRecursive_Tests)
	{
	public:

		TEST_METHOD(AllLettersPresent)
		{
			Assert::IsTrue(HasAllWhileLettersRecursive("whiles are good"));
			Assert::IsTrue(HasAllWhileLettersRecursive("we have a while loop"));
		}

		TEST_METHOD(NotAllLettersPresent)
		{
			Assert::IsFalse(HasAllWhileLettersRecursive("hello world"));
			Assert::IsFalse(HasAllWhileLettersRecursive("wil"));
			Assert::IsFalse(HasAllWhileLettersRecursive(""));
		}
	};
}
