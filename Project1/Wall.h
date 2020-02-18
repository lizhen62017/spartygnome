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

    //Constructor
    CWall(CLevel* level, const std::shared_ptr<CDeclaration> declaration);

    /* Drawing the wall
    * \param graphics the graphics being drawn 
    */
    void Draw(Gdiplus::Graphics* graphics, int scrollX) override;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitWall(this); }

private:
    std::shared_ptr<Gdiplus::Bitmap> mWallImage; ///< Image of Wall
};