/**
 * \file Door.h
 *
 * \author Robert Gustke
 *
 * Class that describes door items
 */

#pragma once
#include <string>

#include "Item.h"
#include "SpartyGnome.h"

class CSpartyGnome;

/**
 * Class for a single door
 */
class CDoor :
	public CItem
{
public:
    /// default constructor (disabled)
    CDoor() = delete;

    ///copy constructor (disabled)
    CDoor(const CDoor&) = delete;

    CDoor(CLevel* level, const std::shared_ptr<CDeclaration> declaration);

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitDoor(this); }

    /// Get the width of the item
    /// \returns item width
    virtual double GetWidth() override { return GetImage()->GetWidth(); };

    /// Get the height of the item
    /// \returns item height
    virtual double GetHeight() override { return GetImage()->GetHeight(); };

    boolean CollideGnome(CSpartyGnome* gnome);

    void Collided() override;

	virtual bool Update(double elapsed) override;

private:
	/// boolean to prevent too many messsages 
	bool mDoorMessage = false;

	/// The time elapsed since the last update
	double mTimeElapsed = 0.0;
};

