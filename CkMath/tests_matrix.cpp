//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

// Local Includes
#include "tests_matrix.h"
#include "math.h"
#include "test_constants.h"

const bool Test_Matrix_Equal()
{
	const TMatrix4d kA4d{	2.0, 1.0, 3.0, 9.0,
							0.0, 5.0, 6.0, 1.0,
							8.0, 7.0, 2.0, 3.0,
							1.0, 0.0, 3.0, 4.0};

	const TMatrix4d kB4d{	3.0, 1.0, 3.0, 9.0,
							2.0, 5.0, 3.0, 1.0,
							8.0, 9.0, 2.0, 3.0,
							1.0, 0.0, 3.0, 4.0};


	const TMatrix4f kA4f{	2.0f, 1.0f, 3.0f, 9.0f,
							0.0f, 5.0f, 6.0f, 1.0f,
							8.0f, 7.0f, 2.0f, 3.0f,
							1.0f, 0.0f, 3.0f, 4.0f};

	const TMatrix4f kB4f{	3.0f, 1.0f, 3.0f, 9.0f,
							2.0f, 5.0f, 3.0f, 1.0f,
							8.0f, 9.0f, 2.0f, 3.0f,
							1.0f, 0.0f, 3.0f, 4.0f};

	const bool kbPass4d = math::Equal(kA4d, kA4d, s_kdEpsilon) && !math::Equal(kA4d, kB4d, s_kdEpsilon);
	const bool kbPass4f = math::Equal(kA4f, kA4f, s_kfEpsilon) && !math::Equal(kA4f, kB4f, s_kfEpsilon);

	const TMatrix3d kA3d{	2.0, 1.0, 3.0,
							0.0, 5.0, 6.0,
							8.0, 7.0, 2.0};

	const TMatrix3d kB3d{	3.0, 1.0, 3.0,
							2.0, 5.0, 3.0,
							8.0, 9.0, 2.0};


	const TMatrix3f kA3f{	2.0f, 1.0f, 3.0f,
							0.0f, 5.0f, 6.0f,
							8.0f, 7.0f, 2.0f};

	const TMatrix3f kB3f{	3.0f, 1.0f, 3.0f,
							2.0f, 5.0f, 3.0f,
							8.0f, 9.0f, 2.0f};

	const bool kbPass3d = math::Equal(kA3d, kA3d, s_kdEpsilon) && !math::Equal(kA3d, kB3d, s_kdEpsilon);
	const bool kbPass3f = math::Equal(kA3f, kA3f, s_kfEpsilon) && !math::Equal(kA3f, kB3f, s_kfEpsilon);

	const TMatrix2d kA2d{	2.0, 1.0,
							0.0, 5.0};

	const TMatrix2d kB2d{	3.0, 1.0,
							2.0, 5.0};


	const TMatrix2f kA2f{	2.0f, 1.0f,
							0.0f, 5.0f};

	const TMatrix2f kB2f{	3.0f, 1.0f,
							2.0f, 5.0f};

	const bool kbPass2d = math::Equal(kA2d, kA2d, s_kdEpsilon) && !math::Equal(kA2d, kB2d, s_kdEpsilon);
	const bool kbPass2f = math::Equal(kA2f, kA2f, s_kfEpsilon) && !math::Equal(kA2f, kB2f, s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f
			&&	kbPass2d
			&&	kbPass2f);
}

const bool Test_Matrix_ZeroMatrix()
{
	const TMatrix4d kA4d{	0.0, 0.0, 0.0, 0.0,
							0.0, 0.0, 0.0, 0.0,
							0.0, 0.0, 0.0, 0.0,
							0.0, 0.0, 0.0, 0.0};

	const TMatrix4f kA4f{	0.0f, 0.0f, 0.0f, 0.0f,
							0.0f, 0.0f, 0.0f, 0.0f,
							0.0f, 0.0f, 0.0f, 0.0f,
							0.0f, 0.0f, 0.0f, 0.0f};


	const TMatrix3d kA3d{	0.0, 0.0, 0.0,
							0.0, 0.0, 0.0,
							0.0, 0.0, 0.0};

	const TMatrix3f kA3f{	0.0f, 0.0f, 0.0f,
							0.0f, 0.0f, 0.0f,
							0.0f, 0.0f, 0.0f};


	const TMatrix2d kA2d{	0.0, 0.0,
							0.0, 0.0};

	const TMatrix2f kA2f{	0.0f, 0.0f,
							0.0f, 0.0f};

	const bool kbPass4d = math::Equal(math::ZeroMatrix(TMatrix4d()), kA4d, s_kdEpsilon);
	const bool kbPass4f = math::Equal(math::ZeroMatrix(TMatrix4f()), kA4f, s_kfEpsilon);
	const bool kbPass3d = math::Equal(math::ZeroMatrix(TMatrix3d()), kA3d, s_kdEpsilon);
	const bool kbPass3f = math::Equal(math::ZeroMatrix(TMatrix3f()), kA3f, s_kfEpsilon);
	const bool kbPass2d = math::Equal(math::ZeroMatrix(TMatrix2d()), kA2d, s_kdEpsilon);
	const bool kbPass2f = math::Equal(math::ZeroMatrix(TMatrix2f()), kA2f, s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f
			&&	kbPass2d
			&&	kbPass2f);
}

