/**
 * \file SpartyGnome.cpp
 *
 * \author Robert Gustke
 */

#include "pch.h"
#include <string>
#include <Windows.h>
#include <mmsystem.h>
#include "SpartyGnome.h"
#include "Message.h"


using namespace Gdiplus;
using namespace std;

/// The five base images for SpartyGnome animation
const wstring ImageBase = L"data/images/gnome.png"; ///< Base image
const wstring ImageLeft1 = L"data/images/gnome-walk-left-1.png"; ///< First moving left image
const wstring ImageLeft2 = L"data/images/gnome-walk-left-2.png"; ///< Second moving left image
const wstring ImageRight1 = L"data/images/gnome-walk-right-1.png"; ///< First moving right image
const wstring ImageRight2 = L"data/images/gnome-walk-right-2.png"; ///< Second moving right image
const wstring ImageSad = L"data/images/gnome-sad.png"; ///< Sad gnome image
const wstring ImageClimb = L"data/images/gnome-climb.png"; ///< Climbing gnome image

/// The five wing images for SpartyGnome animation
const wstring ImageBaseWing = L"data/images/gnome-wing.png"; ///< Base image with wings
const wstring ImageLeft1Wing = L"data/images/gnome-walk-left-1-wing.png"; ///< First moving left image with wings
const wstring ImageLeft2Wing = L"data/images/gnome-walk-left-2-wing.png"; ///< Second moving left image with wings
const wstring ImageRight1Wing = L"data/images/gnome-walk-right-1-wing.png"; ///< First moving right image with wings
const wstring ImageRight2Wing = L"data/images/gnome-walk-right-2-wing.png"; ///< Second moving right image with wings
const wstring ImageSadWing = L"data/images/gnome-sad-wing.png"; ///< Sad gnome image with wings
const wstring ImageClimbWing = L"data/images/gnome-climb-wing.png"; ///< Climbing gnome image with wings

/// Gravity in virtual pixels per second per second
const double Gravity = 1000.0;

/// Vertial character speed in virtual pixels per second
const double JumpSpeed = -800;

/// Horizontal character speed in pixels per second
const double HorizontalSpeed = 500.00;

/// Small value to ensure we do not stay in collision
const double Epsilon = 0.01;

/// Maximum vertical speed, capped to prevent tunneling
const double MaxVY = 1500;

/// Number to shift the text by so it is centered on screen.
const double TextShift = 575;

/**
 * Constructor for spartyGnome
 * \param game The game the gnome is a part of
 */
CSpartyGnome::CSpartyGnome(CGameSystem* game)
{
    mGameSystem = game;
    mImage = unique_ptr<Bitmap>(Bitmap::FromFile(ImageBase.c_str()));
    if (mImage->GetLastStatus() != Ok)
    {
        AfxMessageBox(L"Failed to open data/images/gnome.png");
    }
}


/**
 * \param graphics The graphic SpartyGnome is being drawn on
 * \param scrollX The distance needed so that SpartyGnome can remain centered 
 */
