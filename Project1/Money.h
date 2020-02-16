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
private:
    double mValue; ///< The value of a given money object
};
