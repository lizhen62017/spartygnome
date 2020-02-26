/**
 * \file Villain.h
 *
 * \author Jeremy Cowelchuk
 *
 * 
 */

#pragma once

#include "Item.h"

const double Velocity = 240; ///< Constant speed for the villains

/**
 * Class for handling villains
 */
class CVillain :
	public CItem
{
public:
    /// default constructor (disabled)
    CVillain() = delete;

    ///copy constructor (disabled)
    CVillain(const CVillain&) = delete;

    CVillain(CLevel* level, const std::shared_ptr<CDeclaration> declaration);

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitVillain(this); };

    /** Determines what happens when colliding with a villain
    */
    void Collided() override;

    /* Updates the villain to enable movement*/
    bool Update(double elapsed) override;

    /// Reverse the direction of the gnome
    void ReverseDirection() { mVelocityY = -mVelocityY; };

    /**
    * The function for loading a villain into the level
    * \param node The XML node specific to the enemy being loaded in.
    */
    void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

private:
    double mVelocityY = Velocity; ///< The speed at which the villain moves
    double mMaxY = 0; ///< The minimum travel height of a villain
    double mMinY = 0; ///< The maximum travel height of a villain
};

