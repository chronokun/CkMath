//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

// Local Includes
#include "math_matrix.h"
#include "math_vector.h"
#include "math_scalar.h"
#include "math_quaternion.h"

//
// Matrix 4
//

const TMatrix4d& math::ZeroMatrix(TMatrix4d& _rResult)
{
	_rResult.m_d11 = 0.0; _rResult.m_d12 = 0.0; _rResult.m_d13 = 0.0; _rResult.m_d14 = 0.0;
	_rResult.m_d21 = 0.0; _rResult.m_d22 = 0.0; _rResult.m_d23 = 0.0; _rResult.m_d24 = 0.0;
	_rResult.m_d31 = 0.0; _rResult.m_d32 = 0.0; _rResult.m_d33 = 0.0; _rResult.m_d34 = 0.0;
	_rResult.m_d41 = 0.0; _rResult.m_d42 = 0.0; _rResult.m_d43 = 0.0; _rResult.m_d44 = 0.0;

	return(_rResult);
}

const TMatrix4f& math::ZeroMatrix(TMatrix4f& _rResult)
{
	_rResult.m_f11 = 0.0f; _rResult.m_f12 = 0.0f; _rResult.m_f13 = 0.0f; _rResult.m_f14 = 0.0f;
	_rResult.m_f21 = 0.0f; _rResult.m_f22 = 0.0f; _rResult.m_f23 = 0.0f; _rResult.m_f24 = 0.0f;
	_rResult.m_f31 = 0.0f; _rResult.m_f32 = 0.0f; _rResult.m_f33 = 0.0f; _rResult.m_f34 = 0.0f;
	_rResult.m_f41 = 0.0f; _rResult.m_f42 = 0.0f; _rResult.m_f43 = 0.0f; _rResult.m_f44 = 0.0f;

	return(_rResult);
}

const TMatrix4d& math::IdentityMatrix(TMatrix4d& _rResult)
{
	_rResult.m_d11 = 1.0; _rResult.m_d12 = 0.0; _rResult.m_d13 = 0.0; _rResult.m_d14 = 0.0;
	_rResult.m_d21 = 0.0; _rResult.m_d22 = 1.0; _rResult.m_d23 = 0.0; _rResult.m_d24 = 0.0;
	_rResult.m_d31 = 0.0; _rResult.m_d32 = 0.0; _rResult.m_d33 = 1.0; _rResult.m_d34 = 0.0;
	_rResult.m_d41 = 0.0; _rResult.m_d42 = 0.0; _rResult.m_d43 = 0.0; _rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& math::IdentityMatrix(TMatrix4f& _rResult)
{
	_rResult.m_f11 = 1.0f; _rResult.m_f12 = 0.0f; _rResult.m_f13 = 0.0f; _rResult.m_f14 = 0.0f;
	_rResult.m_f21 = 0.0f; _rResult.m_f22 = 1.0f; _rResult.m_f23 = 0.0f; _rResult.m_f24 = 0.0f;
	_rResult.m_f31 = 0.0f; _rResult.m_f32 = 0.0f; _rResult.m_f33 = 1.0f; _rResult.m_f34 = 0.0f;
	_rResult.m_f41 = 0.0f; _rResult.m_f42 = 0.0f; _rResult.m_f43 = 0.0f; _rResult.m_f44 = 1.0f;

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
				dAccumulate += math::GetElement(_krA, n, y) * math::GetElement(_krB, x, y);
			}
			math::SetElement(_rResult, dAccumulate, x, y);
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
				fAccumulate += math::GetElement(_krA, n, y) * math::GetElement(_krB, x, y);
			}
			math::SetElement(_rResult, fAccumulate, x, y);
		}
	}

	return(_rResult);
}

const TMatrix4d& math::ScalarMultiply(	TMatrix4d& _rResult,
										const TMatrix4d& _krMatrix,
										const double _kdScalar)
{
	_rResult.m_d11 = _krMatrix.m_d11 * _kdScalar;
	_rResult.m_d12 = _krMatrix.m_d12 * _kdScalar;
	_rResult.m_d13 = _krMatrix.m_d13 * _kdScalar;
	_rResult.m_d14 = _krMatrix.m_d14 * _kdScalar;

	_rResult.m_d21 = _krMatrix.m_d21 * _kdScalar;
	_rResult.m_d22 = _krMatrix.m_d22 * _kdScalar;
	_rResult.m_d23 = _krMatrix.m_d23 * _kdScalar;
	_rResult.m_d24 = _krMatrix.m_d24 * _kdScalar;

	_rResult.m_d31 = _krMatrix.m_d31 * _kdScalar;
	_rResult.m_d32 = _krMatrix.m_d32 * _kdScalar;
	_rResult.m_d33 = _krMatrix.m_d33 * _kdScalar;
	_rResult.m_d34 = _krMatrix.m_d34 * _kdScalar;

	_rResult.m_d41 = _krMatrix.m_d41 * _kdScalar;
	_rResult.m_d42 = _krMatrix.m_d42 * _kdScalar;
	_rResult.m_d43 = _krMatrix.m_d43 * _kdScalar;
	_rResult.m_d44 = _krMatrix.m_d44 * _kdScalar;

	return(_rResult);
}

const TMatrix4f& math::ScalarMultiply(	TMatrix4f& _rResult,
										const TMatrix4f& _krMatrix,
										const float _kfScalar)
{
	_rResult.m_f11 = _krMatrix.m_f11 * _kfScalar;
	_rResult.m_f12 = _krMatrix.m_f12 * _kfScalar;
	_rResult.m_f13 = _krMatrix.m_f13 * _kfScalar;
	_rResult.m_f14 = _krMatrix.m_f14 * _kfScalar;

	_rResult.m_f21 = _krMatrix.m_f21 * _kfScalar;
	_rResult.m_f22 = _krMatrix.m_f22 * _kfScalar;
	_rResult.m_f23 = _krMatrix.m_f23 * _kfScalar;
	_rResult.m_f24 = _krMatrix.m_f24 * _kfScalar;

	_rResult.m_f31 = _krMatrix.m_f31 * _kfScalar;
	_rResult.m_f32 = _krMatrix.m_f32 * _kfScalar;
	_rResult.m_f33 = _krMatrix.m_f33 * _kfScalar;
	_rResult.m_f34 = _krMatrix.m_f34 * _kfScalar;

	_rResult.m_f41 = _krMatrix.m_f41 * _kfScalar;
	_rResult.m_f42 = _krMatrix.m_f42 * _kfScalar;
	_rResult.m_f43 = _krMatrix.m_f43 * _kfScalar;
	_rResult.m_f44 = _krMatrix.m_f44 * _kfScalar;

	return(_rResult);
}

const TVector4d& math::VectorMultiply(	TVector4d& _rResult,
										const TMatrix4d& _krA,
										const TVector4d& _krB)
{
	_rResult.m_dX = (_krA.m_d11 * _krB.m_dX) + (_krA.m_d12 * _krB.m_dY) + (_krA.m_d13 * _krB.m_dZ) + (_krA.m_d14 * _krB.m_dW);
	_rResult.m_dY = (_krA.m_d21 * _krB.m_dX) + (_krA.m_d22 * _krB.m_dY) + (_krA.m_d23 * _krB.m_dZ) + (_krA.m_d24 * _krB.m_dW);
	_rResult.m_dZ = (_krA.m_d31 * _krB.m_dX) + (_krA.m_d32 * _krB.m_dY) + (_krA.m_d33 * _krB.m_dZ) + (_krA.m_d34 * _krB.m_dW);
	_rResult.m_dW = (_krA.m_d41 * _krB.m_dX) + (_krA.m_d42 * _krB.m_dY) + (_krA.m_d43 * _krB.m_dZ) + (_krA.m_d44 * _krB.m_dW);

	return(_rResult);
}

const TVector4f& math::VectorMultiply(	TVector4f& _rResult,
										const TMatrix4f& _krA,
										const TVector4f& _krB)
{
	_rResult.m_fX = (_krA.m_f11 * _krB.m_fX) + (_krA.m_f12 * _krB.m_fY) + (_krA.m_f13 * _krB.m_fZ) + (_krA.m_f14 * _krB.m_fW);
	_rResult.m_fY = (_krA.m_f21 * _krB.m_fX) + (_krA.m_f22 * _krB.m_fY) + (_krA.m_f23 * _krB.m_fZ) + (_krA.m_f24 * _krB.m_fW);
	_rResult.m_fZ = (_krA.m_f31 * _krB.m_fX) + (_krA.m_f32 * _krB.m_fY) + (_krA.m_f33 * _krB.m_fZ) + (_krA.m_f34 * _krB.m_fW);
	_rResult.m_fW = (_krA.m_f41 * _krB.m_fX) + (_krA.m_f42 * _krB.m_fY) + (_krA.m_f43 * _krB.m_fZ) + (_krA.m_f44 * _krB.m_fW);

	return(_rResult);
}

const TMatrix4d& math::Add(	TMatrix4d& _rResult,
							const TMatrix4d& _krA,
							const TMatrix4d& _krB)
{
	_rResult.m_d11 = _krA.m_d11 + _krB.m_d11;
	_rResult.m_d12 = _krA.m_d12 + _krB.m_d12;
	_rResult.m_d13 = _krA.m_d13 + _krB.m_d13;
	_rResult.m_d14 = _krA.m_d14 + _krB.m_d14;

	_rResult.m_d21 = _krA.m_d21 + _krB.m_d21;
	_rResult.m_d22 = _krA.m_d22 + _krB.m_d22;
	_rResult.m_d23 = _krA.m_d23 + _krB.m_d23;
	_rResult.m_d24 = _krA.m_d24 + _krB.m_d24;

	_rResult.m_d31 = _krA.m_d31 + _krB.m_d31;
	_rResult.m_d32 = _krA.m_d32 + _krB.m_d32;
	_rResult.m_d33 = _krA.m_d33 + _krB.m_d33;
	_rResult.m_d34 = _krA.m_d34 + _krB.m_d34;

	_rResult.m_d41 = _krA.m_d41 + _krB.m_d41;
	_rResult.m_d42 = _krA.m_d42 + _krB.m_d42;
	_rResult.m_d43 = _krA.m_d43 + _krB.m_d43;
	_rResult.m_d44 = _krA.m_d44 + _krB.m_d44;

	return(_rResult);
}

