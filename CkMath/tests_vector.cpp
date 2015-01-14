//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

// Local Includes
#include "tests_vector.h"
#include "ckmath.h"
#include "test_constants.h"



const bool Test_Vector_ZeroVector()
{
	const TVector4d kZero4dRef = TVector4d{0.0, 0.0, 0.0, 0.0};
	const TVector4f kZero4fRef = TVector4f{0.0f, 0.0f, 0.0f, 0.0f};
	const TVector3d kZero3dRef = TVector3d{0.0, 0.0, 0.0};
	const TVector3f kZero3fRef = TVector3f{0.0f, 0.0f, 0.0f};
	const TVector2d kZero2dRef = TVector2d{0.0, 0.0};
	const TVector2f kZero2fRef = TVector2f{0.0f, 0.0f};

	const TVector4d kZero4dTest = ZeroVector(TVector4d());
	const TVector4f kZero4fTest = ZeroVector(TVector4f());
	const TVector3d kZero3dTest = ZeroVector(TVector3d());
	const TVector3f kZero3fTest = ZeroVector(TVector3f());
	const TVector2d kZero2dTest = ZeroVector(TVector2d());
	const TVector2f kZero2fTest = ZeroVector(TVector2f());

	const bool kbPass4d = Equal(kZero4dRef, kZero4dTest, s_kdEpsilon);
	const bool kbPass4f = Equal(kZero4fRef, kZero4fTest, s_kfEpsilon);
	const bool kbPass3d = Equal(kZero3dRef, kZero3dTest, s_kdEpsilon);
	const bool kbPass3f = Equal(kZero3fRef, kZero3fTest, s_kfEpsilon);
	const bool kbPass2d = Equal(kZero2dRef, kZero2dTest, s_kdEpsilon);
	const bool kbPass2f = Equal(kZero2fRef, kZero2fTest, s_kfEpsilon);

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

	const bool kbPass4d = (!Equal(kA4d, kB4d, s_kdEpsilon)) && Equal(kA4d, kA4d, s_kdEpsilon);
	const bool kbPass4f = (!Equal(kA4f, kB4f, s_kfEpsilon)) && Equal(kA4f, kA4f, s_kfEpsilon);

	const bool kbPass3d = (!Equal(kA3d, kB3d, s_kdEpsilon)) && Equal(kA3d, kA3d, s_kdEpsilon);
	const bool kbPass3f = (!Equal(kA3f, kB3f, s_kfEpsilon)) && Equal(kA3f, kA3f, s_kfEpsilon);

	const bool kbPass2d = (!Equal(kA2d, kB2d, s_kdEpsilon)) && Equal(kA2d, kA2d, s_kdEpsilon);
	const bool kbPass2f = (!Equal(kA2f, kB2f, s_kfEpsilon)) && Equal(kA2f, kA2f, s_kfEpsilon);

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

	const bool kbPass4d = Equal(kC4d, Add(TVector4d(), kA4d, kB4d), s_kdEpsilon);
	const bool kbPass4f = Equal(kC4f, Add(TVector4f(), kA4f, kB4f), s_kfEpsilon);

	const bool kbPass3d = Equal(kC3d, Add(TVector3d(), kA3d, kB3d), s_kdEpsilon);
	const bool kbPass3f = Equal(kC3f, Add(TVector3f(), kA3f, kB3f), s_kfEpsilon);

	const bool kbPass2d = Equal(kC2d, Add(TVector2d(), kA2d, kB2d), s_kdEpsilon);
	const bool kbPass2f = Equal(kC2f, Add(TVector2f(), kA2f, kB2f), s_kfEpsilon);

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

	const bool kbPass4d = Equal(kC4d, Subtract(TVector4d(), kA4d, kB4d), s_kdEpsilon);
	const bool kbPass4f = Equal(kC4f, Subtract(TVector4f(), kA4f, kB4f), s_kfEpsilon);

	const bool kbPass3d = Equal(kC3d, Subtract(TVector3d(), kA3d, kB3d), s_kdEpsilon);
	const bool kbPass3f = Equal(kC3f, Subtract(TVector3f(), kA3f, kB3f), s_kfEpsilon);

	const bool kbPass2d = Equal(kC2d, Subtract(TVector2d(), kA2d, kB2d), s_kdEpsilon);
	const bool kbPass2f = Equal(kC2f, Subtract(TVector2f(), kA2f, kB2f), s_kfEpsilon);

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

	const bool kbPass4d = Equal(ScalarMultiply(TVector4d(), kA4d, 2.0), kB4d, s_kdEpsilon);
	const bool kbPass4f = Equal(ScalarMultiply(TVector4f(), kA4f, 2.0f), kB4f, s_kfEpsilon);

	const bool kbPass3d = Equal(ScalarMultiply(TVector3d(), kA3d, 2.0), kB3d, s_kdEpsilon);
	const bool kbPass3f = Equal(ScalarMultiply(TVector3f(), kA3f, 2.0f), kB3f, s_kfEpsilon);

	const bool kbPass2d = Equal(ScalarMultiply(TVector2d(), kA2d, 2.0), kB2d, s_kdEpsilon);
	const bool kbPass2f = Equal(ScalarMultiply(TVector2f(), kA2f, 2.0f), kB2f, s_kfEpsilon);

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
	const double kB2d = SquareRoot(2.0);

	const TVector2f kA2f{1.0f, 1.0f};
	const float kB2f = SquareRoot(2.0f);

	const bool kbPass4d = Equal(VectorMagnitude(kA4d), kB4d, s_kdEpsilon);
	const bool kbPass4f = Equal(VectorMagnitude(kA4f), kB4f, s_kfEpsilon);

	const bool kbPass3d = Equal(VectorMagnitude(kA3d), kB3d, s_kdEpsilon);
	const bool kbPass3f = Equal(VectorMagnitude(kA3f), kB3f, s_kfEpsilon);

	const bool kbPass2d = Equal(VectorMagnitude(kA2d), kB2d, s_kdEpsilon);
	const bool kbPass2f = Equal(VectorMagnitude(kA2f), kB2f, s_kfEpsilon);

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

	const bool kbPass4d = Equal(DotProduct(kA4d, kB4d), kC4d, s_kdEpsilon);
	const bool kbPass4f = Equal(DotProduct(kA4f, kB4f), kC4f, s_kfEpsilon);

	const bool kbPass3d = Equal(DotProduct(kA3d, kB3d), kC3d, s_kdEpsilon);
	const bool kbPass3f = Equal(DotProduct(kA3f, kB3f), kC3f, s_kfEpsilon);

	const bool kbPass2d = Equal(DotProduct(kA2d, kB2d), kC2d, s_kdEpsilon);
	const bool kbPass2f = Equal(DotProduct(kA2f, kB2f), kC2f, s_kfEpsilon);

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

	const bool kbPass3d = Equal(CrossProduct(TVector3d(), kA3d, kB3d), kC3d, s_kdEpsilon);
	const bool kbPass3f = Equal(CrossProduct(TVector3f(), kA3f, kB3f), kC3f, s_kfEpsilon);

	return(		kbPass3d
			&&	kbPass3f);
}

