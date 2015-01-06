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

//