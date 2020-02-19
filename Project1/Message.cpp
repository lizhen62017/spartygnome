/**
 * \file Message.cpp
 *
 * \author Torre Rocco
 */

#include "pch.h"
#include "Message.h"

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