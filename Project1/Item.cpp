/**
 * \file Item.cpp
 *
 * \author Chase Lindeboom
 */

#include "pch.h"
#include <string>
#include "Item.h"
#include "Level.h"

using namespace Gdiplus;
using namespace std;

const Gdiplus::REAL Epsilon = 1; ///< remove the white lines between objects made of multiple pictures.


/**
 * Constructor constructing item from Level Xml file
 * \param level The level this item is a member of
 * \param declaration Declaration used to instantiate member variables
 */
CItem::CItem(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    mLevel(level)
{
    mItemImage = shared_ptr<Bitmap>(declaration->GetImage(0));
}

/**
 * Constructor constructing item for game system
 * \param level The game system this item belongs to
 */
CItem::CItem(CLevel* level) : mLevel(level)
{
}


/**
 * Destructor
 */
CItem::~CItem()
{
}


/**
 * Draw this item
 */
void CItem::Draw(Gdiplus::Graphics* graphics, float scrollX)
{
	double wid = mItemImage->GetWidth();
	double hit = mItemImage->GetHeight();

	graphics->DrawImage(mItemImage.get(),
		float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
		(float)mItemImage->GetWidth() + Epsilon, (float)mItemImage->GetHeight());
}

/**
 * Loads attributes for an item node
 * \param node The Xml node we are loading from
 */
void CItem::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    mX = node->GetAttributeDoubleValue(L"x", 0);
    mY = node->GetAttributeDoubleValue(L"y", 0);
}

