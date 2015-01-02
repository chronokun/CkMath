//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

// Local Includes
#include "math_vector.h"
#include "math_scalar.h"

//
// Vector 4
//

const TVector4d& math::ZeroVector(TVector4d& _rResult)
{
	_rResult.m_dX = 0.0;
	_rResult.m_dY = 0.0;
	_rResult.m_dZ = 0.0;
	_rResult.m_dW = 0.0;

	return(_rResult);
}

const TVector4f& math::ZeroVector(TVector4f& _rResult)
{
	_rResult.m_fX = 0.0f;
	_rResult.m_fY = 0.0f;
	_rResult.m_fZ = 0.0f;
	_rResult.m_fW = 0.0f;

	return(_rResult);
}

const bool math::Equal(	const TVector4d& _krA,
						const TVector4d& _krB,
						const double _kdEpsilon)
{
	const bool kbEqual =	(math::Magnitude(_krA.m_dX - _krB.m_dX) < _kdEpsilon)
						&&	(math::Magnitude(_krA.m_dY - _krB.m_dY) < _kdEpsilon)
						&&	(math::Magnitude(_krA.m_dZ - _krB.m_dZ) < _kdEpsilon)
						&&	(math::Magnitude(_krA.m_dW - _krB.m_dW) < _kdEpsilon);

	return(kbEqual);
}

const bool math::Equal(	const TVector4f& _krA,
						const TVector4f& _krB,
						const float _kfEpsilon)
{
	const bool kbEqual =	(math::Magnitude(_krA.m_fX - _krB.m_fX) < _kfEpsilon)
						&&	(math::Magnitude(_krA.m_fY - _krB.m_fY) < _kfEpsilon)
						&&	(math::Magnitude(_krA.m_fZ - _krB.m_fZ) < _kfEpsilon)
						&&	(math::Magnitude(_krA.m_fW - _krB.m_fW) < _kfEpsilon);

	return(kbEqual);
}

const TVector4d& math::Add(	TVector4d& _rResult,
							const TVector4d& _krA, 
							const TVector4d& _krB)
{
#ifdef __CKMATH_USE_AVX__
	_rResult.m_Vec = _mm256_add_pd(_krA.m_Vec, _krB.m_Vec); 
#else
	_rResult.m_dX = _krA.m_dX + _krB.m_dX;
	_rResult.m_dY = _krA.m_dY + _krB.m_dY;
	_rResult.m_dZ = _krA.m_dZ + _krB.m_dZ;
	_rResult.m_dW = _krA.m_dW + _krB.m_dW;
#endif

	return(_rResult);
}

const TVector4f& math::Add(	TVector4f& _rResult,
							const TVector4f& _krA, 
							const TVector4f& _krB)
{
#ifdef __CKMATH_USE_AVX__
	_rResult.m_Vec = _mm_add_ps(_krA.m_Vec, _krB.m_Vec);
#else
	_rResult.m_fX = _krA.m_fX + _krB.m_fX;
	_rResult.m_fY = _krA.m_fY + _krB.m_fY;
	_rResult.m_fZ = _krA.m_fZ + _krB.m_fZ;
	_rResult.m_fW = _krA.m_fW + _krB.m_fW;
#endif

	return(_rResult);
}

const TVector4d& math::Subtract(TVector4d& _rResult,
								const TVector4d& _krA,
								const TVector4d& _krB)
{
	_rResult.m_dX = _krA.m_dX - _krB.m_dX;
	_rResult.m_dY = _krA.m_dY - _krB.m_dY;
	_rResult.m_dZ = _krA.m_dZ - _krB.m_dZ;
	_rResult.m_dW = _krA.m_dW - _krB.m_dW;

	return(_rResult);
}

const TVector4f& math::Subtract(TVector4f& _rResult,
								const TVector4f& _krA,
								const TVector4f& _krB)
{
	_rResult.m_fX = _krA.m_fX - _krB.m_fX;
	_rResult.m_fY = _krA.m_fY - _krB.m_fY;
	_rResult.m_fZ = _krA.m_fZ - _krB.m_fZ;
	_rResult.m_fW = _krA.m_fW - _krB.m_fW;

	return(_rResult);
}

