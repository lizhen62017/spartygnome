/**
 * \file Message.h
 *
 * \author Torre Rocco
 *
 * 
 */

#pragma once
#include "Item.h"



/**
 * Implements all of the messages in the game 
 */
class CMessage : public CItem
{
public:
	/// default constructor (disabled)
	CMessage() = delete;

	CMessage(CGameSystem* game, std::wstring text, int textSize, std::wstring color, double delayTime);

	///copy constructor (disabled)
	CMessage(const CMessage&) = delete;

private:
	double mDelayTime = 0; ///< The value of a given messsages delay

	double mElapsedTime = 0; ///< The time since creation

	int mTextSize = 0; ///< The value of the text size

	std::wstring mText; ///< text the message displays

	std::wstring mColor; ///< color that the message displays
};

