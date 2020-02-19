/**
 * \file Money.cpp
 *
 * \author Jeremy Cowelchuk
 */

#include "pch.h"
#include "Money.h"


 /**
  * Constructor for a money when loaded from level file
  * \param level The level this money is a part of
  * \param declaration The Declaration used to instantiate this item
  */
CMoney::CMoney(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CItemPickup(level, declaration)
{
}