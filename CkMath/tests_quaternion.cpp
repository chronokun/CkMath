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

const bool Test_Quaternion_AxisAngleQuaternion()
{
	const double kdAngle = s_kdTau / 4.0;
	const TVector3d kAxisd{1.0, 0.0, 0.0};
	const TVector4d kAd = AxisAngleQuaternion(TVector4d(), kAxisd, kdAngle);
	const double kdCosHalfAngle = Cosine(kdAngle / 2.0);
	const double kdSinHalfAngle = Sine(kdAngle / 2.0);
	const TVector4d kBd{	kAxisd.m_dX * kdSinHalfAngle,
							kAxisd.m_dY * kdSinHalfAngle,
							kAxisd.m_dZ * kdSinHalfAngle,
							kdCosHalfAngle};

	const bool kbPassd = Equal(kAd, kBd, s_kdEpsilon);

	const float kfAngle = s_kfTau / 4.0f;
	const TVector3f kAxisf{1.0f, 0.0f, 0.0f};
	const TVector4f kAf = AxisAngleQuaternion(TVector4f(), kAxisf, kfAngle);
	const float kfCosHalfAngle = Cosine(kfAngle / 2.0f);
	const float kfSinHalfAngle = Sine(kfAngle / 2.0f);
	const TVector4f kBf{	kAxisf.m_fX * kfSinHalfAngle,
							kAxisf.m_fY * kfSinHalfAngle,
							kAxisf.m_fZ * kfSinHalfAngle,
							kfCosHalfAngle};

	const bool kbPassf = Equal(kAf, kBf, s_kfEpsilon);

	return(kbPassd && kbPassf);
}

const bool Test_Quaternion_QuaternionProduct()
{
	const TVector3d kAxisd{1.0, 0.0, 0.0};
	const TVector4d kAd = AxisAngleQuaternion(TVector4d(), kAxisd, s_kdTau / 8.0);
	const TVector4d kBd = AxisAngleQuaternion(TVector4d(), kAxisd, s_kdTau / 4.0);
	const TVector4d kCd = QuaternionProduct(TVector4d(), kAd, kAd);

	const bool kbPassd = Equal(kCd, kBd, s_kdEpsilon);

	const TVector3f kAxisf{1.0f, 0.0f, 0.0f};
	const TVector4f kAf = AxisAngleQuaternion(TVector4f(), kAxisf, s_kfTau / 8.0f);
	const TVector4f kBf = AxisAngleQuaternion(TVector4f(), kAxisf, s_kfTau / 4.0f);
	const TVector4f kCf = QuaternionProduct(TVector4f(), kAf, kAf);

	const bool kbPassf = Equal(kCf, kBf, s_kfEpsilon);

	return(kbPassd && kbPassf);
}

const bool Test_Quaternion_QuaternionRotate()
{
	const TVector3d kAxisd{1.0, 0.0, 0.0};
	const double kdAngle = s_kdTau / 4.0;
	const TVector4d kQuatd = AxisAngleQuaternion(TVector4d(), kAxisd, kdAngle);
	const TVector3d kAd{0.0, 1.0, 0.0};
	const TVector3d kBd = QuaternionRotate(TVector3d(), kAd, kQuatd);
	const TVector3d kCd{0.0, 0.0, 1.0};

	const bool kbPassd = Equal(kBd, kCd, s_kdEpsilon);

	const TVector3f kAxisf{1.0f, 0.0f, 0.0f};
	const float kfAngle = s_kfTau / 4.0f;
	const TVector4f kQuatf = AxisAngleQuaternion(TVector4f(), kAxisf, kfAngle);
	const TVector3f kAf{0.0f, 1.0f, 0.0f};
	const TVector3f kBf = QuaternionRotate(TVector3f(), kAf, kQuatf);
	const TVector3f kCf{0.0f, 0.0f, 1.0f};

	const bool kbPassf = Equal(kBf, kCf, s_kfEpsilon);

	return(kbPassd && kbPassf);
}