const bool Test_Matrix_IdentityMatrix()
{
	const TMatrix4d kA4d{	1.0, 0.0, 0.0, 0.0,
							0.0, 1.0, 0.0, 0.0,
							0.0, 0.0, 1.0, 0.0,
							0.0, 0.0, 0.0, 1.0};

	const TMatrix4f kA4f{	1.0f, 0.0f, 0.0f, 0.0f,
							0.0f, 1.0f, 0.0f, 0.0f,
							0.0f, 0.0f, 1.0f, 0.0f,
							0.0f, 0.0f, 0.0f, 1.0f};


	const TMatrix3d kA3d{	1.0, 0.0, 0.0,
							0.0, 1.0, 0.0,
							0.0, 0.0, 1.0};

	const TMatrix3f kA3f{	1.0f, 0.0f, 0.0f,
							0.0f, 1.0f, 0.0f,
							0.0f, 0.0f, 1.0f};


	const TMatrix2d kA2d{	1.0, 0.0,
							0.0, 1.0};

	const TMatrix2f kA2f{	1.0f, 0.0f,
							0.0f, 1.0f};

	const bool kbPass4d = math::Equal(math::IdentityMatrix(TMatrix4d()), kA4d, s_kdEpsilon);
	const bool kbPass4f = math::Equal(math::IdentityMatrix(TMatrix4f()), kA4f, s_kfEpsilon);
	const bool kbPass3d = math::Equal(math::IdentityMatrix(TMatrix3d()), kA3d, s_kdEpsilon);
	const bool kbPass3f = math::Equal(math::IdentityMatrix(TMatrix3f()), kA3f, s_kfEpsilon);
	const bool kbPass2d = math::Equal(math::IdentityMatrix(TMatrix2d()), kA2d, s_kdEpsilon);
	const bool kbPass2f = math::Equal(math::IdentityMatrix(TMatrix2f()), kA2f, s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f
			&&	kbPass2d
			&&	kbPass2f);
}

