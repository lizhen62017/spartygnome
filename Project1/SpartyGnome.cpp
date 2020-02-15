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
    
    for (auto collided : GetLevel()->CollisionTest(this))
    {
        if (collided != nullptr)
        {
            if (abs(collided->GetX() - GetX()) < 44) //collided->GetWidth() / 2.0 + GetWidth() / 2.0 - Epsilon)
            {
                if (newV.Y() > 0 && collided->GetY() > GetY())
                {
                    // We are falling, stop at the collision point
                    newP.SetY(collided->GetY() - collided->GetHeight() / 2.0 - GetHeight() / 2.0 - Epsilon);
                }
                else if (newV.Y() < 0 && collided->GetY() < GetY())
                {
                    // We are rising, stop at the collision point
                    newP.SetY(collided->GetY() + collided->GetHeight() / 2.0 + GetHeight() / 2.0 + Epsilon);
                }
                // If we collide, we cancel any velocity
                // in the Y direction
                newV.SetY(0);
            }
            
            if (abs(collided->GetY() - GetY()) < 103) //collided->GetHeight() / 2.0 + GetHeight() / 2.0 - Epsilon) NEED TO CHANGE THIS
            {
                if (newV.X() > 0 && collided->GetX() > GetX())
                {
                    // We are moving to the right, stop at the collision point
                    newP.SetX(collided->GetX() - collided->GetWidth() / 2.0 - GetWidth() / 2.0 - Epsilon);
                    newV.SetX(0);
                }
                else if (newV.X() < 0 && collided->GetX() < GetX())
                {
                    // We are moving to the left, stop at the collision point
                    newP.SetX(collided->GetX() + collided->GetWidth() / 2.0 + GetWidth() / 2.0 + Epsilon);
                    newV.SetX(0);
                }

                // If we collide, we cancel any velocity
                // in the X direction
                
            }
        }
    }

    mV = newV;
    mP = newP;
}