/**
 * \file Money.cpp
 *
 * \author Jeremy Cowelchuk
 */

#include "pch.h"
#include "Money.h"
#include "MoneyEvaluator.h"
#include "Scoreboard.h"


 /**
  * Constructor for a money when loaded from level file
  * \param level The level this money is a part of
  * \param declaration The Declaration used to instantiate this item
  */
CMoney::CMoney(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CItemPickup(level, declaration)
{
    CMoneyEvaluator visitor;
    declaration->Accept(&visitor);
    mValue = visitor.GetMoneyValue();
}

/**
* The function for handling money collisions
*/
void CMoney::Collided()
{
    if (!mHit)
    {
        if (mValue > 0)
        {
            PlaySound(TEXT("data/sounds/coin-sound.wav"), NULL, SND_ASYNC);
        }
        else if (mValue > 2500)
        {
            PlaySound(TEXT("data/sounds/bigMoney.wav"), NULL, SND_ASYNC);
        }
        else
        {
            PlaySound(TEXT("data/sounds/error.wav"), NULL, SND_ASYNC);
        }
        auto scoreboard = GetLevel()->GetGame()->GetScoreboard();
        scoreboard->AddDollars(mValue);
    }
    mHit = true;
}

/**
 * The function for updating the money
 * Handle updates for animation
 * \param elapsed The time since the last update
 * \returns false if the item becomes marked for deletion,
 * true if not
 */
bool CMoney::Update(double elapsed)
{
    if (mHit)
    {
        // doesn't delete item until it is offscreen
        if (GetY() - GetImage()->GetHeight() / 2 < 0)
        {
            return true;
        }
        double newY = GetY() + mVelocity * elapsed;
        SetLocation(GetX(), newY);
    }
    return false;
}