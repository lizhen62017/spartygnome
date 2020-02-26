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

    /// Level constructor declaration
    CPlatform(CLevel* level, const std::shared_ptr<CDeclaration> declaration);

    void Draw(Gdiplus::Graphics* graphics, float scrollX) override;
    
    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitPlatform(this); }

private:

    /// Image for the middle of the platform
    std::shared_ptr<Gdiplus::Bitmap> mMidImage;

    /// Image for the right of the platform
    std::shared_ptr<Gdiplus::Bitmap> mRightImage;
};

