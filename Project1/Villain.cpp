/**
 * \file Villain.cpp
 *
 * \author Jeremy Cowelchuk
 */

#include "pch.h"
#include "Villain.h"
#include "SpartyGnome.h"

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

    this->SetLocation(this->GetX(), newY);

    // reverse direction if the villain has gone beyond it's allowed pacing distance
    if ((newY < mMinY && mVelocityY > 0) || (newY > mMaxY && mVelocityY < 0))
    {
        ReverseDirection();
    }

    //return false to prevent deletion
    return false;
}


void CVillain::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    //get the maximum distancethe villain is allowed to move
    mMaxY = node->GetAttributeDoubleValue(L"y", 0);
    mMinY =  mMaxY- 300;

    CItem::XmlLoad(node);
}