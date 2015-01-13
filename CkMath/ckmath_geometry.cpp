//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

// Local Includes
#include "ckmath_scalar.h"
#include "ckmath_vector.h"
#include "ckmath_geometry.h"

using namespace math;

const bool math::IsIntersection(const TPlane3d& _krA,
								const TPlane3d& _krB,
								const TPlane3d& _krC)
{
	const TVector3d kNAxNB = math::CrossProduct(TVector3d(), _krA.m_Normal, _krB.m_Normal);
	return(math::Magnitude(math::DotProduct(kNAxNB, _krC.m_Normal)) > 0.0);
}

const bool math::IsIntersection(const TPlane3f& _krA,
								const TPlane3f& _krB,
								const TPlane3f& _krC)
{
	const TVector3f kNAxNB = math::CrossProduct(TVector3f(), _krA.m_Normal, _krB.m_Normal);
	return(math::Magnitude(math::DotProduct(kNAxNB, _krC.m_Normal)) > 0.0f);
}

const TVector3d& math::GetIntersection(	TVector3d& _rResult,
										const TPlane3d& _krA,
										const TPlane3d& _krB,
										const TPlane3d& _krC)
{
	const TVector3d kNBxNC = math::CrossProduct(TVector3d(), _krB.m_Normal, _krC.m_Normal);
	const TVector3d kNCxNA = math::CrossProduct(TVector3d(), _krC.m_Normal, _krA.m_Normal);
	const TVector3d kNAxNB = math::CrossProduct(TVector3d(), _krA.m_Normal, _krB.m_Normal);

	const double kdDistanceA = math::DotProduct(_krA.m_Normal, _krA.m_Point);
	const double kdDistanceB = math::DotProduct(_krB.m_Normal, _krB.m_Point);
	const double kdDistanceC = math::DotProduct(_krC.m_Normal, _krC.m_Point);

	const TVector3d kDA_NBxNC = math::ScalarMultiply(TVector3d(), kNBxNC, kdDistanceA);
	const TVector3d kDB_NCxNA = math::ScalarMultiply(TVector3d(), kNCxNA, kdDistanceB);
	const TVector3d kDC_NAxNB = math::ScalarMultiply(TVector3d(), kNAxNB, kdDistanceC);

	const double kdDenom = math::DotProduct(kNAxNB, _krC.m_Normal);

	const TVector3d kNumer = math::Add(TVector3d(), math::Add(TVector3d(), kDA_NBxNC, kDB_NCxNA), kDC_NAxNB);

	_rResult = math::ScalarMultiply(_rResult, kNumer, (1.0 / kdDenom));

	return(_rResult);
}

const TVector3f& math::GetIntersection(	TVector3f& _rResult,
										const TPlane3f& _krA,
										const TPlane3f& _krB,
										const TPlane3f& _krC)
{
	const TVector3f kNBxNC = math::CrossProduct(TVector3f(), _krB.m_Normal, _krC.m_Normal);
	const TVector3f kNCxNA = math::CrossProduct(TVector3f(), _krC.m_Normal, _krA.m_Normal);
	const TVector3f kNAxNB = math::CrossProduct(TVector3f(), _krA.m_Normal, _krB.m_Normal);

	const float kfDistanceA = math::DotProduct(_krA.m_Normal, _krA.m_Point);
	const float kfDistanceB = math::DotProduct(_krB.m_Normal, _krB.m_Point);
	const float kfDistanceC = math::DotProduct(_krC.m_Normal, _krC.m_Point);

	const TVector3f kDA_NBxNC = math::ScalarMultiply(TVector3f(), kNBxNC, kfDistanceA);
	const TVector3f kDB_NCxNA = math::ScalarMultiply(TVector3f(), kNCxNA, kfDistanceB);
	const TVector3f kDC_NAxNB = math::ScalarMultiply(TVector3f(), kNAxNB, kfDistanceC);

	const float kfDenom = math::DotProduct(kNAxNB, _krC.m_Normal);

	const TVector3f kNumer = math::Add(TVector3f(), math::Add(TVector3f(), kDA_NBxNC, kDB_NCxNA), kDC_NAxNB);

	_rResult = math::ScalarMultiply(_rResult, kNumer, (1.0f / kfDenom));

	return(_rResult);
}

const TVector3d& math::GetPolygonNormal(TVector3d& _rResult, const TVector3d* _kpVertices, const size_t _kVertexCount)
{
	_rResult = math::ZeroVector(TVector3d());

	for(size_t i = 0; i < _kVertexCount; ++i)
	{
		const size_t kIndexA = ((_kVertexCount-1)+i)%_kVertexCount;
		const size_t kIndexB = i;

		const TVector3d& krA = _kpVertices[kIndexA];
		const TVector3d& krB = _kpVertices[kIndexB];

		const TVector3d kCrossProduct = math::CrossProduct(TVector3d(), krA, krB);

		_rResult = math::Add(_rResult, _rResult, kCrossProduct);
	}

	_rResult = math::Normalize(_rResult, _rResult);

	return(_rResult);
}

const TVector3f& math::GetPolygonNormal(TVector3f& _rResult, const TVector3f* _kpVertices, const size_t _kVertexCount)
{
	_rResult = math::ZeroVector(TVector3f());

	for(size_t i = 0; i < _kVertexCount; ++i)
	{
		const size_t kIndexA = ((_kVertexCount-1)+i)%_kVertexCount;
		const size_t kIndexB = i;

		const TVector3f& krA = _kpVertices[kIndexA];
		const TVector3f& krB = _kpVertices[kIndexB];

		const TVector3f kCrossProduct = math::CrossProduct(TVector3f(), krA, krB);

		_rResult = math::Add(_rResult, _rResult, kCrossProduct);
	}

	_rResult = math::Normalize(_rResult, _rResult);

	return(_rResult);
}