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

	/// Draw this item
	/// \param graphics Graphics device to draw on
	/// \param scrollX the distance the gnome has scrolled
	virtual void Draw(Gdiplus::Graphics* graphics, int scrollX) override;

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual bool Update(double elapsed) override;

private:
	double mVelocity = 500; ///< The velocity the message moves at

	int mSizeMultiplier = 0; ///< The number the size is multiplied by

	double mTimeElapsed = 0.0; ///< The time since creation

	double mSizeTimer = 0.0; ///< The time since last size addition
};

