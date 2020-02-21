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
* The function for handling tuitionUp collisions
*/
void CMoney::Collided()
{
    if (!mHit)
    {
        auto scoreboard = GetLevel()->GetGame()->GetScoreboard();
        scoreboard->AddDollars(mValue);
    }
    mHit = true;
}

/**
 * The function for updating the tuitionUp
 */
bool CMoney::Update(double elapsed)
{
    if (mHit)
    {
        if (GetY() - GetImage()->GetHeight() / 2 < 0)
        {
            return true;
        }
        double newY = GetY() + mVelocity * elapsed;
        SetLocation(GetX(), newY);
    }
    return false;
}