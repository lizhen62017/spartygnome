#include "pch.h"
#include "CppUnitTest.h"

#include "Level.h"

#include <regex>
#include <string>
#include <fstream>
#include <streambuf>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CLevelTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCLevelConstruct)
		{
			std::wstring path = L"../Project1/data/levels/level0.xml";
			CLevel level0(path);
		}

		TEST_METHOD(TestCLevelLoading)
		{
			std::wstring path = L"../Project1/data/levels/level0.xml";
			CLevel level0(path);

			double width = 1024;
			double height = 1024;
			double startX = 468;
			double startY = 572;


			Assert::IsTrue(level0.GetWidth() == 1024);
			Assert::IsTrue(level0.GetHeight() == 1024);
			Assert::IsTrue(level0.GetStartX() == 468);
			Assert::IsTrue(level0.GetStartY() == 572);
		}

		TEST_METHOD(TestDeclarationLoading)
		{
			std::wstring path = L"../Project1/data/levels/level0.xml";
			CLevel level0(path);

			CDeclaration background = level0.GetDeclaration(L"i001");
			Assert::IsTrue(background.GetType() == L"background");
			Assert::IsFalse(background.GetType() == L"platform");

			CDeclaration platform = level0.GetDeclaration(L"i005");
			Assert::IsTrue(platform.GetType() == L"platform");
			Assert::IsFalse(platform.GetType() == L"background");
		}
	};

}