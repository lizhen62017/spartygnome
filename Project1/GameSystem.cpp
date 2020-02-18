#include "pch.h"
#include "GameSystem.h"
#include "Scoreboard.h"
#include "SpartyGnome.h"

using namespace Gdiplus;
using namespace std;

//constant for scale of the window.  All background objects are 1024 pixels, so
// that is going to be what it is scaled to at all times.
const int BackgroundSize = 1024;

/// Maximum amount of time to allow for elapsed
const double MaxElapsed = 0.001;

/**
* Constructor
*/

CGameSystem::CGameSystem()
{
	// initialize game scoreboard
	mScoreboard = new CScoreboard(this);
    mGnome = new CSpartyGnome(this);

}


/**
* Destructor
*/
CGameSystem::~CGameSystem()
{
	delete mScoreboard;
	delete mGnome;
}

/**
 * Draws the Game and scales everything accordingly
 * \param graphics The graphics which are being drawn
 * \param width The width of the current game window 
 * \param height The height of the current game window
 */
void CGameSystem::Draw(Gdiplus::Graphics* graphics,int width, int height)
{
    //
    // Automatic Scaling
    //
    mScale = float(height) / float(BackgroundSize);
    graphics->ScaleTransform(mScale, mScale);

    // Determine the virtual width
    auto virtualWidth = (float)width / mScale;

    auto xOffset = (float)-mGnome->GetX() + virtualWidth / 2.0f;

    // all drawing needs to be below here to allow for virtual pixels

    
    // determine which level is currently active
    switch (mCurrentLevel)
    {
    case (Level0):
        mLevel0.Draw(graphics, xOffset);
        mGnome->ChangeLevel(&mLevel0);
        break;
    case (Level1):
        mLevel1.Draw(graphics, xOffset);
        mGnome->ChangeLevel(&mLevel1);
        break;
    case (Level2):
        mLevel2.Draw(graphics, xOffset);
        mGnome->ChangeLevel(&mLevel2);
        break;
    case (Level3):
        mLevel3.Draw(graphics, xOffset);
        mGnome->ChangeLevel(&mLevel3);
        break;
    }

    mGnome->Draw(graphics, xOffset);

	mScoreboard->Draw(graphics);


}


/** Handle updates for animation
* \param elapsed The time since the last update
*/

void CGameSystem::Update(double elapsed)
{
    //
    // Prevent tunnelling
    //
    double temp = elapsed;
    while (elapsed > MaxElapsed)
    {
        mGnome->Update(MaxElapsed);

        elapsed -= MaxElapsed;
    }

    // Consume any remaining time
    if (elapsed > 0)
    {
        mGnome->Update(elapsed);
    }
	mScoreboard->Update(temp);
}


/**
 * Resets a level on load or gnome death
 */
void CGameSystem::Reset()
{
    mScoreboard->Reset();
}

/**
 * Completes level and loads next level
 */
void CGameSystem::Completion()
{
    mScoreboard->Door();
}


void CGameSystem::ChangeLevel(int level)
{
    switch (level)
    {
    case (0):
        mCurrentLevel = Level0;
        break;
    case (1):
        mCurrentLevel = Level1;
        break;
    case (2):
        mCurrentLevel = Level2;
        break;
    case (3):
        mCurrentLevel = Level3;
        break;
    }
    mGnome->Reset();
}
