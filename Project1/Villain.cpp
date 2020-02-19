/**
 * \file Villain.cpp
 *
 * \author Jeremy Cowelchuk
 */

#include "pch.h"
#include "Villain.h"

/// The maximum allowed distance a villain is allowed to move
const double MaxTravelDistance = 300;

/** 
* The declaration constructor for the Villain class
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

}

/**
* The function for moving the villain
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