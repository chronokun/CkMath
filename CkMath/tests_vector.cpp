//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

// Local Includes
#include "tests_vector.h"
#include "math.h"
#include "test_constants.h"

const bool Test_Vector_ZeroVector()
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

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f
			&&	kbPass2d
			&&	kbPass2f);
}

const bool Test_Vector_Equal()
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

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f
			&&	kbPass2d
			&&	kbPass2f);
}

const bool Test_Vector_Add()
{
	const TVector4d kA4d{1.0, 0.0, 0.0, 2.5};
	const TVector4d kB4d{0.0, 1.0, 2.0, 1.0};
	const TVector4d kC4d{1.0, 1.0, 2.0, 3.5};

	const TVector4f kA4f{1.0f, 0.0f, 0.0f, 2.5f};
	const TVector4f kB4f{0.0f, 1.0f, 2.0f, 1.0f};
	const TVector4f kC4f{1.0f, 1.0f, 2.0f, 3.5f};

	const TVector3d kA3d{1.0, 0.0, 1.0};
	const TVector3d kB3d{0.0, 1.0, 2.0};
	const TVector3d kC3d{1.0, 1.0, 3.0};

	const TVector3f kA3f{1.0f, 0.5f, -1.0f};
	const TVector3f kB3f{0.0f, 1.0f, 2.0f};
	const TVector3f kC3f{1.0f, 1.5f, 1.0f};

	const TVector2d kA2d{1.0, 0.0};
	const TVector2d kB2d{-1.0, 0.0};
	const TVector2d kC2d{0.0, 0.0};

	const TVector2f kA2f{1.0f, 0.0f};
	const TVector2f kB2f{-1.0f, 0.0f};
	const TVector2f kC2f{0.0f, 0.0f};

	const bool kbPass4d = math::Equal(kC4d, math::Add(TVector4d(), kA4d, kB4d), s_kdEpsilon);
	const bool kbPass4f = math::Equal(kC4f, math::Add(TVector4f(), kA4f, kB4f), s_kfEpsilon);

	const bool kbPass3d = math::Equal(kC3d, math::Add(TVector3d(), kA3d, kB3d), s_kdEpsilon);
	const bool kbPass3f = math::Equal(kC3f, math::Add(TVector3f(), kA3f, kB3f), s_kfEpsilon);

	const bool kbPass2d = math::Equal(kC2d, math::Add(TVector2d(), kA2d, kB2d), s_kdEpsilon);
	const bool kbPass2f = math::Equal(kC2f, math::Add(TVector2f(), kA2f, kB2f), s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f
			&&	kbPass2d
			&&	kbPass2f);
}

const bool Test_Vector_Subtract()
{
	const TVector4d kA4d{1.0, 0.0, 0.0, 2.5};
	const TVector4d kB4d{0.0, 1.0, 2.0, 1.0};
	const TVector4d kC4d{1.0, -1.0, -2.0, 1.5};

	const TVector4f kA4f{1.0f, 0.0f, 0.0f, 2.5f};
	const TVector4f kB4f{0.0f, 1.0f, 2.0f, 1.0f};
	const TVector4f kC4f{1.0f, -1.0f, -2.0f, 1.5f};

	const TVector3d kA3d{1.0, 0.0, 1.0};
	const TVector3d kB3d{0.0, 1.0, 2.0};
	const TVector3d kC3d{1.0, -1.0, -1.0};

	const TVector3f kA3f{1.0f, 0.5f, -1.0f};
	const TVector3f kB3f{0.0f, 1.0f, 2.0f};
	const TVector3f kC3f{1.0f, -0.5f, -3.0f};

	const TVector2d kA2d{1.0, 0.0};
	const TVector2d kB2d{-1.0, 0.0};
	const TVector2d kC2d{2.0, 0.0};

	const TVector2f kA2f{1.0f, 0.0f};
	const TVector2f kB2f{-1.0f, 0.0f};
	const TVector2f kC2f{2.0f, 0.0f};

	const bool kbPass4d = math::Equal(kC4d, math::Subtract(TVector4d(), kA4d, kB4d), s_kdEpsilon);
	const bool kbPass4f = math::Equal(kC4f, math::Subtract(TVector4f(), kA4f, kB4f), s_kfEpsilon);

	const bool kbPass3d = math::Equal(kC3d, math::Subtract(TVector3d(), kA3d, kB3d), s_kdEpsilon);
	const bool kbPass3f = math::Equal(kC3f, math::Subtract(TVector3f(), kA3f, kB3f), s_kfEpsilon);

	const bool kbPass2d = math::Equal(kC2d, math::Subtract(TVector2d(), kA2d, kB2d), s_kdEpsilon);
	const bool kbPass2f = math::Equal(kC2f, math::Subtract(TVector2f(), kA2f, kB2f), s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f
			&&	kbPass2d
			&&	kbPass2f);
}

