/**
 * \file MoneyEvaluator.cpp
 *
 * \author Chase Lindeboom
 */

#include "pch.h"
#include "MoneyEvaluator.h"

#include "MoneyDeclaration.h"


 /** Visit a CMoneyDeclaration object
  * \param building money declaration we are visiting */
void CMoneyEvaluator::VisitMoneyDeclaration(CMoneyDeclaration* moneyDeclaration)
{
    mMoneyValue = moneyDeclaration->GetValue();
}