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

private:
    bool mActive = true; ///< Bool for determining whether or not the item is currently active
};

