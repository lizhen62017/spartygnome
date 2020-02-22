#include "pch.h"
#include "GameSystem.h"
#include "Scoreboard.h"
#include "SpartyGnome.h"
#include "Item.h"
#include "Message.h"

using namespace Gdiplus;
using namespace std;

//constant for scale of the window.  All background objects are 1024 pixels, so
// that is going to be what it is scaled to at all times.
const int BackgroundSize = 1024;

/// Maximum amount of time to allow for elapsed, tuned to have 0.020 works the best
const double MaxElapsed = 0.019; 

/**
* Constructor
*/
CGameSystem::CGameSystem()
{
	// initialize game scoreboard
	mScoreboard = new CScoreboard(this);
    mGnome = new CSpartyGnome(this);

	mLevel0 = new CLevel(this, L"data/levels/level0.xml");
	mLevel0->SetStartX(500);
	mLevel0->SetStartY(500);
	mLevel1 = new CLevel(this, L"data/levels/level1.xml");
	mLevel1->SetStartX(850);
	mLevel1->SetStartY(550);
	mLevel2 = new CLevel(this, L"data/levels/level2.xml");
	mLevel3 = new CLevel(this, L"data/levels/level3.xml");

	mCurrentLevel = mLevel1;

	mCurrentLevel->Install();
}


/**
* Destructor
*/
CGameSystem::~CGameSystem()
{
	delete mScoreboard;
	delete mGnome;
	delete mLevel0;
	delete mLevel1;
	delete mLevel2;
	delete mLevel3;

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

	mWidth = virtualWidth;

    auto xOffset = (float)-mGnome->GetX() + virtualWidth / 2.0f;

    // all drawing needs to be below here to allow for virtual pixels

    for (auto item : mItems)
    {
        item->Draw(graphics, xOffset);
    }

    mGnome->Draw(graphics, xOffset);

	mScoreboard->Draw(graphics, virtualWidth);


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
	mGnome->UpdateImageTime(temp);
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

	std::shared_ptr<CItem> removeItem;

	// Update mitems if returns true, delete
	for (auto item : mItems)
	{
		bool del = item->Update(temp);

		if (del)
		{
			removeItem = item;
		}
	}

	RemoveItem(removeItem);

	// if respawn is set, wait two seconds
	if (mRespawn)
	{
		mTimeElapsed += temp;

		if (mTimeElapsed >= 2.0)
		{
			mCurrentLevel->Install();
			mGnome->Alive(true);
			Reset();
			mRespawn = false;
			mTimeElapsed = 0.0;
		}
	}

	// if respawn is set, wait two seconds
	if (mLevelUp)
	{
		mTimeElapsed += temp;
		int level = GetLevel(); //Get integer level number
		mGnome->SetVelX(0);
		mGnome->SetVelY(0);
		mGnome->SetIsControllable(false);
		shared_ptr<CItem> item;
		item = make_shared<CMessage>(this, L"Level " + to_wstring(level) + L" Clear!", 150, L"red", 2.0);
		item->SetLocation((mWidth / 2.0) - 700, 100);
		Add(item);
		/// The solution above is very shitty because 
		/// I did not quite get why there is a ScoreBoard::Door() function... 
		/// I should use that but do not know how
		if (mTimeElapsed >= 2.0)
		{
			if (level < 3)
			{
				ChangeLevel(level + 1); //engage level
			}
			else
			{
				ChangeLevel(level); //loop at level 3
			}
			Reset();
			mLevelUp = false;
			mTimeElapsed = 0.0;
			mGnome->SetIsControllable(false);
			mGnome->SetTimeElapsed(0.0);
		}
	}
}


/**
 * Resets a level on load or gnome death
 */
void CGameSystem::Reset()
{
    mScoreboard->Reset();
	mGnome->Wings(true); //Change me
}


/**
 * Clears the items known by the gamesystem
 */
void CGameSystem::Clear()
{
	mItems.clear();
}


/**
 * Completes level and loads next level
 */
void CGameSystem::Completion()
{
    mScoreboard->Door();
}

//maybe put the gnome level switching here?

void CGameSystem::ChangeLevel(int level)
{
    switch (level)
    {
    case (0):
        mCurrentLevel = mLevel0;
        break;
    case (1):
        mCurrentLevel = mLevel1;
        break;
    case (2):
        mCurrentLevel = mLevel2;
        break;
    case (3):
        mCurrentLevel = mLevel3;
        break;
    }
    //mGnome->ChangeLevel(mCurrentLevel);
	mCurrentLevel->Install();
	Reset();
	mGnome->SetIsControllable(false);
	mGnome->SetTimeElapsed(0.0);
}


/** Add an item to the game
 * \param item New item to add
 */
void CGameSystem::Add(std::shared_ptr<CItem> item)
{
	mItems.push_back(item);
}



/**
 * Tests each item known by the gamesystem to see if it is colliding with the gnome
 * \param gnome Pointer to Spartygnome to see if we are colliding
 * \returns A vector of items gnome is currently colliding with
 */
std::vector<std::shared_ptr<CItem>> CGameSystem::CollisionTest(CSpartyGnome* gnome)
{
	std::vector<std::shared_ptr<CItem>> mOut;
	for (int i = 0; i < mItems.size(); i++)
	{
		// Border for the item
		auto itemLeft = mItems[i]->GetX() - mItems[i]->GetWidth() / 2;
		auto itemRight = mItems[i]->GetX() + mItems[i]->GetWidth() / 2;
		auto itemTop = mItems[i]->GetY() - mItems[i]->GetHeight() / 2;
		auto itemBottom = mItems[i]->GetY() + mItems[i]->GetHeight() / 2;

		// For us
		auto ourLeft = gnome->GetX() - gnome->GetWidth() / 2;
		auto ourRight = gnome->GetX() + gnome->GetWidth() / 2;
		auto ourTop = gnome->GetY() - gnome->GetHeight() / 2;
		auto ourBottom = gnome->GetY() + gnome->GetHeight() / 2;

		// Test for all of the non-collision cases,
		// cases where there is a gap between the two items
		if (!(ourRight < itemLeft ||  // Completely to the left
			ourLeft > itemRight ||  // Completely to the right
			ourTop > itemBottom ||  // Completely below
			ourBottom < itemTop))    // Completely above
		{
			mOut.push_back(mItems[i]);
		}
	}
	return mOut;
}


/**
 * Remove an item on the screen
 * \param item to be removed
 */
void CGameSystem::RemoveItem(std::shared_ptr<CItem> item)
{
	auto loc = find(mItems.begin(), mItems.end(), item);

	if (loc != end(mItems))
	{
		mItems.erase(loc);
	}
}

/*
* Function for returning a given int value of the current level
* \returns int An int of a given level
*/
int CGameSystem::GetLevel()
{
	if (mCurrentLevel == mLevel0)
	{
		return 0;
	}
	else if (mCurrentLevel == mLevel1)
	{
		return 1;
	}
	else if (mCurrentLevel == mLevel2)
	{
		return 2;
	}
	else 
	{
		return 3;
	}
}





