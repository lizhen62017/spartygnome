/**
 * \file Villain.h
 *
 * \author Jeremy Cowelchuk
 *
 * 
 */

#pragma once
#include "Item.h"
#include "Vector.h"

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

    /// Get the width of the item
    /// \returns item width
    virtual int GetWidth() override { return 0;};

    /// Get the height of the item
    /// \returns item height
    virtual int GetHeight() override { return 0; };

    /** Define if item is collidable
    * \return value The value of whether or not it's collidable
    */
    virtual boolean IsCollidable() override { return false; };

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { }

    /** Determines what happens when colliding with a villain
    */
    void Collided() override;

    /* Updates the villain to enable movement
    * \param elapsed The time elapsed since last update */
    bool Update(double elapsed) override;

private:
    double mVelocityY = 150; ///< The speed at which the villain moves
    double mTraveled = 0; ///< The total distance the villain has traveled
};