const TMatrix4f& math::Add(	TMatrix4f& _rResult,
							const TMatrix4f& _krA,
							const TMatrix4f& _krB)
{
	_rResult.m_f11 = _krA.m_f11 + _krB.m_f11;
	_rResult.m_f12 = _krA.m_f12 + _krB.m_f12;
	_rResult.m_f13 = _krA.m_f13 + _krB.m_f13;
	_rResult.m_f14 = _krA.m_f14 + _krB.m_f14;

	_rResult.m_f21 = _krA.m_f21 + _krB.m_f21;
	_rResult.m_f22 = _krA.m_f22 + _krB.m_f22;
	_rResult.m_f23 = _krA.m_f23 + _krB.m_f23;
	_rResult.m_f24 = _krA.m_f24 + _krB.m_f24;

	_rResult.m_f31 = _krA.m_f31 + _krB.m_f31;
	_rResult.m_f32 = _krA.m_f32 + _krB.m_f32;
	_rResult.m_f33 = _krA.m_f33 + _krB.m_f33;
	_rResult.m_f34 = _krA.m_f34 + _krB.m_f34;

	_rResult.m_f41 = _krA.m_f41 + _krB.m_f41;
	_rResult.m_f42 = _krA.m_f42 + _krB.m_f42;
	_rResult.m_f43 = _krA.m_f43 + _krB.m_f43;
	_rResult.m_f44 = _krA.m_f44 + _krB.m_f44;

	return(_rResult);
}

const TMatrix4d& math::Transpose(	TMatrix4d& _rResult,
									const TMatrix4d& _krMatrix)
{
	_rResult.m_d11 = _krMatrix.m_d11; _rResult.m_d12 = _krMatrix.m_d21; _rResult.m_d13 = _krMatrix.m_d31; _rResult.m_d14 = _krMatrix.m_d41;
	_rResult.m_d21 = _krMatrix.m_d12; _rResult.m_d22 = _krMatrix.m_d22; _rResult.m_d23 = _krMatrix.m_d32; _rResult.m_d24 = _krMatrix.m_d42;
	_rResult.m_d31 = _krMatrix.m_d13; _rResult.m_d32 = _krMatrix.m_d23; _rResult.m_d33 = _krMatrix.m_d33; _rResult.m_d34 = _krMatrix.m_d43;
	_rResult.m_d41 = _krMatrix.m_d14; _rResult.m_d42 = _krMatrix.m_d24; _rResult.m_d43 = _krMatrix.m_d34; _rResult.m_d44 = _krMatrix.m_d44;

	return(_rResult);
}

const TMatrix4f& math::Transpose(	TMatrix4f& _rResult,
									const TMatrix4f& _krMatrix)
{
	_rResult.m_f11 = _krMatrix.m_f11; _rResult.m_f12 = _krMatrix.m_f21; _rResult.m_f13 = _krMatrix.m_f31; _rResult.m_f14 = _krMatrix.m_f41;
	_rResult.m_f21 = _krMatrix.m_f12; _rResult.m_f22 = _krMatrix.m_f22; _rResult.m_f23 = _krMatrix.m_f32; _rResult.m_f24 = _krMatrix.m_f42;
	_rResult.m_f31 = _krMatrix.m_f13; _rResult.m_f32 = _krMatrix.m_f23; _rResult.m_f33 = _krMatrix.m_f33; _rResult.m_f34 = _krMatrix.m_f43;
	_rResult.m_f41 = _krMatrix.m_f14; _rResult.m_f42 = _krMatrix.m_f24; _rResult.m_f43 = _krMatrix.m_f34; _rResult.m_f44 = _krMatrix.m_f44;

	return(_rResult);
}

const double math::GetElement(	const TMatrix4d& _krMatrix,
								const size_t _kRow,
								const size_t _kColumn)
{
	double dResult;

	if(_kRow == 1)
	{
		if(_kColumn == 1)
		{
			dResult = _krMatrix.m_d11;
		}
		else if(_kColumn == 2)
		{
			dResult = _krMatrix.m_d12;
		}
		else if(_kColumn == 3)
		{
			dResult = _krMatrix.m_d13;
		}
		else if(_kColumn == 4)
		{
			dResult = _krMatrix.m_d14;
		}
	}
	else if(_kRow == 2)
	{
		if(_kColumn == 1)
		{
			dResult = _krMatrix.m_d21;
		}
		else if(_kColumn == 2)
		{
			dResult = _krMatrix.m_d22;
		}
		else if(_kColumn == 3)
		{
			dResult = _krMatrix.m_d23;
		}
		else if(_kColumn == 4)
		{
			dResult = _krMatrix.m_d24;
		}
	}
	else if(_kRow == 3)
	{
		if(_kColumn == 1)
		{
			dResult = _krMatrix.m_d31;
		}
		else if(_kColumn == 2)
		{
			dResult = _krMatrix.m_d32;
		}
		else if(_kColumn == 3)
		{
			dResult = _krMatrix.m_d33;
		}
		else if(_kColumn == 4)
		{
			dResult = _krMatrix.m_d34;
		}
	}
	else if(_kRow == 4)
	{
		if(_kColumn == 1)
		{
			dResult = _krMatrix.m_d41;
		}
		else if(_kColumn == 2)
		{
			dResult = _krMatrix.m_d42;
		}
		else if(_kColumn == 3)
		{
			dResult = _krMatrix.m_d43;
		}
		else if(_kColumn == 4)
		{
			dResult = _krMatrix.m_d44;
		}
	}

	return(dResult);
}

const float math::GetElement(	const TMatrix4f& _krMatrix,
								const size_t _kRow,
								const size_t _kColumn)
{
	float fResult;

	if(_kRow == 1)
	{
		if(_kColumn == 1)
		{
			fResult = _krMatrix.m_f11;
		}
		else if(_kColumn == 2)
		{
			fResult = _krMatrix.m_f12;
		}
		else if(_kColumn == 3)
		{
			fResult = _krMatrix.m_f13;
		}
		else if(_kColumn == 4)
		{
			fResult = _krMatrix.m_f14;
		}
	}
	else if(_kRow == 2)
	{
		if(_kColumn == 1)
		{
			fResult = _krMatrix.m_f21;
		}
		else if(_kColumn == 2)
		{
			fResult = _krMatrix.m_f22;
		}
		else if(_kColumn == 3)
		{
			fResult = _krMatrix.m_f23;
		}
		else if(_kColumn == 4)
		{
			fResult = _krMatrix.m_f24;
		}
	}
	else if(_kRow == 3)
	{
		if(_kColumn == 1)
		{
			fResult = _krMatrix.m_f31;
		}
		else if(_kColumn == 2)
		{
			fResult = _krMatrix.m_f32;
		}
		else if(_kColumn == 3)
		{
			fResult = _krMatrix.m_f33;
		}
		else if(_kColumn == 4)
		{
			fResult = _krMatrix.m_f34;
		}
	}
	else if(_kRow == 4)
	{
		if(_kColumn == 1)
		{
			fResult = _krMatrix.m_f41;
		}
		else if(_kColumn == 2)
		{
			fResult = _krMatrix.m_f42;
		}
		else if(_kColumn == 3)
		{
			fResult = _krMatrix.m_f43;
		}
		else if(_kColumn == 4)
		{
			fResult = _krMatrix.m_f44;
		}
	}

	return(fResult);
}


TMatrix4d& math::SetElement(	TMatrix4d& _rResult,
								const double _kdValue,
								const size_t _kRow,
								const size_t _kColumn)
{
	if(_kRow == 1)
	{
		if(_kColumn == 1)
		{
			_rResult.m_d11 = _kdValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_d12 = _kdValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_d13 = _kdValue;
		}
		else if(_kColumn == 4)
		{
			_rResult.m_d14 = _kdValue;
		}
	}
	else if(_kRow == 2)
	{
		if(_kColumn == 1)
		{
			_rResult.m_d21 = _kdValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_d22 = _kdValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_d23 = _kdValue;
		}
		else if(_kColumn == 4)
		{
			_rResult.m_d24 = _kdValue;
		}
	}
	else if(_kRow == 3)
	{
		if(_kColumn == 1)
		{
			_rResult.m_d31 = _kdValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_d32 = _kdValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_d33 = _kdValue;
		}
		else if(_kColumn == 4)
		{
			_rResult.m_d34 = _kdValue;
		}
	}
	else if(_kRow == 4)
	{
		if(_kColumn == 1)
		{
			_rResult.m_d41 = _kdValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_d42 = _kdValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_d43 = _kdValue;
		}
		else if(_kColumn == 4)
		{
			_rResult.m_d44 = _kdValue;
		}
	}

	return(_rResult);
}

