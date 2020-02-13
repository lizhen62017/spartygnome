/**
 * \file SpartyGnome.cpp
 *
 * \author Robert Gustke
 */

#include "pch.h"
#include "SpartyGnome.h"

using namespace Gdiplus;


/// Gravity in virtual pixels per second per second
const double Gravity = 1000.0;

/// Horizontal character speed in pixels per second
const double HorizontalSpeed = 500.00;

const double JumpSpeed = -800;

/// Small value to ensure we do not stay in collision
const double Epsilon = 0.01;


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
* Updates SpartyGnome's location
* \param elapsed elapsed time since last update
*/
void CSpartyGnome::Update(double elapsed)
{
    SetLocX(mX+elapsed*mVx);
    SetLocY(mY+elapsed*mVy);
}