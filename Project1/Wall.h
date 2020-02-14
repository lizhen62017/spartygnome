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
     * \param aquarium Aquarium this fish is a member of
     */
    CWall(CLevel* level, const std::wstring& filename);

    void Draw(Gdiplus::Graphics* graphics);

    /**
     * mode setter
     * \param mode mode to be set
     */
    void SetMode(int mode) { mMode = mode; };

private:
    std::unique_ptr<Gdiplus::Bitmap> mWall1Image;
    std::unique_ptr<Gdiplus::Bitmap> mWall2Image;
    int mMode = 0; ///<mode 0 Wall1, 1 Wall2
};