const TVector4d& math::ScalarMultiply(	TVector4d& _rResult,
										const TVector4d& _krV,
										const double _kdS)
{
	_rResult.m_dX = _krV.m_dX * _kdS;
	_rResult.m_dY = _krV.m_dY * _kdS;
	_rResult.m_dZ = _krV.m_dZ * _kdS;
	_rResult.m_dW = _krV.m_dW * _kdS;

	return(_rResult);
}

const TVector4f& math::ScalarMultiply(	TVector4f& _rResult,
										const TVector4f& _krV,
										const float _kfS)
{
	_rResult.m_fX = _krV.m_fX * _kfS;
	_rResult.m_fY = _krV.m_fY * _kfS;
	_rResult.m_fZ = _krV.m_fZ * _kfS;
	_rResult.m_fW = _krV.m_fW * _kfS;

	return(_rResult);
}

const double math::Magnitude(const TVector4d& _krV)
{
	return(math::SquareRoot(	math::Square(_krV.m_dX)
							+	math::Square(_krV.m_dY)
							+	math::Square(_krV.m_dZ)
							+	math::Square(_krV.m_dW)));
}

const float math::Magnitude(const TVector4f& _krV)
{
	return(math::SquareRoot(	math::Square(_krV.m_fX)
							+	math::Square(_krV.m_fY)
							+	math::Square(_krV.m_fZ)
							+	math::Square(_krV.m_fW)));
}

const double math::DotProduct(	const TVector4d& _krA,
								const TVector4d& _krB)
{
	return(		(_krA.m_dX * _krB.m_dX)
			+	(_krA.m_dY * _krB.m_dY)
			+	(_krA.m_dZ * _krB.m_dZ)
			+	(_krA.m_dW * _krB.m_dW));
}

const float math::DotProduct(	const TVector4f& _krA,
								const TVector4f& _krB)
{
	return(		(_krA.m_fX * _krB.m_fX)
			+	(_krA.m_fY * _krB.m_fY)
			+	(_krA.m_fZ * _krB.m_fZ)
			+	(_krA.m_fW * _krB.m_fW));
}

const TVector4d& math::Normalize(	TVector4d& _rResult,
									const TVector4d& _krV)
{
	math::ScalarMultiply(_rResult, _krV, (1.0 / math::Magnitude(_krV)) );
	return(_rResult);
}

const TVector4f& math::Normalize(	TVector4f& _rResult,
									const TVector4f& _krV)
{
	math::ScalarMultiply(_rResult, _krV, (1.0f / math::Magnitude(_krV)) );
	return(_rResult);
}

const TVector4d& math::Projection(	TVector4d& _rResult,
									const TVector4d& _krA,
									const TVector4d& _krB)
{
	const double kdDenom = math::Square(math::Magnitude(_krB));

	const TVector4d kNumer = math::ScalarMultiply(TVector4d(), _krB, DotProduct(_krA, _krB));

	_rResult = math::ScalarMultiply(_rResult, kNumer, kdDenom);

	return(_rResult);
}

const TVector4f& math::Projection(	TVector4f& _rResult,
									const TVector4f& _krA,
									const TVector4f& _krB)
{
	const float kfDenom = math::Square(math::Magnitude(_krB));

	const TVector4f kNumer = math::ScalarMultiply(TVector4f(), _krB, DotProduct(_krA, _krB));

	_rResult = math::ScalarMultiply(_rResult, kNumer, kfDenom);

	return(_rResult);
}

const double math::AngleBetween(const TVector4d& _krA,
								const TVector4d& _krB)
{
	const double kdAngle = math::ArcCos(	math::DotProduct(_krA, _krB) 
										/	( math::Magnitude(_krA) * math::Magnitude(_krB) ) );

	return(kdAngle);
}

const float math::AngleBetween(	const TVector4f& _krA,
								const TVector4f& _krB)
{
	const float kfAngle = math::ArcCos(		math::DotProduct(_krA, _krB) 
										/	( math::Magnitude(_krA) * math::Magnitude(_krB) ) );

	return(kfAngle);
}

