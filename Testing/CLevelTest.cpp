#include "pch.h"
#include "CppUnitTest.h"

#include "Level.h"
#include "Background.h"
#include "Platform.h"
#include "GameSystem.h"

#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <memory>

using namespace std;
using namespace Gdiplus;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{

	class CTestVisitor : public CItemVisitor
	{
	public:
		virtual void VisitBackground(CBackground* background) override { mNumBackgrounds++; }
		virtual void VisitPlatform(CPlatform* building) override { mNumPlatforms++; }

		void ResetVisits()
		{
			mNumBackgrounds = 0;
			mNumPlatforms = 0;
		}

		int mNumBackgrounds = 0;
		int mNumPlatforms = 0;
	};

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
			std::wstring path = L"data/levels/level1.xml";

			CGameSystem game;

			CLevel level0(&game, path);
		}

		TEST_METHOD(TestCLevelLoading)
		{
			std::wstring path = L"data/levels/level0.xml";

			CGameSystem game;

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

		TEST_METHOD(TestDeclarationLoading)
		{
			std::wstring path = L"data/levels/level0.xml";

			CGameSystem game;

			CLevel level0(&game, path);

			std::shared_ptr<CDeclaration> background = level0.GetDeclaration(L"i001");
			Assert::IsTrue(background->GetType() == L"background");
			Assert::IsFalse(background->GetType() == L"platform");

			std::shared_ptr<CDeclaration> platform = level0.GetDeclaration(L"i005");
			Assert::IsTrue(platform->GetType() == L"platform");
			Assert::IsFalse(platform->GetType() == L"background");
		}

		TEST_METHOD(TestCItemVisitor)
		{
			// FIXME!!!
			std::wstring path = L"data/levels/level0.xml";

			CGameSystem game;

			CLevel level(&game, path);


			wstring filename = L"data/images/grass.png";

			shared_ptr<Bitmap> image;

			// Get image
			image = shared_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
			if (image->GetLastStatus() != Ok)
			{
				wstring message = L"Failed to open" + path;
				AfxMessageBox(message.c_str()); //////FIX THIS LATER
			}

			CTestVisitor visitor;
			level.Accept(&visitor);
			Assert::AreEqual(1, visitor.mNumBackgrounds,
				L"Visitor number of backgrounds");

			visitor.ResetVisits();


			const shared_ptr<CDeclaration> emptyDeclaration = make_shared<CDeclaration>();
			emptyDeclaration->AddImage(image);

			// Add some platforms and backgrounds
			auto item1 = make_shared<CBackground>(&level, emptyDeclaration);
			auto item2 = make_shared<CBackground>(&level, emptyDeclaration);

			level.Add(item1);
			level.Add(item2);

			level.Accept(&visitor);
			Assert::AreEqual(3, visitor.mNumBackgrounds,
				L"Visitor number of backgrounds");

		}

	};

}