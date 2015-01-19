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

const bool Test_Quaternion_ConjugateQuaternion()
{
	const TVector4d kAd = AxisAngleQuaternion(TVector4d(), Normalize(TVector3d(), TVector3d{1.0, 1.0, 1.0}), (s_kdTau / 4.0));
	const TVector4d kBd = AxisAngleQuaternion(TVector4d(), Normalize(TVector3d(), TVector3d{-1.0, -1.0, -1.0}), (s_kdTau / 4.0));

	const bool kbPassd = Equal(kBd, ConjugateQuaternion(TVector4d(), kAd), s_kdEpsilon);

	const TVector4f kAf = AxisAngleQuaternion(TVector4f(), Normalize(TVector3f(), TVector3f{1.0f, 1.0f, 1.0f}), (s_kfTau / 4.0f));
	const TVector4f kBf = AxisAngleQuaternion(TVector4f(), Normalize(TVector3f(), TVector3f{-1.0f, -1.0f, -1.0f}), (s_kfTau / 4.0f));

	const bool kbPassf = Equal(kBf, ConjugateQuaternion(TVector4f(), kAf), s_kfEpsilon);

	return(kbPassd && kbPassf);
}

const bool Test_Quaternion_InverseQuaternion()
{
	const TVector4d kAd = AxisAngleQuaternion(TVector4d(), Normalize(TVector3d(), TVector3d{1.0, 1.0, 1.0}), (s_kdTau / 4.0));
	const TVector4d kBd = InverseQuaternion(TVector4d(), kAd);

	const bool kbPassd = Equal(QuaternionProduct(TVector4d(), kAd, kBd), IdentityQuaternion(TVector4d()), s_kdEpsilon);

	const TVector4f kAf = AxisAngleQuaternion(TVector4f(), Normalize(TVector3f(), TVector3f{1.0f, 1.0f, 1.0f}), (s_kfTau / 4.0f));
	const TVector4f kBf = InverseQuaternion(TVector4f(), kAf);

	const bool kbPassf = Equal(QuaternionProduct(TVector4f(), kAf, kBf), IdentityQuaternion(TVector4f()), s_kfEpsilon);

	return(kbPassd && kbPassf);
}

const bool Test_Quaternion_UnitQuaternion()
{
	const TVector4d kAd{9.0, 6.0, 2.0, 3.0};
	const TVector4d kBd = UnitQuaternion(TVector4d(), kAd);

	const bool kbPassd = Equal(ConjugateQuaternion(TVector4d(), kBd), InverseQuaternion(TVector4d(), kBd), s_kdEpsilon);

	const TVector4f kAf{1.0f, 2.0f, 3.0f, 4.0f};
	const TVector4f kBf = UnitQuaternion(TVector4f(), kAf);

	const bool kbPassf = Equal(ConjugateQuaternion(TVector4f(), kBf), InverseQuaternion(TVector4f(), kBf), s_kfEpsilon);

	return(kbPassd && kbPassf);
}