const bool Test_Matrix_Multiply()
{
	const TMatrix4d kA4d{	1.00, 2.00, 3.00, 4.00,
							5.00, 6.00, 7.00, 8.00,
							9.00, 10.0, 11.0, 12.0,
							13.0, 14.0, 15.0, 16.0};

	const TMatrix4d kB4d{	32.0, 30.0, 28.0, 26.0,
							24.0, 22.0, 20.0, 18.0,
							16.0, 14.0, 12.0, 10.0,
							8.00, 6.00, 4.00, 2.00};

	const TMatrix4d kC4d{	160.00, 140.00, 120.00, 100.00,
							480.00, 428.00, 376.00, 324.00,
							800.00, 716.00, 632.00, 548.00,
							1120.0, 1004.0, 888.00, 772.00};

	const TMatrix4f kA4f{	1.00f, 2.00f, 3.00f, 4.00f,
							5.00f, 6.00f, 7.00f, 8.00f,
							9.00f, 10.0f, 11.0f, 12.0f,
							13.0f, 14.0f, 15.0f, 16.0f};

	const TMatrix4f kB4f{	32.0f, 30.0f, 28.0f, 26.0f,
							24.0f, 22.0f, 20.0f, 18.0f,
							16.0f, 14.0f, 12.0f, 10.0f,
							8.00f, 6.00f, 4.00f, 2.00f};

	const TMatrix4f kC4f{	160.00f, 140.00f, 120.00f, 100.00f,
							480.00f, 428.00f, 376.00f, 324.00f,
							800.00f, 716.00f, 632.00f, 548.00f,
							1120.0f, 1004.0f, 888.00f, 772.00f};

	const TMatrix4d kD4d = math::Multiply(TMatrix4d(), kA4d, kB4d);
	const TMatrix4f kD4f = math::Multiply(TMatrix4f(), kA4f, kB4f);

	const bool kbPass4d = math::Equal(kD4d, kC4d, s_kdEpsilon);
	const bool kbPass4f = math::Equal(kD4f, kC4f, s_kfEpsilon);

	const TMatrix3d kA3d{	1.0, 2.0, 3.0,
							4.0, 5.0, 6.0,
							7.0, 8.0, 9.0};

	const TMatrix3d kB3d{	3.0, 2.0, 1.0,
							4.0, 5.0, 6.0,
							9.0, 8.0, 7.0};

	const TMatrix3d kC3d{	38.00, 36.00, 34.00,
							86.00, 81.00, 76.00,
							134.0, 126.0, 118.0};

	const TMatrix3f kA3f{	1.0f, 2.0f, 3.0f,
							4.0f, 5.0f, 6.0f,
							7.0f, 8.0f, 9.0f};

	const TMatrix3f kB3f{	3.0f, 2.0f, 1.0f,
							4.0f, 5.0f, 6.0f,
							9.0f, 8.0f, 7.0f};

	const TMatrix3f kC3f{	38.00f, 36.00f, 34.00f,
							86.00f, 81.00f, 76.00f,
							134.0f, 126.0f, 118.0f};

	const TMatrix3d kD3d = math::Multiply(TMatrix3d(), kA3d, kB3d);
	const TMatrix3f kD3f = math::Multiply(TMatrix3f(), kA3f, kB3f);

	const bool kbPass3d = math::Equal(kD3d, kC3d, s_kdEpsilon);
	const bool kbPass3f = math::Equal(kD3f, kC3f, s_kfEpsilon);

	TMatrix2d kA2d{	1.0, 2.0,
					3.0, 4.0};

	TMatrix2d kB2d{	8.0, 6.0,
					4.0, 2.0};

	TMatrix2d kC2d{	16.0, 10.0,
					40.0, 26.0};

	TMatrix2f kA2f{	1.0f, 2.0f,
					3.0f, 4.0f};

	TMatrix2f kB2f{	8.0f, 6.0f,
					4.0f, 2.0f};

	TMatrix2f kC2f{	16.0f, 10.0f,
					40.0f, 26.0f};

	const TMatrix2d kD2d = math::Multiply(TMatrix2d(), kA2d, kB2d);
	const TMatrix2f kD2f = math::Multiply(TMatrix2f(), kA2f, kB2f);

	const bool kbPass2d = math::Equal(kD2d, kC2d, s_kdEpsilon);
	const bool kbPass2f = math::Equal(kD2f, kC2f, s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f
			&&	kbPass2d
			&&	kbPass2f);
}

const bool Test_Matrix_ScalarMultiply()
{
	const TMatrix4d kA4d{	2.0, 0.0, 0.0, 0.0,
							0.0, 2.0, 0.0, 0.0,
							0.0, 0.0, 2.0, 0.0,
							0.0, 0.0, 0.0, 2.0};

	const TMatrix4f kA4f{	2.0f, 0.0f, 0.0f, 0.0f,
							0.0f, 2.0f, 0.0f, 0.0f,
							0.0f, 0.0f, 2.0f, 0.0f,
							0.0f, 0.0f, 0.0f, 2.0f};


	const TMatrix3d kA3d{	2.0, 0.0, 0.0,
							0.0, 2.0, 0.0,
							0.0, 0.0, 2.0};

	const TMatrix3f kA3f{	2.0f, 0.0f, 0.0f,
							0.0f, 2.0f, 0.0f,
							0.0f, 0.0f, 2.0f};


	const TMatrix2d kA2d{	2.0, 0.0,
							0.0, 2.0};

	const TMatrix2f kA2f{	2.0f, 0.0f,
							0.0f, 2.0f};

	const bool kbPass4d = math::Equal(math::ScalarMultiply(TMatrix4d(), math::IdentityMatrix(TMatrix4d()), 2.0), kA4d, s_kdEpsilon);
	const bool kbPass4f = math::Equal(math::ScalarMultiply(TMatrix4f(), math::IdentityMatrix(TMatrix4f()), 2.0f), kA4f, s_kfEpsilon);
	const bool kbPass3d = math::Equal(math::ScalarMultiply(TMatrix3d(), math::IdentityMatrix(TMatrix3d()), 2.0), kA3d, s_kdEpsilon);
	const bool kbPass3f = math::Equal(math::ScalarMultiply(TMatrix3f(), math::IdentityMatrix(TMatrix3f()), 2.0f), kA3f, s_kfEpsilon);
	const bool kbPass2d = math::Equal(math::ScalarMultiply(TMatrix2d(), math::IdentityMatrix(TMatrix2d()), 2.0), kA2d, s_kdEpsilon);
	const bool kbPass2f = math::Equal(math::ScalarMultiply(TMatrix2f(), math::IdentityMatrix(TMatrix2f()), 2.0f), kA2f, s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f
			&&	kbPass2d
			&&	kbPass2f);
}

