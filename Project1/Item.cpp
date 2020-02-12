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
	mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
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
void CItem::Draw(Gdiplus::Graphics* graphics)
{
	double wid = mItemImage->GetWidth();
	double hit = mItemImage->GetHeight();

	graphics->DrawImage(mItemImage.get(),
		float(GetX() - wid / 2), float(GetY() - hit / 2),
		(float)mItemImage->GetWidth(), (float)mItemImage->GetHeight());
}

