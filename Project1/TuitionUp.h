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
private:
    /// default constructor (disabled)
    CTuitionUp() = delete;

    ///copy constructor (disabled)
    CTuitionUp(const CTuitionUp&) = delete;
public:
};