const bool Test_Matrix_VectorMultiply()
{
	const TMatrix4d kA4d{	2.0, 0.0, 0.0, 0.0,
							0.0, 3.0, 0.0, 0.0,
							0.0, 0.0, 4.0, 0.0,
							0.0, 0.0, 0.0, 5.0};

	const TVector4d kB4d{ 1.0, 1.0, 1.0, 1.0 };
	const TVector4d kC4d{ 2.0, 3.0, 4.0, 5.0 };

	const TMatrix4f kA4f{	2.0f, 0.0f, 0.0f, 0.0f,
							0.0f, 3.0f, 0.0f, 0.0f,
							0.0f, 0.0f, 4.0f, 0.0f,
							0.0f, 0.0f, 0.0f, 5.0f};

	const TVector4f kB4f{ 1.0f, 1.0f, 1.0f, 1.0f };
	const TVector4f kC4f{ 2.0f, 3.0f, 4.0f, 5.0f };


	const TMatrix3d kA3d{	2.0, 0.0, 0.0,
							0.0, 3.0, 0.0,
							0.0, 0.0, 4.0};

	const TVector3d kB3d{ 1.0, 1.0, 1.0 };
	const TVector3d kC3d{ 2.0, 3.0, 4.0 };

	const TMatrix3f kA3f{	2.0f, 0.0f, 0.0f,
							0.0f, 3.0f, 0.0f,
							0.0f, 0.0f, 4.0f};

	const TVector3f kB3f{ 1.0f, 1.0f, 1.0f };
	const TVector3f kC3f{ 2.0f, 3.0f, 4.0f };

	const TMatrix2d kA2d{	2.0, 0.0,
							0.0, 3.0};

	const TVector2d kB2d{ 1.0, 1.0 };
	const TVector2d kC2d{ 2.0, 3.0 };

	const TMatrix2f kA2f{	2.0f, 0.0f,
							0.0f, 3.0f};

	const TVector2f kB2f{ 1.0f, 1.0f };
	const TVector2f kC2f{ 2.0f, 3.0f };

	const bool kbPass4d = math::Equal(kC4d, math::VectorMultiply(TVector4d(), kA4d, kB4d), s_kdEpsilon);
	const bool kbPass4f = math::Equal(kC4f, math::VectorMultiply(TVector4f(), kA4f, kB4f), s_kfEpsilon);
	const bool kbPass3d = math::Equal(kC3d, math::VectorMultiply(TVector3d(), kA3d, kB3d), s_kdEpsilon);
	const bool kbPass3f = math::Equal(kC3f, math::VectorMultiply(TVector3f(), kA3f, kB3f), s_kfEpsilon);
	const bool kbPass2d = math::Equal(kC2d, math::VectorMultiply(TVector2d(), kA2d, kB2d), s_kdEpsilon);
	const bool kbPass2f = math::Equal(kC2f, math::VectorMultiply(TVector2f(), kA2f, kB2f), s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f
			&&	kbPass2d
			&&	kbPass2f);
}

