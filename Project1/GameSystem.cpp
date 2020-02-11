#include "pch.h"
#include "Game.h"

using namespace Gdiplus;
using namespace std;

void CGameSystem::OnDraw(Gdiplus::Graphics* graphics,int width, int height)
{
    //
    // Automatic Scaling
    //
    mScale = float(height) / float(mBackground.GetImageHeight());
    graphics->ScaleTransform(mScale, mScale);

    // Determine the virtual width
    auto virtualWidth = (float)width / mScale;



    // Compute the amount to scroll in the X dimension
  //  auto xOffset = (float)-gnome->GetX() + virtualWidth / 2.0f;

    int xOffset = 0;

    mBackground.OnDraw(graphics,xOffset);

}
