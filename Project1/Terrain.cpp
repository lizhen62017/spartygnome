/**
 * \file Terrain.cpp
 *
 * \author Zhen Li
 */

#include "pch.h"
#include "Terrain.h"
#include "Level.h"
#include <string>

using namespace Gdiplus;
using namespace std;

/**
 * Constructor
 * \param level The level this item is a member of
 * \param filename Filename for the image we use
 */
CTerrain::CTerrain(CLevel* level, const std::wstring& filename) : CItem(level, filename)
{
}

/**
 * Constructor
 * \param level The level this item is a member of
 * \param declaration A pointer to the Declaration used to instantiate this object
 */
CTerrain::CTerrain(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CItem(level, declaration)
{
}


/**Loads the attributes of a Platform item from an Xml Node
 * \param node The Xml node we are loading the platform from
 */
void CTerrain::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> & node)
{
    mWidth = node->GetAttributeDoubleValue(L"width", 0);
    mHeight = node->GetAttributeDoubleValue(L"height", 0);

    CItem::XmlLoad(node);
}

    /** Getter for terrain height
     * \return height of terrain */
int CTerrain::GetHeight()
{
    return mHeight;
}

    /** Getter for terrain width
     * \return width of terrain */
int CTerrain::GetWidth()
{
    return mWidth;
}


/**
 * Function for determining if a given item has collision physics
 * \return true Terrain has collision physics 
 */
boolean CTerrain::IsCollidable()
{
    return true;
}