const bool Test_Matrix_Add()
{
	const TMatrix4d kA4d{	1.00, 2.00, 3.00, 4.00,
							5.00, 6.00, 7.00, 8.00,
							9.00, 10.0, 11.0, 12.0,
							13.0, 14.0, 15.0, 16.0};

	const TMatrix4f kA4f{	1.00f, 2.00f, 3.00f, 4.00f,
							5.00f, 6.00f, 7.00f, 8.00f,
							9.00f, 10.0f, 11.0f, 12.0f,
							13.0f, 14.0f, 15.0f, 16.0f};

	const bool kbPass4d = math::Equal(math::ScalarMultiply(TMatrix4d(), kA4d, 2.0), math::Add(TMatrix4d(), kA4d, kA4d), s_kdEpsilon);
	const bool kbPass4f = math::Equal(math::ScalarMultiply(TMatrix4f(), kA4f, 2.0f), math::Add(TMatrix4f(), kA4f, kA4f), s_kfEpsilon);

	const TMatrix3d kA3d{	1.0, 2.0, 3.0,
							4.0, 5.0, 6.0,
							7.0, 8.0, 9.0};

	const TMatrix3f kA3f{	1.0f, 2.0f, 3.0f,
							4.0f, 5.0f, 6.0f,
							7.0f, 8.0f, 9.0f};

	const bool kbPass3d = math::Equal(math::ScalarMultiply(TMatrix3d(), kA3d, 2.0), math::Add(TMatrix3d(), kA3d, kA3d), s_kdEpsilon);
	const bool kbPass3f = math::Equal(math::ScalarMultiply(TMatrix3f(), kA3f, 2.0f), math::Add(TMatrix3f(), kA3f, kA3f), s_kfEpsilon);

	const TMatrix2d kA2d{	1.0, 2.0,
							3.0, 4.0};

	const TMatrix2f kA2f{	1.0f, 2.0f,
							3.0f, 4.0f};

	const bool kbPass2d = math::Equal(math::ScalarMultiply(TMatrix2d(), kA2d, 2.0), math::Add(TMatrix2d(), kA2d, kA2d), s_kdEpsilon);
	const bool kbPass2f = math::Equal(math::ScalarMultiply(TMatrix2f(), kA2f, 2.0f), math::Add(TMatrix2f(), kA2f, kA2f), s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f
			&&	kbPass2d
			&&	kbPass2f);
}

const bool Test_Matrix_Transpose()
{
	const TMatrix4d kA4d{	1.00, 2.00, 3.00, 4.00,
							5.00, 6.00, 7.00, 8.00,
							9.00, 10.0, 11.0, 12.0,
							13.0, 14.0, 15.0, 16.0};

	const TMatrix4d kB4d{	1.00, 5.00, 9.00, 13.0,
							2.00, 6.00, 10.0, 14.0,
							3.00, 7.00, 11.0, 15.0,
							4.00, 8.00, 12.0, 16.0};

	const TMatrix4f kA4f{	1.00f, 2.00f, 3.00f, 4.00f,
							5.00f, 6.00f, 7.00f, 8.00f,
							9.00f, 10.0f, 11.0f, 12.0f,
							13.0f, 14.0f, 15.0f, 16.0f};

	const TMatrix4f kB4f{	1.00f, 5.00f, 9.00f, 13.0f,
							2.00f, 6.00f, 10.0f, 14.0f,
							3.00f, 7.00f, 11.0f, 15.0f,
							4.00f, 8.00f, 12.0f, 16.0f};

	const bool kbPass4d = math::Equal(math::Transpose(TMatrix4d(), kA4d), kB4d, s_kdEpsilon);
	const bool kbPass4f = math::Equal(math::Transpose(TMatrix4f(), kA4f), kB4f, s_kfEpsilon);

	const TMatrix3d kA3d{	1.0, 2.0, 3.0,
							4.0, 5.0, 6.0,
							7.0, 8.0, 9.0};

	const TMatrix3d kB3d{	1.0, 4.0, 7.0,
							2.0, 5.0, 8.0,
							3.0, 6.0, 9.0};

	const TMatrix3f kA3f{	1.0f, 2.0f, 3.0f,
							4.0f, 5.0f, 6.0f,
							7.0f, 8.0f, 9.0f};

	const TMatrix3f kB3f{	1.0f, 4.0f, 7.0f,
							2.0f, 5.0f, 8.0f,
							3.0f, 6.0f, 9.0f};

	const bool kbPass3d = math::Equal(math::Transpose(TMatrix3d(), kA3d), kB3d, s_kdEpsilon);
	const bool kbPass3f = math::Equal(math::Transpose(TMatrix3f(), kA3f), kB3f, s_kfEpsilon);

	const TMatrix2d kA2d{	1.0, 2.0,
							3.0, 4.0};

	const TMatrix2d kB2d{	1.0, 3.0,
							2.0, 4.0};

	const TMatrix2f kA2f{	1.0f, 2.0f,
							3.0f, 4.0f};

	const TMatrix2f kB2f{	1.0f, 3.0f,
							2.0f, 4.0f};

	const bool kbPass2d = math::Equal(math::Transpose(TMatrix2d(), kA2d), kB2d, s_kdEpsilon);
	const bool kbPass2f = math::Equal(math::Transpose(TMatrix2f(), kA2f), kB2f, s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f
			&&	kbPass2d
			&&	kbPass2f);
}

