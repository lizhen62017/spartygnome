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
 * \param filename the name of the door image
 */
CDoor::CDoor(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CItem(level, declaration)
{
}

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

void CDoor::Collided()
{
    int temp = GetLevel()->GetGame()->GetLevel(); //Get integer level number
    if (temp < 3)
    {
        GetLevel()->GetGame()->ChangeLevel(temp + 1); //engage level
    }
    else
    {
        GetLevel()->GetGame()->ChangeLevel(temp); //loop at level 3
    }
}


