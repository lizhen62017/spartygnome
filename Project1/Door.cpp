/**
 * \file Door.cpp
 *
 * \author Robert Gustke
 */


#include "pch.h"

#include<string>
#include "Door.h"
#include "MovingMessage.h"

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
	auto Gnome = GetLevel()->GetGame()->GetGnome();

    if (CollideGnome(Gnome))
    {
		if (Gnome->GetKey())
		{
			GetLevel()->GetGame()->SetLevelUp(true);
		}
		else
		{
			if (!mDoorMessage)
			{ 
				shared_ptr<CItem> item;
				item = make_shared<CMovingMessage>(GetLevel(), L"Forgot the Key!", 10, L"blue", 0.3);
				item->SetLocation(GetX() - 190, GetY());
				GetLevel()->GetGame()->Add(item);
				mDoorMessage = true;
			}
		}
    }
}


/**
 * The function for adding another door message
 * Handle updates for animation
 * \param elapsed The time since the last update
 * \returns false 
 */
bool CDoor::Update(double elapsed)
{

	if (mDoorMessage)
	{
		mTimeElapsed += elapsed;

		if (mTimeElapsed >= 5.0)
		{
			mDoorMessage = false;
			mTimeElapsed = 0;
		}
	}

	return false;
}


