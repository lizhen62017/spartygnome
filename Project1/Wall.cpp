/**
 * \file Platform.cpp
 *
 * \author Zhen Li
 */

#include "pch.h"
#include <string>
#include "Wall.h"

using namespace std;
using namespace Gdiplus;

//Strentch image 
const double Epsilon = 1;
/**
 * Constructor for a platform when loaded from level file
 * \param level The level this platform is a part of
 * \param declaration The Declaration used to instantiate this item
 */
CWall::CWall(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CTerrain(level, declaration)
{
    mWallImage = shared_ptr<Bitmap>(declaration->GetImage(0));
}

/**
 * Draw this item
 * \param graphics Graphics device to draw on
 * \param scrollX The offset used due to screen scrolling
 */
void CWall::Draw(Gdiplus::Graphics* graphics, int scrollX)
{
    double wid = 32;
    double hit = 32;

    float numMid = (GetHeight() - 64) / 32;

    if (numMid < 0)
    {
        graphics->DrawImage(mWallImage.get(),
            float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
            (float)mWallImage->GetWidth(), (float)mWallImage->GetHeight() + Epsilon);
    }

    else
    {
        float currentCenter = GetY() - (numMid / 2) * 32 - 16;
        float bottomCenter = GetY() + (numMid / 2) * 32 + 16;

        graphics->DrawImage(mWallImage.get(),
            float(GetX() - wid / 2 + scrollX), float(currentCenter - hit / 2),
            (float)mWallImage->GetWidth(), (float)mWallImage->GetHeight() + Epsilon);

        currentCenter += 32;

        while (currentCenter < bottomCenter)
        {
            graphics->DrawImage(mWallImage.get(),
                float(GetX() - wid / 2 + scrollX), float(currentCenter - hit / 2),
                (float)mWallImage->GetWidth(), (float)mWallImage->GetHeight() + Epsilon);

            currentCenter += 32;
        }

        graphics->DrawImage(mWallImage.get(),
            float(GetX() - wid / 2 + scrollX), float(currentCenter - hit / 2),
            (float)mWallImage->GetWidth(), (float)mWallImage->GetHeight() + Epsilon);

    }
}