const double math::Distance(const TVector4d& _krA,
							const TVector4d& _krB)
{
	const double kdDistance = math::Magnitude(math::Subtract(TVector4d(), _krA, _krB));

	return(kdDistance);
}

const float math::Distance(	const TVector4f& _krA,
							const TVector4f& _krB)
{
	const float kfDistance = math::Magnitude(math::Subtract(TVector4f(), _krA, _krB));

	return(kfDistance);
}

//
// Vector 3
//

const TVector3d& math::ZeroVector(TVector3d& _rResult)
{
	_rResult.m_dX = 0.0;
	_rResult.m_dY = 0.0;
	_rResult.m_dZ = 0.0;

	return(_rResult);
}

const TVector3f& math::ZeroVector(TVector3f& _rResult)
{
	_rResult.m_fX = 0.0f;
	_rResult.m_fY = 0.0f;
	_rResult.m_fZ = 0.0f;

	return(_rResult);
}

const bool math::Equal(	const TVector3d& _krA,
						const TVector3d& _krB,
						const double _kdEpsilon)
{
	const bool kbEqual =	(math::Magnitude(_krA.m_dX - _krB.m_dX) < _kdEpsilon)
						&&	(math::Magnitude(_krA.m_dY - _krB.m_dY) < _kdEpsilon)
						&&	(math::Magnitude(_krA.m_dZ - _krB.m_dZ) < _kdEpsilon);

	return(kbEqual);
}

const bool math::Equal(	const TVector3f& _krA,
						const TVector3f& _krB,
						const float _kfEpsilon)
{
	const bool kbEqual =	(math::Magnitude(_krA.m_fX - _krB.m_fX) < _kfEpsilon)
						&&	(math::Magnitude(_krA.m_fY - _krB.m_fY) < _kfEpsilon)
						&&	(math::Magnitude(_krA.m_fZ - _krB.m_fZ) < _kfEpsilon);

	return(kbEqual);
}

const TVector3d& math::Add(	TVector3d& _rResult,
							const TVector3d& _krA, 
							const TVector3d& _krB)
{
	_rResult.m_dX = _krA.m_dX + _krB.m_dX;
	_rResult.m_dY = _krA.m_dY + _krB.m_dY;
	_rResult.m_dZ = _krA.m_dZ + _krB.m_dZ;

	return(_rResult);
}

const TVector3f& math::Add(	TVector3f& _rResult,
							const TVector3f& _krA, 
							const TVector3f& _krB)
{
	_rResult.m_fX = _krA.m_fX + _krB.m_fX;
	_rResult.m_fY = _krA.m_fY + _krB.m_fY;
	_rResult.m_fZ = _krA.m_fZ + _krB.m_fZ;

	return(_rResult);
}

const TVector3d& math::Subtract(TVector3d& _rResult,
								const TVector3d& _krA,
								const TVector3d& _krB)
{
	_rResult.m_dX = _krA.m_dX - _krB.m_dX;
	_rResult.m_dY = _krA.m_dY - _krB.m_dY;
	_rResult.m_dZ = _krA.m_dZ - _krB.m_dZ;

	return(_rResult);
}

const TVector3f& math::Subtract(TVector3f& _rResult,
								const TVector3f& _krA,
								const TVector3f& _krB)
{
	_rResult.m_fX = _krA.m_fX - _krB.m_fX;
	_rResult.m_fY = _krA.m_fY - _krB.m_fY;
	_rResult.m_fZ = _krA.m_fZ - _krB.m_fZ;

	return(_rResult);
}

const TVector3d& math::ScalarMultiply(	TVector3d& _rResult,
										const TVector3d& _krV,
										const double _kdS)
{
	_rResult.m_dX = _krV.m_dX * _kdS;
	_rResult.m_dY = _krV.m_dY * _kdS;
	_rResult.m_dZ = _krV.m_dZ * _kdS;

	return(_rResult);
}

