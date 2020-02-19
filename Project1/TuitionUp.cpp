/**
 * \file TuitionUp.cpp
 *
 * \author Jeremy Cowelchuk
 */

#include "pch.h"
#include "TuitionUp.h"

 /**
  * Constructor for a tuition-up when loaded from level file
  * \param level The level this tuition-up is a part of
  * \param declaration The Declaration used to instantiate this item
  */
CTuitionUp::CTuitionUp(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CItemPickup(level, declaration)
{
}