const bool Test_Matrix_GetElement()
{
	const TMatrix4d kA4d{	1.00, 2.00, 3.00, 4.00,
							5.00, 6.00, 7.00, 8.00,
							9.00, 10.0, 11.0, 12.0,
							13.0, 14.0, 15.0, 16.0};

	const double kB4d[]{	1.00, 2.00, 3.00, 4.00,
							5.00, 6.00, 7.00, 8.00,
							9.00, 10.0, 11.0, 12.0,
							13.0, 14.0, 15.0, 16.0};

	const TMatrix4f kA4f{	1.00f, 2.00f, 3.00f, 4.00f,
							5.00f, 6.00f, 7.00f, 8.00f,
							9.00f, 10.0f, 11.0f, 12.0f,
							13.0f, 14.0f, 15.0f, 16.0f};

	const float kB4f[]{	1.00f, 2.00f, 3.00f, 4.00f,
						5.00f, 6.00f, 7.00f, 8.00f,
						9.00f, 10.0f, 11.0f, 12.0f,
						13.0f, 14.0f, 15.0f, 16.0f};

	bool bPass4d = true;
	bool bPass4f = true;
	for(size_t i = 0; i < 16; ++i)
	{
		size_t x = (i % 4) + 1;
		size_t y = (i / 4) + 1;

		if(!math::Equal(math::GetElement(kA4d, y, x), kB4d[i], s_kdEpsilon))
		{
			bPass4d = false;
		}

		if(!math::Equal(math::GetElement(kA4f, y, x), kB4f[i], s_kfEpsilon))
		{
			bPass4f = false;
		}
	}

	const TMatrix3d kA3d{	1.0, 2.0, 3.0,
							4.0, 5.0, 6.0,
							7.0, 8.0, 9.0};

	const double kB3d[]{	1.0, 2.0, 3.0,
							4.0, 5.0, 6.0,
							7.0, 8.0, 9.0};
	
	const TMatrix3f kA3f{	1.0f, 2.0f, 3.0f,
							4.0f, 5.0f, 6.0f,
							7.0f, 8.0f, 9.0f};

	const float kB3f[]{	1.0f, 2.0f, 3.0f,
						4.0f, 5.0f, 6.0f,
						7.0f, 8.0f, 9.0f};

	bool bPass3d = true;
	bool bPass3f = true;
	for(size_t i = 0; i < 9; ++i)
	{
		size_t x = (i % 3) + 1;
		size_t y = (i / 3) + 1;

		if(!math::Equal(math::GetElement(kA3d, y, x), kB3d[i], s_kdEpsilon))
		{
			bPass3d = false;
		}

		if(!math::Equal(math::GetElement(kA3f, y, x), kB3f[i], s_kfEpsilon))
		{
			bPass3f = false;
		}
	}

	const TMatrix2d kA2d{	1.0, 2.0,
							3.0, 4.0};

	const double kB2d[]{	1.0, 2.0,
							3.0, 4.0};
	
	const TMatrix2f kA2f{	1.0f, 2.0f,
							3.0f, 4.0f};

	const float kB2f[]{	1.0f, 2.0f,
						3.0f, 4.0f};

	bool bPass2d = true;
	bool bPass2f = true;
	for(size_t i = 0; i < 4; ++i)
	{
		size_t x = (i % 2) + 1;
		size_t y = (i / 2) + 1;

		if(!math::Equal(math::GetElement(kA2d, y, x), kB2d[i], s_kdEpsilon))
		{
			bPass2d = false;
		}

		if(!math::Equal(math::GetElement(kA2f, y, x), kB2f[i], s_kfEpsilon))
		{
			bPass2f = false;
		}
	}


	return(		bPass4d
			&&	bPass4f
			&&	bPass3d
			&&	bPass3f
			&&	bPass2d
			&&	bPass2f);
}

