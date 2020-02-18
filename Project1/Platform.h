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
#include "Terrain.h"
#include "Declaration.h"

/**
 * Class representing a platform item in our game
 */
class CPlatform :
	public CTerrain
{
public:
    /// Default constructor (disabled)
    CPlatform() = delete;

    /// Copy constructor (disabled)
    CPlatform(const CPlatform&) = delete;

    //CPlatform::CPlatform(CLevel* level, const std::wstring& filename);

    /// Level constructor declaration
    CPlatform(CLevel* level, const std::shared_ptr<CDeclaration> declaration);

    void Draw(Gdiplus::Graphics* graphics, int scrollX) override;


     
    //void SetIsEdge(int edge) { isEdge = edge; };


      
    //void SetMode(int mode) { mMode = mode; };
    
    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitPlatform(this); }

private:

    // image for the left of the platform
    //std::shared_ptr<Gdiplus::Bitmap> mLeftImage; FIXME May be redundant with mItemImage.

    /// Image for the middle of the platform
    std::shared_ptr<Gdiplus::Bitmap> mMidImage;

    /// Image for the right of the platform
    std::shared_ptr<Gdiplus::Bitmap> mRightImage;
    /**
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
    */
};

