/**
 * \file ItemPickup.cpp
 *
 * \author Jeremy Cowelchuk
 */

#include "pch.h"
#include "ItemPickup.h"

CItemPickup::CItemPickup(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CItem(level, declaration)
{
}

boolean CItemPickup::IsCollidable()
{
    return false;
}