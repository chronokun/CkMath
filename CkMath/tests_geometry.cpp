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

	const bool kPass3d = Equal(GetInterval(kRay3d, kPlane3d), 2.0, s_kdEpsilon);

	return(kPass3d);
}
