/**
 * \file Villain.h
 *
 * \author Jeremy Cowelchuk
 *
 * 
 */

#pragma once
#include "Item.h"
#include "Level.h"
#include "Declaration.h"

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

    /// Get the width of the item
    /// \returns item width
    virtual int GetWidth() override { return GetImage()->GetWidth(); };

    /// Get the height of the item
    /// \returns item height
    virtual int GetHeight() override { return GetImage()->GetHeight()-20; };

    /** Define if item is collidable
    * \return value The value of whether or not it's collidable
    */
    virtual boolean IsCollidable() override { return false; };

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

    void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

private:
    double mVelocityY = Velocity; ///< The speed at which the villain moves
    double mMaxY = 0; ///< The minimum travel height of a villain
    double mMinY = 0; ///< The maximum travel height of a villain
};

