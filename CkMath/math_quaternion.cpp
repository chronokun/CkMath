//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

// Local Includes
#include "math_quaternion.h"
#include "math_scalar.h"
#include "math_vector.h"

//
// Quaternion
//

const TVector4d& math::IdentityQuaternion(TVector4d& _rResult)
{
	_rResult.m_dW = 1.0;

	_rResult.m_dX = 0.0;
	_rResult.m_dY = 0.0;
	_rResult.m_dZ = 0.0;

	return(_rResult);
}

const TVector4f& math::IdentityQuaternion(TVector4f& _rResult)
{
	_rResult.m_fW = 1.0f;

	_rResult.m_fX = 0.0f;
	_rResult.m_fY = 0.0f;
	_rResult.m_fZ = 0.0f;

	return(_rResult);
}

const TVector4d& math::ConjugateQuaternion(TVector4d& _rResult, const TVector4d& _krQuaternion)
{
	_rResult.m_dW = _krQuaternion.m_dW;

	_rResult.m_dX = -_krQuaternion.m_dX;
	_rResult.m_dY = -_krQuaternion.m_dY;
	_rResult.m_dZ = -_krQuaternion.m_dZ;

	return(_rResult);
}

const TVector4f& math::ConjugateQuaternion(TVector4f& _rResult, const TVector4f& _krQuaternion)
{
	_rResult.m_fW = _krQuaternion.m_fW;

	_rResult.m_fX = -_krQuaternion.m_fX;
	_rResult.m_fY = -_krQuaternion.m_fY;
	_rResult.m_fZ = -_krQuaternion.m_fZ;

	return(_rResult);
}

const TVector4d& math::InverseQuaternion(TVector4d& _rResult, const TVector4d& _krQuaternion)
{
	_rResult = math::ScalarMultiply(_rResult, 
									math::ConjugateQuaternion(TVector4d(), _krQuaternion),
									(1.0 / math::Square(math::QuaternionMagnitude(_krQuaternion))));

	return(_rResult);
}

const TVector4f& math::InverseQuaternion(TVector4f& _rResult, const TVector4f& _krQuaternion)
{
	_rResult = math::ScalarMultiply(_rResult, 
									math::ConjugateQuaternion(TVector4f(), _krQuaternion),
									(1.0f / math::Square(math::QuaternionMagnitude(_krQuaternion))));

	return(_rResult);
}

const TVector4d& math::UnitQuaternion(TVector4d& _rResult, const TVector4d& _krQuaternion)
{
	_rResult = math::ScalarMultiply(	_rResult,
										_krQuaternion,
										(1.0 / math::QuaternionMagnitude(_krQuaternion)));

	return(_rResult);
}

const TVector4f& math::UnitQuaternion(TVector4f& _rResult, const TVector4f& _krQuaternion)
{
	_rResult = math::ScalarMultiply(	_rResult,
										_krQuaternion,
										(1.0f / math::QuaternionMagnitude(_krQuaternion)));

	return(_rResult);
}

const TVector4d& math::AxisAngleQuaternion(TVector4d& _rResult, const TVector3d& _krAxis, const double _kdAngle)
{
	_rResult.m_dW = math::Cosine(_kdAngle / 2.0);

	_rResult.m_dX = _krAxis.m_dX * math::Sine(_kdAngle / 2.0);
	_rResult.m_dY = _krAxis.m_dY * math::Sine(_kdAngle / 2.0);
	_rResult.m_dZ = _krAxis.m_dZ * math::Sine(_kdAngle / 2.0);

	return(_rResult);
}

const TVector4f& math::AxisAngleQuaternion(TVector4f& _rResult, const TVector3f& _krAxis, const float _kfAngle)
{
	_rResult.m_fW = math::Cosine(_kfAngle / 2.0f);

	_rResult.m_fX = _krAxis.m_fX * math::Sine(_kfAngle / 2.0f);
	_rResult.m_fY = _krAxis.m_fY * math::Sine(_kfAngle / 2.0f);
	_rResult.m_fZ = _krAxis.m_fZ * math::Sine(_kfAngle / 2.0f);

	return(_rResult);
}

const double math::QuaternionMagnitude(const TVector4d& _krQuaternion)
{
	return(math::SquareRoot(math::QuaternionProduct(TVector4d(),
													math::ConjugateQuaternion(	TVector4d(),
																				_krQuaternion),
													_krQuaternion).m_dW));
}

const float math::QuaternionMagnitude(const TVector4f& _krQuaternion)
{
	return(math::SquareRoot(math::QuaternionProduct(TVector4f(),
													math::ConjugateQuaternion(	TVector4f(),
																				_krQuaternion),
													_krQuaternion).m_fW));
}

const TVector4d& math::QuaternionProduct(TVector4d& _rResult, const TVector4d& _krA, const TVector4d& _krB)
{
	_rResult.m_dW = (_krA.m_dW * _krB.m_dW) - (_krA.m_dX * _krB.m_dX) - (_krA.m_dY * _krB.m_dY) - (_krA.m_dZ * _krB.m_dZ);
	_rResult.m_dX = (_krA.m_dW * _krB.m_dX) + (_krA.m_dX * _krB.m_dW) + (_krA.m_dY * _krB.m_dZ) - (_krA.m_dZ * _krB.m_dY);
	_rResult.m_dY = (_krA.m_dW * _krB.m_dY) - (_krA.m_dX * _krB.m_dZ) + (_krA.m_dY * _krB.m_dW) + (_krA.m_dZ * _krB.m_dX);
	_rResult.m_dZ = (_krA.m_dW * _krB.m_dZ) + (_krA.m_dX * _krB.m_dY) - (_krA.m_dY * _krB.m_dX) + (_krA.m_dZ * _krB.m_dW);

	return(_rResult);
}

