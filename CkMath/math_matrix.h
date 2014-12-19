//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

#pragma once

#ifndef __MATH_MATRIX_H__
#define __MATH_MATRIX_H__

// Local Includes
#include "math_types.h"

// Vector Function Prototypes
namespace math
{
	//
	// Matrix 4
	//

	const TMatrix4d& ZeroMatrix(TMatrix4d& _rResult);

	const TMatrix4f& ZeroMatrix(TMatrix4f& _rResult);

	const TMatrix4d& IdentityMatrix(TMatrix4d& _rResult);

	const TMatrix4f& IdentityMatrix(TMatrix4f& _rResult);

	const TMatrix4d& Multiply(	TMatrix4d& _rResult,
								const TMatrix4d& _krA,
								const TMatrix4d& _krB);

	const TMatrix4f& Multiply(	TMatrix4f& _rResult,
								const TMatrix4f& _krA,
								const TMatrix4f& _krB);

	const TMatrix4d& ScalarMultiply(TMatrix4d& _rResult,
									const TMatrix4d& _krMatrix,
									const double _kdScalar);

	const TMatrix4f& ScalarMultiply(TMatrix4f& _rResult,
									const TMatrix4f& _krMatrix,
									const float _kfScalar);

	const TVector4d& VectorMultiply(TVector4d& _rResult,
									const TMatrix4d& _krA,
									const TVector4d& _krB);

	const TVector4f& VectorMultiply(TVector4f& _rResult,
									const TMatrix4f& _krA,
									const TVector4f& _krB);

	const TMatrix4d& Add(	TMatrix4d& _rResult,
							const TMatrix4d& _krA,
							const TMatrix4d& _krB);

	const TMatrix4f& Add(	TMatrix4f& _rResult,
							const TMatrix4f& _krA,
							const TMatrix4f& _krB);

	const TMatrix4d& Transpose(	TMatrix4d& _rResult,
								const TMatrix4d& _krMatrix);

	const TMatrix4f& Transpose(	TMatrix4f& _rResult,
								const TMatrix4f& _krMatrix);
}

#endif