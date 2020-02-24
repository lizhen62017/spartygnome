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
* \param level The level the message is a part of
* \param text The text to be displayed
* \param textSize The size of the text to be displayed
* \param color The color of the text
* \param delayTime The time the text stays on screen
*/
CMovingMessage::CMovingMessage(CLevel* level, std::wstring text, double textSize, std::wstring color, double delayTime) :
	CMessage(level, text, textSize, color, delayTime)
{
	mStartSize = textSize;
}

// still need to refine this function
bool CMovingMessage::Update(double elapsed)
{
	mSizeTimer += elapsed;

	double newX = GetX() - (mVelocity * 0.32) * elapsed;
	double newY = GetY() - mVelocity * elapsed;
	SetLocation(newX, newY);

	SetSize(mStartSize + (mSizeTimer / GetDelay()) * (mMaxSize - mStartSize));

	if ((GetY() + GetSize()) < 0)
	{
		return true;
	}

	return false;
}
