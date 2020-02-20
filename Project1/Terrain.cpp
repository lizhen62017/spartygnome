/**
 * \file Terrain.cpp
 *
 * \author Zhen Li
 */

#include "pch.h"
#include "Terrain.h"
#include "Level.h"
#include <string>
#include "GameSystem.h"
#include "SpartyGnome.h"

using namespace Gdiplus;
using namespace std;

/**
 * Constructor
 * \param level The level this item is a member of
 * \param filename Filename for the image we use
 
CTerrain::CTerrain(CLevel* level, const std::wstring& filename) : CItem(level, filename)
{
}*/

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
 * Function for determining if a given item has collision physics
 * \return true Terrain has collision physics 
 */
boolean CTerrain::IsCollidable()
{
    return true;
}


/**
 * Determines gnomes reaction when colliding with terrain
 */
void CTerrain::Collided()
{
    // The gnome that is collideing
    auto Gnome = GetLevel()->GetGame()->GetGnome();

    if (abs(GetY() - Gnome->GetY()) > GetHeight() / 2.0 + Gnome->GetHeight() / 2.0 - 23) //Purely vertical collision, tuned to have 23 works the best
    {
       if (Gnome->GetVelY() > 0 && GetY() > Gnome->GetY())
        {
           Gnome->FallingColide(GetY(), GetHeight());
        }
        else if (Gnome->GetVelY() < 0 && GetY() < Gnome->GetY())
        {
           Gnome->RisingColide(GetY(), GetHeight());
        }
    }

    if (abs(GetX() - Gnome->GetX()) > GetWidth() / 2.0 + Gnome->GetWidth() / 2.0 - 13) //Purely horizontal collision, tuned to have 13 works the best
    {
        if (Gnome->GetVelX() > 0 && GetX() > Gnome->GetX())
        {
            Gnome->RightColide(GetX(), GetWidth());
        }
        else if (Gnome->GetVelX() < 0 && GetX() < Gnome->GetX())
        {
            // We are moving to the left, stop at the collision point
            Gnome->LeftColide(GetX(), GetWidth());
        }
    }
}