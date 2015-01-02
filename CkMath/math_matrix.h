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

	const TMatrix3d& Submatrix(	TMatrix3d& _rResult, 
								const TMatrix4d& _krMatrix,
								const size_t _kDeletedRow,
								const size_t _kDeletedColumn);

	const TMatrix3f& Submatrix(	TMatrix3f& _rResult, 
								const TMatrix4f& _krMatrix,
								const size_t _kDeletedRow,
								const size_t _kDeletedColumn);

	const double FirstMinor(const TMatrix4d& _krMatrix,
							const size_t _kRow,
							const size_t _kColumn);

	const float FirstMinor(const TMatrix4f& _krMatrix,
							const size_t _kRow,
							const size_t _kColumn);

	const TMatrix4d& MatrixOfMinors(TMatrix4d& _rResult,
									const TMatrix4d& _krMatrix);

	const TMatrix4f& MatrixOfMinors(TMatrix4f& _rResult,
									const TMatrix4f& _krMatrix);

	const double Determinant(const TMatrix4d& _krMatrix);

	const float Determinant(const TMatrix4f& _krMatrix);

	const TMatrix4d& Inverse(	TMatrix4d& _rResult,
								const TMatrix4d& _krMatrix);

	const TMatrix4f& Inverse(	TMatrix4f& _rResult,
								const TMatrix4f& _krMatrix);

	//
	// Matrix 3
	//

	const TMatrix3d& ZeroMatrix(TMatrix3d& _rResult);

	const TMatrix3f& ZeroMatrix(TMatrix3f& _rResult);

	const TMatrix3d& IdentityMatrix(TMatrix3d& _rResult);

	const TMatrix3f& IdentityMatrix(TMatrix3f& _rResult);

	const TMatrix3d& Multiply(	TMatrix3d& _rResult,
								const TMatrix3d& _krA,
								const TMatrix3d& _krB);

	const TMatrix3f& Multiply(	TMatrix3f& _rResult,
								const TMatrix3f& _krA,
								const TMatrix3f& _krB);

	const TMatrix3d& ScalarMultiply(TMatrix3d& _rResult,
									const TMatrix3d& _krMatrix,
									const double _kdScalar);

	const TMatrix3f& ScalarMultiply(TMatrix3f& _rResult,
									const TMatrix3f& _krMatrix,
									const float _kfScalar);

	const TVector3d& VectorMultiply(TVector3d& _rResult,
									const TMatrix3d& _krA,
									const TVector3d& _krB);

	const TVector3f& VectorMultiply(TVector3f& _rResult,
									const TMatrix3f& _krA,
									const TVector3f& _krB);

	const TMatrix3d& Add(	TMatrix3d& _rResult,
							const TMatrix3d& _krA,
							const TMatrix3d& _krB);

	const TMatrix3f& Add(	TMatrix3f& _rResult,
							const TMatrix3f& _krA,
							const TMatrix3f& _krB);

	const TMatrix3d& Transpose(	TMatrix3d& _rResult,
								const TMatrix3d& _krMatrix);

	const TMatrix3f& Transpose(	TMatrix3f& _rResult,
								const TMatrix3f& _krMatrix);

	const TMatrix2d& Submatrix(	TMatrix2d& _rResult, 
								const TMatrix3d& _krMatrix,
								const size_t _kDeletedRow,
								const size_t _kDeletedColumn);

	const TMatrix2f& Submatrix(	TMatrix2f& _rResult, 
								const TMatrix3f& _krMatrix,
								const size_t _kDeletedRow,
								const size_t _kDeletedColumn);

	const double Determinant(const TMatrix3d& _krMatrix);

	const float Determinant(const TMatrix3f& _krMatrix);

	const double FirstMinor(const TMatrix3d& _krMatrix,
							const size_t _kRow,
							const size_t _kColumn);

	const float FirstMinor(	const TMatrix3f& _krMatrix,
							const size_t _kRow,
							const size_t _kColumn);

	const TMatrix3d& MatrixOfMinors(TMatrix3d& _rResult,
									const TMatrix3d& _krMatrix);

	const TMatrix3f& MatrixOfMinors(TMatrix3f& _rResult,
									const TMatrix3f& _krMatrix);

	const TMatrix3d& MatrixOfCofactors(	TMatrix3d& _rResult,
										const TMatrix3d& _krMatrix);

	const TMatrix3f& MatrixOfCofactors(	TMatrix3f& _rResult,
										const TMatrix3f& _krMatrix);

	const TMatrix3d& Inverse(	TMatrix3d& _rResult,
								const TMatrix3d& _krMatrix);

	const TMatrix3f& Inverse(	TMatrix3f& _rResult,
								const TMatrix3f& _krMatrix);

	//
	// Matrix 2
	//

	const double Determinant(const TMatrix2d& _krMatrix);

	const float Determinant(const TMatrix2f& _krMatrix);

}

#endif