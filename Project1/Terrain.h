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
#include "SpartyGnome.h"

/**
 * Abstract Base class representing terrain (walls and platforms) 
 */
class CTerrain : public CItem
{
public:
    /// Default constructor (disabled)
    CTerrain() = delete;

    /// Copy constructor (disabled)
    CTerrain(const CTerrain&) = delete;

    //CTerrain::CTerrain(CLevel* level, const std::wstring& filename);

    CTerrain(CLevel* level, const std::shared_ptr<CDeclaration> declaration);

    /** Getter for terrain height
     * \return height of terrain */
    double GetHeight() override { return mHeight; }

    /** Getter for terrain width
    * \return width of terrain */
    double GetWidth() override { return mWidth; }

    void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    void Collided() override;

private:
    /// The height of the terrain
    double mHeight = 0;

    /// The width of the terrain
    double mWidth = 0;
};

