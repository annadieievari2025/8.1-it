#define _CRT_SECURE_NO_WARNINGS
#include "pch.h" 
#include "CppUnitTest.h"
#include "../8.1/8.1.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WhileReplaceTests
{
	TEST_CLASS(WhileReplaceTests)
	{
	public:

		TEST_METHOD(Test_HasAllWhileLetters_Positive)
		{
			const char* str = "Рядок містить while.";
			Assert::IsTrue(HasAllWhileLetters(str));
		}

		TEST_METHOD(Test_HasAllWhileLetters_Negative)
		{
			const char* str = "В рядку не вистачає літер.";
			Assert::IsFalse(HasAllWhileLetters(str));
		}
	};
}