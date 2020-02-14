/**
 * \file Platform.h
 *
 * \author Chase Lindeboom
 *
 * Class representing a platform item
 */

#pragma once
#include <memory>
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

    CPlatform::CPlatform(CLevel* level, const std::wstring& filename);

    void Draw(Gdiplus::Graphics* graphics);

    /**
     * shape setter
     * \param edge decide whether shape should go as edge or not
     */
    void SetIsEdge(int edge) { isEdge = edge; };

    /**
      * mode setter
      * \param mode mode to be set
      */
    void SetMode(int mode) { mMode = mode; };

private:
    /// Width of platform, needs to stack up image by image
    double mWidth = 0;

    /// Height of platform
    double mHeight = 0;

    std::unique_ptr<Gdiplus::Bitmap> mGrassImage;
    std::unique_ptr<Gdiplus::Bitmap> mGrassMidImage;
    std::unique_ptr<Gdiplus::Bitmap> mGrassLeftImage;
    std::unique_ptr<Gdiplus::Bitmap> mGrassRightImage;
    std::unique_ptr<Gdiplus::Bitmap> mSnowImage;
    std::unique_ptr<Gdiplus::Bitmap> mSnowMidImage;
    std::unique_ptr<Gdiplus::Bitmap> mSnowLeftImage;
    std::unique_ptr<Gdiplus::Bitmap> mSnowRightImage;
    std::unique_ptr<Gdiplus::Bitmap> mIndustrialImage;
    std::unique_ptr<Gdiplus::Bitmap> mIndustrialMidImage;
    std::unique_ptr<Gdiplus::Bitmap> mIndustrialLeftImage;
    std::unique_ptr<Gdiplus::Bitmap> mIndustrialRightImage;
    int isEdge = 0; ///< 0 if Mid, 1 if Left, 2 if Right, 3 if Only
    int mMode = 0; ///<mode 0 grass, 1 snow, 2 industrial
};

