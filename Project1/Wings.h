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

    void Collided() override {}
};

