/**
 * \file MoneyEvaluator.h
 *
 * \author Chase Lindeboom
 *
 * Visitor that returns the value of a money declaration
 *
 * A Declaration visitor that returns the value
 * of a money declaration to use for instantiating
 * the money object.
 */

#pragma once
#include "DeclarationVisitor.h"

class CMoneyDeclaration;


/**
 * Declaration visitor that returns the value of a 
 * money declaration
 */
class CMoneyEvaluator :
	public CDeclarationVisitor
{
public:
    /** Get the value of money declaration
     * \returns value of money declaration */
    double GetMoneyValue() const { return mMoneyValue; }

    /** Visit a CMoneyDeclaration object
     * \param building money declaration we are visiting */
    void VisitMoneyDeclaration(CMoneyDeclaration* moneyDeclaration) override;

private:

    //The value of the money
    double mMoneyValue = 0;
};

