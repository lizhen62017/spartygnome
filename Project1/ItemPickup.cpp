/**
 * \file ItemPickup.cpp
 *
 * \author Jeremy Cowelchuk
 */

#include "pch.h"
#include "ItemPickup.h"


/**
 * CItemPickup Constructor
 * \param level The level this item is a part of
 * \param declaration Declaration used to instantiate this item
 */
CItemPickup::CItemPickup(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CItem(level, declaration)
{
}


/**
 * Checks if SpartyGnome can collide with this item
 * \returns false
 */
boolean CItemPickup::IsCollidable()
{
    return false;
}