const TVector3f& math::ScalarMultiply(	TVector3f& _rResult,
										const TVector3f& _krV,
										const float _kfS)
{
	_rResult.m_fX = _krV.m_fX * _kfS;
	_rResult.m_fY = _krV.m_fY * _kfS;
	_rResult.m_fZ = _krV.m_fZ * _kfS;

	return(_rResult);
}

const double math::Magnitude(const TVector3d& _krV)
{
	return(math::SquareRoot(	math::Square(_krV.m_dX)
							+	math::Square(_krV.m_dY)
							+	math::Square(_krV.m_dZ)));
}

const float math::Magnitude(const TVector3f& _krV)
{
	return(math::SquareRoot(	math::Square(_krV.m_fX)
							+	math::Square(_krV.m_fY)
							+	math::Square(_krV.m_fZ)));
}

const double math::DotProduct(	const TVector3d& _krA,
								const TVector3d& _krB)
{
	return(		(_krA.m_dX * _krB.m_dX)
			+	(_krA.m_dY * _krB.m_dY)
			+	(_krA.m_dZ * _krB.m_dZ));
}

const float math::DotProduct(	const TVector3f& _krA,
								const TVector3f& _krB)
{
	return(		(_krA.m_fX * _krB.m_fX)
			+	(_krA.m_fY * _krB.m_fY)
			+	(_krA.m_fZ * _krB.m_fZ));
}

const TVector3d& math::CrossProduct(TVector3d& _rResult,
									const TVector3d& _krA,
									const TVector3d& _krB)
{
	_rResult.m_dX = (_krA.m_dY * _krB.m_dZ) - ( _krA.m_dZ * _krB.m_dY);
	_rResult.m_dY = (_krA.m_dZ * _krB.m_dX) - ( _krA.m_dX * _krB.m_dZ);
	_rResult.m_dZ = (_krA.m_dX * _krB.m_dY) - ( _krA.m_dY * _krB.m_dX);

	return(_rResult);
}

const TVector3f& math::CrossProduct(TVector3f& _rResult,
									const TVector3f& _krA,
									const TVector3f& _krB)
{
	_rResult.m_fX = (_krA.m_fY * _krB.m_fZ) - ( _krA.m_fZ * _krB.m_fY);
	_rResult.m_fY = (_krA.m_fZ * _krB.m_fX) - ( _krA.m_fX * _krB.m_fZ);
	_rResult.m_fZ = (_krA.m_fX * _krB.m_fY) - ( _krA.m_fY * _krB.m_fX);

	return(_rResult);
}

const TVector3d& math::Normalize(	TVector3d& _rResult,
									const TVector3d& _krV)
{
	math::ScalarMultiply(_rResult, _krV, (1.0 / math::Magnitude(_krV)) );
	return(_rResult);
}

const TVector3f& math::Normalize(	TVector3f& _rResult,
									const TVector3f& _krV)
{
	math::ScalarMultiply(_rResult, _krV, (1.0f / math::Magnitude(_krV)) );
	return(_rResult);
}

const TVector3d& math::Projection(	TVector3d& _rResult,
									const TVector3d& _krA,
									const TVector3d& _krB)
{
	const double kdDenom = math::Square(math::Magnitude(_krB));

	const TVector3d kNumer = math::ScalarMultiply(TVector3d(), _krB, DotProduct(_krA, _krB));

	_rResult = math::ScalarMultiply(_rResult, kNumer, kdDenom);

	return(_rResult);
}

const TVector3f& math::Projection(	TVector3f& _rResult,
									const TVector3f& _krA,
									const TVector3f& _krB)
{
	const float kfDenom = math::Square(math::Magnitude(_krB));

	const TVector3f kNumer = math::ScalarMultiply(TVector3f(), _krB, DotProduct(_krA, _krB));

	_rResult = math::ScalarMultiply(_rResult, kNumer, kfDenom);

	return(_rResult);
}

const double math::AngleBetween(const TVector3d& _krA,
								const TVector3d& _krB)
{
	const double kdAngle = math::ArcCos(	math::DotProduct(_krA, _krB) 
										/	( math::Magnitude(_krA) * math::Magnitude(_krB) ) );

	return(kdAngle);
}

