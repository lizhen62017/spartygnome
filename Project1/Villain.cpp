/**
 * \file Villain.cpp
 *
 * \author Jeremy Cowelchuk
 */

#include "pch.h"
#include "Villain.h"
#include "Level.h"
#include "GameSystem.h"
#include "SpartyGnome.h"

/// The maximum allowed distance a villain is allowed to move
const double MaxTravelDistance = 300;

/** 
* The declaration constructor for the Villain class
* \param level The level the villain is a part of
* \param declaration The declaration of a given Villain object
*/
CVillain::CVillain(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CItem(level, declaration)
{
}

/**
* The function for handling Villain collisions
*/
void CVillain::Collided()
{
    auto Gnome = GetLevel()->GetGame()->GetGnome();
    Gnome->Death(true);
}

/**
* The function for moving the villain
* \param elapsed The time since the last villain update
* \return false The villain is to be never removed
*/
bool CVillain::Update(double elapsed)
{
    double newY = this->GetY() - mVelocityY * elapsed;

    mTraveled += mVelocityY * elapsed;

    this->SetLocation(this->GetX(), newY);

    if (mTraveled > MaxTravelDistance || mTraveled < -MaxTravelDistance)
    {
        mVelocityY = -mVelocityY;
        mTraveled = 0;
    }

    return false;
}