/**
 * \file SpartyGnome.cpp
 *
 * \author Robert Gustke
 */

#include <string>
#include "pch.h"
#include "SpartyGnome.h"

using namespace Gdiplus;
using namespace std;

const wstring ImageName = L"data/images/gnome.png"; ///< please change this to several animation pictures in sprint 2

/// Gravity in virtual pixels per second per second
const double Gravity = 1000.0;

/// Horizontal character speed in pixels per second
const double HorizontalSpeed = 500.00;

/// Vertial character speed in pixels per second
const double JumpSpeed = -800;

/// Small value to ensure we do not stay in collision
const double Epsilon = 0.01;


/**
 * Constructor for spartGnome
 */
CSpartyGnome::CSpartyGnome()
{
    mImage = unique_ptr<Bitmap>(Bitmap::FromFile(ImageName.c_str()));
    if (mImage->GetLastStatus() != Ok)
    {
        AfxMessageBox(L"Failed to open data/images/gnome.png");
    }
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

        graphics->DrawImage(mImage.get(),
            float(mP.X() - wid / 2), float(mP.Y() - hit / 2),
            (float)mImage->GetWidth(), (float)mImage->GetHeight());
    }
}

/**
* Updates SpartyGnome's location
* \param elapsed elapsed time since last update
*/
void CSpartyGnome::Update(double elapsed)
{
    // Gravity
    // Compute a new velocity with gravity added in.
    CVector newV(mV.X(), mV.Y() + Gravity * elapsed);

    // Update position
    CVector newP = mP + newV * elapsed;

    mP.SetY(newP.Y());
    
    auto collided = GetLevel()->CollisionTest(this);
    if (collided != nullptr)
    {
        if (newV.Y() > 0)
        {
            // We are falling, stop at the collision point
            newP.SetY(collided->GetY() - collided->GetHeight() / 2 - GetHeight() / 2 - Epsilon);
        }
        else
        {
            // We are rising, stop at the collision point
            newP.SetY(collided->GetY() + collided->GetHeight() / 2 + GetHeight() / 2 + Epsilon);

        }

        // If we collide, we cancel any velocity
        // in the Y direction
        newV.SetY(0);
    }

    //
    // Try updating the X location
    //
    mP.SetX(newP.X());

    collided = GetLevel()->CollisionTest(this);
    /*
    if (collided != nullptr)
    {
        if (newV.X() > 0)
        {
            // We are moving to the right, stop at the collision point
            newP.SetX(collided->GetX() - collided->GetWidth() / 2 - GetWidth() / 2 - Epsilon);
        }
        else if (newV.X() < 0)
        {
            // We are moving to the left, stop at the collision point
            newP.SetX(collided->GetX() + collided->GetWidth() / 2 + GetWidth() / 2 + Epsilon);
        }

        // If we collide, we cancel any velocity
        // in the X direction
        newV.SetX(0);
    }
    */

    mV = newV;
    mP = newP;
}