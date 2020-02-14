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

class CWall : public CItem
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

    /* Drawing the wall
    * \param graphics the graphics being drawn 
    */
    void Draw(Gdiplus::Graphics* graphics);

    /**
     * mode setter
     * \param mode mode to be set
     */
    void SetMode(int mode) { mMode = mode; };

private:
    std::unique_ptr<Gdiplus::Bitmap> mWall1Image; ///< Image of Wall1
    std::unique_ptr<Gdiplus::Bitmap> mWall2Image; ///< Image of Wall2
    int mMode = 0; ///<mode 0 Wall1, 1 Wall2
};