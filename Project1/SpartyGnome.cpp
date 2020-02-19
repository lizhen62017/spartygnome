/**
 * \file SpartyGnome.cpp
 *
 * \author Robert Gustke
 */

#include <string>
#include "pch.h"
#include "SpartyGnome.h"
#include "Message.h"

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
    mTimeElapsed += elapsed;
    if (mTimeElapsed >= 2.1)
    {
        isControllable = true;
    }
    // Gravity
    // Compute a new velocity with gravity added in.
    CVector newV(mV.X(), mV.Y() + Gravity * elapsed);

    // Update position
    CVector newP = mP + newV * elapsed;

    mP.SetY(newP.Y());
    
    if (!isAfterDeath)
    {
        for (auto collided : GetGame()->CollisionTest(this))
        {
            if (collided != nullptr && collided->IsCollidable())
            {
                if (abs(collided->GetY() - GetY()) > collided->GetHeight() / 2.0 + GetHeight() / 2.0 - 23) //Purely vertical collision, tuned to have 23 works the best
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

                if (abs(collided->GetX() - GetX()) > collided->GetWidth() / 2.0 + GetWidth() / 2.0 - 13) //Purely horizontal collision, tuned to have 13 works the best
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
        // Display "You Lose" image here
        if (villain)
        {
            isAfterDeath = true; //Avoid further collision
            SetVelY(500); //Let it fall
        }
        //Message to check if working, leave commented
        //AfxMessageBox(L"SpartyGnome has died");

		// A pointer for the message we are loading

		// only run once -> when he dies
		if (mIsAlive)
		{
			shared_ptr<CItem> item;

			item = make_shared<CMessage>(mGameSystem, L"You Lose!", 150, L"red", 2.0);
			item->SetLocation(512, 100);
			mGameSystem->Add(item);

			mGameSystem->SetRespawn(true);
			mIsAlive = false;
			
		}

        //Temp location reset to make playtesting easier
        // Reset();
        isAfterDeath = false;
        isControllable = false;
        mTimeElapsed = 0.0;
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


/**
 * A class for changing which level spartygnome currently is in
 * \param level the level being changed to
 */
void CSpartyGnome::ChangeLevel(CLevel* level)
{
    // mLevel = level;
}

/**
 * function for resetting spartygnomes location after dying or a level change
 */
void CSpartyGnome::Reset()
{
    SetLocX(512);
    SetLocY(128);
    SetVelX(0);
    SetVelY(0);
}
