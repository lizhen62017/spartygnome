#include "pch.h"
#include "SpartyGnome.h"

using namespace Gdiplus;


/**
 * Constructor for spartGnome
 */
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


/**
 * \param graphics The graphic SpartyGnome is being drawn on
 */
void CSpartyGnome::Draw(Gdiplus::Graphics* graphics)
{
    if (mImage != nullptr)
    {
        int wid = mImage->GetWidth();
        int hit = mImage->GetHeight();

        graphics->DrawImage(mImage, mX, mY, wid, hit);
    }
}


/**
 * Sets SpartyGnome location
 * \param x New X location
 * \param y New Y location
 */
void CSpartyGnome::SetLocation(double x, double y)
{
    mX = x;
    mY = y;
}