const bool Test_Vector_Normalize()
{
	const TVector4d kA4d{1.0, 1.0, 1.0, 1.0};
	const TVector4f kA4f{1.0f, 1.0f, 1.0f, 1.0f};

	const TVector3d kA3d{1.0, 1.0, 1.0};
	const TVector3f kA3f{1.0f, 1.0f, 1.0f};

	const TVector2d kA2d{1.0, 1.0};
	const TVector2f kA2f{1.0f, 1.0f};

	const bool kbPass4d = Equal(VectorMagnitude(Normalize(TVector4d(), kA4d)), 1.0, s_kdEpsilon);
	const bool kbPass4f = Equal(VectorMagnitude(Normalize(TVector4f(), kA4f)), 1.0f, s_kfEpsilon);
	const bool kbPass3d = Equal(VectorMagnitude(Normalize(TVector3d(), kA3d)), 1.0, s_kdEpsilon);
	const bool kbPass3f = Equal(VectorMagnitude(Normalize(TVector3f(), kA3f)), 1.0f, s_kfEpsilon);
	const bool kbPass2d = Equal(VectorMagnitude(Normalize(TVector2d(), kA2d)), 1.0, s_kdEpsilon);
	const bool kbPass2f = Equal(VectorMagnitude(Normalize(TVector2f(), kA2f)), 1.0f, s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f
			&&	kbPass2d
			&&	kbPass2f);
}

