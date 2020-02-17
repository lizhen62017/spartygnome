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

/// Vertial character speed in pixels per second
const double JumpSpeed = -800;

/// Small value to ensure we do not stay in collision
const double Epsilon = 0.01;


/**
 * Constructor for spartyGnome
 * \param game The game the gnome is a part of
 */
CSpartyGnome::CSpartyGnome(CGameSystem* game)
{
    mGameSystem = game;
    mImage = unique_ptr<Bitmap>(Bitmap::FromFile(ImageName.c_str()));
    if (mImage->GetLastStatus() != Ok)
    {
        AfxMessageBox(L"Failed to open data/images/gnome.png");
    }
}


/**
 * \param graphics The graphic SpartyGnome is being drawn on
 * \param scrollX The distance needed so that SpartyGnome can remain centered 
 */
void CSpartyGnome::Draw(Gdiplus::Graphics* graphics, int scrollX)
{
    if (mImage != nullptr)
    {
        int wid = mImage->GetWidth();
        int hit = mImage->GetHeight();

        graphics->DrawImage(mImage.get(),
            float(mP.X() - wid / 2) + scrollX, float(mP.Y() - hit / 2),
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
    
    if (!isAfterDeath)
    {
        for (auto collided : GetLevel()->CollisionTest(this))
        {
            if (collided != nullptr)
            {
                if (abs(collided->GetX() - GetX()) < collided->GetWidth() / 2.0 + GetWidth() / 2.0 - 11)
                {
                    if (newV.Y() > 0 && collided->GetY() > GetY())
                    {
                        // We are falling, stop at the collision point
                        newP.SetY(collided->GetY() - collided->GetHeight() / 2.0 - GetHeight() / 2.0 - Epsilon);
                        misJumping = false;
                        mDoubleJump = false;
                        newV.SetY(0);
                    }
                    else if (newV.Y() < 0 && collided->GetY() < GetY())
                    {
                        // We are rising, stop at the collision point
                        newP.SetY(collided->GetY() + collided->GetHeight() / 2.0 + GetHeight() / 2.0 + Epsilon);
                        newV.SetY(0);
                    }
                    // If we collide, we cancel any velocity
                    // in the Y direction
                    
                }

                if (abs(collided->GetY() - GetY()) < collided->GetHeight() / 2.0 + GetHeight() / 2.0 - 21) 
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
    }

    mV = newV;
    mP = newP;

    //Check if gnome died
    Death(false);
}

/**
 * Function to check if SpartyGnome has died
 * \param villain Boolean if Death function was called via a villian hit test
 */
void CSpartyGnome::Death(boolean villain)
{
    if (mP.Y() - mImage->GetHeight() / 2 > 1024 || villain)
    {
        if (villain)
        {
            SetIsAfterDeath(true);
        }
        else
        {
            //Message to check if working, leave commented
            //AfxMessageBox(L"SpartyGnome has died");
            mGameSystem->Reset();
            //Temp location reset to make playtesting easier
            SetLocX(512);
            SetLocY(128);
            SetIsAfterDeath(false);
        }
    }
}

    /**
    * Function for processing a jump
    */
void CSpartyGnome::Jump()
{
    if (!misJumping && mV.Y() == 0)
    {
        SetVelY(JumpSpeed);
        misJumping = true;
    }
    // Support for double jumping if gnome has wings
    else if (mWings && !mDoubleJump && mV.Y() > 0)
    {
        SetVelY(JumpSpeed);
        mDoubleJump = true;
    }
}