/**
 * \file Wings.h
 *
 * \author Jeremy Cowelchuk
 *
 * 
 */


#pragma once
#include "ItemPickup.h"
/**
 * Class for handling the team item, a wings item that allows double jumps
 */
class CWings :
	public CItemPickup
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
    virtual int GetWidth() override { return GetImage()->GetWidth(); };

    /// Get the height of the item
    /// \returns item height
    virtual int GetHeight() override { return GetImage()->GetHeight(); };

private:
    double mVelocity = -750; ///< the speed wings moves after being hit
    bool mHit = false; ///< determines when the wings has been hit by spartygnome
};