const bool Test_Vector_ScalarMultiply()
{
	const TVector4d kA4d{1.0, -1.0, 0.0, 2.0};
	const TVector4d kB4d{2.0, -2.0, 0.0, 4.0};

	const TVector4f kA4f{1.0f, -1.0f, 0.0f, 2.0f};
	const TVector4f kB4f{2.0f, -2.0f, 0.0f, 4.0f};

	const TVector3d kA3d{1.0, -1.0, 0.5};
	const TVector3d kB3d{2.0, -2.0, 1.0};

	const TVector3f kA3f{1.0f, -1.0f, 0.2f};
	const TVector3f kB3f{2.0f, -2.0f, 0.4f};

	const TVector2d kA2d{1.0, -1.0};
	const TVector2d kB2d{2.0, -2.0};

	const TVector2f kA2f{1.0f, -1.0f};
	const TVector2f kB2f{2.0f, -2.0f};

	const bool kbPass4d = math::Equal(math::ScalarMultiply(TVector4d(), kA4d, 2.0), kB4d, s_kdEpsilon);
	const bool kbPass4f = math::Equal(math::ScalarMultiply(TVector4f(), kA4f, 2.0f), kB4f, s_kfEpsilon);

	const bool kbPass3d = math::Equal(math::ScalarMultiply(TVector3d(), kA3d, 2.0), kB3d, s_kdEpsilon);
	const bool kbPass3f = math::Equal(math::ScalarMultiply(TVector3f(), kA3f, 2.0f), kB3f, s_kfEpsilon);

	const bool kbPass2d = math::Equal(math::ScalarMultiply(TVector2d(), kA2d, 2.0), kB2d, s_kdEpsilon);
	const bool kbPass2f = math::Equal(math::ScalarMultiply(TVector2f(), kA2f, 2.0f), kB2f, s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f
			&&	kbPass2d
			&&	kbPass2f);
}

const bool Test_Vector_VectorMagnitude()
{
	const TVector4d kA4d{1.0, 1.0, 1.0, 1.0};
	const double kB4d = 2.0;

	const TVector4f kA4f{1.0f, 1.0f, 1.0f, 1.0f};
	const float kB4f = 2.0f;

	const TVector3d kA3d{2.0, 2.0, 1.0};
	const double kB3d = 3.0;

	const TVector3f kA3f{2.0f, 2.0f, 1.0f};
	const float kB3f = 3.0f;

	const TVector2d kA2d{1.0, 1.0};
	const double kB2d = math::SquareRoot(2.0);

	const TVector2f kA2f{1.0f, 1.0f};
	const float kB2f = math::SquareRoot(2.0f);

	const bool kbPass4d = math::Equal(math::VectorMagnitude(kA4d), kB4d, s_kdEpsilon);
	const bool kbPass4f = math::Equal(math::VectorMagnitude(kA4f), kB4f, s_kfEpsilon);

	const bool kbPass3d = math::Equal(math::VectorMagnitude(kA3d), kB3d, s_kdEpsilon);
	const bool kbPass3f = math::Equal(math::VectorMagnitude(kA3f), kB3f, s_kfEpsilon);

	const bool kbPass2d = math::Equal(math::VectorMagnitude(kA2d), kB2d, s_kdEpsilon);
	const bool kbPass2f = math::Equal(math::VectorMagnitude(kA2f), kB2f, s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f
			&&	kbPass2d
			&&	kbPass2f);
}

const bool Test_Vector_DotProduct()
{
	const TVector4d kA4d{1.0, -1.0, 1.0, -1.0};
	const TVector4d kB4d{1.0, 1.0, 1.0, 1.0};
	const double kC4d = 0.0;

	const TVector4f kA4f{1.0f, -1.0f, 1.0f, -1.0f};
	const TVector4f kB4f{1.0f, 1.0f, 1.0f, 1.0f};
	const float kC4f = 0.0f;

	const TVector3d kA3d{1.0, -1.0, 1.0};
	const TVector3d kB3d{1.0, 1.0, 1.0};
	const double kC3d = 1.0;

	const TVector3f kA3f{1.0f, -1.0f, 1.0f};
	const TVector3f kB3f{1.0f, 1.0f, 1.0f};
	const float kC3f = 1.0f;

	const TVector2d kA2d{-1.0, -1.0};
	const TVector2d kB2d{1.0, 1.0};
	const double kC2d = -2.0f;

	const TVector2f kA2f{-1.0f, -1.0f};
	const TVector2f kB2f{1.0f, 1.0f};
	const float kC2f = -2.0f;

	const bool kbPass4d = math::Equal(math::DotProduct(kA4d, kB4d), kC4d, s_kdEpsilon);
	const bool kbPass4f = math::Equal(math::DotProduct(kA4f, kB4f), kC4f, s_kfEpsilon);

	const bool kbPass3d = math::Equal(math::DotProduct(kA3d, kB3d), kC3d, s_kdEpsilon);
	const bool kbPass3f = math::Equal(math::DotProduct(kA3f, kB3f), kC3f, s_kfEpsilon);

	const bool kbPass2d = math::Equal(math::DotProduct(kA2d, kB2d), kC2d, s_kdEpsilon);
	const bool kbPass2f = math::Equal(math::DotProduct(kA2f, kB2f), kC2f, s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f
			&&	kbPass2d
			&&	kbPass2f);
}

const bool Test_Vector_CrossProduct()
{
	const TVector3d kA3d{1.0, 0.0, 0.0};
	const TVector3d kB3d{0.0, 1.0, 0.0};
	const TVector3d kC3d{0.0, 0.0, 1.0};

	const TVector3f kA3f{1.0f, 0.0f, 0.0f};
	const TVector3f kB3f{0.0f, 1.0f, 0.0f};
	const TVector3f kC3f{0.0f, 0.0f, 1.0f};

	const bool kbPass3d = math::Equal(math::CrossProduct(TVector3d(), kA3d, kB3d), kC3d, s_kdEpsilon);
	const bool kbPass3f = math::Equal(math::CrossProduct(TVector3f(), kA3f, kB3f), kC3f, s_kfEpsilon);

	return(		kbPass3d
			&&	kbPass3f);
}