const bool Test_Vector_Projection()
{
	const TVector4d kA4d{2.0, 2.0, 2.0, 2.0};
	const TVector4d kB4d{0.0, 0.0, 0.0, 1.0};
	const TVector4d kC4d{0.0, 0.0, 0.0, 2.0};

	const TVector4f kA4f{2.0f, 2.0f, 2.0f, 2.0};
	const TVector4f kB4f{0.0f, 0.0f, 0.0f, 1.0};
	const TVector4f kC4f{0.0f, 0.0f, 0.0f, 2.0};

	const TVector3d kA3d{2.0, 2.0, 2.0};
	const TVector3d kB3d{0.0, 0.0, 1.0};
	const TVector3d kC3d{0.0, 0.0, 2.0};

	const TVector3f kA3f{2.0f, 2.0f, 2.0f};
	const TVector3f kB3f{0.0f, 0.0f, 1.0f};
	const TVector3f kC3f{0.0f, 0.0f, 2.0f};

	const TVector2d kA2d{2.0, 2.0};
	const TVector2d kB2d{0.0, 1.0};
	const TVector2d kC2d{0.0, 2.0};

	const TVector2f kA2f{2.0f, 2.0f};
	const TVector2f kB2f{0.0f, 1.0f};
	const TVector2f kC2f{0.0f, 2.0f};

	const bool kbPass4d = Equal(Projection(TVector4d(), kA4d, kB4d), kC4d, s_kdEpsilon);
	const bool kbPass4f = Equal(Projection(TVector4f(), kA4f, kB4f), kC4f, s_kfEpsilon);
	const bool kbPass3d = Equal(Projection(TVector3d(), kA3d, kB3d), kC3d, s_kdEpsilon);
	const bool kbPass3f = Equal(Projection(TVector3f(), kA3f, kB3f), kC3f, s_kfEpsilon);
	const bool kbPass2d = Equal(Projection(TVector2d(), kA2d, kB2d), kC2d, s_kdEpsilon);
	const bool kbPass2f = Equal(Projection(TVector2f(), kA2f, kB2f), kC2f, s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f
			&&	kbPass2d
			&&	kbPass2f);
}

const bool Test_Vector_AngleBetween()
{
	const TVector4d kA4d{10.0, 0.0, 0.0, 0.0};
	const TVector4d kB4d{0.0, 0.0, 0.0, 10.0};

	const TVector4f kA4f{10.0f, 0.0f, 0.0f, 0.0f};
	const TVector4f kB4f{0.0f, 0.0f, 0.0f, 10.0f};

	const TVector3d kA3d{10.0, 0.0, 0.0};
	const TVector3d kB3d{0.0, 0.0, 10.0};

	const TVector3f kA3f{10.0f, 0.0f, 0.0f};
	const TVector3f kB3f{0.0f, 0.0f, 10.0f};

	const TVector2d kA2d{10.0, 0.0};
	const TVector2d kB2d{0.0, 10.0};

	const TVector2f kA2f{10.0f, 0.0f};
	const TVector2f kB2f{0.0f, 10.0f};

	const bool kbPass4d = Equal(AngleBetween(kA4d, kB4d), s_kdTau / 4.0, s_kdEpsilon);
	const bool kbPass4f = Equal(AngleBetween(kA4f, kB4f), s_kfTau / 4.0f, s_kfEpsilon);
	const bool kbPass3d = Equal(AngleBetween(kA3d, kB3d), s_kdTau / 4.0, s_kdEpsilon);
	const bool kbPass3f = Equal(AngleBetween(kA3f, kB3f), s_kfTau / 4.0f, s_kfEpsilon);
	const bool kbPass2d = Equal(AngleBetween(kA2d, kB2d), s_kdTau / 4.0, s_kdEpsilon);
	const bool kbPass2f = Equal(AngleBetween(kA2f, kB2f), s_kfTau / 4.0f, s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f
			&&	kbPass2d
			&&	kbPass2f);
}

