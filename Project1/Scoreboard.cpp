/**
 * \file Scoreboard.cpp
 *
 * \author Torre Rocco
 */

#include "pch.h"
#include "Scoreboard.h"



using namespace std;
using namespace Gdiplus;

/**
* Constructor
* \param game The game this score is a part of
*/
CScoreboard::CScoreboard(CGameSystem* game) : mGameSystem(game)
{
}

/**
* Destructor
*/
CScoreboard::~CScoreboard()
{
}


/**
* Draws the score to the screen
* \param graphics Graphics context on which to draw
*/
void CScoreboard::Draw(Gdiplus::Graphics* graphics)
{
	std::wstring timePrint;
	std::wstring dollarsPrint = L"$" + GetDollars();

	if (mTime < 10)
	{
		timePrint = L"0:0" + std::to_wstring(mTime);
	}
	else if (mTime < 60)
	{
		timePrint = L"0:" + std::to_wstring(mTime);
	}
	else
	{
		int rem = mTime % 60;
		if (rem < 10)
		{
			timePrint = std::to_wstring(mTime / 60) + L":0" + std::to_wstring(rem);
		}
		else
		{
			timePrint = std::to_wstring(mTime / 60) + L":" + std::to_wstring(rem);
		}
	}

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 70, FontStyleBold);
	SolidBrush blue(Color(0, 255, 255));
	graphics->DrawString(timePrint.c_str(), -1, &font, PointF(90, 25), &blue);
	graphics->DrawString(dollarsPrint.c_str(), -1, &font, PointF(2000, 25), &blue);

	if (mDied)
	{
		FontFamily fontFamily(L"Arial");
		Gdiplus::Font font(&fontFamily, 150, FontStyleBold);
		SolidBrush purple(Color(255, 0, 255));
		graphics->DrawString(L"You Lose!", -1, &font, PointF(512, 400), &purple);

		mTime = 0;
		mDollars = 0;
		mDied = false;

	}
}



void CScoreboard::Update(double elapsed)
{
	mTimeElapsed += elapsed;

	if (mTimeElapsed >= 1.0)
	{
		mTime += 1;
		mTimeElapsed = 0.0;
	}
}


/**
 * Resets the scoreboard on gnome death or level reload
 */
void CScoreboard::Reset()
{
	mDied = true;
}

