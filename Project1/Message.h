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

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitMessage(this); }

	/// Get the width of the item
	/// \returns item width
	virtual int GetWidth() { return 0; };

	/// Get the height of the item
	/// \returns item height
	virtual int GetHeight() { return 0; };

	/**
	* Function for determining if an object has collision physics
	* \return False Pickup items do not have collision physics as expected.
	*/
	boolean IsCollidable() override;

	/// Draw this item
	/// \param graphics Graphics device to draw on
	/// \param scrollX the distance the gnome has scrolled
	virtual void Draw(Gdiplus::Graphics* graphics, int scrollX) override;

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual bool Update(double elapsed) override;

	void Collided() override {}

private:
	double mDelayTime = 0; ///< The value of a given messsages delay

	double mTimeElapsed = 0; ///< The time since creation

	int mTextSize = 0; ///< The value of the text size

	std::wstring mText; ///< text the message displays

	std::wstring mColor; ///< color that the message displays
};

