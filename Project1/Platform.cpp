/**
 * \file Platform.cpp
 *
 * \author Chase Lindeboom
 */

#include "pch.h"
#include "Platform.h"

using namespace Gdiplus;
using namespace std;

/// Stretches the image a bit so there is no gap between images.
const Gdiplus::REAL Epsilon = 1;


/**
 * Constructor for a platform when loaded from level file
 * \param level The level this platform is a part of
 * \param declaration The Declaration used to instantiate this item
 */
CPlatform::CPlatform(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CTerrain(level, declaration)
{
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

    double numMid = (GetWidth() - 64)/ 32;

    if (numMid < 0)
    {
        graphics->DrawImage(mMidImage.get(), 
            float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
            (float)mMidImage->GetWidth() + Epsilon, (float)mMidImage->GetHeight());
    }

    else 
    {
        double currentCenter = GetX() - (numMid / 2) * 32 - 16;
        double rightCenter = GetX() + (numMid / 2) * 32 + 16;

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