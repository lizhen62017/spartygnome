/**
 * \file Wings.cpp
 *
 * \author Jeremy Cowelchuk
 */

#include "pch.h"
#include "Wings.h"

 /**
  * Constructor for wings when loaded from level file
  * \param level The level the wings a part of
  * \param declaration The Declaration used to instantiate this item
  */
CWings::CWings(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CItemPickup(level, declaration)
{
}
