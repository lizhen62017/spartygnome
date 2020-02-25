#include "pch.h"
#include "CppUnitTest.h"
#include "Level.h"
#include "Declaration.h"
#include "Item.h"
#include "GameSystem.h"
#include "SpartyGnome.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	/**
	 *  CItem mock derived object
	 */
	class CItemMock : public CItem
	{
	public:
		/**  Constructor
		 * \param level Level this item is a member of
		 * \param filename Filename for opening item image
		 */
		CItemMock(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
			CItem(level, declaration)
		{
		}

		///  Default constructor (disabled)
		CItemMock() = delete;

		///  Copy constructor (disabled)
		CItemMock(const CItemMock&) = delete;

		~CItemMock() {}

		/** Accept a visitor
		 * \param visitor The visitor we accept 
		 */
		virtual void Accept(CItemVisitor* visitor) override{ }
		
		/// Get the width of the item
		/// \returns item width
		virtual double GetWidth() override { return 0; } //FIXME Virtual Item

		/// Get the height of the item
		/// \returns item height
		virtual double GetHeight() override { return 0; } //FIXME Virtual Item

		/** Define if item is collidable
		* \param collidable the situation
		*/
		virtual boolean IsCollidable() override { return true; }; //FIXME Virtual Item

		/// Handles results of a collision with an item
		virtual void Collided() override {};
};

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

			CGameSystem game;

			CLevel level0(&game, path);

			CItemMock item(&level0, level0.GetDeclaration(L"i001"));

			// Test SetLocation, GetX, and GetY
			item.SetLocation(10.5, 17.2);
			Assert::AreEqual(10.5, item.GetX(), 0.0001);
			Assert::AreEqual(17.2, item.GetY(), 0.0001);
		}

		TEST_METHOD(TestCItemCollision)
		{
			std::wstring path = L"data/levels/level1.xml";

			CGameSystem game;

			CSpartyGnome gnome(&game);

			CLevel level1(&game, path);

			CItemMock item(&level1, level1.GetDeclaration(L"i008")); //add a money on the same location as gnome

			// Test SetLocation, GetX, and GetY
			item.SetLocation(512,512);
			gnome.SetLocX(512);
			gnome.SetLocY(512);
			Assert::IsTrue(game.CollisionTest(&gnome).size() == 1); //See if it collides with money
		}

	};
} 