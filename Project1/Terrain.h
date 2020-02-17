/**
 * \file Terrain.h
 *
 * \author Zhen Li
 *
 * 
 */

#pragma once
#include "Item.h"
#include "Level.h"
#include "Declaration.h"

class CTerrain : public CItem
{
public:
    /// Default constructor (disabled)
    CTerrain() = delete;

    /// Copy constructor (disabled)
    CTerrain(const CTerrain&) = delete;

    CTerrain::CTerrain(CLevel* level, const std::wstring& filename);

    CTerrain(CLevel* level, const std::shared_ptr<CDeclaration> declaration);

    void Draw(Gdiplus::Graphics* graphics, int scrollX) override;

private:
    /// The image of this item
    std::shared_ptr<Gdiplus::Bitmap> mItemImage;
};

