/**
 * \file Scoreboard.h
 *
 * \author Torre Rocco
 *
 * Handles all scores diplayed for the game
 */

#pragma once

#include <string>
#include "GameSystem.h"

/**
 * Scoreboard class for game display
 */
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
	std::wstring GetDollars() { return std::to_wstring(int(mDollars)); }

	/// Draws the score to the screen
	virtual void Draw(Gdiplus::Graphics* graphics, float width);

	/// Adds dollars to the total amount
	/// \param dollarAmount number of dollars to add to mDollars
	void AddDollars(double dollarAmount);

	/// Update the scoreboard
	/// \param elapsed The time elapsed from previous update
	void Update(double elapsed);

	void Reset();

private:
	/// The game this item is contained in
	CGameSystem* mGameSystem;

	/// The tuition dollars collected in the game
	double mDollars = 0;

	/// The time elapsed since the level started
	int mTime = 0;

	/// The time elapsed since the last second
	double mTimeElapsed = 0.0;

    /// shift to move the money to print it correctly
	Gdiplus::REAL mMoneyShift = 230;

	/// limit to increase the shift
	double mMoneyShiftLimit = 100;
};

