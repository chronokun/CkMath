//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

// Local Includes
#include "tests_quaternion.h"
#include "ckmath.h"
#include "test_constants.h"

const bool Test_Quaternion_IdentityQuaternion()
{
	const TVector4d kAd = IdentityQuaternion(TVector4d());
	const TVector4d kBd = TVector4d{0.0, 0.0, 0.0, 1.0};

	const bool kbPassd = Equal(kAd, kBd, s_kdEpsilon);

	const TVector4f kAf = IdentityQuaternion(TVector4f());
	const TVector4f kBf = TVector4f{0.0f, 0.0f, 0.0f, 1.0f};

	const bool kbPassf = Equal(kAf, kBf, s_kfEpsilon);

	return(kbPassd && kbPassf);
}