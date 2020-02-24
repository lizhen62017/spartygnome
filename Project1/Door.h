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

    CDoor(CLevel* level, const std::shared_ptr<CDeclaration> declaration);

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitDoor(this); }

    /// Get the width of the item
    /// \returns item width
    virtual double GetWidth() override { return GetImage()->GetWidth(); };

    /// Get the height of the item
    /// \returns item height
    virtual double GetHeight() override { return GetImage()->GetHeight(); };

    /** Define if item is collidable
    * \return value The value of whether or not it's collidable
    */
    virtual boolean IsCollidable() { return false; } //FIXME

    boolean CollideGnome(CSpartyGnome* gnome);

    void Collided() override;
};

