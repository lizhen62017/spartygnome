/**
 * \file Fragile.cpp
 *
 * \author Zhen Li
 */

#include "pch.h"
#include "Fragile.h"

using namespace std;
using namespace Gdiplus;

/**
 * Constructor for a fragile platform when loaded from level file
 * \param level The level this fragile platform is a part of
 * \param declaration The Declaration used to instantiate this item
 */
CFragile::CFragile(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CTerrain(level, declaration)
{
    mFragileImage = shared_ptr<Bitmap>(declaration->GetImage(0));
}

void CFragile::Draw(Gdiplus::Graphics* graphics, float scrollX)
{
    double wid = 160;
    double hit = 32;
    graphics->DrawImage(mFragileImage.get(),
            float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
            (float)wid, (float)hit);
}

/**
* The function for handling collision
*/
void CFragile::Collided()
{
    CTerrain::Collided();
    mHit = true;
}

/**
 * The function for updating the fragile platform
 * Handle updates for animation
 * \param elapsed The time since the last update
 * \returns false if the item becomes marked for deletion,
 * true if not
 */
bool CFragile::Update(double elapsed)
{
    if (mHit)
    {
        mTimeElapsed += elapsed;
        if (mTimeElapsed >= 2.0)
        {
            PlaySound(TEXT("data/sounds/Crumbling.wav"), NULL, SND_ASYNC);
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}