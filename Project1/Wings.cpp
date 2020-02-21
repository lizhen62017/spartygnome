/**
 * \file Wings.cpp
 *
 * \author Jeremy Cowelchuk
 */

#include "pch.h"
#include "Wings.h"
#include "Level.h"
#include "GameSystem.h"
#include "SpartyGnome.h"

 /**
  * Constructor for wings when loaded from level file
  * \param level The level the wings a part of
  * \param declaration The Declaration used to instantiate this item
  */
CWings::CWings(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CItemPickup(level, declaration)
{
}


/**
 * Function to handle SpartyGnome collision with wings
 */
void CWings::Collided()
{
	mHit = true;
	GetLevel()->GetGame()->GetGnome()->Wings(true);
}

/**
* The function for updating the wings
*/
bool CWings::Update(double elapsed)
{
	if (mHit)
	{
		if (GetY() - GetImage()->GetHeight() / 2 > 1024)
		{
			return true;
		}
		double newY = GetY() + mVelocity * elapsed;
		SetLocation(GetX(), newY);
	}


	return false;
}