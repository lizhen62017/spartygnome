#include "pch.h"
#include "SpartyGnome.h"

using namespace Gdiplus;

CSpartyGnome::CSpartyGnome()
{
    mImage = Bitmap::FromFile(L"../data/images/gnome.png");
    if (mImage->GetLastStatus() != Ok)
    {
        AfxMessageBox(L"Failed to open data/images/gnome.png");
    }
    // Will need to update to starting platform
    mX = 512;
    mY = 512;
}