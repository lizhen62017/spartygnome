/**
 * \file Door.h
 *
 * \author Robert Gustke
 *
 * Class for door items
 */

#pragma once
#include "Item.h"
#include<string>

class CDoor :
	public CItem
{
public:
    /// default constructor (disabled)
    CDoor() = delete;

    ///copy constructor (disabled)
    CDoor(const CDoor&) = delete;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitDoor(this); }

    CDoor::CDoor(CLevel* level, const std::wstring& filename);
};

