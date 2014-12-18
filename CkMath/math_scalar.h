//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

#pragma once

#ifndef __MATH_SCALAR_H__
#define __MATH_SCALAR_H__

// Library Includes
#include <cmath>

// Scalar Function Prototypes
namespace math
{
	// double
	inline const double Square(const double _kdScalar)
	{
		return(_kdScalar * _kdScalar);
	}

	inline const double Magnitude(const double _kdScalar)
	{
		return(abs(_kdScalar));
	}

	inline const double SquareRoot(const double _kdScalar)
	{
		return(sqrt(_kdScalar));
	}

	inline const double ArcCos(const double _kdScalar)
	{
		return(acos(_kdScalar));
	}

	// float
	inline const float Square(const float _kfScalar)
	{
		return(_kfScalar * _kfScalar);
	}

	inline const float Magnitude(const float _kfScalar)
	{
		return(fabsf(_kfScalar));
	}

	inline const float SquareRoot(const float _kfScalar)
	{
		return(sqrtf(_kfScalar));
	}

	inline const float ArcCos(const float _kfScalar)
	{
		return(acosf(_kfScalar));
	}
}

#endif