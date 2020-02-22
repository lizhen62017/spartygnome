/**
 * \file TuitionUp.cpp
 *
 * \author Jeremy Cowelchuk
 */

#include "pch.h"
#include "TuitionUp.h"
#include "Level.h"
#include "GameSystem.h"
#include "Scoreboard.h"

 /**
  * Constructor for a tuition-up when loaded from level file
  * \param level The level this tuition-up is a part of
  * \param declaration The Declaration used to instantiate this item
  */
CTuitionUp::CTuitionUp(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CItemPickup(level, declaration)
{
}


/**
* The function for handling tuitionUp collisions
*/
void CTuitionUp::Collided()
{
	if (!mHit)
	{
		GetLevel()->GetGame()->GetScoreboard()->UpdateMultiplier(0.1);;
        PlaySound(TEXT("data/sounds/tuitionUp.wav"), NULL, SND_ASYNC);
	}
	mHit = true;
}

/**
 * The function for updating the tuitionUp
 * Handle updates for animation
 * \param elapsed The time since the last update
 * \returns false if the item becomes marked for deletion,
 * true if not
 */
bool CTuitionUp::Update(double elapsed)
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