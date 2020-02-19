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
};

