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


private:
    /// The gnome object for the game
    CSpartyGnome* mGnome;

	/// The scoreboard object for the game
	CScoreboard* mScoreboard;

    /// The scale of the game is set to
	float mScale;

    /// Level object for level 0
	CLevel mLevel0 = CLevel(L"data/levels/level0.xml");
    /// Level object for level 1
    CLevel mLevel1 = CLevel(L"data/levels/level1.xml");
};
