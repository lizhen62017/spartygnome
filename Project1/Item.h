/**
 * \file Item.h
 *
 * \author Chase Lindeboom
 *
 * Base class representing an item in a level
 */

#pragma once


#include <memory>
#include <string>

#include "XmlNode.h"

class CLevel;

/**
 * Base class for any item in our game.
 */
class CItem
{
public:
	virtual ~CItem();

	/// Default constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem&) = delete;

	/** The X location of the item
	* \returns X location in pixels */
	double GetX() const { return mX; }

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mY; }

	/** The Aquarium the item is in
	* \returns Level the item is associated with */
	CLevel* GetLevel() { return mLevel; }

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	void SetLocation(double x, double y) { mX = x; mY = y; }

	/// Draw this item
	/// \param graphics Graphics device to draw on
	void Draw(Gdiplus::Graphics* graphics, int scrollX);

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}

	/// Get the width of the item
	/// \returns item width
	int GetWidth() const { return mItemImage->GetWidth(); }

	/// Get the height of the item
	/// \returns item height
	int GetHeight() const { return mItemImage->GetHeight(); }

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

protected:
	CItem(CLevel* level, const std::wstring& filename);

private:
	/// The level this item is contained in
	CLevel* mLevel;

	// Item location in the level
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item

	/// The image of this item
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;

	/// id given to specific item if it needs to be copied
	std::wstring mID;
};