TMatrix4f& math::SetElement(	TMatrix4f& _rResult,
								const float _kfValue,
								const size_t _kRow,
								const size_t _kColumn)
{
	if(_kRow == 1)
	{
		if(_kColumn == 1)
		{
			_rResult.m_f11 = _kfValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_f12 = _kfValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_f13 = _kfValue;
		}
		else if(_kColumn == 4)
		{
			_rResult.m_f14 = _kfValue;
		}
	}
	else if(_kRow == 2)
	{
		if(_kColumn == 1)
		{
			_rResult.m_f21 = _kfValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_f22 = _kfValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_f23 = _kfValue;
		}
		else if(_kColumn == 4)
		{
			_rResult.m_f24 = _kfValue;
		}
	}
	else if(_kRow == 3)
	{
		if(_kColumn == 1)
		{
			_rResult.m_f31 = _kfValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_f32 = _kfValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_f33 = _kfValue;
		}
		else if(_kColumn == 4)
		{
			_rResult.m_f34 = _kfValue;
		}
	}
	else if(_kRow == 4)
	{
		if(_kColumn == 1)
		{
			_rResult.m_f41 = _kfValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_f42 = _kfValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_f43 = _kfValue;
		}
		else if(_kColumn == 4)
		{
			_rResult.m_f44 = _kfValue;
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

				math::SetElement(_rResult, math::GetElement(_krMatrix, i, j), InsertI, InsertJ);
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

				math::SetElement(_rResult, math::GetElement(_krMatrix, i, j), InsertI, InsertJ);
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
	_rResult.m_d11 = math::FirstMinor(_krMatrix, 1, 1);
	_rResult.m_d12 = math::FirstMinor(_krMatrix, 1, 2);
	_rResult.m_d13 = math::FirstMinor(_krMatrix, 1, 3);
	_rResult.m_d14 = math::FirstMinor(_krMatrix, 1, 4);

	_rResult.m_d21 = math::FirstMinor(_krMatrix, 2, 1);
	_rResult.m_d22 = math::FirstMinor(_krMatrix, 2, 2);
	_rResult.m_d23 = math::FirstMinor(_krMatrix, 2, 3);
	_rResult.m_d24 = math::FirstMinor(_krMatrix, 2, 4);

	_rResult.m_d31 = math::FirstMinor(_krMatrix, 3, 1);
	_rResult.m_d32 = math::FirstMinor(_krMatrix, 3, 2);
	_rResult.m_d33 = math::FirstMinor(_krMatrix, 3, 3);
	_rResult.m_d34 = math::FirstMinor(_krMatrix, 3, 4);

	_rResult.m_d41 = math::FirstMinor(_krMatrix, 4, 1);
	_rResult.m_d42 = math::FirstMinor(_krMatrix, 4, 2);
	_rResult.m_d43 = math::FirstMinor(_krMatrix, 4, 3);
	_rResult.m_d44 = math::FirstMinor(_krMatrix, 4, 4);

	return(_rResult);
}

const TMatrix4f& math::MatrixOfMinors(	TMatrix4f& _rResult,
										const TMatrix4f& _krMatrix)
{
	_rResult.m_f11 = math::FirstMinor(_krMatrix, 1, 1);
	_rResult.m_f12 = math::FirstMinor(_krMatrix, 1, 2);
	_rResult.m_f13 = math::FirstMinor(_krMatrix, 1, 3);
	_rResult.m_f14 = math::FirstMinor(_krMatrix, 1, 4);

	_rResult.m_f21 = math::FirstMinor(_krMatrix, 2, 1);
	_rResult.m_f22 = math::FirstMinor(_krMatrix, 2, 2);
	_rResult.m_f23 = math::FirstMinor(_krMatrix, 2, 3);
	_rResult.m_f24 = math::FirstMinor(_krMatrix, 2, 4);

	_rResult.m_f31 = math::FirstMinor(_krMatrix, 3, 1);
	_rResult.m_f32 = math::FirstMinor(_krMatrix, 3, 2);
	_rResult.m_f33 = math::FirstMinor(_krMatrix, 3, 3);
	_rResult.m_f34 = math::FirstMinor(_krMatrix, 3, 4);

	_rResult.m_f41 = math::FirstMinor(_krMatrix, 4, 1);
	_rResult.m_f42 = math::FirstMinor(_krMatrix, 4, 2);
	_rResult.m_f43 = math::FirstMinor(_krMatrix, 4, 3);
	_rResult.m_f44 = math::FirstMinor(_krMatrix, 4, 4);

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

const TMatrix4d& math::TranslationMatrix(	TMatrix4d& _rResult,
											const TVector3d& _krVector)
{
	_rResult.m_d11 = 1.0; _rResult.m_d12 = 0.0; _rResult.m_d13 = 0.0; _rResult.m_d14 = _krVector.m_dX;
	_rResult.m_d21 = 0.0; _rResult.m_d22 = 1.0; _rResult.m_d23 = 0.0; _rResult.m_d24 = _krVector.m_dY;
	_rResult.m_d31 = 0.0; _rResult.m_d32 = 0.0; _rResult.m_d33 = 1.0; _rResult.m_d34 = _krVector.m_dZ;
	_rResult.m_d41 = 0.0; _rResult.m_d42 = 0.0; _rResult.m_d43 = 0.0; _rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& math::TranslationMatrix(	TMatrix4f& _rResult,
											const TVector3f& _krVector)
{
	_rResult.m_f11 = 1.0f; _rResult.m_f12 = 0.0f; _rResult.m_f13 = 0.0f; _rResult.m_f14 = _krVector.m_fX;
	_rResult.m_f21 = 0.0f; _rResult.m_f22 = 1.0f; _rResult.m_f23 = 0.0f; _rResult.m_f24 = _krVector.m_fY;
	_rResult.m_f31 = 0.0f; _rResult.m_f32 = 0.0f; _rResult.m_f33 = 1.0f; _rResult.m_f34 = _krVector.m_fZ;
	_rResult.m_f41 = 0.0f; _rResult.m_f42 = 0.0f; _rResult.m_f43 = 0.0f; _rResult.m_f44 = 1.0f;

	return(_rResult);
}

const TMatrix4d& math::TranslationMatrix(	TMatrix4d& _rResult,
											const double _kdX,
											const double _kdY,
											const double _kdZ)
{
	_rResult.m_d11 = 1.0; _rResult.m_d12 = 0.0; _rResult.m_d13 = 0.0; _rResult.m_d14 = _kdX;
	_rResult.m_d21 = 0.0; _rResult.m_d22 = 1.0; _rResult.m_d23 = 0.0; _rResult.m_d24 = _kdY;
	_rResult.m_d31 = 0.0; _rResult.m_d32 = 0.0; _rResult.m_d33 = 1.0; _rResult.m_d34 = _kdZ;
	_rResult.m_d41 = 0.0; _rResult.m_d42 = 0.0; _rResult.m_d43 = 0.0; _rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& math::TranslationMatrix(	TMatrix4f& _rResult,
											const float _kfX,
											const float _kfY,
											const float _kfZ)
{
	_rResult.m_f11 = 1.0f; _rResult.m_f12 = 0.0f; _rResult.m_f13 = 0.0f; _rResult.m_f14 = _kfX;
	_rResult.m_f21 = 0.0f; _rResult.m_f22 = 1.0f; _rResult.m_f23 = 0.0f; _rResult.m_f24 = _kfY;
	_rResult.m_f31 = 0.0f; _rResult.m_f32 = 0.0f; _rResult.m_f33 = 1.0f; _rResult.m_f34 = _kfZ;
	_rResult.m_f41 = 0.0f; _rResult.m_f42 = 0.0f; _rResult.m_f43 = 0.0f; _rResult.m_f44 = 1.0f;

	return(_rResult);
}

const TMatrix4d& math::ScalingMatrix(	TMatrix4d& _rResult,
										const double _kdX,
										const double _kdY,
										const double _kdZ)
{
	_rResult.m_d11 = _kdX; _rResult.m_d12 = 0.0; _rResult.m_d13 = 0.0; _rResult.m_d14 = 0.0;
	_rResult.m_d21 = 0.0; _rResult.m_d22 = _kdY; _rResult.m_d23 = 0.0; _rResult.m_d24 = 0.0;
	_rResult.m_d31 = 0.0; _rResult.m_d32 = 0.0; _rResult.m_d33 = _kdZ; _rResult.m_d34 = 0.0;
	_rResult.m_d41 = 0.0; _rResult.m_d42 = 0.0; _rResult.m_d43 = 0.0; _rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& math::ScalingMatrix(	TMatrix4f& _rResult,
										const float _kfX,
										const float _kfY,
										const float _kfZ)
{
	_rResult.m_f11 = _kfX; _rResult.m_f12 = 0.0f; _rResult.m_f13 = 0.0f; _rResult.m_f14 = 0.0f;
	_rResult.m_f21 = 0.0f; _rResult.m_f22 = _kfY; _rResult.m_f23 = 0.0f; _rResult.m_f24 = 0.0f;
	_rResult.m_f31 = 0.0f; _rResult.m_f32 = 0.0f; _rResult.m_f33 = _kfZ; _rResult.m_f34 = 0.0f;
	_rResult.m_f41 = 0.0f; _rResult.m_f42 = 0.0f; _rResult.m_f43 = 0.0f; _rResult.m_f44 = 1.0f;

	return(_rResult);
}

const TMatrix4d& math::TransformationMatrix(TMatrix4d& _rResult,
											const TVector3d& _krBasisX,
											const TVector3d& _krBasisY,
											const TVector3d& _krBasisZ,
											const TVector3d& _krTranslation)
{
	_rResult.m_d11 = _krBasisX.m_dX; _rResult.m_d12 = _krBasisY.m_dY; _rResult.m_d13 = _krBasisZ.m_dZ; _rResult.m_d14 = _krTranslation.m_dX;
	_rResult.m_d11 = _krBasisX.m_dX; _rResult.m_d12 = _krBasisY.m_dY; _rResult.m_d13 = _krBasisZ.m_dZ; _rResult.m_d24 = _krTranslation.m_dY;
	_rResult.m_d11 = _krBasisX.m_dX; _rResult.m_d12 = _krBasisY.m_dY; _rResult.m_d13 = _krBasisZ.m_dZ; _rResult.m_d34 = _krTranslation.m_dZ;

	_rResult.m_d41 = 0.0; _rResult.m_d42 = 0.0; _rResult.m_d43 = 0.0; _rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& math::TransformationMatrix(TMatrix4f& _rResult,
											const TVector3f& _krBasisX,
											const TVector3f& _krBasisY,
											const TVector3f& _krBasisZ,
											const TVector3f& _krTranslation)
{
	_rResult.m_f11 = _krBasisX.m_fX; _rResult.m_f12 = _krBasisY.m_fY; _rResult.m_f13 = _krBasisZ.m_fZ; _rResult.m_f14 = _krTranslation.m_fX;
	_rResult.m_f11 = _krBasisX.m_fX; _rResult.m_f12 = _krBasisY.m_fY; _rResult.m_f13 = _krBasisZ.m_fZ; _rResult.m_f24 = _krTranslation.m_fY;
	_rResult.m_f11 = _krBasisX.m_fX; _rResult.m_f12 = _krBasisY.m_fY; _rResult.m_f13 = _krBasisZ.m_fZ; _rResult.m_f34 = _krTranslation.m_fZ;

	_rResult.m_f41 = 0.0f; _rResult.m_f42 = 0.0f; _rResult.m_f43 = 0.0f; _rResult.m_f44 = 1.0f;

	return(_rResult);
}

const TMatrix4d& math::OrientationMatrix(	TMatrix4d& _rResult,
											const TVector4d& _krQuaternion)
{
	_rResult = math::TransformationMatrix(	_rResult,
											math::QuaternionRotate(TVector3d(), TVector3d{1.0, 0.0, 0.0}, _krQuaternion),
											math::QuaternionRotate(TVector3d(), TVector3d{0.0, 1.0, 0.0}, _krQuaternion),
											math::QuaternionRotate(TVector3d(), TVector3d{0.0, 0.0, 1.0}, _krQuaternion),
											TVector3d{0.0, 0.0, 0.0});

	return(_rResult);
}

const TMatrix4f& math::OrientationMatrix(	TMatrix4f& _rResult,
											const TVector4f& _krQuaternion)
{
	_rResult = math::TransformationMatrix(	_rResult,
											math::QuaternionRotate(TVector3f(), TVector3f{1.0f, 0.0f, 0.0f}, _krQuaternion),
											math::QuaternionRotate(TVector3f(), TVector3f{0.0f, 1.0f, 0.0f}, _krQuaternion),
											math::QuaternionRotate(TVector3f(), TVector3f{0.0f, 0.0f, 1.0f}, _krQuaternion),
											TVector3f{0.0f, 0.0f, 0.0f});

	return(_rResult);
}

const TMatrix4d& math::OrientationMatrix(	TMatrix4d& _rResult,
											const TVector3d& _krAxis,
											const double _kdAngle)
{
	const TVector4d kQuaternion = math::AxisAngleQuaternion(TVector4d(), _krAxis, _kdAngle);

	_rResult = math::TransformationMatrix(	_rResult,
											math::QuaternionRotate(TVector3d(), TVector3d{1.0, 0.0, 0.0}, kQuaternion),
											math::QuaternionRotate(TVector3d(), TVector3d{0.0, 1.0, 0.0}, kQuaternion),
											math::QuaternionRotate(TVector3d(), TVector3d{0.0, 0.0, 1.0}, kQuaternion),
											TVector3d{0.0, 0.0, 0.0});

	return(_rResult);
}

const TMatrix4f& math::OrientationMatrix(	TMatrix4f& _rResult,
											const TVector3f& _krAxis,
											const float _kfAngle)
{
	const TVector4f kQuaternion = math::AxisAngleQuaternion(TVector4f(), _krAxis, _kfAngle);

	_rResult = math::TransformationMatrix(	_rResult,
											math::QuaternionRotate(TVector3f(), TVector3f{1.0f, 0.0f, 0.0f}, kQuaternion),
											math::QuaternionRotate(TVector3f(), TVector3f{0.0f, 1.0f, 0.0f}, kQuaternion),
											math::QuaternionRotate(TVector3f(), TVector3f{0.0f, 0.0f, 1.0f}, kQuaternion),
											TVector3f{0.0f, 0.0f, 0.0f});

	return(_rResult);
}

const TMatrix4d& math::AxisOrientationXMatrix(	TMatrix4d& _rResult,
												const double _kdAngle)
{
	_rResult.m_d11 = 1.0; _rResult.m_d12 = 0.0;						_rResult.m_d13 = 0.0;						_rResult.m_d14 = 0.0;
	_rResult.m_d21 = 0.0; _rResult.m_d22 = math::Cosine(_kdAngle);	_rResult.m_d23 = -math::Sine(_kdAngle);		_rResult.m_d24 = 0.0;
	_rResult.m_d31 = 0.0; _rResult.m_d32 = math::Sine(_kdAngle);	_rResult.m_d33 = math::Cosine(_kdAngle);	_rResult.m_d34 = 0.0;
	_rResult.m_d41 = 0.0; _rResult.m_d42 = 0.0;						_rResult.m_d43 = 0.0;						_rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& math::AxisOrientationXMatrix(	TMatrix4f& _rResult,
												const float _kfAngle)
{
	_rResult.m_f11 = 1.0f; _rResult.m_f12 = 0.0f;						_rResult.m_f13 = 0.0f;						_rResult.m_f14 = 0.0f;
	_rResult.m_f21 = 0.0f; _rResult.m_f22 = math::Cosine(_kfAngle);		_rResult.m_f23 = -math::Sine(_kfAngle);		_rResult.m_f24 = 0.0f;
	_rResult.m_f31 = 0.0f; _rResult.m_f32 = math::Sine(_kfAngle);		_rResult.m_f33 = math::Cosine(_kfAngle);	_rResult.m_f34 = 0.0f;
	_rResult.m_f41 = 0.0f; _rResult.m_f42 = 0.0f;						_rResult.m_f43 = 0.0f;						_rResult.m_f44 = 1.0f;

	return(_rResult);
}

const TMatrix4d& math::AxisOrientationYMatrix(	TMatrix4d& _rResult,
												const double _kdAngle)
{
	_rResult.m_d11 = math::Cosine(_kdAngle);	_rResult.m_d12 = 0.0;	_rResult.m_d13 = math::Sine(_kdAngle);		_rResult.m_d14 = 0.0;
	_rResult.m_d21 = 0.0;						_rResult.m_d22 = 1.0;	_rResult.m_d23 = 0.0;						_rResult.m_d24 = 0.0;
	_rResult.m_d31 = -math::Sine(_kdAngle);		_rResult.m_d32 = 0.0;	_rResult.m_d33 = math::Cosine(_kdAngle);	_rResult.m_d34 = 0.0;
	_rResult.m_d41 = 0.0;						_rResult.m_d42 = 0.0;	_rResult.m_d43 = 0.0;						_rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& math::AxisOrientationYMatrix(	TMatrix4f& _rResult,
												const float _kfAngle)
{
	_rResult.m_f11 = math::Cosine(_kfAngle);	_rResult.m_f12 = 0.0f;	_rResult.m_f13 = math::Sine(_kfAngle);		_rResult.m_f14 = 0.0f;
	_rResult.m_f21 = 0.0f;						_rResult.m_f22 = 1.0f;	_rResult.m_f23 = 0.0f;						_rResult.m_f24 = 0.0f;
	_rResult.m_f31 = -math::Sine(_kfAngle);		_rResult.m_f32 = 0.0f;	_rResult.m_f33 = math::Cosine(_kfAngle);	_rResult.m_f34 = 0.0f;
	_rResult.m_f41 = 0.0f;						_rResult.m_f42 = 0.0f;	_rResult.m_f43 = 0.0f;						_rResult.m_f44 = 1.0f;

	return(_rResult);
}

const TMatrix4d& math::AxisOrientationZMatrix(	TMatrix4d& _rResult,
												const double _kdAngle)
{
	_rResult.m_d11 = math::Cosine(_kdAngle);	_rResult.m_d12 = -math::Sine(_kdAngle);		_rResult.m_d13 = 0.0;	_rResult.m_d14 = 0.0;
	_rResult.m_d21 = math::Sine(_kdAngle);		_rResult.m_d22 = math::Cosine(_kdAngle);	_rResult.m_d23 = 0.0;	_rResult.m_d24 = 0.0;
	_rResult.m_d31 = 0.0;						_rResult.m_d32 = 0.0;						_rResult.m_d33 = 1.0;	_rResult.m_d34 = 0.0;
	_rResult.m_d41 = 0.0;						_rResult.m_d42 = 0.0;						_rResult.m_d43 = 0.0;	_rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& math::AxisOrientationZMatrix(	TMatrix4f& _rResult,
												const float _kfAngle)
{
	_rResult.m_f11 = math::Cosine(_kfAngle);	_rResult.m_f12 = -math::Sine(_kfAngle);		_rResult.m_f13 = 0.0f;	_rResult.m_f14 = 0.0f;
	_rResult.m_f21 = math::Sine(_kfAngle);		_rResult.m_f22 = math::Cosine(_kfAngle);	_rResult.m_f23 = 0.0f;	_rResult.m_f24 = 0.0f;
	_rResult.m_f31 = 0.0f;						_rResult.m_f32 = 0.0f;						_rResult.m_f33 = 1.0f;	_rResult.m_f34 = 0.0f;
	_rResult.m_f41 = 0.0f;						_rResult.m_f42 = 0.0f;						_rResult.m_f43 = 0.0f;	_rResult.m_f44 = 1.0f;

	return(_rResult);
}

const TMatrix4d& math::PerspectiveMatrix(	TMatrix4d& _rResult,
											const double _kdLeft,	const double _kdRight,
											const double _kdBottom,	const double _kdTop,
											const double _kdFar,	const double _kdNear)
{
	_rResult.m_d11 = ((2.0 * _kdNear) / (_kdRight - _kdLeft));	_rResult.m_d12 = 0.0;										_rResult.m_d13 = ((_kdRight + _kdLeft) / (_kdRight - _kdLeft));	_rResult.m_d14 = 0.0;
	_rResult.m_d21 = 0.0;										_rResult.m_d22 = ((2.0 * _kdNear) / (_kdTop - _kdBottom));	_rResult.m_d23 = ((_kdTop + _kdBottom) / (_kdTop - _kdBottom));	_rResult.m_d24 = 0.0;
	_rResult.m_d31 = 0.0;										_rResult.m_d32 = 0.0;										_rResult.m_d33 = (-(_kdFar + _kdNear) / (_kdFar - _kdNear));	_rResult.m_d34 = ((-2.0 * _kdFar * _kdNear) / (_kdFar - _kdNear));
	_rResult.m_d41 = 0.0;										_rResult.m_d42 = 0.0;										_rResult.m_d43 = -1.0;											_rResult.m_d44 = 0.0;

	return(_rResult);
}

const TMatrix4f& math::PerspectiveMatrix(	TMatrix4f& _rResult,
											const float _kfLeft,	const float _kfRight,
											const float _kfBottom,	const float _kfTop,
											const float _kfFar,		const float _kfNear)
{
	_rResult.m_f11 = ((2.0f * _kfNear) / (_kfRight - _kfLeft));	_rResult.m_f12 = 0.0f;										_rResult.m_f13 = ((_kfRight + _kfLeft) / (_kfRight - _kfLeft));	_rResult.m_f14 = 0.0f;
	_rResult.m_f21 = 0.0f;										_rResult.m_f22 = ((2.0f * _kfNear) / (_kfTop - _kfBottom));	_rResult.m_f23 = ((_kfTop + _kfBottom) / (_kfTop - _kfBottom));	_rResult.m_f24 = 0.0f;
	_rResult.m_f31 = 0.0f;										_rResult.m_f32 = 0.0f;										_rResult.m_f33 = (-(_kfFar + _kfNear) / (_kfFar - _kfNear));	_rResult.m_f34 = ((-2.0f * _kfFar * _kfNear) / (_kfFar - _kfNear));
	_rResult.m_f41 = 0.0f;										_rResult.m_f42 = 0.0f;										_rResult.m_f43 = -1.0f;											_rResult.m_f44 = 0.0f;

	return(_rResult);
}

const TMatrix4d& math::PerspectiveMatrix(	TMatrix4d& _rResult,
											const double _kdFovX, const double _kdFovY,
											const double _kdFar,	const double _kdNear)
{
	_rResult.m_d11 = math::ArcTan(_kdFovX / 2.0);	_rResult.m_d12 = 0.0;							_rResult.m_d13 = 0.0;											_rResult.m_d14 = 0.0;
	_rResult.m_d21 = 0.0;							_rResult.m_d22 = math::ArcTan(_kdFovY / 2.0);	_rResult.m_d23 = 0.0;											_rResult.m_d24 = 0.0;
	_rResult.m_d31 = 0.0;							_rResult.m_d32 = 0.0;							_rResult.m_d33 = (-(_kdFar + _kdNear) / (_kdFar - _kdNear));	_rResult.m_d34 = ((-2.0 * _kdFar * _kdNear) / (_kdFar - _kdNear));
	_rResult.m_d41 = 0.0;							_rResult.m_d42 = 0.0;							_rResult.m_d43 = -1.0;											_rResult.m_d44 = 0.0;

	return(_rResult);
}

const TMatrix4f& math::PerspectiveMatrix(	TMatrix4f& _rResult,
											const float _kfFovX, const float _kfFovY,
											const float _kfFar,	const float _kfNear)
{
	_rResult.m_f11 = math::ArcTan(_kfFovX / 2.0f);	_rResult.m_f12 = 0.0f;							_rResult.m_f13 = 0.0f;											_rResult.m_f14 = 0.0f;
	_rResult.m_f21 = 0.0f;							_rResult.m_f22 = math::ArcTan(_kfFovY / 2.0f);	_rResult.m_f23 = 0.0f;											_rResult.m_f24 = 0.0f;
	_rResult.m_f31 = 0.0f;							_rResult.m_f32 = 0.0f;							_rResult.m_f33 = (-(_kfFar + _kfNear) / (_kfFar - _kfNear));	_rResult.m_f34 = ((-2.0f * _kfFar * _kfNear) / (_kfFar - _kfNear));
	_rResult.m_f41 = 0.0f;							_rResult.m_f42 = 0.0f;							_rResult.m_f43 = -1.0f;											_rResult.m_f44 = 0.0f;

	return(_rResult);
}

const TMatrix4d& math::OrthographicMatrix(	TMatrix4d& _rResult,
											const double _kdLeft,	const double _kdRight,
											const double _kdBottom,	const double _kdTop,
											const double _kdFar,	const double _kdNear)
{
	_rResult.m_d11 = (2.0 / (_kdRight - _kdLeft));	_rResult.m_d12 = 0.0;							_rResult.m_d13 = 0.0;							_rResult.m_d14 = (-(_kdRight + _kdLeft) / (_kdRight - _kdLeft));
	_rResult.m_d21 = 0.0;							_rResult.m_d22 = (2.0 / (_kdTop - _kdBottom));	_rResult.m_d23 = 0.0;							_rResult.m_d24 = (-(_kdTop + _kdBottom) / (_kdTop - _kdBottom));
	_rResult.m_d31 = 0.0;							_rResult.m_d32 = 0.0;							_rResult.m_d33 = (-2.0 / (_kdFar - _kdNear));	_rResult.m_d34 = (-(_kdFar + _kdNear) / (_kdFar - _kdNear));
	_rResult.m_d41 = 0.0;							_rResult.m_d42 = 0.0;							_rResult.m_d43 = 0.0;							_rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& math::OrthographicMatrix(	TMatrix4f& _rResult,
											const float _kfLeft,	const float _kfRight,
											const float _kfBottom,	const float _kfTop,
											const float _kfFar,		const float _kfNear)
{
	_rResult.m_f11 = (2.0f / (_kfRight - _kfLeft));	_rResult.m_f12 = 0.0f;							_rResult.m_f13 = 0.0f;							_rResult.m_f14 = (-(_kfRight + _kfLeft) / (_kfRight - _kfLeft));
	_rResult.m_f21 = 0.0f;							_rResult.m_f22 = (2.0f / (_kfTop - _kfBottom));	_rResult.m_f23 = 0.0f;							_rResult.m_f24 = (-(_kfTop + _kfBottom) / (_kfTop - _kfBottom));
	_rResult.m_f31 = 0.0f;							_rResult.m_f32 = 0.0f;							_rResult.m_f33 = (-2.0f / (_kfFar - _kfNear));	_rResult.m_f34 = (-(_kfFar + _kfNear) / (_kfFar - _kfNear));
	_rResult.m_f41 = 0.0f;							_rResult.m_f42 = 0.0f;							_rResult.m_f43 = 0.0f;							_rResult.m_f44 = 1.0f;

	return(_rResult);
}

const TMatrix4d& math::OrthographicMatrix(	TMatrix4d& _rResult,
											const double _kdWidth,	const double _kdHeight,
											const double _kdFar,	const double _kdNear)
{
	const double kdRight = _kdWidth / 2.0;
	const double kdTop = _kdHeight / 2.0;

	_rResult.m_d11 = (1.0 / kdRight);	_rResult.m_d12 = 0.0;			_rResult.m_d13 = 0.0;							_rResult.m_d14 = 0.0;
	_rResult.m_d21 = 0.0;				_rResult.m_d22 = (1.0 / kdTop);	_rResult.m_d23 = 0.0;							_rResult.m_d24 = 0.0;
	_rResult.m_d31 = 0.0;				_rResult.m_d32 = 0.0;			_rResult.m_d33 = (-2.0 / (_kdFar - _kdNear));	_rResult.m_d34 = (-(_kdFar + _kdNear) / (_kdFar - _kdNear));
	_rResult.m_d41 = 0.0;				_rResult.m_d42 = 0.0;			_rResult.m_d43 = 0.0;							_rResult.m_d44 = 1.0;

	return(_rResult);
}

const TMatrix4f& math::OrthographicMatrix(	TMatrix4f& _rResult,
											const float _kfWidth,	const float _kfHeight,
											const float _kfFar,		const float _kfNear)
{
	const float kfRight = _kfWidth / 2.0f;
	const float kfTop = _kfHeight / 2.0f;

	_rResult.m_f11 = (1.0f / kfRight);	_rResult.m_f12 = 0.0f;				_rResult.m_f13 = 0.0f;							_rResult.m_f14 = 0.0f;
	_rResult.m_f21 = 0.0f;				_rResult.m_f22 = (1.0f / kfTop);	_rResult.m_f23 = 0.0f;							_rResult.m_f24 = 0.0f;
	_rResult.m_f31 = 0.0f;				_rResult.m_f32 = 0.0f;				_rResult.m_f33 = (-2.0f / (_kfFar - _kfNear));	_rResult.m_f34 = (-(_kfFar + _kfNear) / (_kfFar - _kfNear));
	_rResult.m_f41 = 0.0f;				_rResult.m_f42 = 0.0f;				_rResult.m_f43 = 0.0f;							_rResult.m_f44 = 1.0f;

	return(_rResult);
}

//
// Matrix 3
//

const TMatrix3d& math::ZeroMatrix(TMatrix3d& _rResult)
{
	_rResult.m_d11 = 0.0; _rResult.m_d12 = 0.0; _rResult.m_d13 = 0.0;
	_rResult.m_d21 = 0.0; _rResult.m_d22 = 0.0; _rResult.m_d23 = 0.0;
	_rResult.m_d31 = 0.0; _rResult.m_d32 = 0.0; _rResult.m_d33 = 0.0;

	return(_rResult);
}

const TMatrix3f& math::ZeroMatrix(TMatrix3f& _rResult)
{
	_rResult.m_f11 = 0.0f; _rResult.m_f12 = 0.0f; _rResult.m_f13 = 0.0f;
	_rResult.m_f21 = 0.0f; _rResult.m_f22 = 0.0f; _rResult.m_f23 = 0.0f;
	_rResult.m_f31 = 0.0f; _rResult.m_f32 = 0.0f; _rResult.m_f33 = 0.0f;

	return(_rResult);
}

const TMatrix3d& math::IdentityMatrix(TMatrix3d& _rResult)
{
	_rResult.m_d11 = 1.0; _rResult.m_d12 = 0.0; _rResult.m_d13 = 0.0;
	_rResult.m_d21 = 0.0; _rResult.m_d22 = 1.0; _rResult.m_d23 = 0.0;
	_rResult.m_d31 = 0.0; _rResult.m_d32 = 0.0; _rResult.m_d33 = 1.0;

	return(_rResult);
}

const TMatrix3f& math::IdentityMatrix(TMatrix3f& _rResult)
{
	_rResult.m_f11 = 1.0f; _rResult.m_f12 = 0.0f; _rResult.m_f13 = 0.0f;
	_rResult.m_f21 = 0.0f; _rResult.m_f22 = 1.0f; _rResult.m_f23 = 0.0f;
	_rResult.m_f31 = 0.0f; _rResult.m_f32 = 0.0f; _rResult.m_f33 = 1.0f;

	return(_rResult);
}

const TMatrix3d& math::Multiply(TMatrix3d& _rResult,
								const TMatrix3d& _krA,
								const TMatrix3d& _krB)
{
	_rResult.m_d11 = ((_krA.m_d11 * _krB.m_d11) + (_krA.m_d12 * _krB.m_d21) + (_krA.m_d13 * _krB.m_d31));
	_rResult.m_d12 = ((_krA.m_d11 * _krB.m_d12) + (_krA.m_d12 * _krB.m_d22) + (_krA.m_d13 * _krB.m_d32));
	_rResult.m_d13 = ((_krA.m_d11 * _krB.m_d13) + (_krA.m_d12 * _krB.m_d23) + (_krA.m_d13 * _krB.m_d33));

	_rResult.m_d21 = ((_krA.m_d21 * _krB.m_d11) + (_krA.m_d22 * _krB.m_d21) + (_krA.m_d23 * _krB.m_d31));
	_rResult.m_d22 = ((_krA.m_d21 * _krB.m_d12) + (_krA.m_d22 * _krB.m_d22) + (_krA.m_d23 * _krB.m_d32));
	_rResult.m_d22 = ((_krA.m_d21 * _krB.m_d13) + (_krA.m_d22 * _krB.m_d23) + (_krA.m_d23 * _krB.m_d33));

	_rResult.m_d31 = ((_krA.m_d31 * _krB.m_d11) + (_krA.m_d32 * _krB.m_d21) + (_krA.m_d33 * _krB.m_d31));
	_rResult.m_d32 = ((_krA.m_d31 * _krB.m_d12) + (_krA.m_d32 * _krB.m_d22) + (_krA.m_d33 * _krB.m_d32));
	_rResult.m_d32 = ((_krA.m_d31 * _krB.m_d13) + (_krA.m_d32 * _krB.m_d23) + (_krA.m_d33 * _krB.m_d33));

	return(_rResult);
}

const TMatrix3f& math::Multiply(TMatrix3f& _rResult,
								const TMatrix3f& _krA,
								const TMatrix3f& _krB)
{
	_rResult.m_f11 = ((_krA.m_f11 * _krB.m_f11) + (_krA.m_f12 * _krB.m_f21) + (_krA.m_f13 * _krB.m_f31));
	_rResult.m_f12 = ((_krA.m_f11 * _krB.m_f12) + (_krA.m_f12 * _krB.m_f22) + (_krA.m_f13 * _krB.m_f32));
	_rResult.m_f13 = ((_krA.m_f11 * _krB.m_f13) + (_krA.m_f12 * _krB.m_f23) + (_krA.m_f13 * _krB.m_f33));

	_rResult.m_f21 = ((_krA.m_f21 * _krB.m_f11) + (_krA.m_f22 * _krB.m_f21) + (_krA.m_f23 * _krB.m_f31));
	_rResult.m_f22 = ((_krA.m_f21 * _krB.m_f12) + (_krA.m_f22 * _krB.m_f22) + (_krA.m_f23 * _krB.m_f32));
	_rResult.m_f22 = ((_krA.m_f21 * _krB.m_f13) + (_krA.m_f22 * _krB.m_f23) + (_krA.m_f23 * _krB.m_f33));

	_rResult.m_f31 = ((_krA.m_f31 * _krB.m_f11) + (_krA.m_f32 * _krB.m_f21) + (_krA.m_f33 * _krB.m_f31));
	_rResult.m_f32 = ((_krA.m_f31 * _krB.m_f12) + (_krA.m_f32 * _krB.m_f22) + (_krA.m_f33 * _krB.m_f32));
	_rResult.m_f32 = ((_krA.m_f31 * _krB.m_f13) + (_krA.m_f32 * _krB.m_f23) + (_krA.m_f33 * _krB.m_f33));

	return(_rResult);
}

const TMatrix3d& math::ScalarMultiply(	TMatrix3d& _rResult,
										const TMatrix3d& _krMatrix,
										const double _kdScalar)
{
	_rResult.m_d11 = _krMatrix.m_d11 * _kdScalar; _rResult.m_d12 = _krMatrix.m_d12 * _kdScalar; _rResult.m_d13 = _krMatrix.m_d13 * _kdScalar;
	_rResult.m_d21 = _krMatrix.m_d21 * _kdScalar; _rResult.m_d22 = _krMatrix.m_d22 * _kdScalar; _rResult.m_d23 = _krMatrix.m_d23 * _kdScalar;
	_rResult.m_d31 = _krMatrix.m_d31 * _kdScalar; _rResult.m_d32 = _krMatrix.m_d32 * _kdScalar; _rResult.m_d33 = _krMatrix.m_d33 * _kdScalar;

	return(_rResult);
}

const TMatrix3f& math::ScalarMultiply(	TMatrix3f& _rResult,
										const TMatrix3f& _krMatrix,
										const float _kfScalar)
{
	_rResult.m_f11 = _krMatrix.m_f11 * _kfScalar; _rResult.m_f12 = _krMatrix.m_f12 * _kfScalar; _rResult.m_f13 = _krMatrix.m_f13 * _kfScalar;
	_rResult.m_f21 = _krMatrix.m_f21 * _kfScalar; _rResult.m_f22 = _krMatrix.m_f22 * _kfScalar; _rResult.m_f23 = _krMatrix.m_f23 * _kfScalar;
	_rResult.m_f31 = _krMatrix.m_f31 * _kfScalar; _rResult.m_f32 = _krMatrix.m_f32 * _kfScalar; _rResult.m_f33 = _krMatrix.m_f33 * _kfScalar;

	return(_rResult);
}

const TVector3d& math::VectorMultiply(	TVector3d& _rResult,
										const TMatrix3d& _krA,
										const TVector3d& _krB)
{
	_rResult.m_dX = (_krA.m_d11 * _krB.m_dX) + (_krA.m_d12 * _krB.m_dY) + (_krA.m_d13 * _krB.m_dZ);
	_rResult.m_dY = (_krA.m_d21 * _krB.m_dX) + (_krA.m_d22 * _krB.m_dY) + (_krA.m_d23 * _krB.m_dZ);
	_rResult.m_dZ = (_krA.m_d31 * _krB.m_dX) + (_krA.m_d32 * _krB.m_dY) + (_krA.m_d33 * _krB.m_dZ);

	return(_rResult);
}

const TVector3f& math::VectorMultiply(	TVector3f& _rResult,
										const TMatrix3f& _krA,
										const TVector3f& _krB)
{
	_rResult.m_fX = (_krA.m_f11 * _krB.m_fX) + (_krA.m_f12 * _krB.m_fY) + (_krA.m_f13 * _krB.m_fZ);
	_rResult.m_fY = (_krA.m_f21 * _krB.m_fX) + (_krA.m_f22 * _krB.m_fY) + (_krA.m_f23 * _krB.m_fZ);
	_rResult.m_fZ = (_krA.m_f31 * _krB.m_fX) + (_krA.m_f32 * _krB.m_fY) + (_krA.m_f33 * _krB.m_fZ);

	return(_rResult);
}

const TMatrix3d& math::Add(	TMatrix3d& _rResult,
							const TMatrix3d& _krA,
							const TMatrix3d& _krB)
{
	_rResult.m_d11 = _krA.m_d11 + _krB.m_d11; _rResult.m_d12 = _krA.m_d12 + _krB.m_d12; _rResult.m_d13 = _krA.m_d13 + _krB.m_d13;
	_rResult.m_d21 = _krA.m_d21 + _krB.m_d21; _rResult.m_d22 = _krA.m_d22 + _krB.m_d22; _rResult.m_d23 = _krA.m_d23 + _krB.m_d23;
	_rResult.m_d31 = _krA.m_d31 + _krB.m_d31; _rResult.m_d32 = _krA.m_d32 + _krB.m_d32; _rResult.m_d33 = _krA.m_d33 + _krB.m_d33;

	return(_rResult);
}

const TMatrix3f& math::Add(	TMatrix3f& _rResult,
							const TMatrix3f& _krA,
							const TMatrix3f& _krB)
{
	_rResult.m_f11 = _krA.m_f11 + _krB.m_f11; _rResult.m_f12 = _krA.m_f12 + _krB.m_f12; _rResult.m_f13 = _krA.m_f13 + _krB.m_f13;
	_rResult.m_f21 = _krA.m_f21 + _krB.m_f21; _rResult.m_f22 = _krA.m_f22 + _krB.m_f22; _rResult.m_f23 = _krA.m_f23 + _krB.m_f23;
	_rResult.m_f31 = _krA.m_f31 + _krB.m_f31; _rResult.m_f32 = _krA.m_f32 + _krB.m_f32; _rResult.m_f33 = _krA.m_f33 + _krB.m_f33;

	return(_rResult);
}

const TMatrix3d& math::Transpose(	TMatrix3d& _rResult,
									const TMatrix3d& _krMatrix)
{
	_rResult.m_d11 = _krMatrix.m_d11; _rResult.m_d12 = _krMatrix.m_d21; _rResult.m_d13 = _krMatrix.m_d31;
	_rResult.m_d21 = _krMatrix.m_d12; _rResult.m_d22 = _krMatrix.m_d22; _rResult.m_d23 = _krMatrix.m_d32;
	_rResult.m_d31 = _krMatrix.m_d13; _rResult.m_d32 = _krMatrix.m_d23; _rResult.m_d33 = _krMatrix.m_d33;

	return(_rResult);
}

const TMatrix3f& math::Transpose(	TMatrix3f& _rResult,
									const TMatrix3f& _krMatrix)
{
	_rResult.m_f11 = _krMatrix.m_f11; _rResult.m_f12 = _krMatrix.m_f21; _rResult.m_f13 = _krMatrix.m_f31;
	_rResult.m_f21 = _krMatrix.m_f12; _rResult.m_f22 = _krMatrix.m_f22; _rResult.m_f23 = _krMatrix.m_f32;
	_rResult.m_f31 = _krMatrix.m_f13; _rResult.m_f32 = _krMatrix.m_f23; _rResult.m_f33 = _krMatrix.m_f33;
	
	return(_rResult);
}

TMatrix3d& math::SetElement(	TMatrix3d& _rResult,
								const double _kdValue,
								const size_t _kRow,
								const size_t _kColumn)
{
	if(_kRow == 1)
	{
		if(_kColumn == 1)
		{
			_rResult.m_d11 = _kdValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_d12 = _kdValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_d13 = _kdValue;
		}
	}
	else if(_kRow == 2)
	{
		if(_kColumn == 1)
		{
			_rResult.m_d21 = _kdValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_d22 = _kdValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_d23 = _kdValue;
		}
	}
	else if(_kRow == 3)
	{
		if(_kColumn == 1)
		{
			_rResult.m_d31 = _kdValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_d32 = _kdValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_d33 = _kdValue;
		}
	}

	return(_rResult);
}

TMatrix3f& math::SetElement(	TMatrix3f& _rResult,
								const float _kfValue,
								const size_t _kRow,
								const size_t _kColumn)
{
	if(_kRow == 1)
	{
		if(_kColumn == 1)
		{
			_rResult.m_f11 = _kfValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_f12 = _kfValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_f13 = _kfValue;
		}
	}
	else if(_kRow == 2)
	{
		if(_kColumn == 1)
		{
			_rResult.m_f21 = _kfValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_f22 = _kfValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_f23 = _kfValue;
		}
	}
	else if(_kRow == 3)
	{
		if(_kColumn == 1)
		{
			_rResult.m_f31 = _kfValue;
		}
		else if(_kColumn == 2)
		{
			_rResult.m_f32 = _kfValue;
		}
		else if(_kColumn == 3)
		{
			_rResult.m_f33 = _kfValue;
		}
	}

	return(_rResult);
}

const TMatrix2d& math::Submatrix(	TMatrix2d& _rResult, 
									const TMatrix3d& _krMatrix,
									const size_t _kDeletedRow,
									const size_t _kDeletedColumn)
{
	if(_kDeletedRow == 1)
	{
		if(_kDeletedColumn == 1)
		{
			_rResult.m_d11 = _krMatrix.m_d22; _rResult.m_d12 = _krMatrix.m_d23;
			_rResult.m_d21 = _krMatrix.m_d32; _rResult.m_d22 = _krMatrix.m_d33;
		}
		else if(_kDeletedColumn == 2)
		{
			_rResult.m_d11 = _krMatrix.m_d21; _rResult.m_d12 = _krMatrix.m_d23;
			_rResult.m_d21 = _krMatrix.m_d31; _rResult.m_d22 = _krMatrix.m_d33;
		}
		else if(_kDeletedColumn == 3)
		{
			_rResult.m_d11 = _krMatrix.m_d21; _rResult.m_d12 = _krMatrix.m_d22;
			_rResult.m_d21 = _krMatrix.m_d31; _rResult.m_d22 = _krMatrix.m_d32;
		}
	}
	else if(_kDeletedRow == 2)
	{
		if(_kDeletedColumn == 1)
		{
			_rResult.m_d11 = _krMatrix.m_d12; _rResult.m_d12 = _krMatrix.m_d13;
			_rResult.m_d21 = _krMatrix.m_d32; _rResult.m_d22 = _krMatrix.m_d33;
		}
		else if(_kDeletedColumn == 2)
		{
			_rResult.m_d11 = _krMatrix.m_d11; _rResult.m_d12 = _krMatrix.m_d13;
			_rResult.m_d21 = _krMatrix.m_d31; _rResult.m_d22 = _krMatrix.m_d33;
		}
		else if(_kDeletedColumn == 3)
		{
			_rResult.m_d11 = _krMatrix.m_d11; _rResult.m_d12 = _krMatrix.m_d12;
			_rResult.m_d21 = _krMatrix.m_d31; _rResult.m_d22 = _krMatrix.m_d32;
		}
	}
	else if(_kDeletedRow == 3)
	{
		if(_kDeletedColumn == 1)
		{
			_rResult.m_d11 = _krMatrix.m_d12; _rResult.m_d12 = _krMatrix.m_d13;
			_rResult.m_d21 = _krMatrix.m_d22; _rResult.m_d22 = _krMatrix.m_d23;
		}
		else if(_kDeletedColumn == 2)
		{
			_rResult.m_d11 = _krMatrix.m_d11; _rResult.m_d12 = _krMatrix.m_d13;
			_rResult.m_d21 = _krMatrix.m_d21; _rResult.m_d22 = _krMatrix.m_d23;
		}
		else if(_kDeletedColumn == 3)
		{
			_rResult.m_d11 = _krMatrix.m_d11; _rResult.m_d12 = _krMatrix.m_d12;
			_rResult.m_d21 = _krMatrix.m_d21; _rResult.m_d22 = _krMatrix.m_d22;
		}
	}

	return(_rResult);
}

const TMatrix2f& math::Submatrix(	TMatrix2f& _rResult, 
									const TMatrix3f& _krMatrix,
									const size_t _kDeletedRow,
									const size_t _kDeletedColumn)
{
	if(_kDeletedRow == 1)
	{
		if(_kDeletedColumn == 1)
		{
			_rResult.m_f11 = _krMatrix.m_f22; _rResult.m_f12 = _krMatrix.m_f23;
			_rResult.m_f21 = _krMatrix.m_f32; _rResult.m_f22 = _krMatrix.m_f33;
		}
		else if(_kDeletedColumn == 2)
		{
			_rResult.m_f11 = _krMatrix.m_f21; _rResult.m_f12 = _krMatrix.m_f23;
			_rResult.m_f21 = _krMatrix.m_f31; _rResult.m_f22 = _krMatrix.m_f33;
		}
		else if(_kDeletedColumn == 3)
		{
			_rResult.m_f11 = _krMatrix.m_f21; _rResult.m_f12 = _krMatrix.m_f22;
			_rResult.m_f21 = _krMatrix.m_f31; _rResult.m_f22 = _krMatrix.m_f32;
		}
	}
	else if(_kDeletedRow == 2)
	{
		if(_kDeletedColumn == 1)
		{
			_rResult.m_f11 = _krMatrix.m_f12; _rResult.m_f12 = _krMatrix.m_f13;
			_rResult.m_f21 = _krMatrix.m_f32; _rResult.m_f22 = _krMatrix.m_f33;
		}
		else if(_kDeletedColumn == 2)
		{
			_rResult.m_f11 = _krMatrix.m_f11; _rResult.m_f12 = _krMatrix.m_f13;
			_rResult.m_f21 = _krMatrix.m_f31; _rResult.m_f22 = _krMatrix.m_f33;
		}
		else if(_kDeletedColumn == 3)
		{
			_rResult.m_f11 = _krMatrix.m_f11; _rResult.m_f12 = _krMatrix.m_f12;
			_rResult.m_f21 = _krMatrix.m_f31; _rResult.m_f22 = _krMatrix.m_f32;
		}
	}
	else if(_kDeletedRow == 3)
	{
		if(_kDeletedColumn == 1)
		{
			_rResult.m_f11 = _krMatrix.m_f12; _rResult.m_f12 = _krMatrix.m_f13;
			_rResult.m_f21 = _krMatrix.m_f22; _rResult.m_f22 = _krMatrix.m_f23;
		}
		else if(_kDeletedColumn == 2)
		{
			_rResult.m_f11 = _krMatrix.m_f11; _rResult.m_f12 = _krMatrix.m_f13;
			_rResult.m_f21 = _krMatrix.m_f21; _rResult.m_f22 = _krMatrix.m_f23;
		}
		else if(_kDeletedColumn == 3)
		{
			_rResult.m_f11 = _krMatrix.m_f11; _rResult.m_f12 = _krMatrix.m_f12;
			_rResult.m_f21 = _krMatrix.m_f21; _rResult.m_f22 = _krMatrix.m_f22;
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
	_rResult.m_d11 = math::FirstMinor(_krMatrix, 1, 1);
	_rResult.m_d12 = math::FirstMinor(_krMatrix, 1, 2);
	_rResult.m_d13 = math::FirstMinor(_krMatrix, 1, 3);

	_rResult.m_d21 = math::FirstMinor(_krMatrix, 2, 1);
	_rResult.m_d22 = math::FirstMinor(_krMatrix, 2, 2);
	_rResult.m_d23 = math::FirstMinor(_krMatrix, 2, 3);

	_rResult.m_d31 = math::FirstMinor(_krMatrix, 3, 1);
	_rResult.m_d32 = math::FirstMinor(_krMatrix, 3, 2);
	_rResult.m_d33 = math::FirstMinor(_krMatrix, 3, 3);

	return(_rResult);
}

const TMatrix3f& math::MatrixOfMinors(	TMatrix3f& _rResult,
										const TMatrix3f& _krMatrix)
{
	_rResult.m_f11 = math::FirstMinor(_krMatrix, 1, 1);
	_rResult.m_f12 = math::FirstMinor(_krMatrix, 1, 2);
	_rResult.m_f13 = math::FirstMinor(_krMatrix, 1, 3);

	_rResult.m_f21 = math::FirstMinor(_krMatrix, 2, 1);
	_rResult.m_f22 = math::FirstMinor(_krMatrix, 2, 2);
	_rResult.m_f23 = math::FirstMinor(_krMatrix, 2, 3);

	_rResult.m_f31 = math::FirstMinor(_krMatrix, 3, 1);
	_rResult.m_f32 = math::FirstMinor(_krMatrix, 3, 2);
	_rResult.m_f33 = math::FirstMinor(_krMatrix, 3, 3);

	return(_rResult);
}

const TMatrix3d& math::MatrixOfCofactors(	TMatrix3d& _rResult,
											const TMatrix3d& _krMatrix)
{
	_rResult = math::MatrixOfMinors(_rResult, _krMatrix);
	
	_rResult.m_d12 *= -1.0;

	_rResult.m_d21 *= -1.0;
	_rResult.m_d23 *= -1.0;

	_rResult.m_d32 *= -1.0;

	return(_rResult);
}

const TMatrix3f& math::MatrixOfCofactors(	TMatrix3f& _rResult,
											const TMatrix3f& _krMatrix)
{
	_rResult = math::MatrixOfMinors(_rResult, _krMatrix);

	_rResult.m_f12 *= -1.0f;

	_rResult.m_f21 *= -1.0f;
	_rResult.m_f23 *= -1.0f;

	_rResult.m_f32 *= -1.0f;

	return(_rResult);
}

const TMatrix3d& math::Inverse(	TMatrix3d& _rResult,
								const TMatrix3d& _krMatrix)
{
	_rResult = math::ScalarMultiply(_rResult, math::Transpose(TMatrix3d(), _krMatrix), 1.0/math::Determinant(_krMatrix));

	return(_rResult);
}

const TMatrix3f& math::Inverse(	TMatrix3f& _rResult,
								const TMatrix3f& _krMatrix)
{
	_rResult = math::ScalarMultiply(_rResult, math::Transpose(TMatrix3f(), _krMatrix), 1.0f/math::Determinant(_krMatrix));

	return(_rResult);
}

//
// Matrix 2
//

const TMatrix2d& math::ZeroMatrix(TMatrix2d& _rResult)
{
	_rResult.m_d11 = 0.0; _rResult.m_d12 = 0.0;
	_rResult.m_d21 = 0.0; _rResult.m_d22 = 0.0;

	return(_rResult);
}

const TMatrix2f& math::ZeroMatrix(TMatrix2f& _rResult)
{
	_rResult.m_f11 = 0.0f; _rResult.m_f12 = 0.0f;
	_rResult.m_f21 = 0.0f; _rResult.m_f22 = 0.0f;

	return(_rResult);
}

const TMatrix2d& math::IdentityMatrix(TMatrix2d& _rResult)
{
	_rResult.m_d11 = 1.0; _rResult.m_d12 = 0.0;
	_rResult.m_d21 = 0.0; _rResult.m_d22 = 1.0;

	return(_rResult);
}

const TMatrix2f& math::IdentityMatrix(TMatrix2f& _rResult)
{
	_rResult.m_f11 = 1.0f; _rResult.m_f12 = 0.0f;
	_rResult.m_f21 = 0.0f; _rResult.m_f22 = 1.0f;

	return(_rResult);
}

const TMatrix2d& math::Multiply(TMatrix2d& _rResult,
								const TMatrix2d& _krA,
								const TMatrix2d& _krB)
{
	_rResult.m_d11 = ((_krA.m_d11 * _krB.m_d11) + (_krA.m_d12 * _krB.m_d21));
	_rResult.m_d12 = ((_krA.m_d11 * _krB.m_d12) + (_krA.m_d12 * _krB.m_d22));
	_rResult.m_d21 = ((_krA.m_d21 * _krB.m_d11) + (_krA.m_d22 * _krB.m_d21));
	_rResult.m_d22 = ((_krA.m_d21 * _krB.m_d12) + (_krA.m_d22 * _krB.m_d22));

	return(_rResult);
}

const TMatrix2f& math::Multiply(TMatrix2f& _rResult,
								const TMatrix2f& _krA,
								const TMatrix2f& _krB)
{
	_rResult.m_f11 = ((_krA.m_f11 * _krB.m_f11) + (_krA.m_f12 * _krB.m_f21));
	_rResult.m_f12 = ((_krA.m_f11 * _krB.m_f12) + (_krA.m_f12 * _krB.m_f22));
	_rResult.m_f21 = ((_krA.m_f21 * _krB.m_f11) + (_krA.m_f22 * _krB.m_f21));
	_rResult.m_f22 = ((_krA.m_f21 * _krB.m_f12) + (_krA.m_f22 * _krB.m_f22));

	return(_rResult);
}

const TMatrix2d& math::ScalarMultiply(	TMatrix2d& _rResult,
										const TMatrix2d& _krMatrix,
										const double _kdScalar)
{
	_rResult.m_d11 = _krMatrix.m_d11 * _kdScalar; _rResult.m_d12 = _krMatrix.m_d12 * _kdScalar;
	_rResult.m_d21 = _krMatrix.m_d21 * _kdScalar; _rResult.m_d22 = _krMatrix.m_d22 * _kdScalar;

	return(_rResult);
}

const TMatrix2f& math::ScalarMultiply(	TMatrix2f& _rResult,
										const TMatrix2f& _krMatrix,
										const float _kfScalar)
{
	_rResult.m_f11 = _krMatrix.m_f11 * _kfScalar; _rResult.m_f12 = _krMatrix.m_f12 * _kfScalar;
	_rResult.m_f21 = _krMatrix.m_f21 * _kfScalar; _rResult.m_f22 = _krMatrix.m_f22 * _kfScalar;

	return(_rResult);
}

const TVector2d& math::VectorMultiply(	TVector2d& _rResult,
										const TMatrix2d& _krA,
										const TVector2d& _krB)
{
	_rResult.m_dX = (_krA.m_d11 * _krB.m_dX) + (_krA.m_d12 * _krB.m_dY);
	_rResult.m_dY = (_krA.m_d21 * _krB.m_dX) + (_krA.m_d22 * _krB.m_dY);

	return(_rResult);
}

const TVector2f& math::VectorMultiply(	TVector2f& _rResult,
										const TMatrix2f& _krA,
										const TVector2f& _krB)
{
	_rResult.m_fX = (_krA.m_f11 * _krB.m_fX) + (_krA.m_f12 * _krB.m_fY);
	_rResult.m_fY = (_krA.m_f21 * _krB.m_fX) + (_krA.m_f22 * _krB.m_fY);

	return(_rResult);
}

const TMatrix2d& math::Add(	TMatrix2d& _rResult,
							const TMatrix2d& _krA,
							const TMatrix2d& _krB)
{
	_rResult.m_d11 = _krA.m_d11 + _krB.m_d11; _rResult.m_d12 = _krA.m_d12 + _krB.m_d12;
	_rResult.m_d21 = _krA.m_d21 + _krB.m_d21; _rResult.m_d22 = _krA.m_d22 + _krB.m_d22;

	return(_rResult);
}

const TMatrix2f& math::Add(	TMatrix2f& _rResult,
							const TMatrix2f& _krA,
							const TMatrix2f& _krB)
{
	_rResult.m_f11 = _krA.m_f11 + _krB.m_f11; _rResult.m_f12 = _krA.m_f12 + _krB.m_f12;
	_rResult.m_f21 = _krA.m_f21 + _krB.m_f21; _rResult.m_f22 = _krA.m_f22 + _krB.m_f22;

	return(_rResult);
}

const TMatrix2d& math::Transpose(	TMatrix2d& _rResult,
									const TMatrix2d& _krMatrix)
{
	_rResult.m_d11 = _krMatrix.m_d11; _rResult.m_d12 = _krMatrix.m_d21;
	_rResult.m_d21 = _krMatrix.m_d12; _rResult.m_d22 = _krMatrix.m_d22;

	return(_rResult);
}

const TMatrix2f& math::Transpose(	TMatrix2f& _rResult,
									const TMatrix2f& _krMatrix)
{
	_rResult.m_f11 = _krMatrix.m_f11; _rResult.m_f12 = _krMatrix.m_f21;
	_rResult.m_f21 = _krMatrix.m_f12; _rResult.m_f22 = _krMatrix.m_f22;

	return(_rResult);
}

const TMatrix2d& math::Inverse(	TMatrix2d& _rResult,
								const TMatrix2d& _krMatrix)
{
	_rResult = math::ScalarMultiply(_rResult, math::Transpose(TMatrix2d(), _krMatrix), 1.0/math::Determinant(_krMatrix));

	return(_rResult);
}

const TMatrix2f& math::Inverse(	TMatrix2f& _rResult,
								const TMatrix2f& _krMatrix)
{
	_rResult = math::ScalarMultiply(_rResult, math::Transpose(TMatrix2f(), _krMatrix), 1.0f/math::Determinant(_krMatrix));

	return(_rResult);
}

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