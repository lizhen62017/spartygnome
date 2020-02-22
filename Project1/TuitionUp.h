/**
 * \file TuitionUp.h
 *
 * \author Jeremy Cowelchuk
 *
 * 
 */

#pragma once
#include "ItemPickup.h"

/**
 * Class for handling tuition up pickups
 */
class CTuitionUp :
	public CItemPickup
{
public:
    /// default constructor (disabled)
    CTuitionUp() = delete;

    ///copy constructor (disabled)
    CTuitionUp(const CTuitionUp&) = delete;

    CTuitionUp(CLevel* level, const std::shared_ptr<CDeclaration> declaration);

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitTuitionUp(this); }

	void Collided() override;

	virtual bool Update(double elapsed) override;

    /// Get the width of the item
    /// \returns item width
    virtual int GetWidth() override { return GetImage()->GetWidth(); };

    /// Get the height of the item
    /// \returns item height
    virtual int GetHeight() override { return GetImage()->GetHeight(); };

private:

	double mVelocity = 750; ///< the speed tuitionUp moves after being hit
	bool mHit = false; ///< determines when the tuitionUp has been hit by spartygnome
};

