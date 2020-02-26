/**
 * \file Money.h
 *
 * \author Jeremy Cowelchuk
 *
 * Class for a money object
 */

#pragma once
#include "Item.h"

class CItem;

/**
 * Class for money items in a given level
 */
class CMoney :
	public CItem
{
public:
    /// default constructor (disabled)
    CMoney() = delete;

    CMoney(CLevel* level, const std::shared_ptr<CDeclaration> declaration);

    ///copy constructor (disabled)
    CMoney(const CMoney&) = delete;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitMoney(this); }

    void Collided() override;

    virtual bool Update(double elapsed) override;

    /// Get the width of the item
    /// \returns item width
    virtual double GetWidth() override { return GetImage()->GetWidth(); };

    /// Get the height of the item
    /// \returns item height
    virtual double GetHeight() override { return GetImage()->GetHeight(); };

	/** multiplies money value when tuitionUp is collected*/
	void Multiply() { mValue *= 1.1; }

private:
    double mValue = 0; ///< The value of a given money object

    double mVelocity = -750; ///< the speed money moves after being hit
    bool mHit = false; ///< determines when the money has been hit by spartygnome

};
