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
