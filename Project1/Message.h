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

	CMessage(CLevel* level, std::wstring text, double textSize, std::wstring color, double delayTime);

	///copy constructor (disabled)
	CMessage(const CMessage&) = delete;

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitMessage(this); }

	/// Get the width of the item
	/// \returns item width
	virtual double GetWidth() { return 0; };

	/// Get the height of the item
	/// \returns item height
	virtual double GetHeight() { return 0; };

	/**
	* Function for determining if an object has collision physics
	* \return False Pickup items do not have collision physics as expected.
	*/
	boolean IsCollidable() override;

	/// Draw this item
	/// \param graphics Graphics device to draw on
	/// \param scrollX the distance the gnome has scrolled
	virtual void Draw(Gdiplus::Graphics* graphics, float scrollX) override;

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	/// \return The boolean for it is it to be deleted
	virtual bool Update(double elapsed) override;

	/// Handle collisions when it's collided with
	void Collided() override {}

	/// adds to the size of the message
	/// \param size int to add
	void SetSize(double size) { mTextSize = size; }

	/// gets the size of the message
	/// \returns mTextsize size of text
	double GetSize() { return mTextSize; }

	/// gets the delay of the message
	/// \returns mDelayTime delay 
	double GetDelay() { return mDelayTime; }

private:
	double mDelayTime = 0; ///< The value of a given messsages delay

	double mTimeElapsed = 0; ///< The time since creation

	double mTextSize = 0; ///< The value of the text size

	std::wstring mText; ///< text the message displays

	std::wstring mColor; ///< color that the message displays
};

