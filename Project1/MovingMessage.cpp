/**
 * \file MovingMessage.cpp
 *
 * \author Torre Rocco
 */

#include "pch.h"
#include "MovingMessage.h"

using namespace std;
using namespace Gdiplus;

CMovingMessage::CMovingMessage(CGameSystem* game, std::wstring text, int textSize, std::wstring color, double delayTime) :
	CMessage(game, text, textSize, color, delayTime)
{
}

void CMovingMessage::Draw(Gdiplus::Graphics* graphics, int scrollX)
{
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, GetTextSize(), FontStyleBold);

	if (GetColor() == L"red")
	{
		SolidBrush purple(Color(255, 0, 255));
		graphics->DrawString(GetText().c_str(), -1, &font, PointF(GetX(), GetY()), &purple);
	}
	else if (GetColor() == L"green")
	{
		SolidBrush green(Color(0, 255, 0));
		graphics->DrawString(GetText().c_str(), -1, &font, PointF(GetX(), GetY()), &green);
	}
	else
	{
		SolidBrush blue(Color(0, 255, 255));
		graphics->DrawString(GetText().c_str(), -1, &font, PointF(GetX(), GetY()), &blue);
	}
}

bool CMovingMessage::Update(double elapsed)
{
	mTimeElapsed += elapsed;
	mSizeTimer += elapsed;

	double newY = GetY() - mVelocity * elapsed;
	SetLocation(GetX(), newY);

	if (mTimeElapsed >= GetDelay())
	{
		return true;
	}

	if (mSizeTimer >= 0.5)
	{
		AddToSize(1);
		mSizeTimer = 0.0;
	}

	return false;
}
