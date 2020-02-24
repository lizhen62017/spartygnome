/**
 * \file MoneyMultiplier.cpp
 *
 * \author Torre Rocco
 */

#include "pch.h"
#include "MoneyMultiplier.h"
#include "Money.h"


void CMoneyMultiplier::VisitMoney(CMoney* money)
{
	money->Multiply();
}
