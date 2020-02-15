/**
 * \file MoneyDeclaration.h
 *
 * \author Chase Lindeboom
 *
 * Class representing a money declaration
 */

#pragma once

#include "Declaration.h"


/**
 * Class representing a money declaration
 */
class CMoneyDeclaration :
    public CDeclaration 

{
public:
    
    /**  Sets the declarations value
    * \param value The value of the money */
    void SetValue(double value) { mValue = value; }

    /**  Gets the value of the money declaration
     * \return the value of the money declaration */
    double GetValue() { return mValue; }

private:

    /// The value of the money declaration
    double mValue = 0;
};

