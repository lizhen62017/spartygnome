/**
 * \file Message.cpp
 *
 * \author Torre Rocco
 */

#include "pch.h"
#include "Message.h"
#include "Level.h"


using namespace std;
using namespace Gdiplus;

/**
* Function for creating a message to display
* \param level The level to display the message in
* \param text The text to display
* \param textSize The size of the text
* \param color The color of the text
* \param delayTime The time it is shown on screen
*/
CMessage::CMessage(CLevel* level, std::wstring text, double textSize, std::wstring color, double delayTime) : CItem(level)
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

void CMessage::Draw(Gdiplus::Graphics* graphics, float scrollX)
{

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, Gdiplus::REAL(mTextSize), FontStyleBold);

	auto off = GetLevel()->GetOffset();

	auto xCoordinate = Gdiplus::REAL(GetX() + (scrollX - GetLevel()->GetOffset()));
	auto yCoordinate = Gdiplus::REAL(GetY());

	if (mColor == L"red")
	{
		SolidBrush red(Color(255, 0, 255));
		graphics->DrawString(mText.c_str(), -1, &font, PointF(xCoordinate, yCoordinate), &red);
	}
	else if (mColor == L"green")
	{
		SolidBrush green(Color(0, 255, 0));
		graphics->DrawString(mText.c_str(), -1, &font, PointF(xCoordinate, yCoordinate), &green);
	}
	else
	{
		SolidBrush blue(Color(0, 255, 255));
		graphics->DrawString(mText.c_str(), -1, &font, PointF(xCoordinate, yCoordinate), &blue);
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
