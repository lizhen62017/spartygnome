/**
 * \file Money.h
 *
 * \author Jeremy Cowelchuk
 *
 * 
 */

#include "ItemPickup.h"
/**
 * Class for money items in a given level
 */
class CMoney :
	public CItemPickup
{
public:
    /// default constructor (disabled)
    CMoney() = delete;

    ///copy constructor (disabled)
    CMoney(const CMoney&) = delete;

private:
    double mValue; ///< The value of a given money object
};