void CSpartyGnome::Draw(Gdiplus::Graphics* graphics, float scrollX)
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
* \param elapsed Elapsed time since last update
*/
void CSpartyGnome::Update(double elapsed)
{
    mTimeElapsed += elapsed;
    if (mTimeElapsed >= 2.0)
    {
        isControllable = true;
    }

    // Stupid way to detect ladder and start climbing
    if ((GetGame()->GetLevel() == 3 && mP.X() > 3926 && mP.X() < 3939 && mP.Y() > 99 && mP.Y() < 663) ||
        (GetGame()->GetLevel() == 3 && mP.X() > 3166 && mP.X() < 3179 && mP.Y() > 0 && mP.Y() < 381))
    {
        if (!isClimbing)
        {
            SetVelX(0);
            SetVelY(0);
        }
        isClimbing = true;
        mImageState = ImageState::Climb;
        mImageTime = 0.0;
    }
    else
    {
        if (isClimbing)
        {
            if (GetVelX() < -0.5)
            {
                mImageState = ImageState::Left1;
                mImageTime = 0.0;
            }
            else if (GetVelX() > 0.5)
            {
                mImageState = ImageState::Right1;
                mImageTime = 0.0;
            }
        }
        isClimbing = false;
    }

    // Compute a new velocity with gravity added in.
    CVector newV(mV.X(), mV.Y() + Gravity * elapsed);

    // Disable gravity while climbing a ladder
    if (isClimbing)
    {
        newV = mV; 
    }

    // Update position
    CVector newP = mP + newV * elapsed;


    mP.SetY(newP.Y());

    if (mV.Y() >= MaxVY)
    {
        mV.SetY(MaxVY);
    }

    mV = newV;
    mP = newP;

    if (!mIsAfterDeath) //< check if the gnome is dead
    {
        for (auto collided : GetGame()->CollisionTest(this))
        {
            collided->Collided();
        }
    }

    //Check if gnome died in this update
    Death(false);

    //Set proper image state for animation
    if (mImageState == ImageState::Left1 && mImageTime > .2500 && !misJumping && GetVelY() == 0)
    {
        mImageState = ImageState::Left2;
        mImageTime = 0.0;
    }
    else if (mImageState == ImageState::Left2 && mImageTime > .2500 && !misJumping && GetVelY() == 0)
    {
        mImageState = ImageState::Left1;
        mImageTime = 0.0;
    }
    else if (mImageState == ImageState::Right1 && mImageTime > .2500 && !misJumping && GetVelY() == 0)
    {
        mImageState = ImageState::Right2;
        mImageTime = 0.0;
    }
    else if (mImageState == ImageState::Right2 && mImageTime > .2500 && !misJumping && GetVelY() == 0)
    {
        mImageState = ImageState::Right1;
        mImageTime = 0.0;
    }

    //Set the correct image based on ImageState
    if (mImageState == ImageState::Base)
    {
        if (mWings) {SetImage(ImageBaseWing);}
        else { SetImage(ImageBase); }
        mImageTime = 0.0;
    }
    else if (mImageState == ImageState::Left1)
    {
        if (mWings) { SetImage(ImageLeft1Wing); }
        else { SetImage(ImageLeft1); }
    }
    else if (mImageState == ImageState::Right1)
    {
        if (mWings) { SetImage(ImageRight1Wing); }
        else { SetImage(ImageRight1); }
    }
    else if (mImageState == ImageState::Left2)
    {
        if (mWings) { SetImage(ImageLeft2Wing); }
        else { SetImage(ImageLeft2); }
    }
    else if (mImageState == ImageState::Right2)
    {
        if (mWings) { SetImage(ImageRight2Wing); }
        else { SetImage(ImageRight2); }
    }
    else if (mImageState == ImageState::Sad)
    {
        if (mWings) { SetImage(ImageSadWing); }
        else { SetImage(ImageSad); }
    }

    else if (mImageState == ImageState::Climb)
    {
        if (mWings) { SetImage(ImageClimbWing); }
        else { SetImage(ImageClimb); }
    }
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
            mIsAfterDeath = true; //Avoid further collision
            SetVelY(500); //Let it fall
        }

		// only run once -> when he dies
		if (mIsAlive)
		{
			shared_ptr<CItem> item;
            PlaySound(TEXT("data/sounds/pacman_death.wav"), NULL, SND_ASYNC);
			item = make_shared<CMessage>(mGameSystem->GetCurrentLevel(), L"You Lose!", 100, L"red", 2.0);
            item->SetLocation(GetX() - (360 - mGameSystem->GetCurrentLevel()->GetOffset()), 150);
			mGameSystem->Add(item);
            SetVelX(0);
            
            // Set attributes to reflect death
            mImageState = ImageState::Sad;
			mGameSystem->SetRespawn(true);
			mIsAlive = false;
            mWings = false;
			
		}

        isControllable = false;
        mTimeElapsed = 0.0;
    }
}

/**
* Function for processing a jump
*/
void CSpartyGnome::Jump()
{
    if (!isClimbing)
    {
        if (!misJumping && mV.Y() <= 0.5 && mV.Y() >= -0.5) //< Can the gnome jump
        {
            PlaySound(TEXT("data/sounds/jump.wav"), NULL, SND_ASYNC);
            SetVelY(JumpSpeed);
            misJumping = true;
        }
        // Support for double jumping if gnome has wings
        else if (mWings && !mDoubleJump && mV.Y() > 20) //< Can the gnome double jump
        {
            PlaySound(TEXT("data/sounds/double_jump.wav"), NULL, SND_ASYNC);
            SetVelY(JumpSpeed);
            mDoubleJump = true;
        }
        if (mImageState == ImageState::Sad) { mImageState = ImageState::Base; }
    }
}

/**
 * Function to handle collision with top of wall or platform
 * \param y Y coord of the object collided with
 * \param height Height of the object collided with
 */
