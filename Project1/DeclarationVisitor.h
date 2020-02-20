/**
 * \file DeclarationVisitor.h
 *
 * \author
 *
 * Declaration visitor base class.
 */


#pragma once

 // Forward references to all declaration types
class CMoneyDeclaration;

/** Declaration visitor base class */
class CDeclarationVisitor
{
public:
    virtual ~CDeclarationVisitor() {}

    /** Visit a CMoneyDeclaration object
     * \param declaration CMoneyDeclaration we are visiting */
    virtual void VisitMoneyDeclaration(CMoneyDeclaration* moneyDeclaration) {}
};

