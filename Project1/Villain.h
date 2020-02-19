/**
 * \file Villain.h
 *
 * \author Jeremy Cowelchuk
 *
 * 
 */

#pragma once
#include "Item.h"
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

    void Collided() override {}

private:
};

