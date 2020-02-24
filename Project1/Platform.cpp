/**
 * \file Platform.cpp
 *
 * \author Chase Lindeboom
 */

#include "pch.h"
#include "Platform.h"

using namespace Gdiplus;
using namespace std;

/// filenames 
/**
const wstring GrassImageName = L"data/images/grass.png"; ///< Grass Image
const wstring GrassMidImageName = L"data/images/grassMid.png"; ///< Grass Mid Image
const wstring GrassLeftImageName = L"data/images/grassLeft.png"; ///< Grass Left Image
const wstring GrassRightImageName = L"data/images/grassRight.png"; ///< Grass Right Image
const wstring SnowImageName = L"data/images/snow.png"; ///< Snow Image
const wstring SnowMidImageName = L"data/images/snowMid.png"; ///< Snow Mid Image
const wstring SnowLeftImageName = L"data/images/snowLeft.png"; ///< Snow Left Image
const wstring SnowRightImageName = L"data/images/snowRight.png"; ///< Snow Right Image
const wstring IndustrialImageName = L"data/images/platformIndustrial_057.png"; ///< Industrial Image
const wstring IndustrialMidImageName = L"data/images/platformIndustrial_060.png"; ///< Industrial Mid Image
const wstring IndustrialLeftImageName = L"data/images/platformIndustrial_059.png"; ///< Industrial Left Image
const wstring IndustrialRightImageName = L"data/images/platformIndustrial_061.png"; ///< Industrial Right Image
*/
// Strentch image a bit so no gap between them.
const double Epsilon = 1;


/**
 * Constructor for a platform when loaded from level file
 * \param level The level this platform is a part of
 * \param declaration The Declaration used to instantiate this item
 */
CPlatform::CPlatform(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CTerrain(level, declaration)
{
    //mLeftImage = unique_ptr<Bitmap>(declaration->GetImage(0)); FIXME: Redundant with mItemImage
    mMidImage = shared_ptr<Bitmap>(declaration->GetImage(1));
    mRightImage = shared_ptr<Bitmap>(declaration->GetImage(2));
}


/**
 * Draw this item
 * \param graphics Graphics device to draw on
 * \param scrollX The offset used due to screen scrolling
 */
void CPlatform::Draw(Gdiplus::Graphics* graphics, float scrollX)
{
    double wid = 32;
    double hit = 32;

    float numMid = (GetWidth() - 64)/ 32;

    if (numMid < 0)
    {
        graphics->DrawImage(mMidImage.get(), 
            float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
            (float)mMidImage->GetWidth() + Epsilon, (float)mMidImage->GetHeight());
    }

    else 
    {
        float currentCenter = GetX() - (numMid / 2) * 32 - 16;
        float rightCenter = GetX() + (numMid / 2) * 32 + 16;

        graphics->DrawImage(GetImage().get(),
            float(currentCenter - wid / 2 + scrollX), float(GetY() - hit / 2),
            (float)GetImage()->GetWidth() + Epsilon, (float)GetImage()->GetHeight());

        currentCenter += 32;

        while (currentCenter < rightCenter)
        {
            graphics->DrawImage(mMidImage.get(),
                float(currentCenter - wid / 2 + scrollX), float(GetY() - hit / 2),
                (float)mMidImage->GetWidth() + Epsilon, (float)mMidImage->GetHeight());

            currentCenter += 32;
        }

        graphics->DrawImage(mRightImage.get(),
            float(currentCenter - wid / 2 + scrollX), float(GetY() - hit / 2),
            (float)mRightImage->GetWidth() + Epsilon, (float)mRightImage->GetHeight());

    }
}