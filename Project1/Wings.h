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
    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitWings(this); }
};

