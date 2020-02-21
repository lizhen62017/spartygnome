/**
 * \file Message.cpp
 *
 * \author Torre Rocco
 */

#include "pch.h"
#include "Message.h"


using namespace std;
using namespace Gdiplus;

/**
* Function for creating a message to display
* \param game The game to display the message in
* \param text The text to display
* \param textSize The size of the text
* \param color The color of the text
* \param delayTime The time it is shown on screen
*/
CMessage::CMessage(CGameSystem* game, std::wstring text, int textSize, std::wstring color, double delayTime) : CItem(game)
{
	mText = text;
	mTextSize = textSize;
	mColor = color;
	mDelayTime = delayTime;
}


boolean CMessage::IsCollidable()
{
	return false;
}

void CMessage::Draw(Gdiplus::Graphics* graphics, int scrollX)
{

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, mTextSize, FontStyleBold);

	if (mColor == L"red")
	{
		SolidBrush purple(Color(255, 0, 255));
		graphics->DrawString(mText.c_str(), -1, &font, PointF(GetX(), GetY()), &purple);
	}
	else
	{
		SolidBrush blue(Color(0, 255, 255));
		graphics->DrawString(mText.c_str(), -1, &font, PointF(GetX(), GetY()), &blue);
	}

}

bool CMessage::Update(double elapsed)
{

	mTimeElapsed += elapsed;

	if (mTimeElapsed >= mDelayTime)
	{
		return true;
	}

	return false;

}
