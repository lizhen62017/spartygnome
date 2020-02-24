#include "pch.h"
#include "CppUnitTest.h"
#include "GameSystem.h"
#include "Item.h"
#include "Message.h"
#include <memory>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace Testing
{
	TEST_CLASS(CGameSystemTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestConstruct)
		{
			CGameSystem game;
		}

		TEST_METHOD(TestLevelLoad)
		{
			CGameSystem game;

			std::wstring path = L"data/levels/level0.xml";

			CLevel level0(&game, path);

			double width = 1024;
			double height = 1024;
			double startX = 468;
			double startY = 572;


			Assert::IsTrue(level0.GetWidth() == 1024);
			Assert::IsTrue(level0.GetHeight() == 1024);
			Assert::IsTrue(level0.GetStartX() == 468);
			Assert::IsTrue(level0.GetStartY() == 572);
		}

		TEST_METHOD(TestLevelClear)
		{
			CGameSystem game;

			std::wstring path = L"data/levels/level1.xml";
			Assert::IsTrue(game.ItemsLength() != 0);

			CLevel level1(&game, path);
			game.Clear();
			Assert::IsTrue(game.ItemsLength() == 0);
		}

		TEST_METHOD(TestGetAttributes)
		{
			CGameSystem game;
			game.GetGnome();
			game.GetScoreboard();
			game.GetLevel();
		}


		TEST_METHOD(TestGameAddRemove)
		{
			CGameSystem game;

			std::wstring path = L"data/levels/level1.xml";
			int initial = game.ItemsLength();

			auto item = make_shared<CMessage>(game.GetCurrentLevel(), L"Testing String", 150, L"red", 2.0);
			item->SetLocation(500, 500);
			game.Add(item);
			
			// test that item was properly added
			Assert::IsTrue(game.ItemsLength() == initial + 1);

			game.RemoveItem(item);

			// test that item was properly removes
			Assert::IsTrue(game.ItemsLength() == initial);

		}
	};
}