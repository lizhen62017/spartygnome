#include "pch.h"
#include "CppUnitTest.h"
#include "SpartyGnome.h"
#include "GameSystem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CSpartyGnomeTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestLocation)
		{
			CGameSystem game;

			CSpartyGnome gnome(&game);
			gnome.SetLocX(512);
			gnome.SetLocY(512);
			Assert::IsTrue(gnome.GetX() == 512, L"Correct Test");
			Assert::IsTrue(gnome.GetY() == 512, L"Correct Test");
			gnome.SetLocX(600);
			gnome.SetLocY(700);
			Assert::IsFalse(gnome.GetX() == 512, L"Incorrect Test");
			Assert::IsFalse(gnome.GetY() == 512, L"Incorrect Test");
		}

		TEST_METHOD(TestVelocity)
		{
			CGameSystem game;

			CSpartyGnome gnome(&game);

			Assert::IsTrue(gnome.GetVelX() == 0, L"Correct Test");
			Assert::IsTrue(gnome.GetVelY() == 0, L"Correct Test");
			gnome.SetVelX(600);
			gnome.SetVelY(700);
			Assert::IsTrue(gnome.GetVelX() == 600, L"Correct Test");
			Assert::IsTrue(gnome.GetVelY() == 700, L"Correct Test");
			Assert::IsFalse(gnome.GetVelX() == 512, L"Incorrect Test");
			Assert::IsFalse(gnome.GetVelY() == 512, L"Incorrect Test");
		}

		TEST_METHOD(Jump)
		{
			CGameSystem game;

			CSpartyGnome gnome(&game);

			Assert::IsTrue(gnome.GetVelY() == 0, L"Base Test");
			gnome.SetVelY(10);
			gnome.Jump();
			Assert::IsTrue(gnome.GetVelY() == 10, L"Didn't jump Test");
			gnome.SetVelY(0);
			gnome.Jump();
			Assert::IsTrue(gnome.GetVelY() == -800, L"Jumped Test");
		}

		TEST_METHOD(TestGnomeControllable)
		{
			CGameSystem game;

			CSpartyGnome gnome(&game);

			Assert::IsFalse(gnome.GetIsControllable());
		}

	};
}