const float math::AngleBetween(	const TVector3f& _krA,
								const TVector3f& _krB)
{
	const float kfAngle = math::ArcCos(		math::DotProduct(_krA, _krB) 
										/	( math::Magnitude(_krA) * math::Magnitude(_krB) ) );

	return(kfAngle);
}

const double math::Distance(const TVector3d& _krA,
							const TVector3d& _krB)
{
	const double kdDistance = math::Magnitude(math::Subtract(TVector3d(), _krA, _krB));

	return(kdDistance);
}

const float math::Distance(	const TVector3f& _krA,
							const TVector3f& _krB)
{
	const float kfDistance = math::Magnitude(math::Subtract(TVector3f(), _krA, _krB));

	return(kfDistance);
}

const double math::ScalarTripleProduct(	const TVector3d& _krA,
										const TVector3d& _krB,
										const TVector3d& _krC)
{
	return(math::DotProduct(_krA, math::CrossProduct(TVector3d(), _krB, _krC)));
}

const float math::ScalarTripleProduct(	const TVector3f& _krA,
										const TVector3f& _krB,
										const TVector3f& _krC)
{
	return(math::DotProduct(_krA, math::CrossProduct(TVector3f(), _krB, _krC)));
}

const TVector3d& math::VectorTripleProduct(	TVector3d& _rResult,
											const TVector3d& _krA,
											const TVector3d& _krB,
											const TVector3d& _krC)
{
	return(math::CrossProduct(_rResult, _krA, math::CrossProduct(TVector3d(), _krB, _krC)));
}

const TVector3f& math::VectorTripleProduct(	TVector3f& _rResult,
											const TVector3f& _krA,
											const TVector3f& _krB,
											const TVector3f& _krC)
{
	return(math::CrossProduct(_rResult, _krA, math::CrossProduct(TVector3f(), _krB, _krC)));
}

//
// Vector 2
//

const TVector2d& math::ZeroVector(TVector2d& _rResult)
{
	_rResult.m_dX = 0.0;
	_rResult.m_dY = 0.0;

	return(_rResult);
}

const TVector2f& math::ZeroVector(TVector2f& _rResult)
{
	_rResult.m_fX = 0.0f;
	_rResult.m_fY = 0.0f;

	return(_rResult);
}

const bool math::Equal(	const TVector2d& _krA,
						const TVector2d& _krB,
						const double _kdEpsilon)
{
	const bool kbEqual =	(math::Magnitude(_krA.m_dX - _krB.m_dX) < _kdEpsilon)
						&&	(math::Magnitude(_krA.m_dY - _krB.m_dY) < _kdEpsilon);

	return(kbEqual);
}

const bool math::Equal(	const TVector2f& _krA,
						const TVector2f& _krB,
						const float _kfEpsilon)
{
	const bool kbEqual =	(math::Magnitude(_krA.m_fX - _krB.m_fX) < _kfEpsilon)
						&&	(math::Magnitude(_krA.m_fY - _krB.m_fY) < _kfEpsilon);

	return(kbEqual);
}

const TVector2d& math::Add(	TVector2d& _rResult,
							const TVector2d& _krA, 
							const TVector2d& _krB)
{
	_rResult.m_dX = _krA.m_dX + _krB.m_dX;
	_rResult.m_dY = _krA.m_dY + _krB.m_dY;

	return(_rResult);
}

const TVector2f& math::Add(	TVector2f& _rResult,
							const TVector2f& _krA, 
							const TVector2f& _krB)
{
	_rResult.m_fX = _krA.m_fX + _krB.m_fX;
	_rResult.m_fY = _krA.m_fY + _krB.m_fY;

	return(_rResult);
}

const TVector2d& math::Subtract(TVector2d& _rResult,
								const TVector2d& _krA,
								const TVector2d& _krB)
{
	_rResult.m_dX = _krA.m_dX - _krB.m_dX;
	_rResult.m_dY = _krA.m_dY - _krB.m_dY;

	return(_rResult);
}

