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

	/// Updates the screen from the last elapsed time
	void Update(double elapsed);

    void Reset();

    void Completion();

    
    /// Changes the level to the desired level
    /// \param level The level being changed to
    void ChangeLevel(int level);
    

private:
    /// The gnome object for the game
    CSpartyGnome* mGnome;

	/// The scoreboard object for the game
	CScoreboard* mScoreboard;

    /// The scale of the game is set to. Defaults to 1 for no scaling
	float mScale = 1;

	CLevel mLevel0 = CLevel(L"data/levels/level0.xml"); ///< Level object for level 0
    CLevel mLevel1 = CLevel(L"data/levels/level1.xml"); ///< Level object for level 1
    CLevel mLevel2 = CLevel(L"data/levels/level2.xml"); ///< Level object for level 2
    CLevel mLevel3 = CLevel(L"data/levels/level3.xml"); ///< Level object for level 3

    /// The current and active level
    CLevel mCurrentLevel = mLevel1;
};