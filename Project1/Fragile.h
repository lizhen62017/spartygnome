/**
 * \file Fragile.h
 *
 * \author Zhen Li
 *
 * 
 */

#pragma once
#include <memory>
#include "Item.h"
#include "Level.h"
#include "Terrain.h"
#include "Declaration.h"

 /**
  * The Fragile Class
  */
class CFragile : public CTerrain
{
public:
    /// Default constructor (disabled)
    CFragile() = delete;

    /// Copy constructor (disabled)
    CFragile(const CFragile&) = delete;

    //Constructor
    CFragile(CLevel* level, const std::shared_ptr<CDeclaration> declaration);

    /* Drawing the fragile platform
    * \param graphics the graphics being drawn
    */
    void Draw(Gdiplus::Graphics* graphics, int scrollX) override;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitFragile(this); }

    /**Getter for terrain height
      * \return height of terrain
      */
    int GetHeight() override { return 32; }

    /** Getter for terrain width
    * \return width of terrain */
    int GetWidth() override { return 160; }

    void Collided() override;

    virtual bool Update(double elapsed) override;

private:
    std::shared_ptr<Gdiplus::Bitmap> mFragileImage; ///< Image of Fragile
    bool mHit = false; ///< determines when the Fragile has been hit by spartygnome

    /// Total time
    double mTimeElapsed = 0.0;
};