const bool Test_Matrix_SetElement()
{
	bool bPass4d = true;
	bool bPass4f = true;
	for(size_t i = 0; i < 16; ++i)
	{
		size_t x = (i % 4) + 1;
		size_t y = (i / 4) + 1;

		if(!math::Equal(math::GetElement(math::SetElement(TMatrix4d(), (double)i, y, x), y, x), (double)i, s_kdEpsilon))
		{
			bPass4d = false;
		}
		if(!math::Equal(math::GetElement(math::SetElement(TMatrix4f(), (float)i, y, x), y, x), (float)i, s_kfEpsilon))
		{
			bPass4f = false;
		}
	}

	bool bPass3d = true;
	bool bPass3f = true;
	for(size_t i = 0; i < 9; ++i)
	{
		size_t x = (i % 3) + 1;
		size_t y = (i / 3) + 1;

		if(!math::Equal(math::GetElement(math::SetElement(TMatrix3d(), (double)i, y, x), y, x), (double)i, s_kdEpsilon))
		{
			bPass3d = false;
		}
		if(!math::Equal(math::GetElement(math::SetElement(TMatrix3f(), (float)i, y, x), y, x), (float)i, s_kfEpsilon))
		{
			bPass3f = false;
		}
	}

	bool bPass2d = true;
	bool bPass2f = true;
	for(size_t i = 0; i < 4; ++i)
	{
		size_t x = (i % 2) + 1;
		size_t y = (i / 2) + 1;

		if(!math::Equal(math::GetElement(math::SetElement(TMatrix2d(), (double)i, y, x), y, x), (double)i, s_kdEpsilon))
		{
			bPass2d = false;
		}
		if(!math::Equal(math::GetElement(math::SetElement(TMatrix2f(), (float)i, y, x), y, x), (float)i, s_kfEpsilon))
		{
			bPass2f = false;
		}
	}

	return(		bPass4d
			&&	bPass4f
			&&	bPass3d
			&&	bPass3f
			&&	bPass2d
			&&	bPass2f);
}

const bool Test_Matrix_Submatrix()
{
	const TMatrix4d kA4d{	1.00, 2.00, 3.00, 4.00,
							5.00, 6.00, 7.00, 8.00,
							9.00, 10.0, 11.0, 12.0,
							13.0, 14.0, 15.0, 16.0};

	const TMatrix3d kB4d{	1.00, 3.00, 4.00,
							9.00, 11.0, 12.0,
							13.0, 15.0, 16.0};

	const TMatrix4f kA4f{	1.00f, 2.00f, 3.00f, 4.00f,
							5.00f, 6.00f, 7.00f, 8.00f,
							9.00f, 10.0f, 11.0f, 12.0f,
							13.0f, 14.0f, 15.0f, 16.0f};

	const TMatrix3f kB4f{	1.00f, 3.00f, 4.00f,
							9.00f, 11.0f, 12.0f,
							13.0f, 15.0f, 16.0f};

	const bool kbPass4d = math::Equal(math::Submatrix(TMatrix3d(), kA4d, 2, 2), kB4d, s_kdEpsilon);
	const bool kbPass4f = math::Equal(math::Submatrix(TMatrix3f(), kA4f, 2, 2), kB4f, s_kfEpsilon);

	const TMatrix3d kA3d{	1.0, 2.0, 3.0,
							4.0, 5.0, 6.0,
							7.0, 8.0, 9.0};

	const TMatrix2d kB3d{	1.0, 3.0,
							7.0, 9.0};

	const TMatrix3f kA3f{	1.0f, 2.0f, 3.0f,
							4.0f, 5.0f, 6.0f,
							7.0f, 8.0f, 9.0f};

	const TMatrix2f kB3f{	1.0f, 3.0f,
							7.0f, 9.0f};

	const bool kbPass3d = math::Equal(math::Submatrix(TMatrix2d(), kA3d, 2, 2), kB3d, s_kdEpsilon);
	const bool kbPass3f = math::Equal(math::Submatrix(TMatrix2f(), kA3f, 2, 2), kB3f, s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f);
}

