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
	const TVector4d kA4d{1.0, 0.0, 0.0, 2.5};
	const TVector4d kB4d{0.0, 1.0, 2.0, 0.9};

	const TVector4f kA4f{1.0f, 0.0f, 0.0f, 2.5f};
	const TVector4f kB4f{0.0f, 1.0f, 2.0f, 0.9f};

	const TVector3d kA3d{1.0, 0.0, 0.0};
	const TVector3d kB3d{0.0, 1.0, 2.0};

	const TVector3f kA3f{1.0f, 0.0f, 0.0f};
	const TVector3f kB3f{0.0f, 1.0f, 2.0f};

	const TVector2d kA2d{1.0, 0.0};
	const TVector2d kB2d{-1.0, 0.0};

	const TVector2f kA2f{1.0, 0.0};
	const TVector2f kB2f{-1.0, 0.0};

	const bool kbPass4d = (!math::Equal(kA4d, kB4d, s_kdEpsilon)) && math::Equal(kA4d, kA4d, s_kdEpsilon);
	const bool kbPass4f = (!math::Equal(kA4f, kB4f, s_kfEpsilon)) && math::Equal(kA4f, kA4f, s_kfEpsilon);

	const bool kbPass3d = (!math::Equal(kA3d, kB3d, s_kdEpsilon)) && math::Equal(kA3d, kA3d, s_kdEpsilon);
	const bool kbPass3f = (!math::Equal(kA3f, kB3f, s_kfEpsilon)) && math::Equal(kA3f, kA3f, s_kfEpsilon);

	const bool kbPass2d = (!math::Equal(kA2d, kB2d, s_kdEpsilon)) && math::Equal(kA2d, kA2d, s_kdEpsilon);
	const bool kbPass2f = (!math::Equal(kA2f, kB2f, s_kfEpsilon)) && math::Equal(kA2f, kA2f, s_kfEpsilon);

	if(		kbPass4d
		&&	kbPass4f
		&&	kbPass3d
		&&	kbPass3f
		&&	kbPass2d
		&&	kbPass2f)
	{
		return("PASS: Vector_Equal\n");
	}
	else
	{
		return("FAIL: Vector_Equal\n");
	}
}