/**
 * \file Door.cpp
 *
 * \author Robert Gustke
 */


#include "pch.h"
#include "Door.h"
#include<string>

using namespace Gdiplus;
using namespace std;

/// Collision distance for the door in pixels
const double CollisionDistance = 20;

/**
 * Basic contructor for a door
 * \param level the level the door is in
 * \param declaration the declaration of a given object
 */
CDoor::CDoor(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CItem(level, declaration)
{
}

/**
* The function for handling what happens with the gnome collides with a door
* \param gnome The gnome colliding into the door object
* \return bool The check to see if the gnome is far enough in the door to enable level switching.
*/
boolean CDoor::CollideGnome(CSpartyGnome* gnome)
{
    // Collision for door is different
    double dx = gnome->GetX() - GetX();
    double dy = gnome->GetY() - GetY();
    double distance = sqrt(dx * dx + dy * dy);
    if (distance < CollisionDistance)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
* Function for switching levels when the gnome collides with a door
*/
void CDoor::Collided()
{
    GetLevel()->GetGame()->SetLevelUp(true);
}


