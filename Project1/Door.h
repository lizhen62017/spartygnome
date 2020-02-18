/**
 * \file Door.h
 *
 * \author Robert Gustke
 *
 * Class for door items
 */

#pragma once
#include "Item.h"
#include <string>
#include "SpartyGnome.h"

class CSpartyGnome;

/**
 * Class for a single door
 */
class CDoor :
	public CItem
{
public:
    /// default constructor (disabled)
    CDoor() = delete;

    ///copy constructor (disabled)
    CDoor(const CDoor&) = delete;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitDoor(this); }

    CDoor(CLevel* level, const std::shared_ptr<CDeclaration> declaration);

    /** Getter for terrain height
     * \return height of terrain */
    int GetHeight() override { return mItemImage->GetHeight(); }

    /** Getter for terrain width
    * \return width of terrain */
    int GetWidth() override { return mItemImage->GetWidth(); }

    boolean CollideGnome(CSpartyGnome* gnome);

private:
    /// The image of door
    std::shared_ptr<Gdiplus::Bitmap> mItemImage;
};

