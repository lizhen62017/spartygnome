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
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 60);
	SolidBrush blue(Color(0, 0, 255));
	graphics->DrawString(L"Arial", -1, &font, PointF(100, 100), &blue);
}


