//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

#pragma once

#ifndef __MATH_QUATERNION_H__
#define __MATH_QUATERNION_H__

// Local Includes
#include "math_types.h"

// Quaternion Function Prototypes
namespace math
{
	const TVector4d& IdentityQuaternion(TVector4d& _rResult);

	const TVector4d& ConjugateQuaternion(TVector4d& _rResult, const TVector4d& _krQuaternion);

	const TVector4d& InverseQuaternion(TVector4d& _rResult, const TVector4d& _krQuaternion);

	const TVector4d& UnitQuaternion(TVector4d& _rResult, const TVector4d& _krQuaternion);

	const TVector4d& AxisAngleQuaternion(TVector4d& _rResult, const TVector3d& _krAxis, const double _kdAngle);

	const double QuaternionMagnitude(TVector4d& _rResult, const TVector4d& _krQuaternion);

	const TVector4d& QuaternionProduct(TVector4d& _rResult, const TVector4d& _krA, const TVector4d& _krB);

	const TVector3d& QuaternionRotate(TVector3d& _rResult, const TVector4d& _krQuaternion);
}

#endif