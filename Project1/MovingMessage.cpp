/**
 * \file MovingMessage.cpp
 *
 * \author Torre Rocco
 */

#include "pch.h"
#include "MovingMessage.h"

using namespace std;
using namespace Gdiplus;

/**
* Function for creating a moving message item
* \param game The game the message is a part of
* \param text The text to be displayed
* \param textSize The size of the text to be displayed
* \param color The color of the text
* \param delayTime The time the text stays on screen
*/
CMovingMessage::CMovingMessage(CGameSystem* game, std::wstring text, int textSize, std::wstring color, double delayTime) :
	CMessage(game, text, textSize, color, delayTime)
{
}

// still need to refine this function
bool CMovingMessage::Update(double elapsed)
{
	mSizeTimer += elapsed;

	double newY = GetY() - mVelocity * elapsed;
	SetLocation(GetX(), newY);


	if (mSizeTimer >= 0.5)
	{
		AddToSize(1);
		mSizeTimer = 0.0;
	}

	return false;
}
