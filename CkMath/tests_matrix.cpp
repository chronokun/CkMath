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
	TMatrix4d kA4d{	2.0, 1.0, 3.0, 9.0,
					0.0, 5.0, 6.0, 1.0,
					8.0, 7.0, 2.0, 3.0,
					1.0, 0.0, 3.0, 4.0};

	TMatrix4d kB4d{	3.0, 1.0, 3.0, 9.0,
					2.0, 5.0, 3.0, 1.0,
					8.0, 9.0, 2.0, 3.0,
					1.0, 0.0, 3.0, 4.0};


	TMatrix4f kA4f{	2.0f, 1.0f, 3.0f, 9.0f,
					0.0f, 5.0f, 6.0f, 1.0f,
					8.0f, 7.0f, 2.0f, 3.0f,
					1.0f, 0.0f, 3.0f, 4.0f};

	TMatrix4f kB4f{	3.0f, 1.0f, 3.0f, 9.0f,
					2.0f, 5.0f, 3.0f, 1.0f,
					8.0f, 9.0f, 2.0f, 3.0f,
					1.0f, 0.0f, 3.0f, 4.0f};

	const bool kbPass4d = math::Equal(kA4d, kA4d, s_kdEpsilon) && !math::Equal(kA4d, kB4d, s_kdEpsilon);
	const bool kbPass4f = math::Equal(kA4f, kA4f, s_kfEpsilon) && !math::Equal(kA4f, kB4f, s_kfEpsilon);

	TMatrix3d kA3d{	2.0, 1.0, 3.0,
					0.0, 5.0, 6.0,
					8.0, 7.0, 2.0};

	TMatrix3d kB3d{	3.0, 1.0, 3.0,
					2.0, 5.0, 3.0,
					8.0, 9.0, 2.0};


	TMatrix3f kA3f{	2.0f, 1.0f, 3.0f,
					0.0f, 5.0f, 6.0f,
					8.0f, 7.0f, 2.0f};

	TMatrix3f kB3f{	3.0f, 1.0f, 3.0f,
					2.0f, 5.0f, 3.0f,
					8.0f, 9.0f, 2.0f};

	const bool kbPass3d = math::Equal(kA3d, kA3d, s_kdEpsilon) && !math::Equal(kA3d, kB3d, s_kdEpsilon);
	const bool kbPass3f = math::Equal(kA3f, kA3f, s_kfEpsilon) && !math::Equal(kA3f, kB3f, s_kfEpsilon);

	TMatrix2d kA2d{	2.0, 1.0,
					0.0, 5.0};

	TMatrix2d kB2d{	3.0, 1.0,
					2.0, 5.0};


	TMatrix2f kA2f{	2.0f, 1.0f,
					0.0f, 5.0f};

	TMatrix2f kB2f{	3.0f, 1.0f,
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

//