//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

// Local Includes
#include "tests_vector.h"
#include "math.h"
#include "test_constants.h"

const char* Test_Vector_ZeroVector()
{
	const TVector4d kZero4dRef = TVector4d{0.0, 0.0, 0.0, 0.0};
	const TVector4f kZero4fRef = TVector4f{0.0f, 0.0f, 0.0f, 0.0f};
	const TVector3d kZero3dRef = TVector3d{0.0, 0.0, 0.0};
	const TVector3f kZero3fRef = TVector3f{0.0f, 0.0f, 0.0f};
	const TVector2d kZero2dRef = TVector2d{0.0, 0.0};
	const TVector2f kZero2fRef = TVector2f{0.0f, 0.0f};

	const TVector4d kZero4dTest = math::ZeroVector(TVector4d());
	const TVector4f kZero4fTest = math::ZeroVector(TVector4f());
	const TVector3d kZero3dTest = math::ZeroVector(TVector3d());
	const TVector3f kZero3fTest = math::ZeroVector(TVector3f());
	const TVector2d kZero2dTest = math::ZeroVector(TVector2d());
	const TVector2f kZero2fTest = math::ZeroVector(TVector2f());

	const bool kbPass4d = math::Equal(kZero4dRef, kZero4dTest, s_kdEpsilon);
	const bool kbPass4f = math::Equal(kZero4fRef, kZero4fTest, s_kfEpsilon);
	const bool kbPass3d = math::Equal(kZero3dRef, kZero3dTest, s_kdEpsilon);
	const bool kbPass3f = math::Equal(kZero3fRef, kZero3fTest, s_kfEpsilon);
	const bool kbPass2d = math::Equal(kZero2dRef, kZero2dTest, s_kdEpsilon);
	const bool kbPass2f = math::Equal(kZero2fRef, kZero2fTest, s_kfEpsilon);

	if(		kbPass4d
		&&	kbPass4f
		&&	kbPass3d
		&&	kbPass3f
		&&	kbPass2d
		&&	kbPass2f)
	{
		return("PASS: Vector_ZeroVector\n");
	}
	else
	{
		return("FAIL: Vector_ZeroVector\n");
	}
}

const char* Test_Vector_Equal()
{
	return("FAIL: Vector_ZeroVector\n");
}