/**
 * \file Money.cpp
 *
 * \author Jeremy Cowelchuk
 */

#include "pch.h"
#include "Money.h"
#include "Level.h"
#include "MoneyEvaluator.h"
#include "Scoreboard.h"
#include "Message.h"
#include <memory>

using namespace std;

 /**
  * Constructor for a money when loaded from level file
  * \param level The level this money is a part of
  * \param declaration The Declaration used to instantiate this item
  */
CMoney::CMoney(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CItem(level, declaration)
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
		shared_ptr<CItem> item;

        if (mValue > 2500)
        {
            PlaySound(TEXT("data/sounds/bigMoney.wav"), NULL, SND_ASYNC);
			item = make_shared<CMessage>(GetLevel(), L"$" + std::to_wstring(int(mValue)), 25, L"green", 2.0);
        }
        else if (mValue > 0)
        {
            PlaySound(TEXT("data/sounds/coin-sound.wav"), NULL, SND_ASYNC);
			item = make_shared<CMessage>(GetLevel(), L"$" + std::to_wstring(int(mValue)), 25, L"green", 2.0);
        }
        else
        {
            PlaySound(TEXT("data/sounds/error.wav"), NULL, SND_ASYNC);
			item = make_shared<CMessage>(GetLevel(), L"$" + std::to_wstring(int(mValue)), 25, L"red", 2.0);
        }
        auto scoreboard = GetLevel()->GetGame()->GetScoreboard();
        scoreboard->AddDollars(mValue);

		item->SetLocation(GetX() - (45 - GetLevel()->GetOffset()), GetY());
		GetLevel()->GetGame()->Add(item);
    }
    mHit = true;
}

/**
 * The function for updating the money
 * Handles updates for animation
 * \param elapsed The time since the last update
 * \returns false if the item becomes marked for deletion, true if not
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