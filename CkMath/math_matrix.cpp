//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

// Local Includes
#include "math_matrix.h"
#include "math_vector.h"
#include "math_scalar.h"

//
// Matrix 4
//

const TMatrix4d& math::ZeroMatrix(TMatrix4d& _rResult)
{
	_rResult.m_d11 = 0.0;
	_rResult.m_d12 = 0.0;
	_rResult.m_d13 = 0.0;
	_rResult.m_d14 = 0.0;

	_rResult.m_d21 = 0.0;
	_rResult.m_d22 = 0.0;
	_rResult.m_d23 = 0.0;
	_rResult.m_d24 = 0.0;

	_rResult.m_d31 = 0.0;
	_rResult.m_d32 = 0.0;
	_rResult.m_d33 = 0.0;
	_rResult.m_d34 = 0.0;

	_rResult.m_d41 = 0.0;
	_rResult.m_d42 = 0.0;
	_rResult.m_d43 = 0.0;
	_rResult.m_d44 = 0.0;

	return(_rResult);
}

const TMatrix4f& math::ZeroMatrix(TMatrix4f& _rResult)
{
	_rResult.m_f11 = 0.0f;
	_rResult.m_f12 = 0.0f;
	_rResult.m_f13 = 0.0f;
	_rResult.m_f14 = 0.0f;

	_rResult.m_f21 = 0.0f;
	_rResult.m_f22 = 0.0f;
	_rResult.m_f23 = 0.0f;
	_rResult.m_f24 = 0.0f;

	_rResult.m_f31 = 0.0f;
	_rResult.m_f32 = 0.0f;
	_rResult.m_f33 = 0.0f;
	_rResult.m_f34 = 0.0f;

	_rResult.m_f41 = 0.0f;
	_rResult.m_f42 = 0.0f;
	_rResult.m_f43 = 0.0f;
	_rResult.m_f44 = 0.0f;

	return(_rResult);
}

