/**
 * \file GameSystem.h
 *
 * \author
 *
 * 
 */

#pragma once

#include "Background.h"
#include "Level.h"
#include <string>

class CScoreboard;
class CSpartyGnome;
class CItem;

/**
 * CGameSystem Class
 * used for handling the game system
 */
class CGameSystem
{
public:
	/// Constructor
	CGameSystem();

	/// Destructor
	~CGameSystem();


    /// Draws
	void Draw(Gdiplus::Graphics* graphics, int width, int height);

    /// Gets the gnome object
    /// \return the gnome object
    CSpartyGnome* GetGnome() { return mGnome; }

	/// Gets the scoreboard object
	/// \return the scoreboard object
	CScoreboard* GetScoreboard() { return mScoreboard; }

	/// Updates the screen from the last elapsed time
	void Update(double elapsed);

	void SetRespawn(bool state) { mRespawn = state; }

    void Reset();

	void Clear();

    void Completion();

    
    /// Changes the level to the desired level
    /// \param level The level being changed to
    void ChangeLevel(int level);


	void Add(std::shared_ptr<CItem> item);

	std::vector<std::shared_ptr<CItem>> CollisionTest(CSpartyGnome* gnome);

	void RemoveItem(std::shared_ptr<CItem> item);

	/** The virtual width of the game
	* \returns mWidth width of the game */
	float GetVirtualWidth() { return mWidth; }

	/** The current level number the game is on
	* \returns level the number in current */
	int GetLevel();

	void SetLevelUp(boolean status) { mLevelUp = status; }
    
private:
    /// The gnome object for the game
    CSpartyGnome* mGnome;

	/// The scoreboard object for the game
	CScoreboard* mScoreboard;

	/// keeps track of the virtual width of the game
	float mWidth = 2226.76880;

	/// tests to see if respawn delay is needed
	bool mRespawn = false;

	/// keeps track of time in the game 
	double mTimeElapsed = 0.0;

    /// The scale of the game is set to. Defaults to 1 for no scaling
	float mScale = 1;

	CLevel* mLevel0; ///< Level object for level 0
    CLevel* mLevel1; ///< Level object for level 1
    CLevel* mLevel2; ///< Level object for level 2
    CLevel* mLevel3; ///< Level object for level 3

    /// The current and active level
    CLevel* mCurrentLevel;


	/// All of the items currently in gamesystem
	std::vector<std::shared_ptr<CItem>> mItems;

	boolean mLevelUp = false;
};