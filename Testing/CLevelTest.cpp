#include "pch.h"
#include "CppUnitTest.h"

#include "Level.h"
#include "Background.h"
#include "Platform.h"
#include "Money.h"
#include "TuitionUp.h"
#include "Wings.h"
#include "Villain.h"
#include "Door.h"
#include "Wall.h"
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
		virtual void VisitMoney(CMoney* money) override { mNumMoney++; }
		virtual void VisitVillain(CVillain* villain) override { mNumVillains++; }
		virtual void VisitWall(CWall* wall) override { mNumWalls++; }
		virtual void VisitTuitionUp(CTuitionUp* tuitionUp) override { mNumTuitionUps++; }
		virtual void VisitWings(CWings* wings) override { mNumWings++; }
		virtual void VisitDoor(CDoor* door) override { mNumDoors++; }

		void ResetVisits()
		{
			mNumBackgrounds = 0;
			mNumPlatforms = 0;
			mNumMoney = 0;
			mNumVillains = 0;
			mNumWalls = 0;
			mNumTuitionUps = 0;
			mNumWings = 0;
			mNumDoors = 0;
		}

		int mNumBackgrounds = 0;
		int mNumPlatforms = 0;
		int mNumMoney = 0;
		int mNumVillains = 0;
		int mNumWalls = 0;
		int mNumTuitionUps = 0;
		int mNumWings = 0;
		int mNumDoors = 0;
		
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

		TEST_METHOD(TestLoad)
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

		TEST_METHOD(TestXmlDeclaration)
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
				AfxMessageBox(message.c_str());
			}

			CTestVisitor visitor;

			// Set the initial values in case we change them later in level 0
			level.Accept(&visitor);
			int initialBackgrounds = visitor.mNumBackgrounds;
			int initialVillains = visitor.mNumVillains;

			// Reset the visitor to make sure count is accurate
			visitor.ResetVisits();

			// Make an empty declaration
			const shared_ptr<CDeclaration> emptyDeclaration = make_shared<CDeclaration>();
			emptyDeclaration->AddImage(image);

			// Add some platforms and backgrounds
			auto item1 = make_shared<CBackground>(&level, emptyDeclaration);
			auto item2 = make_shared<CBackground>(&level, emptyDeclaration);
			auto item3 = make_shared<CVillain>(&level, emptyDeclaration);

			level.Add(item1);
			level.Add(item2);
			level.Add(item3);

			level.Accept(&visitor);
			Assert::AreEqual(initialBackgrounds + 2, visitor.mNumBackgrounds,
				L"Visitor number of backgrounds");
			Assert::AreEqual(initialVillains + 1, visitor.mNumVillains,
				L"Visitor number of villains");

		}
		TEST_METHOD(TestXmlItem)
		{
			//Test invalid if we change level 1
			std::wstring path = L"data/levels/level1.xml";

			CGameSystem game;

			CLevel level1(&game, path);

			CTestVisitor visitor;
			level1.Accept(&visitor);

			Assert::AreEqual(8, visitor.mNumBackgrounds);
			Assert::AreEqual(23, visitor.mNumPlatforms);
			Assert::AreEqual(10, visitor.mNumWalls);
			Assert::AreEqual(44, visitor.mNumMoney);
			Assert::AreEqual(2, visitor.mNumVillains);
			Assert::AreEqual(1, visitor.mNumTuitionUps);
			Assert::AreEqual(0, visitor.mNumWings);
			Assert::AreEqual(1, visitor.mNumDoors);
		}

	};

}