const bool Test_Matrix_FirstMinor()
{
	const TMatrix4d kA4d{	1.00, 2.00, 3.00, 4.00,
							5.00, 6.00, 7.00, 8.00,
							9.00, 10.0, 11.0, 12.0,
							13.0, 14.0, 15.0, 16.0};

	const double kB4d = math::Determinant(math::Submatrix(TMatrix3d(), kA4d, 3, 4));

	const TMatrix4f kA4f{	1.00f, 2.00f, 3.00f, 4.00f,
							5.00f, 6.00f, 7.00f, 8.00f,
							9.00f, 10.0f, 11.0f, 12.0f,
							13.0f, 14.0f, 15.0f, 16.0f};

	const float kB4f = math::Determinant(math::Submatrix(TMatrix3f(), kA4f, 1, 2));

	const bool kbPass4d = math::Equal(math::FirstMinor(kA4d, 3, 4), kB4d, s_kdEpsilon);
	const bool kbPass4f = math::Equal(math::FirstMinor(kA4f, 1, 2), kB4f, s_kfEpsilon);

	const TMatrix3d kA3d{	1.0, 2.0, 3.0,
							4.0, 5.0, 6.0,
							7.0, 8.0, 9.0};

	const double kB3d = math::Determinant(math::Submatrix(TMatrix2d(), kA3d, 2, 2));

	const TMatrix3f kA3f{	1.0f, 2.0f, 3.0f,
							4.0f, 5.0f, 6.0f,
							7.0f, 8.0f, 9.0f};

	const float kB3f = math::Determinant(math::Submatrix(TMatrix2f(), kA3f, 3, 1));

	const bool kbPass3d = math::Equal(math::FirstMinor(kA3d, 2, 2), kB3d, s_kdEpsilon);
	const bool kbPass3f = math::Equal(math::FirstMinor(kA3f, 3, 1), kB3f, s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f);
}

const bool Test_Matrix_MatrixOfMinors()
{
	const TMatrix4d kA4d{	2.0, 0.0, 0.0, 5.0,
							0.0, 3.0, 0.0, 6.0,
							0.0, 0.0, 4.0, 7.0,
							0.0, 0.0, 0.0, 1.0};

	const TMatrix4d kB4d{	012.0, 000.0, 000.0, 000.0,
							000.0, 008.0, 000.0, 000.0,
							000.0, 000.0, 006.0, 000.0,
							060.0, -48.0, 042.0, 024.0};

	const TMatrix4d kC4d = math::MatrixOfMinors(TMatrix4d(), kA4d);

	const bool kbPass4d = math::Equal(kB4d, kC4d, s_kdEpsilon);

	const TMatrix4f kA4f{	2.0f, 0.0f, 0.0f, 5.0f,
							0.0f, 3.0f, 0.0f, 6.0f,
							0.0f, 0.0f, 4.0f, 7.0f,
							0.0f, 0.0f, 0.0f, 1.0f};

	const TMatrix4f kB4f{	012.0f, 000.0f, 000.0f, 000.0f,
							000.0f, 008.0f, 000.0f, 000.0f,
							000.0f, 000.0f, 006.0f, 000.0f,
							060.0f, -48.0f, 042.0f, 024.0f};

	const TMatrix4f kC4f = math::MatrixOfMinors(TMatrix4f(), kA4f);

	const bool kbPass4f = math::Equal(kB4f, kC4f, s_kfEpsilon);

	const TMatrix3d kA3d{	2.0, 0.0, 5.0,
							0.0, 3.0, 6.0,
							0.0, 0.0, 1.0};

	const TMatrix3d kB3d{	003.0, 000.0, 000.0,
							000.0, 002.0, 000.0,
							-15.0, 012.0, 006.0};

	const TMatrix3d kC3d = math::MatrixOfMinors(TMatrix3d(), kA3d);

	const bool kbPass3d = math::Equal(kB3d, kC3d, s_kdEpsilon);

	const TMatrix3f kA3f{	2.0f, 0.0f, 5.0f,
							0.0f, 3.0f, 6.0f,
							0.0f, 0.0f, 1.0f};

	const TMatrix3f kB3f{	003.0f, 000.0f, 000.0f,
							000.0f, 002.0f, 000.0f,
							-15.0f, 012.0f, 006.0f};

	const TMatrix3f kC3f = math::MatrixOfMinors(TMatrix3f(), kA3f);

	const bool kbPass3f = math::Equal(kB3f, kC3f, s_kfEpsilon);

	return(		kbPass4d
			&&	kbPass4f
			&&	kbPass3d
			&&	kbPass3f);
}

//