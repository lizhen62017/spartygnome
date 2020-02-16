/**
 * \file Scoreboard.h
 *
 * \author Torre Rocco
 *
 * Handles all scores diplayed fo the game
 */

#pragma once

#include "GameSystem.h"
#include <string>

/// Scoreboard class
class CScoreboard
{
public:
	/// Default Constructor (disabled)
	CScoreboard() = delete;

	/// Constructor
	CScoreboard(CGameSystem* game);

	/// Copy constructor (disabled)
	CScoreboard(const CScoreboard&) = delete;

	/// Destructor
	~CScoreboard();

	/// Gets the money amount
	/// \return money The money as a std::wstring to print to the screen
	std::wstring GetDollars() { return std::to_wstring(mDollars); }

	/// Draws the score to the screen
	virtual void Draw(Gdiplus::Graphics* graphics);

	/// Adds dollars to the total amount
	/// \param dollarAmount number of dollars to add to mDollars
	void AddDollars(int dollarAmount) { mDollars += dollarAmount; }

	/// Update the scoreboard
	/// \param elapsed The time elapsed from previous update
	void Update(double elapsed);

private:
	/// The game this item is contained in
	CGameSystem* mGameSystem;

	/// The tuition dollars collected in the game
	int mDollars = 0;

	/// The time elapsed since the level started
	int mTime = 0;

	/// The time elapsed since the last second
	double mTimeElapsed = 0.0;
};