const bool Test_Vector_Distance()
{
	const TVector4d kA4d{4.0, 3.0, 1.0, -1.0};
	const TVector4d kB4d{4.0, 3.0, 1.0, 1.0};
	const double kC4d = 2.0;

	const TVector4f kA4f{4.0f, 3.0f, 1.0f, -1.0f};
	const TVector4f kB4f{4.0f, 3.0f, 1.0f, 1.0f};
	const float kC4f = 2.0f;

	const TVector3d kA3d{2.0, -2.0, 3.0};
	const TVector3d kB3d{2.0, 2.0, 3.0};
	const double kC3d = 4.0;

	const TVector3f kA3f{2.0f, -2.0f, 3.0f};
	const TVector3f kB3f{2.0f, 2.0f, 3.0f};
	const float kC3f = 4.0f;

	const TVector2d kA2d{1.0, 0.0};
	const TVector2d kB2d{0.0, 1.0};
	const double kC2d = SquareRoot(2.0);

	const TVector2f kA2f{1.0f, 0.0f};
	const TVector2f kB2f{0.0f, 1.0f};
	const float kC2f = SquareRoot(2.0f);

	const bool kbPass4d = Equal(Distance(kA4d, kB4d), kC4d, s_kdEpsilon);
	const bool kbPass4f = Equal(Distance(kA4f, kB4f), kC4f, s_kfEpsilon);
	const bool kbPass3d = Equal(Distance(kA3d, kB3d), kC3d, s_kdEpsilon);
	const bool kbPass3f = Equal(Distance(kA3f, kB3f), kC3f, s_kfEpsilon);
	const bool kbPass2d = Equal(Distance(kA2d, kB2d), kC2d, s_kdEpsilon);
	const bool kbPass2f = Equal(Distance(kA2f, kB2f), kC2f, s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f
			&&	kbPass2d
			&&	kbPass2f);
}

const bool Test_Vector_ScalarTripleProduct()
{
	const TVector3d kA3d{2.0, 0.0, 0.0};
	const TVector3d kB3d{0.0, 2.0, 0.0};
	const TVector3d kC3d{0.0, 0.0, 2.0};

	const TVector3f kA3f{2.0f, 0.0f, 0.0f};
	const TVector3f kB3f{0.0f, 2.0f, 0.0f};
	const TVector3f kC3f{0.0f, 0.0f, 2.0f};

	const bool kbPass3d = Equal(ScalarTripleProduct(kA3d, kB3d, kC3d), 8.0, s_kdEpsilon);
	const bool kbPass3f = Equal(ScalarTripleProduct(kA3f, kB3f, kC3f), 8.0f, s_kfEpsilon);

	return(kbPass3d && kbPass3f);
}

const bool Test_Vector_VectorTripleProduct()
{
	const TVector3d kA3d{2.0, 0.0, 0.0};
	const TVector3d kB3d{0.0, 2.0, 0.0};
	const TVector3d kC3d{0.0, 0.0, 2.0};
	const TVector3d kD3d = Subtract(	TVector3d(),
											ScalarMultiply(TVector3d(), kB3d, DotProduct(kA3d, kC3d)),
											ScalarMultiply(TVector3d(), kC3d, DotProduct(kA3d, kB3d)));

	const TVector3f kA3f{2.0f, 0.0f, 0.0f};
	const TVector3f kB3f{0.0f, 2.0f, 0.0f};
	const TVector3f kC3f{0.0f, 0.0f, 2.0f};
	const TVector3f kD3f = Subtract(	TVector3f(),
											ScalarMultiply(TVector3f(), kB3f, DotProduct(kA3f, kC3f)),
											ScalarMultiply(TVector3f(), kC3f, DotProduct(kA3f, kB3f)));

	const bool kbPass3d = Equal(VectorTripleProduct(TVector3d(), kA3d, kB3d, kC3d), kD3d, s_kdEpsilon);
	const bool kbPass3f = Equal(VectorTripleProduct(TVector3f(), kA3f, kB3f, kC3f), kD3f, s_kfEpsilon);

	return(kbPass3d && kbPass3f);
}
