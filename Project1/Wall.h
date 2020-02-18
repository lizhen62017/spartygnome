/**
 * \file Wall.h
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
 * The Wall Class
 */
class CWall : public CTerrain
{
public:
    /// Default constructor (disabled)
    CWall() = delete;

    /// Copy constructor (disabled)
    CWall(const CWall&) = delete;

    /**
     * Constructor
     */
    CWall(CLevel* level, const std::wstring& filename);

    CWall(CLevel* level, const std::shared_ptr<CDeclaration> declaration);

    /* Drawing the wall
    * \param graphics the graphics being drawn 
    */
    void Draw(Gdiplus::Graphics* graphics, int scrollX) override;

    /**
     * mode setter
     * \param mode mode to be set
     */
    void SetMode(int mode) { mMode = mode; };

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitWall(this); }

private:
    std::unique_ptr<Gdiplus::Bitmap> mWall1Image; ///< Image of Wall1
    std::unique_ptr<Gdiplus::Bitmap> mWall2Image; ///< Image of Wall2
    int mMode = 0; ///<mode 0 Wall1, 1 Wall2
};