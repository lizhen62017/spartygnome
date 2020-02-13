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

private:
	CSpartyGnome mGnome;
	float mScale;
	CLevel mLevel0 = CLevel(L"../Project1/data/levels/level0.xml");
};
