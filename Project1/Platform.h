/**
 * \file Platform.h
 *
 * \author Chase Lindeboom
 *
 * Class representing a platform item
 */

#pragma once
#include "Item.h"
#include "Level.h"

/**
 * Class representing a platform item in our game
 */
class CPlatform :
	public CItem
{
public:
    /// Default constructor (disabled)
    CPlatform() = delete;

    /// Copy constructor (disabled)
    CPlatform(const CPlatform&) = delete;

    CPlatform(CLevel* level, const std::wstring& filename);

private:
    /// Width of platform
    double mWidth = 0;

    /// Height of platform
    double mHeight = 0;

    /// Left image for the platform 
    Gdiplus::Bitmap* mLeftImage;
    /// Mid image for the platform
    Gdiplus::Bitmap* mMidImage;
    /// Right image for the platform
    Gdiplus::Bitmap* mRightImage;
};

