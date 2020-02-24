/**
 * \file MoneyMultiplier.h
 *
 * \author Torre Rocco
 *
 * Multiplies each money by 1.1
 */

#pragma once

#include "ItemVisitor.h"


/**
 * Multiplies money when tuitionUp is collected
 */
class CMoneyMultiplier : public CItemVisitor
{
public:
	/** \brief Visit a CMoney object
	 * \param money item we are visiting */
	void VisitMoney(CMoney* money) override;
};