const TVector4f& math::QuaternionProduct(TVector4f& _rResult, const TVector4f& _krA, const TVector4f& _krB)
{
	_rResult.m_fW = (_krA.m_fW * _krB.m_fW) - (_krA.m_fX * _krB.m_fX) - (_krA.m_fY * _krB.m_fY) - (_krA.m_fZ * _krB.m_fZ);
	_rResult.m_fX = (_krA.m_fW * _krB.m_fX) + (_krA.m_fX * _krB.m_fW) + (_krA.m_fY * _krB.m_fZ) - (_krA.m_fZ * _krB.m_fY);
	_rResult.m_fY = (_krA.m_fW * _krB.m_fY) - (_krA.m_fX * _krB.m_fZ) + (_krA.m_fY * _krB.m_fW) + (_krA.m_fZ * _krB.m_fX);
	_rResult.m_fZ = (_krA.m_fW * _krB.m_fZ) + (_krA.m_fX * _krB.m_fY) - (_krA.m_fY * _krB.m_fX) + (_krA.m_fZ * _krB.m_fW);

	return(_rResult);
}

const TVector3d& math::QuaternionRotate(TVector3d& _rResult, const TVector3d& _krVector, const TVector4d& _krQuaternion)
{
	const TVector4d kVecAsQuat{_krVector.m_dX, _krVector.m_dY, _krVector.m_dZ, 0.0};

	const TVector4d kResultAsQuat = math::QuaternionProduct(TVector4d(),
															math::QuaternionProduct(TVector4d(), _krQuaternion, kVecAsQuat),
															math::ConjugateQuaternion(TVector4d(), _krQuaternion));

	_rResult.m_dX = kResultAsQuat.m_dX;
	_rResult.m_dY = kResultAsQuat.m_dY;
	_rResult.m_dZ = kResultAsQuat.m_dZ;

	return(_rResult);
}

const TVector3f& math::QuaternionRotate(TVector3f& _rResult, const TVector3f& _krVector, const TVector4f& _krQuaternion)
{
	const TVector4f kVecAsQuat{_krVector.m_fX, _krVector.m_fY, _krVector.m_fZ, 0.0f};

	const TVector4f kResultAsQuat = math::QuaternionProduct(TVector4f(),
															math::QuaternionProduct(TVector4f(), _krQuaternion, kVecAsQuat),
															math::ConjugateQuaternion(TVector4f(), _krQuaternion));

	_rResult.m_fX = kResultAsQuat.m_fX;
	_rResult.m_fY = kResultAsQuat.m_fY;
	_rResult.m_fZ = kResultAsQuat.m_fZ;

	return(_rResult);
}

const TVector4d& math::Slerp(TVector4d& _rResult, const TVector4d& _krA, const TVector4d& _krB, const double _kdT)
{
	const double kdCosOmega = math::DotProduct(_krA, _krB);

	double dK0, dK1;
	if(math::Magnitude(kdCosOmega) == 1.0) // Avoid divide by zero using lerp
	{
		dK0 = 1.0 - _kdT;
		dK1 = _kdT;
	}
	else
	{
		const double kdSinOmega = math::SquareRoot(1.0 - math::Square(kdCosOmega));
		const double kdOmega = math::ArcTan2(kdSinOmega, kdCosOmega);

		dK0 = math::Sine((1.0 - _kdT) * kdOmega) * (1.0 / kdSinOmega);
		dK1 = math::Sine(_kdT * kdOmega) * (1.0 / kdSinOmega);
	}

	_rResult.m_dW = (_krA.m_dW * dK0) + (_krB.m_dW * dK1);
	_rResult.m_dX = (_krA.m_dX * dK0) + (_krB.m_dX * dK1);
	_rResult.m_dY = (_krA.m_dY * dK0) + (_krB.m_dY * dK1);
	_rResult.m_dZ = (_krA.m_dZ * dK0) + (_krB.m_dZ * dK1);

	return(_rResult);
}

const TVector4f& math::Slerp(TVector4f& _rResult, const TVector4f& _krA, const TVector4f& _krB, const float _kfT)
{
	const float kfCosOmega = math::DotProduct(_krA, _krB);

	float fK0, fK1;
	if(math::Magnitude(kfCosOmega) == 1.0f) // Avoid divide by zero using lerp
	{
		fK0 = 1.0f - _kfT;
		fK1 = _kfT;
	}
	else
	{
		const float kfSinOmega = math::SquareRoot(1.0f - math::Square(kfCosOmega));
		const float kfOmega = math::ArcTan2(kfSinOmega, kfCosOmega);

		fK0 = math::Sine((1.0f - _kfT) * kfOmega) * (1.0f / kfSinOmega);
		fK1 = math::Sine(_kfT * kfOmega) * (1.0f / kfSinOmega);
	}

	_rResult.m_fW = (_krA.m_fW * fK0) + (_krB.m_fW * fK1);
	_rResult.m_fX = (_krA.m_fX * fK0) + (_krB.m_fX * fK1);
	_rResult.m_fY = (_krA.m_fY * fK0) + (_krB.m_fY * fK1);
	_rResult.m_fZ = (_krA.m_fZ * fK0) + (_krB.m_fZ * fK1);

	return(_rResult);
}