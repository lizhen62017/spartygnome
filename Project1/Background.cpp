/**
 * \file Background.cpp
 *
 * \author Chase Lindeboom
 */

#include "pch.h"

#include "Background.h"

using namespace Gdiplus;

/**CBackground::CBackground()
{
    // the image name still needs to be determined, haven't added as group consensus desired
    mImage = Bitmap::FromFile(L"data/images/backgroundColorDesert.png");
    if (mImage->GetLastStatus() != Ok)
    {
        AfxMessageBox(L"Failed to open data/images/backgroundColorDesert.png");
    }
}*/


/**
 * Constructor for a Background when loaded from level file
 * \param level The level this background is a part of
 * \param declaration The Declaration used to instantiate this item 
 */
CBackground::CBackground(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CItem(level, declaration)
{
}

// I think this is likely redundant
void CBackground::OnDraw(Gdiplus::Graphics* graphics,double scrollX)
{
    /**int wid = mImage->GetWidth();
    int hit = mImage->GetHeight();

    // draw the background tiled over a distance.  This needs to be figured out more
   // depending on the length of the level.
    graphics->DrawImage(mImage, -wid/2 + scrollX, 0, wid, hit);
    graphics->DrawImage(mImage, wid/2-1 + scrollX, 0, wid, hit);
    graphics->DrawImage(mImage, 1.5 * wid - 2 + scrollX, 0, wid, hit);*/
}