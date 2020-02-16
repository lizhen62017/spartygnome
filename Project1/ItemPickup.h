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

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitItemPickup(this); }

private:
    bool mActive = true; ///< Bool for determining whether or not the item is currently active
};

