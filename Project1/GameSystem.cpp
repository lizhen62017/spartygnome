#include "pch.h"
#include "GameSystem.h"

using namespace Gdiplus;
using namespace std;

void CGameSystem::Draw(Gdiplus::Graphics* graphics,int width, int height)
{
    //
    // Automatic Scaling
    //
    mScale = float(height) / float(2000);
    graphics->ScaleTransform(mScale, mScale);

    // Determine the virtual width
    auto virtualWidth = (float)width / mScale;

    auto xOffset = (float)-mGnome.GetX() + virtualWidth / 2.0f;

    // all drawing needs to be below here to allow for virtual pixels

    mGnome.Draw(graphics);


}