const TMatrix4d& math::IdentityMatrix(TMatrix4d& _rResult)
{
	_rResult.m_d11 = 1.0;
	_rResult.m_d12 = 0.0;
	_rResult.m_d13 = 0.0;
	_rResult.m_d14 = 0.0;
					 
	_rResult.m_d21 = 0.0;
	_rResult.m_d22 = 1.0;
	_rResult.m_d23 = 0.0;
	_rResult.m_d24 = 0.0;
					 
	_rResult.m_d31 = 0.0;
	_rResult.m_d32 = 0.0;
	_rResult.m_d33 = 1.0;
	_rResult.m_d34 = 0.0;
					 
	_rResult.m_d41 = 0.0;
	_rResult.m_d42 = 0.0;
	_rResult.m_d43 = 0.0;
	_rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& math::IdentityMatrix(TMatrix4f& _rResult)
{
	_rResult.m_f11 = 1.0f;
	_rResult.m_f12 = 0.0f;
	_rResult.m_f13 = 0.0f;
	_rResult.m_f14 = 0.0f;
					 
	_rResult.m_f21 = 0.0f;
	_rResult.m_f22 = 1.0f;
	_rResult.m_f23 = 0.0f;
	_rResult.m_f24 = 0.0f;
					 
	_rResult.m_f31 = 0.0f;
	_rResult.m_f32 = 0.0f;
	_rResult.m_f33 = 1.0f;
	_rResult.m_f34 = 0.0f;
					 
	_rResult.m_f41 = 0.0f;
	_rResult.m_f42 = 0.0f;
	_rResult.m_f43 = 0.0f;
	_rResult.m_f44 = 1.0f;

	return(_rResult);
}

const TMatrix4d& math::Multiply(TMatrix4d& _rResult,
								const TMatrix4d& _krA,
								const TMatrix4d& _krB)
{
	for(size_t x = 0; x < 4; ++x)
	{
		for(size_t y = 0; y < 4; ++y)
		{
			double dAccumulate = 0.0;
			for(size_t n = 0; n < 4; ++n)
			{
				dAccumulate += (_krA.m_dItems[n][y] * _krB.m_dItems[x][y]);
			}
			_rResult.m_dItems[x][y] = dAccumulate;
		}
	}

	return(_rResult);
}

const TMatrix4f& math::Multiply(TMatrix4f& _rResult,
								const TMatrix4f& _krA,
								const TMatrix4f& _krB)
{
	for(size_t x = 0; x < 4; ++x)
	{
		for(size_t y = 0; y < 4; ++y)
		{
			float fAccumulate = 0.0;
			for(size_t n = 0; n < 4; ++n)
			{
				fAccumulate += (_krA.m_fItems[n][y] * _krB.m_fItems[x][y]);
			}
			_rResult.m_fItems[x][y] = fAccumulate;
		}
	}

	return(_rResult);
}

const TMatrix4d& math::ScalarMultiply(	TMatrix4d& _rResult,
										const TMatrix4d& _krMatrix,
										const double _kdScalar)
{
	for(size_t x = 0; x < 4; ++x)
	{
		for(size_t y = 0; y < 4; ++y)
		{
			_rResult.m_dItems[x][y] = _krMatrix.m_dItems[x][y] * _kdScalar;
		}
	}

	return(_rResult);
}

const TMatrix4f& math::ScalarMultiply(	TMatrix4f& _rResult,
										const TMatrix4f& _krMatrix,
										const float _kfScalar)
{
	for(size_t x = 0; x < 4; ++x)
	{
		for(size_t y = 0; y < 4; ++y)
		{
			_rResult.m_fItems[x][y] = _krMatrix.m_fItems[x][y] * _kfScalar;
		}
	}

	return(_rResult);
}

const TVector4d& math::VectorMultiply(	TVector4d& _rResult,
										const TMatrix4d& _krA,
										const TVector4d& _krB)
{
	for(size_t y = 0; y < 4; ++y)
	{
		double dAccumulate = 0.0;
		for(size_t n = 0; n < 4; ++n)
		{
			dAccumulate += (_krA.m_dItems[n][y] * _krB.m_dV[n]);
		}
		_rResult.m_dV[y] = dAccumulate;
	}

	return(_rResult);
}

const TVector4f& math::VectorMultiply(	TVector4f& _rResult,
										const TMatrix4f& _krA,
										const TVector4f& _krB)
{
	for(size_t y = 0; y < 4; ++y)
	{
		float fAccumulate = 0.0f;
		for(size_t n = 0; n < 4; ++n)
		{
			fAccumulate += (_krA.m_fItems[n][y] * _krB.m_fV[n]);
		}
		_rResult.m_fV[y] = fAccumulate;
	}

	return(_rResult);
}

const TMatrix4d& math::Add(	TMatrix4d& _rResult,
							const TMatrix4d& _krA,
							const TMatrix4d& _krB)
{
	for(size_t x = 0; x < 4; ++x)
	{
		for(size_t y = 0; y < 4; ++y)
		{
			_rResult.m_dItems[x][y] = _krA.m_dItems[x][y] + _krB.m_dItems[x][y];
		}
	}

	return(_rResult);
}

const TMatrix4f& math::Add(	TMatrix4f& _rResult,
							const TMatrix4f& _krA,
							const TMatrix4f& _krB)
{
	for(size_t x = 0; x < 4; ++x)
	{
		for(size_t y = 0; y < 4; ++y)
		{
			_rResult.m_fItems[x][y] = _krA.m_fItems[x][y] + _krB.m_fItems[x][y];
		}
	}

	return(_rResult);
}

const TMatrix4d& math::Transpose(	TMatrix4d& _rResult,
									const TMatrix4d& _krMatrix)
{
	for(size_t x = 0; x < 4; ++x)
	{
		for(size_t y = 0; y < 4; ++y)
		{
			_rResult.m_dItems[y][x] = _krMatrix.m_dItems[x][y];
		}
	}

	return(_rResult);
}

const TMatrix4f& math::Transpose(	TMatrix4f& _rResult,
									const TMatrix4f& _krMatrix)
{
	for(size_t x = 0; x < 4; ++x)
	{
		for(size_t y = 0; y < 4; ++y)
		{
			_rResult.m_fItems[y][x] = _krMatrix.m_fItems[x][y];
		}
	}

	return(_rResult);
}

const TMatrix3d& math::Submatrix(	TMatrix3d& _rResult, 
									const TMatrix4d& _krMatrix,
									const size_t _kDeletedRow,
									const size_t _kDeletedColumn)
{
	for(size_t i = 0; i < 4; ++i)
	{
		for(size_t j = 0; j < 4; ++j)
		{
			if(		(i != _kDeletedRow)
				&&	(j != _kDeletedColumn))
			{
				size_t InsertI;
				size_t InsertJ;
				if(i < _kDeletedRow)
				{
					InsertI = i;
				}
				else
				{
					InsertI = i-1;
				}
				if(j < _kDeletedColumn)
				{
					InsertJ = j;
				}
				else
				{
					InsertJ = j-1;
				}

				_rResult.m_dItems[InsertI][InsertJ] = _krMatrix.m_dItems[i][j];
			}
		}
	}

	return(_rResult);
}

const TMatrix3f& math::Submatrix(	TMatrix3f& _rResult, 
									const TMatrix4f& _krMatrix,
									const size_t _kDeletedRow,
									const size_t _kDeletedColumn)
{
	for(size_t i = 0; i < 4; ++i)
	{
		for(size_t j = 0; j < 4; ++j)
		{
			if(		(i != _kDeletedRow)
				&&	(j != _kDeletedColumn))
			{
				size_t InsertI;
				size_t InsertJ;
				if(i < _kDeletedRow)
				{
					InsertI = i;
				}
				else
				{
					InsertI = i-1;
				}
				if(j < _kDeletedColumn)
				{
					InsertJ = j;
				}
				else
				{
					InsertJ = j-1;
				}

				_rResult.m_fItems[InsertI][InsertJ] = _krMatrix.m_fItems[i][j];
			}
		}
	}

	return(_rResult);
}

const double math::FirstMinor(	const TMatrix4d& _krMatrix,
								const size_t _kRow,
								const size_t _kColumn)
{
	const TMatrix3d kSubmatrix = math::Submatrix(TMatrix3d(), _krMatrix, _kRow, _kColumn);
	
	return(math::Determinant(kSubmatrix));
}

const float math::FirstMinor(	const TMatrix4f& _krMatrix,
								const size_t _kRow,
								const size_t _kColumn)
{
	const TMatrix3f kSubmatrix = math::Submatrix(TMatrix3f(), _krMatrix, _kRow, _kColumn);
	
	return(math::Determinant(kSubmatrix));
}

const TMatrix4d& math::MatrixOfMinors(	TMatrix4d& _rResult,
										const TMatrix4d& _krMatrix)
{
	for(size_t i = 0; i < 4; ++i)
	{
		for(size_t j = 0; j < 4; ++j)
		{
			_rResult.m_dItems[i][j] = math::FirstMinor(_krMatrix, i, j);
		}
	}

	return(_rResult);
}

const TMatrix4f& math::MatrixOfMinors(	TMatrix4f& _rResult,
										const TMatrix4f& _krMatrix)
{
	for(size_t i = 0; i < 4; ++i)
	{
		for(size_t j = 0; j < 4; ++j)
		{
			_rResult.m_fItems[i][j] = math::FirstMinor(_krMatrix, i, j);
		}
	}

	return(_rResult);
}

const double math::Determinant(const TMatrix4d& _krMatrix)
{
	const double kdDeterminant =	(_krMatrix.m_d11 * math::FirstMinor(_krMatrix, 1, 1))
								-	(_krMatrix.m_d12 * math::FirstMinor(_krMatrix, 1, 2))
								+	(_krMatrix.m_d13 * math::FirstMinor(_krMatrix, 1, 3))
								-	(_krMatrix.m_d14 * math::FirstMinor(_krMatrix, 1, 4));

	return(kdDeterminant);
}

const float math::Determinant(const TMatrix4f& _krMatrix)
{
	const float kfDeterminant =		(_krMatrix.m_f11 * math::FirstMinor(_krMatrix, 1, 1))
								-	(_krMatrix.m_f12 * math::FirstMinor(_krMatrix, 1, 2))
								+	(_krMatrix.m_f13 * math::FirstMinor(_krMatrix, 1, 3))
								-	(_krMatrix.m_f14 * math::FirstMinor(_krMatrix, 1, 4));

	return(kfDeterminant);
}

const TMatrix4d& math::Inverse(	TMatrix4d& _rResult,
								const TMatrix4d& _krMatrix)
{
	_rResult = math::ScalarMultiply(_rResult, math::Transpose(TMatrix4d(), _krMatrix), 1.0/math::Determinant(_krMatrix));

	return(_rResult);
}

const TMatrix4f& math::Inverse(	TMatrix4f& _rResult,
								const TMatrix4f& _krMatrix)
{
	_rResult = math::ScalarMultiply(_rResult, math::Transpose(TMatrix4f(), _krMatrix), 1.0f/math::Determinant(_krMatrix));

	return(_rResult);
}

//
// Matrix 3
//

const TMatrix2d& math::Submatrix(	TMatrix2d& _rResult, 
									const TMatrix3d& _krMatrix,
									const size_t _kDeletedRow,
									const size_t _kDeletedColumn)
{
	for(size_t i = 0; i < 3; ++i)
	{
		for(size_t j = 0; j < 3; ++j)
		{
			if(		(i != _kDeletedRow)
				&&	(j != _kDeletedColumn))
			{
				size_t InsertI;
				size_t InsertJ;
				if(i < _kDeletedRow)
				{
					InsertI = i;
				}
				else
				{
					InsertI = i-1;
				}
				if(j < _kDeletedColumn)
				{
					InsertJ = j;
				}
				else
				{
					InsertJ = j-1;
				}

				_rResult.m_dItems[InsertI][InsertJ] = _krMatrix.m_dItems[i][j];
			}
		}
	}

	return(_rResult);
}

const TMatrix2f& math::Submatrix(	TMatrix2f& _rResult, 
									const TMatrix3f& _krMatrix,
									const size_t _kDeletedRow,
									const size_t _kDeletedColumn)
{
	for(size_t i = 0; i < 3; ++i)
	{
		for(size_t j = 0; j < 3; ++j)
		{
			if(		(i != _kDeletedRow)
				&&	(j != _kDeletedColumn))
			{
				size_t InsertI;
				size_t InsertJ;
				if(i < _kDeletedRow)
				{
					InsertI = i;
				}
				else
				{
					InsertI = i-1;
				}
				if(j < _kDeletedColumn)
				{
					InsertJ = j;
				}
				else
				{
					InsertJ = j-1;
				}

				_rResult.m_fItems[InsertI][InsertJ] = _krMatrix.m_fItems[i][j];
			}
		}
	}

	return(_rResult);
}

const double math::Determinant(const TMatrix3d& _krMatrix)
{
	const double kdDeterminant =	(_krMatrix.m_d11 * _krMatrix.m_d22 * _krMatrix.m_d33)
								+	(_krMatrix.m_d12 * _krMatrix.m_d23 * _krMatrix.m_d31)
								+	(_krMatrix.m_d13 * _krMatrix.m_d21 * _krMatrix.m_d32)
								-	(_krMatrix.m_d13 * _krMatrix.m_d22 * _krMatrix.m_d31)
								-	(_krMatrix.m_d12 * _krMatrix.m_d21 * _krMatrix.m_d33)
								-	(_krMatrix.m_d11 * _krMatrix.m_d23 * _krMatrix.m_d32);

	return(kdDeterminant);
}

const float math::Determinant(const TMatrix3f& _krMatrix)
{
	const float kfDeterminant =		(_krMatrix.m_f11 * _krMatrix.m_f22 * _krMatrix.m_f33)
								+	(_krMatrix.m_f12 * _krMatrix.m_f23 * _krMatrix.m_f31)
								+	(_krMatrix.m_f13 * _krMatrix.m_f21 * _krMatrix.m_f32)
								-	(_krMatrix.m_f13 * _krMatrix.m_f22 * _krMatrix.m_f31)
								-	(_krMatrix.m_f12 * _krMatrix.m_f21 * _krMatrix.m_f33)
								-	(_krMatrix.m_f11 * _krMatrix.m_f23 * _krMatrix.m_f32);

	return(kfDeterminant);
}

const double math::FirstMinor(	const TMatrix3d& _krMatrix,
								const size_t _kRow,
								const size_t _kColumn)
{
	const TMatrix2d kSubmatrix = math::Submatrix(TMatrix2d(), _krMatrix, _kRow, _kColumn);
	
	return(math::Determinant(kSubmatrix));
}

const float math::FirstMinor(	const TMatrix3f& _krMatrix,
								const size_t _kRow,
								const size_t _kColumn)
{
	const TMatrix2f kSubmatrix = math::Submatrix(TMatrix2f(), _krMatrix, _kRow, _kColumn);
	
	return(math::Determinant(kSubmatrix));
}

const TMatrix3d& math::MatrixOfMinors(	TMatrix3d& _rResult,
										const TMatrix3d& _krMatrix)
{
	for(size_t i = 0; i < 3; ++i)
	{
		for(size_t j = 0; j < 3; ++j)
		{
			_rResult.m_dItems[i][j] = math::FirstMinor(_krMatrix, i, j);
		}
	}

	return(_rResult);
}

const TMatrix3f& math::MatrixOfMinors(	TMatrix3f& _rResult,
										const TMatrix3f& _krMatrix)
{
	for(size_t i = 0; i < 3; ++i)
	{
		for(size_t j = 0; j < 3; ++j)
		{
			_rResult.m_fItems[i][j] = math::FirstMinor(_krMatrix, i, j);
		}
	}

	return(_rResult);
}

const TMatrix3d& math::MatrixOfCofactors(	TMatrix3d& _rResult,
											const TMatrix3d& _krMatrix)
{
	_rResult = math::MatrixOfMinors(_rResult, _krMatrix);
	for(size_t i = 0; i < 3; ++i)
	{
		for(size_t j = 0; j < 3; ++j)
		{
			if(((i % 2) == 1) ^ ((j % 2) == 1))
			{
				_rResult.m_dItems[i][j] *= -1.0;
			}
		}
	}

	return(_rResult);
}

const TMatrix3f& math::MatrixOfCofactors(	TMatrix3f& _rResult,
											const TMatrix3f& _krMatrix)
{
	_rResult = math::MatrixOfMinors(_rResult, _krMatrix);
	for(size_t i = 0; i < 3; ++i)
	{
		for(size_t j = 0; j < 3; ++j)
		{
			if(((i % 2) == 1) ^ ((j % 2) == 1))
			{
				_rResult.m_fItems[i][j] *= -1.0f;
			}
		}
	}

	return(_rResult);
}

//
// Matrix 2
//

const double math::Determinant(const TMatrix2d& _krMatrix)
{
	return(		(_krMatrix.m_d11 * _krMatrix.m_d22)
			-	(_krMatrix.m_d12 * _krMatrix.m_d21));
}

const float math::Determinant(const TMatrix2f& _krMatrix)
{
	return(		(_krMatrix.m_f11 * _krMatrix.m_f22)
			-	(_krMatrix.m_f12 * _krMatrix.m_f21));
}