void CSpartyGnome::FallingColide(double y, double height)
{
    // We are falling, stop at the collision point
    SetLocY(y - height / 2.0 - GetHeight() / 2.0 - Epsilon);
    misJumping = false;
    mDoubleJump = false;
    SetVelY(0);
}

/**
 * Function to handle collision with bottom of wall or platform
 * \param y Y coord of the object collided with
 * \param height Height of the object collided with
 */
void CSpartyGnome::RisingColide(double y, double height)
{
    // We are rising, stop at the collision point
    SetLocY(y + height / 2.0 + GetHeight() / 2.0 + Epsilon);
    SetVelY(0);
}

/**
 * Function to handle collision with side of wall or platform
 * \param x X coord of the object collided with
 * \param width Width of the object collided with
 */
void CSpartyGnome::LeftColide(double x, double width)
{
    // We are moving to the left, stop at the collision point
    SetLocX(x + width / 2.0 + GetWidth() / 2.0 + Epsilon);
    mImageState = ImageState::Base;
    mImageTime = 0.0;
    SetVelX(0);
}

/**
 * Function to handle collision with side of wall or platform
 * \param x X coord of the object collided with
 * \param width Width of the object collided with
 */
void CSpartyGnome::RightColide(double x, double width)
{
    // We are moving to the right, stop at the collision point
    SetLocX(x - width / 2.0 - GetWidth() / 2.0 - Epsilon);
    SetVelX(0);
    mImageState = ImageState::Base;
    mImageTime = 0.0;
}


/**
 * Function to determine which collide function to call when gnome collides with terrain
 * \param x X coord of object collided with
 * \param y Y coord of object collided with
 * \param width Width of object collided with
 * \param height Height of object collided with
 */
void CSpartyGnome::TerrainColide(double x, double y, double width, double height)
{
    // Vertical collision
    if (abs(x - GetX()) < width / 2.0 + GetWidth() / 2.0 - 13) //Purely vertical collision, tuned to have 23 works the best
    {
        if (GetVelY() > 0 && y > GetY()) // Gnome is falling
        {
            FallingColide(y, height);
        }
        else if (GetVelY() < 0 && y < GetY()) // Gnome is rising
        {
            RisingColide(y, height);
        }
    }

    // Horizontal collision
    if (abs(y - GetY()) < height / 2.0 + GetHeight() / 2.0 - 23) //Purely horizontal collision, tuned to have 13 works the best
    {
        if (GetVelX() > 0 && x > GetX()) //Moving right
        {
            RightColide(x, width);
        }
        else if (GetVelX() < 0 && x < GetX()) // Moving left
        {
            LeftColide(x, width);
        }
    }
}


/**
 * Function for when right arrow is pressed
 */
void CSpartyGnome::MoveRight()
{
    SetVelX(HorizontalSpeed);
    if (mImageState != ImageState::Right1 && mImageState != ImageState::Right2 && mIsAlive)
    {
        mImageState = ImageState::Right1;
        mImageTime = 0.0;
    }
}

/**
 * Function for when left arrow is pressed
 */
void CSpartyGnome::MoveLeft()
{
    SetVelX(-HorizontalSpeed);
    if (mImageState != ImageState::Left1 && mImageState != ImageState::Left2 && mIsAlive)
    {
        mImageState = ImageState::Left1;
        mImageTime = 0.0;
    }
}

/**
 * Function for when up arrow is pressed
 */
void CSpartyGnome::ClimbUp()
{
    if (isClimbing)
    {
        SetVelY(-500);
    }
}

/**
 * Function for when down arrow is pressed
 */
void CSpartyGnome::ClimbDown()
{
    if (isClimbing)
    {
        SetVelY(500);
    }
}

/**
 * Function for when left or right arrow is released
 */
void CSpartyGnome::Stop()
{
    SetVelX(0);
    if (mIsAlive) 
    {
        mImageState = ImageState::Base;
    }
}

/**
 *  Set the image file of the gnome to draw
 * \param file The image filename
 */
void CSpartyGnome::SetImage(const std::wstring& file)
{
    if (!file.empty())
    {
        mImage = unique_ptr<Bitmap>(Bitmap::FromFile(file.c_str()));
        if (mImage->GetLastStatus() != Ok)
        {
            wstring msg(L"Failed to open ");
            msg += file;
            AfxMessageBox(msg.c_str());
            return;
        }
    }
    else
    {
        mImage.release();
    }
}