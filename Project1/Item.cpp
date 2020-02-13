/**
 * \file Item.cpp
 *
 * \author Chase Lindeboom
 */

#include "pch.h"
#include "Item.h"
#include "Level.h"
#include <string>

using namespace Gdiplus;
using namespace std;

/**
 * Constructor
 * \param level The level this item is a member of
 * \param filename Filename for the image we use
 */
CItem::CItem(CLevel* level, const std::wstring& filename) :
	mLevel(level)
{
	mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str())); ///FIXME some items have multiple images at the same time (platform)
	if (mItemImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}


/**
 * Destructor
 */
CItem::~CItem()
{
}



/**
 * Draw this item
 * \param graphics Graphics device to draw on
 */
void CItem::Draw(Gdiplus::Graphics* graphics, int scrollX)
{
	double wid = mItemImage->GetWidth();
	double hit = mItemImage->GetHeight();

	graphics->DrawImage(mItemImage.get(),
		float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
		(float)mItemImage->GetWidth(), (float)mItemImage->GetHeight());
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

