#include "pch.h"
#include "CppUnitTest.h"
#include "Level.h"
#include "Declaration.h"
#include "Item.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
/*
namespace Testing
{
	/**
	 *  CItem mock derived object
	 
	class CItemMock : public CItem
	{
	public:
		/**  Constructor
		 * \param level Level this item is a member of
		 * \param filename Filename for opening item image
		 
		CItemMock(CLevel* level, const std::wstring filename) : 
			CItem(level, filename)
		{
		}

		///  Default constructor (disabled)
		CItemMock() = delete;

		///  Copy constructor (disabled)
		CItemMock(const CItemMock&) = delete;

		~CItemMock() {}

		/** Accept a visitor
		 * \param visitor The visitor we accept 
		virtual void Accept(CItemVisitor* visitor) override{ }

		/// Get the width of the item
		/// \returns item width
		virtual int GetWidth() override { return 0; } //FIXME Virtual Item

		/// Get the height of the item
		/// \returns item height
		virtual int GetHeight() override { return 0; } //FIXME Virtual Item

		/** Define if item is collidable
		* \param collidable the situation
		
		virtual boolean IsCollidable() override { return true; }; //FIXME Virtual Item
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
			CLevel level0(path);

			CItemMock item(&level0, L"data/images/platformIndustrial_059.png");

			// Test SetLocation, GetX, and GetY
			item.SetLocation(10.5, 17.2);
			Assert::AreEqual(10.5, item.GetX(), 0.0001);
			Assert::AreEqual(17.2, item.GetY(), 0.0001);
		}

	};
} */