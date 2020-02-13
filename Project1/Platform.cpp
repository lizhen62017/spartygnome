/**
 * \file Platform.cpp
 *
 * \author Chase Lindeboom
 */

#include "pch.h"
#include "Platform.h"


/**
 * Constructor
 * \param level the level this Platform is a member of
 * \param filename  The filename for the image
 */
CPlatform::CPlatform(CLevel* level, const std::wstring& filename) :
    CItem(level, filename)
{
    /////FIXME
}