/**
 * \file Vector.cpp
 *
 * All the functions needed for CVector class
 * \author Charles Owen
 * \author Zhen Li
 */

#include "pch.h"
#include "Vector.h"

/**
 * Constructor
 *
 * The default constructor creates a zero vector.
 */
CVector::CVector() : mX(0), mY(0)
{
}

/**
 * Constructor
 *
 * This constructor allows you to specify an initial value
 *
 * \param x Initial x value
 * \param y Initial y value
 */
CVector::CVector(double x, double y) : mX(x), mY(y)
{

}

/**
 * Destructor
 */
CVector::~CVector()
{
}

/**
 * Computer scalar multiply of vector * scalar
 * \param d Value to multiply by
 * \return (*this) * d
 */
CVector CVector::operator*(double d) const
{
	return CVector(mX * d, mY * d);
}


/**
 * Operator +=
 *
 * Adds a vector to an existing vector.
 *
 * \code
 * CVector a(7, 3);
 * CVector b(3, 9);
 * a += b;		// a is now equal to (10, 12)
 * \endcode
 * \param a Value to add to current object
 * \returns *this
 */
CVector &CVector::operator+=(const CVector &a)
{
	mX += a.mX;
	mY += a.mY;
	return *this;
}


/**
 * Operator *= for scalar values
 *
 * Multiplies a vector by a scalar value
 *
 * \code
 * CVector a(7, 3)
 * double d = 0.5;
 * a *= d;   // a is now (3.5, 1.5)
 * \endcode
 * \param d Scalar to multiply by this vector.
 * \returns *this
 */
CVector &CVector::operator*=(double d)
{
	mX *= d;
	mY *= d;
	return *this;
}

/**
* Operator /=
*
* Divides a vector by a scalar value
*
* \code
CVector a(3, 7);
double d = 3;
a /= d;       // a is now (1, 2.3333)
* \endcode
* \param d Scalar to divide by
* \returns *this
*/
CVector &CVector::operator/=(double d)
{
	mX /= d;
	mY /= d;
	return *this;
}



/**
 * Operator + Compute the sum of two vectors
 *
 * \code
 CVector a(3, 7);
 CVector b(7, 9);
 CVector c = a + b;   // c is (10, 16)
 * \endcode
 * \param a First vector operand
 * \param b Second vector operand
 * \returns a + b
 */
CVector operator+(const CVector &a, const CVector &b)
{
	return CVector(a.X() + b.X(), a.Y() + b.Y());
}


/**
* Operator - Compute the subtraction of two vectors
*
* \code
CVector a(3, 7);
CVector b(7, 9);
CVector c = a - b;   // c is (-2, -4)
* \endcode
* \param a First vector operand
* \param b Second vector operand
* \returns a + b
*/
CVector operator-(const CVector &a, const CVector &b)
{
	return CVector(a.X() - b.X(), a.Y() - b.Y());
}


/**
 * Operator /
 *
 * Computes vector a / scalar d
 *
 * \code
 CVector a(3, 7);
 double d = 3;
 CVector b = a / d;	// b is (1, 2.3333)
 * \endcode
 * \param a Vector to divide
 * \param d Scalar to divide by
 * \returns a / d
 */
CVector operator/(const CVector &a, double d)
{
	return CVector(a.X() / d, a.Y() / d);
}
