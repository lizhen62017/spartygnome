/**
 * \file GameSystem.h
 *
 * \author
 *
 * 
 */

#include "Background.h"
#include "SpartyGnome.h"
#include "Level.h"
#include <string>
#pragma once


/**
 * CGameSystem Class
 * used for handling the game system
 */
class CGameSystem
{
public:
    /// Draws
	void Draw(Gdiplus::Graphics* graphics, int width, int height);

    /// Gets the gnome object
    /// \return the gnome object
    CSpartyGnome* GetGnome() { return &mGnome; }

private:
    /// The gnome object for the game
    CSpartyGnome mGnome;
    /// The scale of the game is set to
	float mScale;

    /// Level object for level 0
	CLevel mLevel0 = CLevel(L"data/levels/level0.xml");
    /// Level object for level 1
    CLevel mLevel1 = CLevel(L"data/levels/level1.xml");
};
