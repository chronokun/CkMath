//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

#pragma once

#ifndef __MATH_GEOMETRY_H__
#define __MATH_GEOMETRY_H__

// Local Includes
#include "ckmath_types.h"

const bool IsIntersection(	const TPlane3d& _krA,
							const TPlane3d& _krB,
							const TPlane3d& _krC);

const bool IsIntersection(	const TPlane3f& _krA,
							const TPlane3f& _krB,
							const TPlane3f& _krC);

const TVector3d& GetIntersection(	TVector3d& _rResult,
									const TPlane3d& _krA,
									const TPlane3d& _krB,
									const TPlane3d& _krC);

const TVector3f& GetIntersection(	TVector3f& _rResult,
									const TPlane3f& _krA,
									const TPlane3f& _krB,
									const TPlane3f& _krC);

const TVector3d& GetPolygonNormal(	TVector3d& _rResult,
									const TVector3d* _kpVertices,
									const size_t _kVertexCount);

const TVector3f& GetPolygonNormal(	TVector3f& _rResult,
									const TVector3f* _kpVertices,
									const size_t _kVertexCount);

const double GetInterval(	const TRay3d& _krRay,
							const TPlane3d& _krPlane);

const float GetInterval(	const TRay3f& _krRay,
							const TPlane3f& _krPlane);

const bool IsIntersection(	const TRay3d& _krRay,
							const TPlane3d& _krPlane);

const bool IsIntersection(	const TRay3f& _krRay,
							const TPlane3f& _krPlane);

const TVector3d& GetIntersection(	TVector3d& _rResult,
									const TRay3d& _krRay,
									const TPlane3d& _krPlane);

const TVector3f& GetIntersection(	TVector3f& _rResult,
									const TRay3f& _krRay,
									const TPlane3f& _krPlane);

const bool Intersection(	const TAABB3d& _krAABB,
							const TRay3d& _krRay,
							double& _rdIntervalMin,
							double& _rdIntervalMax);

#endif