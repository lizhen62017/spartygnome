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

class CGameSystem;
class CSpartyGnome;
class CDeclaration;
class CMoneyDeclaration;
class CItem;
class CItemVisitor;


/**
 * Class representing a level in the game
 */
class CLevel
{
public:
    
    // Default constructor deleted
    CLevel() = delete;

    CLevel(CGameSystem* game, const std::wstring& filename);

    void CLevel::Add(std::shared_ptr<CItem> item);

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

    /**  Getter for game system level is a part of
     * \return the game system */
    CGameSystem* GetGame() { return mGame; }

    /**  Setter for level start offset
    * \param loc start offset for gnome */
    void SetOffset(double loc) { mGnomeOffset = loc; }

    /**  Getter for level offset
    * \return level offset */
    double GetOffset() { return mGnomeOffset; }

    void Accept(CItemVisitor* visitor);

	void Install();


private:
	/// The game object the level is in 
	CGameSystem* mGame;

    /// Level width in virtual pixels
    double mWidth;

    /// Level height in virtual pixels
    double mHeight;

    /// Initial starting point for SpartyGnome on X-axis
    double mStartX;

    /// Initial starting point for SpartyGnome on Y-axis
    double mStartY;

    /// The Filename used to instantiate the level
    std::wstring mFilename;

    /// All of the item declarations
    std::map<std::wstring, std::shared_ptr<CDeclaration>> mDeclarations;

    /// All of the items populating the level
    std::vector<std::shared_ptr<CItem>> mItems;

    /// scroll offset of level
    double mGnomeOffset;

    void Load(const std::wstring& filename);

    void XmlDeclaration(const std::shared_ptr<xmlnode::CXmlNode>& node);

    void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);

    std::shared_ptr<Gdiplus::Bitmap> ImageLoad(std::wstring filename);

};

