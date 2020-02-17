#include "pch.h"
#include "CppUnitTest.h"

#include "Scoreboard.h"
#include "GameSystem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CScoreboardTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestScoreboard)
		{
			CGameSystem game;
			CScoreboard score(&game);

			Assert::IsTrue(score.GetDollars() == L"0", L"initial value is 0");

			score.AddDollars(500);

			Assert::IsTrue(score.GetDollars() == L"500", L"testing add functionality");

			score.AddDollars(10000);

			Assert::IsTrue(score.GetDollars() == L"10500", L"testing add functionality");

		}

	};
}