const TVector2f& math::Subtract(TVector2f& _rResult,
								const TVector2f& _krA,
								const TVector2f& _krB)
{
	_rResult.m_fX = _krA.m_fX - _krB.m_fX;
	_rResult.m_fY = _krA.m_fY - _krB.m_fY;

	return(_rResult);
}

const TVector2d& math::ScalarMultiply(	TVector2d& _rResult,
										const TVector2d& _krV,
										const double _kdS)
{
	_rResult.m_dX = _krV.m_dX * _kdS;
	_rResult.m_dY = _krV.m_dY * _kdS;

	return(_rResult);
}

const TVector2f& math::ScalarMultiply(	TVector2f& _rResult,
										const TVector2f& _krV,
										const float _kfS)
{
	_rResult.m_fX = _krV.m_fX * _kfS;
	_rResult.m_fY = _krV.m_fY * _kfS;

	return(_rResult);
}

const double math::Magnitude(const TVector2d& _krV)
{
	return(math::SquareRoot(	math::Square(_krV.m_dX)
							+	math::Square(_krV.m_dY)));
}

const float math::Magnitude(const TVector2f& _krV)
{
	return(math::SquareRoot(	math::Square(_krV.m_fX)
							+	math::Square(_krV.m_fY)));
}

const double math::DotProduct(	const TVector2d& _krA,
								const TVector2d& _krB)
{
	return(		(_krA.m_dX * _krB.m_dX)
			+	(_krA.m_dY * _krB.m_dY));
}

const float math::DotProduct(	const TVector2f& _krA,
								const TVector2f& _krB)
{
	return(		(_krA.m_fX * _krB.m_fX)
			+	(_krA.m_fY * _krB.m_fY));
}

const TVector2d& math::Normalize(	TVector2d& _rResult,
									const TVector2d& _krV)
{
	math::ScalarMultiply(_rResult, _krV, (1.0 / math::Magnitude(_krV)) );
	return(_rResult);
}

const TVector2f& math::Normalize(	TVector2f& _rResult,
									const TVector2f& _krV)
{
	math::ScalarMultiply(_rResult, _krV, (1.0f / math::Magnitude(_krV)) );
	return(_rResult);
}

const TVector2d& math::Projection(	TVector2d& _rResult,
									const TVector2d& _krA,
									const TVector2d& _krB)
{
	const double kdDenom = math::Square(math::Magnitude(_krB));

	const TVector2d kNumer = math::ScalarMultiply(TVector2d(), _krB, DotProduct(_krA, _krB));

	_rResult = math::ScalarMultiply(_rResult, kNumer, kdDenom);

	return(_rResult);
}

const TVector2f& math::Projection(	TVector2f& _rResult,
									const TVector2f& _krA,
									const TVector2f& _krB)
{
	const float kfDenom = math::Square(math::Magnitude(_krB));

	const TVector2f kNumer = math::ScalarMultiply(TVector2f(), _krB, DotProduct(_krA, _krB));

	_rResult = math::ScalarMultiply(_rResult, kNumer, kfDenom);

	return(_rResult);
}

const double math::AngleBetween(const TVector2d& _krA,
								const TVector2d& _krB)
{
	const double kdAngle = math::ArcCos(	math::DotProduct(_krA, _krB) 
										/	( math::Magnitude(_krA) * math::Magnitude(_krB) ) );

	return(kdAngle);
}

const float math::AngleBetween(	const TVector2f& _krA,
								const TVector2f& _krB)
{
	const float kfAngle = math::ArcCos(		math::DotProduct(_krA, _krB) 
										/	( math::Magnitude(_krA) * math::Magnitude(_krB) ) );

	return(kfAngle);
}

const double math::Distance(const TVector2d& _krA,
							const TVector2d& _krB)
{
	const double kdDistance = math::Magnitude(math::Subtract(TVector2d(), _krA, _krB));

	return(kdDistance);
}

const float math::Distance(	const TVector2f& _krA,
							const TVector2f& _krB)
{
	const float kfDistance = math::Magnitude(math::Subtract(TVector2f(), _krA, _krB));

	return(kfDistance);
}