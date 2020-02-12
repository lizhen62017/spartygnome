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

			Assert::IsTrue(gnome.GetX() == 512, L"Correct Test");
			Assert::IsTrue(gnome.GetY() == 512, L"Correct Test");
			gnome.SetLocation(600,700);
			Assert::IsFalse(gnome.GetX() == 512, L"Correct Test");
			Assert::IsFalse(gnome.GetY() == 512, L"Correct Test");
		}

	};
}