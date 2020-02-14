#include "pch.h"
#include "CppUnitTest.h"

#include "SpartyGnome.h"

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
			CSpartyGnome gnome;
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
			CSpartyGnome gnome;

			Assert::IsTrue(gnome.GetVelX() == 0, L"Correct Test");
			Assert::IsTrue(gnome.GetVelY() == 0, L"Correct Test");
			gnome.SetVelX(600);
			gnome.SetVelY(700);
			Assert::IsTrue(gnome.GetVelX() == 600, L"Correct Test");
			Assert::IsTrue(gnome.GetVelY() == 700, L"Correct Test");
			Assert::IsFalse(gnome.GetVelX() == 512, L"Incorrect Test");
			Assert::IsFalse(gnome.GetVelY() == 512, L"Incorrect Test");
		}

	};
}