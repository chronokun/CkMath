//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

// Local Includes
#include "tests_geometry.h"
#include "ckmath.h"
#include "test_constants.h"

const bool Test_Geometry_GetInterval()
{
	const TPlane3d kPlane3d{	TVector3d{2.0, 0.0, 0.0},
								TVector3d{-1.0, 0.0, 0.0}};

	const TRay3d kRay3d{	TVector3d{0.0, 0.0, 0.0},
							TVector3d{1.0, 0.0, 0.0}};

	const TPlane3f kPlane3f{	TVector3f{2.0f, 0.0f, 0.0f},
								TVector3f{-1.0f, 0.0f, 0.0f}};

	const TRay3f kRay3f{	TVector3f{0.0f, 0.0f, 0.0f},
							TVector3f{1.0f, 0.0f, 0.0f}};

	const bool kPass3d = Equal(GetInterval(kRay3d, kPlane3d), 2.0, s_kdEpsilon);
	const bool kPass3f = Equal(GetInterval(kRay3f, kPlane3f), 2.0f, s_kfEpsilon);

	return(kPass3d && kPass3f);
}

const bool Test_Geometry_IsIntersection()
{
	const TPlane3d kPlane3d{	TVector3d{2.0, 0.0, 0.0},
								TVector3d{-1.0, 0.0, 0.0}};

	const TRay3d kRayA3d{	TVector3d{0.0, 0.0, 0.0},
							TVector3d{1.0, 0.0, 0.0}};

	const TRay3d kRayB3d{	TVector3d{0.0, 0.0, 0.0},
							TVector3d{0.0, 1.0, 0.0}};

	const TPlane3f kPlane3f{	TVector3f{2.0f, 0.0f, 0.0f},
								TVector3f{-1.0f, 0.0f, 0.0f}};

	const TRay3f kRayA3f{	TVector3f{0.0f, 0.0f, 0.0f},
							TVector3f{1.0f, 0.0f, 0.0f}};

	const TRay3f kRayB3f{	TVector3f{0.0f, 0.0f, 0.0f},
							TVector3f{0.0f, 1.0f, 0.0f}};

	const bool kPass3d = IsIntersection(kRayA3d, kPlane3d) && !IsIntersection(kRayB3d, kPlane3d);
	const bool kPass3f = IsIntersection(kRayA3f, kPlane3f) && !IsIntersection(kRayB3f, kPlane3f);

	return(kPass3d && kPass3f);
}

const bool Test_Geometry_GetIntersection()
{
	const TPlane3d kPlane3d{	TVector3d{2.0, 0.0, 0.0},
								TVector3d{-1.0, 0.0, 0.0}};

	const TRay3d kRay3d{	TVector3d{0.0, 0.0, 0.0},
							TVector3d{1.0, 0.0, 0.0}};

	const TPlane3f kPlane3f{	TVector3f{2.0f, 0.0f, 0.0f},
								TVector3f{-1.0f, 0.0f, 0.0f}};

	const TRay3f kRay3f{	TVector3f{0.0f, 0.0f, 0.0f},
							TVector3f{1.0f, 0.0f, 0.0f}};

	const TVector3d kIntersect3d{2.0, 0.0, 0.0};

	const TVector3f kIntersect3f{2.0f, 0.0f, 0.0f};

	const bool kPass3d = Equal(GetIntersection(TVector3d(), kRay3d, kPlane3d), kIntersect3d, s_kdEpsilon);
	const bool kPass3f = Equal(GetIntersection(TVector3f(), kRay3f, kPlane3f), kIntersect3f, s_kfEpsilon);

	return(kPass3d && kPass3f);
}
