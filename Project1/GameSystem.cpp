#include "pch.h"
#include "GameSystem.h"
#include "Scoreboard.h"
#include "SpartyGnome.h"

using namespace Gdiplus;
using namespace std;

//constant for scale of the window.  All background objects are 1024 pixels, so
// that is going to be what it is scaled to at all times.
const int BackgroundSize = 1024;


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

    mLevel0.Draw(graphics, xOffset);

    mGnome->Draw(graphics, xOffset);

	mScoreboard->Draw(graphics);


}


/** Handle updates for animation
* \param elapsed The time since the last update
*/

void CGameSystem::Update(double elapsed)
{
	mGnome->Update(elapsed);
	mScoreboard->Update(elapsed);
}


/**
 * Resets a level on load or gnome death
 */
void CGameSystem::Reset()
{
    mScoreboard->Reset();
}