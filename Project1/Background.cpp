/**
 * \file Background.cpp
 *
 * \author Chase Lindeboom
 */

#include "pch.h"

#include "Background.h"

using namespace Gdiplus;

/**
 * Constructor for a Background when loaded from level file
 * \param level The level this background is a part of
 * \param declaration The Declaration used to instantiate this item 
 */
CBackground::CBackground(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CItem(level, declaration)
{
}

