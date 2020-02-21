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
class CItemVisitor;
class CGameSystem;

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

	/**  Setter for level start position x value
	* \param level start position x value */
	void SetStartX(double locX) { mStartX = locX; }

    /**  Getter for level start position y value
     * \return level start position y value */
    double GetStartY() { return mStartY; }

	/**  Setter for level start position y value
	* \param level start position y value */
	void SetStartY(double locY) { mStartY = locY; }

    CGameSystem* GetGame() { return mGame; }


  
   // void Draw(Gdiplus::Graphics* graphics, int scrollX);

    void Accept(CItemVisitor* visitor);

	void Install();


private:
	/// The game object the level is in 
	CGameSystem* mGame;

    /// Level width in virtual pixels
    double mWidth;

    /// Level hieght in virtual pixels
    double mHeight;

    /// Initial starting point for SpartyGnome on X-axis
    double mStartX;

    /// Initial starting point for SpartyGnome on Y-axis
    double mStartY;

    std::wstring mFilename;

    /// All of the item declarations
    std::map<std::wstring, std::shared_ptr<CDeclaration>> mDeclarations;

    /// All of the items populating the level
    std::vector<std::shared_ptr<CItem>> mItems;

    void Load(const std::wstring& filename);

    void XmlDeclaration(const std::shared_ptr<xmlnode::CXmlNode>& node);

    void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);

    std::shared_ptr<Gdiplus::Bitmap> ImageLoad(std::wstring filename);

};

