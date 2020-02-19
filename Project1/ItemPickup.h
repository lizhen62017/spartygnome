/**
 * \file ItemPickup.h
 *
 * \author Jeremy Cowelchuk
 *
 * 
 */

#pragma once
#include "Item.h"
/**
 * Class for temporary pickup items
 */
class CItemPickup :
	public CItem
{
public:

    /// default constructor (disabled)
    CItemPickup() = delete;

    CItemPickup(CLevel* level, const std::shared_ptr<CDeclaration> declaration);

    ///copy constructor (disabled)
    CItemPickup(const CItemPickup&) = delete;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitItemPickup(this); }

    /// Get the width of the item
    /// \returns item width
    virtual int GetWidth() { return 0; };

    /// Get the height of the item
    /// \returns item height
    virtual int GetHeight() {return 0;};

    /**
    * Function for determining if an object has collision physics
    * \return False Pickup items do not have collision physics as expected.
    */
    boolean IsCollidable() override;

    void Collided() override {}

private:
    bool mActive = true; ///< Bool for determining whether or not the item is currently active
};

