/**
 * \file TuitionUp.cpp
 *
 * \author Jeremy Cowelchuk
 */

#include "pch.h"
#include "TuitionUp.h"
#include "Item.h"
#include "Level.h"
#include "GameSystem.h"
#include "Scoreboard.h"
#include "MovingMessage.h"
#include <memory>

using namespace std;

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
		auto game = GetLevel()->GetGame();
		game->GetScoreboard()->UpdateMultiplier();;
        PlaySound(TEXT("data/sounds/tuitionUp.wav"), NULL, SND_ASYNC);

		shared_ptr<CItem> item;

		float t = game->GetVirtualWidth();

		item = make_shared<CMovingMessage>(GetLevel(), L"Tuition Increase!", 80, L"green", 2.0);
		item->SetLocation(GetX(), GetY());
		game->Add(item);
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