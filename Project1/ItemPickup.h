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

    ///copy constructor (disabled)
    CItemPickup(const CItemPickup&) = delete;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitItemPickup(this); }

    /**
    * Function for determining if an object has collision physics
    * \return False Pickup items do not have collision physics as expected.
    */
    boolean IsCollidable() override;

private:
    bool mActive = true; ///< Bool for determining whether or not the item is currently active
};

