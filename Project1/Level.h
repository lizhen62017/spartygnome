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

class CSpartyGnome; // Add this to support Gnome's collision
class CItem;
class CDeclaration;
class CMoneyDeclaration;//CHECK THIS

/**
 * Class representing a level in the game
 */
class CLevel
{
public:
    
    // Default constructor deleted
    CLevel() = delete;

    CLevel(const std::wstring& filename);

    void CLevel::Add(std::shared_ptr<CItem> item);

    void Load(const std::wstring& filename);

    void Clear();

    std::shared_ptr<CDeclaration> GetDeclaration(std::wstring);

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

    /**
   * where Gnome collision happens
   * \param gnome the mighty gnome
   * \return the items to be collided, nullptr if no collision
   */
    std::vector<std::shared_ptr<CItem>> CollisionTest(CSpartyGnome* gnome);

    void Draw(Gdiplus::Graphics* graphics, int scrollX);

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
    std::map<std::wstring, std::shared_ptr<CDeclaration>> mDeclarations;

    /// All of the items populating the level
    std::vector<std::shared_ptr<CItem>> mItems;

    void XmlDeclaration(const std::shared_ptr<xmlnode::CXmlNode>& node);

    void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);

    std::shared_ptr<Gdiplus::Bitmap> ImageLoad(std::wstring filename);

};

