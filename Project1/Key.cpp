/**
 * \file Key.cpp
 *
 * \author Torre Rocco
 */

#include "pch.h"
#include "Key.h"
#include "Level.h"
#include "GameSystem.h"
#include "SpartyGnome.h"


 /**
  * Constructor for the key when loaded from level file
  * \param level The level the key is a part of
  * \param declaration The Declaration used to instantiate this item
  */
CKey::CKey(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
	CItemPickup(level, declaration)
{
}


/**
 * Function to handle SpartyGnome collision with the key
 */
void CKey::Collided()
{
	if (!mHit)
	{
		GetLevel()->GetGame()->GetGnome()->Key(true);
	}
	mHit = true;
}


/**
* The function for updating the key
*/
bool CKey::Update(double elapsed)
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
