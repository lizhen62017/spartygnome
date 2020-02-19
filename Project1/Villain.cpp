/**
 * \file Villain.cpp
 *
 * \author Jeremy Cowelchuk
 */

#include "pch.h"
#include "Villain.h"


CVillain::CVillain(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CItem(level, declaration)
{
}