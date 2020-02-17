/**
 * \file Terrain.cpp
 *
 * \author Zhen Li
 */

#include "pch.h"
#include "Terrain.h"
#include "Level.h"
#include <string>

using namespace Gdiplus;
using namespace std;

CTerrain::CTerrain(CLevel* level, const std::wstring& filename) : CItem(level, filename)
{
}

/**
 * Constructor
 * \param level The level this item is a member of
 * \param filename Filename for the image we use
 */
CTerrain::CTerrain(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CItem(level, declaration)
{
    mItemImage = shared_ptr<Bitmap>(declaration->GetImage(0));
}


/**
 * Draw this item
 */
void CTerrain::Draw(Gdiplus::Graphics* graphics, int scrollX)
{
    double wid = mItemImage->GetWidth();
    double hit = mItemImage->GetHeight();

    graphics->DrawImage(mItemImage.get(),
        float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
        (float)mItemImage->GetWidth(), (float)mItemImage->GetHeight());
}
