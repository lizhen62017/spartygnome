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
#include "Declaration.h"

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

    CPlatform(CLevel* level, const std::shared_ptr<CDeclaration> declaration);

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

    void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

private:
    /// Width of platform, needs to stack up image by image
    double mWidth = 0;

    /// Height of platform
    double mHeight = 0;

    // image for the left of the platform
    //std::shared_ptr<Gdiplus::Bitmap> mLeftImage; FIXME May be redundant with mItemImage.

    /// Image for the middle of the platform
    std::shared_ptr<Gdiplus::Bitmap> mMidImage;

    /// Image for the right of the platform
    std::shared_ptr<Gdiplus::Bitmap> mRightImage;

    std::unique_ptr<Gdiplus::Bitmap> mGrassImage; ///< Grass Image
    std::unique_ptr<Gdiplus::Bitmap> mGrassMidImage; ///< Grass Mid Image
    std::unique_ptr<Gdiplus::Bitmap> mGrassLeftImage; ///< Grass Left Image
    std::unique_ptr<Gdiplus::Bitmap> mGrassRightImage; ///< Grass Right Image
    std::unique_ptr<Gdiplus::Bitmap> mSnowImage; ///< Snow Image
    std::unique_ptr<Gdiplus::Bitmap> mSnowMidImage; ///< Snow Mid Image
    std::unique_ptr<Gdiplus::Bitmap> mSnowLeftImage; ///< Snow Left Image
    std::unique_ptr<Gdiplus::Bitmap> mSnowRightImage; ///< Snow Right Image
    std::unique_ptr<Gdiplus::Bitmap> mIndustrialImage; ///< Industrial Image
    std::unique_ptr<Gdiplus::Bitmap> mIndustrialMidImage; ///< Industrial Mid Image
    std::unique_ptr<Gdiplus::Bitmap> mIndustrialLeftImage; ///< Industrial Left Image
    std::unique_ptr<Gdiplus::Bitmap> mIndustrialRightImage; ///< Industrial Right Image
    int isEdge = 0; ///< 0 if Mid, 1 if Left, 2 if Right, 3 if Only
    int mMode = 0; ///<mode 0 grass, 1 snow, 2 industrial
};

