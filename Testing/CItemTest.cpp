#include "pch.h"
#include "CppUnitTest.h"
#include "Level.h"
#include "Item.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CItemTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCItemConstruct)
		{
			std::wstring path = L"data/levels/level0.xml";
			CLevel level0(path);

			CItem item(&level0, L"data/images/platformIndustrial_059.png");

			// Test SetLocation, GetX, and GetY
			item.SetLocation(10.5, 17.2);
			Assert::AreEqual(10.5, item.GetX(), 0.0001);
			Assert::AreEqual(17.2, item.GetY(), 0.0001);
		}

	};
}