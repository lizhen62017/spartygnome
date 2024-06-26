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
#include <mmsystem.h>

#include "XmlNode.h"
#include "Declaration.h"
#include "ItemVisitor.h"


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

	/** The Level the item is in
	* \returns Level the item is associated with */
	CLevel* GetLevel() { return mLevel; }

	/** The image belonging to the item
	 * \returns The item's image */
	std::shared_ptr<Gdiplus::Bitmap> GetImage() {return mItemImage;}

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	void SetLocation(double x, double y) { mX = x; mY = y; }

	/// Draw this item
	/// \param graphics Graphics device to draw on
	/// \param scrollX the distance the gnome has scrolled
	virtual void Draw(Gdiplus::Graphics* graphics, float scrollX);

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	/// \returns false
	virtual bool Update(double elapsed) { return false; }

	/// Get the width of the item
	/// \returns item width
	virtual double GetWidth() { return GetImage()->GetWidth(); };

	/// Get the height of the item
	/// \returns item height
	virtual double GetHeight() { return GetImage()->GetHeight(); };

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);


	CItem(CLevel* level, const std::shared_ptr<CDeclaration> declaration);

	CItem(CLevel* level);

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) = 0;

	/// Handles results of a collision with an item
	virtual void Collided() = 0;

private:
	/// The level this item is contained in
	CLevel* mLevel;

	// Item location in the level
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item

	/// The image of this item
	std::shared_ptr<Gdiplus::Bitmap> mItemImage;

	/// id given to specific item if it needs to be copied
	std::wstring mID;
};

