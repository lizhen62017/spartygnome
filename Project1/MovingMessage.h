/**
 * \file MovingMessage.h
 *
 * \author Torre Rocco
 *
 * Takes care of all moving message objects put in to the game
 */


#pragma once
#include "Message.h"


/**
 * handles message objects that move
 */
class CMovingMessage : public CMessage
{
public:
	/// default constructor (disabled)
	CMovingMessage() = delete;

	CMovingMessage(CLevel* level, std::wstring text, double textSize, std::wstring color, double delayTime);

	///copy constructor (disabled)
	CMovingMessage(const CMessage&) = delete;

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	/// \return bool The boolean to determine if it is to be deleted
	virtual bool Update(double elapsed) override;

private:
	double mVelocity = 750; ///< The velocity the message moves at

	double mSizeTimer = 0.0; ///< The time since creation

	double mStartSize; ///< The size the text starts at

	double mMaxSize = 25; ///< The greatest size the message can get to
};

