/**
 * \file Terrain.cpp
 *
 * \author Zhen Li
 */

#include "pch.h"
#include "Terrain.h"

using namespace Gdiplus;
using namespace std;

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


/**
 * Determines gnomes reaction when colliding with terrain
 */
void CTerrain::Collided()
{
    GetLevel()->GetGame()->GetGnome()->TerrainColide(GetX(), GetY(), GetWidth(), GetHeight());
}