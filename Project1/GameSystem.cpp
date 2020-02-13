#include "pch.h"
#include "GameSystem.h"

using namespace Gdiplus;
using namespace std;

//constant for scale of the window.  All background objects are 1024 pixels, so
// that is going to be what it is scaled to at all times.
const BACKGROUND_SIZE = 1024;

void CGameSystem::Draw(Gdiplus::Graphics* graphics,int width, int height)
{
    //
    // Automatic Scaling
    //
    mScale = float(height) / float(BACKGROUND_SIZE);
    graphics->ScaleTransform(mScale, mScale);

    // Determine the virtual width
    auto virtualWidth = (float)width / mScale;

    auto xOffset = (float)-mGnome.GetX() + virtualWidth / 2.0f;

    // all drawing needs to be below here to allow for virtual pixels

    mGnome.Draw(graphics);


}
