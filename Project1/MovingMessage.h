/**
 * \file MovingMessage.h
 *
 * \author Torre Rocco
 *
 * 
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

	CMovingMessage(CGameSystem* game, std::wstring text, int textSize, std::wstring color, double delayTime);

	///copy constructor (disabled)
	CMovingMessage(const CMessage&) = delete;

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	/// \return bool The boolean to determine if it is to be deleted
	virtual bool Update(double elapsed) override;

private:
	double mVelocity = 500; ///< The velocity the message moves at

	double mSizeTimer = 0.0; ///< The time since last size addition
};

