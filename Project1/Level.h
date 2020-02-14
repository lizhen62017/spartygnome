/**
 * \file Level.h
 *
 * \author Chase Lindeboom
 *
 * Class representing a level in our gamesystem
 */

#pragma once

#include <vector>
#include <memory>
#include <string>
#include <map>

#include "XmlNode.h"
#include "Declaration.h"

class CItem;

/**
 * Class representing a level in the game
 */
class CLevel
{
public:
    
    CLevel() = delete;

    CLevel(const std::wstring& filename);

    void CLevel::Add(std::shared_ptr<CItem> item);

    void Load(const std::wstring& filename);

    void Clear();

    /**  Getter for level width
     * \return level width */
    double GetWidth() { return mWidth; }

    /**  Getter for level height
     * \return level height */
    double GetHeight() { return mHeight; }

    /**  Getter for level start position x value
     * \return level start position x value */
    double GetStartX() { return mStartX; }

    /**  Getter for level start position y value
     * \return level start position y value */
    double GetStartY() { return mStartY; }

private:
    /// Level width in virtual pixels
    double mWidth;

    /// Level hieght in virtual pixels
    double mHeight;

    /// Initial starting point for SpartyGnome on X-axis
    double mStartX;

    /// Initial starting point for SpartyGnome on Y-axis
    double mStartY;

    /// All of the item declarations
    std::map<std::wstring, CDeclaration> mDeclarations;

    /// All of the items populating the level
    std::vector<std::shared_ptr<CItem>> mItems;

    void XmlDeclaration(const std::shared_ptr<xmlnode::CXmlNode>& node);

    void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);

};

