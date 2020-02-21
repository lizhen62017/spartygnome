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
	virtual void Draw(Gdiplus::Graphics* graphics, int width);

	/// Adds dollars to the total amount
	/// \param dollarAmount number of dollars to add to mDollars
	void AddDollars(int dollarAmount);

	/// Adds to multplier value when tuitionUp is collected
	/// \param increase the amount the multiplier will go up by
	void UpdateMultiplier(double increase) { mMultiplier += increase; }

	/// Update the scoreboard
	/// \param elapsed The time elapsed from previous update
	/// \return bool A boolean to determine if it's deleted
	void Update(double elapsed);

	void Reset();

	void Door();

private:
	/// The game this item is contained in
	CGameSystem* mGameSystem;

	/// The tuition dollars collected in the game
	int mDollars = 0;

	/// The time elapsed since the level started
	int mTime = 0;

	/// The time elapsed since the last second
	double mTimeElapsed = 0.0;

	/// Check to see if should draw door message
	boolean mDoor = false;

	///The multiplier for tuition dollar pickup
	double mMultiplier = 1.0;

};

