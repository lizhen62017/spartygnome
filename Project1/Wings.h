/**
 * \file Wings.h
 *
 * \author Jeremy Cowelchuk
 *
 * Class the describes wings
 */


#pragma once
#include "Item.h"
/**
 * Class for handling the team item, wings item that allows double jumps
 */
class CWings :
	public CItem
{
public:
    /// default constructor (disabled)
    CWings() = delete;

    ///copy constructor (disabled)
    CWings(const CWings&) = delete;

    CWings(CLevel* level, const std::shared_ptr<CDeclaration> declaration);

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitWings(this); }

    void Collided() override;

    /// Handle updates for animation
    /// \param elapsed The time since the last update
    /// \return boolean if it was hit
    virtual bool Update(double elapsed) override;

    /// Get the width of the item
    /// \returns item width
    virtual double GetWidth() override { return GetImage()->GetWidth(); };

    /// Get the height of the item
    /// \returns item height
    virtual double GetHeight() override { return GetImage()->GetHeight(); };

private:
    double mVelocity = -750; ///< the speed wings moves after being hit
    bool mHit = false; ///< determines when the wings has been hit by spartygnome
};

