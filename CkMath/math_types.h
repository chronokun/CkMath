//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

#pragma once

#ifndef __MATH_TYPES_H__
#define __MATH_TYPES_H__

//
//
// Enums
//
//

enum EVectorComponent
{
	COMPONENT_X = 0,
	COMPONENT_Y = 1,
	COMPONENT_Z = 2,
	COMPONENT_W = 3
};

enum EIntersections
{
	INTERSECTION_NOINTERSECT = 0,
	INTERSECTION_ONE = 1,
	INTERSECTION_TWO = 2
};


//
//
// Struct Prototypes
//
//

//
// Vector
//
struct TVector4d
{
	union
	{
		struct
		{
			double m_dX;
			double m_dY;
			double m_dZ;
			double m_dW;
		};
		double m_dV[4];
	};
};

struct TVector4f
{
	union
	{
		struct
		{
			float m_fX;
			float m_fY;
			float m_fZ;
			float m_fW;
		};
		float m_fV[4];
	};
};

struct TVector3d
{
	union
	{
		struct
		{
			double m_dX;
			double m_dY;
			double m_dZ;
		};
		double m_dV[3];
	};
};

struct TVector3f
{
	union
	{
		struct
		{
			float m_fX;
			float m_fY;
			float m_fZ;
		};
		float m_fV[3];
	};
};

struct TVector2d
{
	union
	{
		struct
		{
			double m_dX;
			double m_dY;
		};
		double m_dV[2];
	};
};

struct TVector2f
{
	union
	{
		struct
		{
			float m_fX;
			float m_fY;
		};
		float m_fV[2];
	};
};

//
// Matrix
//
struct TMatrix4d
{
	union
	{
		TVector4d m_Columns[4];
		double m_dItems[4][4];
	};
};

struct TMatrix4f
{
	union
	{
		TVector4f m_Columns[4];
		float m_fItems[4][4];
	};
};

struct TMatrix3d
{
	union
	{
		TVector3d m_Columns[3];
		double m_dItems[3][3];
	};
};

struct TMatrix3f
{
	union
	{
		TVector3f m_Columns[3];
		float m_fItems[3][3];
	};
};

struct TMatrix2d
{
	union
	{
		TVector2d m_Columns[2];
		double m_dItems[2][2];
	};
};

struct TMatrix2f
{
	union
	{
		TVector2f m_Columns[2];
		float m_fItems[2][2];
	};
};

//
// Plane
//
struct TPlane3d
{
	TVector3d m_Point;
	TVector3d m_Normal;
};

struct TPlane3f
{
	TVector3f m_Point;
	TVector3f m_Normal;

};

struct TPlane2d
{
	TVector2d m_Point;
	TVector2d m_Normal;
};

struct TPlane2f
{
	TVector2f m_Point;
	TVector2f m_Normal;
};

//
// Triangle
//
struct TTriangle3d
{
	union
	{
		struct
		{
			TVector3d m_A;
			TVector3d m_B;
			TVector3d m_C;
		};
		TVector3d m_V[3];
	};
};

struct TTriangle3f
{
	union
	{
		struct
		{
			TVector3f m_A;
			TVector3f m_B;
			TVector3f m_C;
		};
		TVector3f m_V[3];
	};
};

struct TTriangle2d
{
	union
	{
		struct
		{
			TVector2d m_A;
			TVector2d m_B;
			TVector2d m_C;
		};
		TVector2d m_V[3];
	};
};

struct TTriangle2f
{
	union
	{
		struct
		{
			TVector2f m_A;
			TVector2f m_B;
			TVector2f m_C;
		};
		TVector2f m_V[3];
	};
};

//
// Line
//
struct TLine3d
{
	TVector3d m_A;
	TVector3d m_B;
};

struct TLine3f
{
	TVector3f m_A;
	TVector3f m_B;
};

struct TLine2d
{
	TVector2d m_A;
	TVector2d m_B;
};

struct TLine2f
{
	TVector2f m_A;
	TVector2f m_B;
};

//
// Ray
//
struct TRay3d
{
	TVector3d m_Start;
	TVector3d m_Direction;
};

struct TRay3f
{
	TVector3f m_Start;
	TVector3f m_Direction;
};

struct TRay2d
{
	TVector2d m_Start;
	TVector2d m_Direction;
};

struct TRay2f
{
	TVector2f m_Start;
	TVector2f m_Direction;
};

//
// Sphere
//
struct TSphere3d
{
	TVector3d m_Center;
	double m_dRadius;
};

struct TSphere3f
{
	TVector3f m_Center;
	float m_fRadius;
};

//
// Circle
//
struct TCircle2d
{
	TVector2d m_Center;
	double m_dRadius;
};

struct TCircle2f
{
	TVector2f m_Center;
	float m_fRadius;
};

//
// Capsule
//
struct TCapsule3d
{
	TLine3d m_Line;
	double m_dRadius;
};

struct TCapsule3f
{
	TLine3f m_Line;
	float m_fRadius;
};

struct TCapsule2d
{
	TLine2d m_Line;
	double m_dRadius;
};

struct TCapsule2f
{
	TLine2f m_Line;
	float m_fRadius;
};

//
// AABB
//
struct TAABB3d
{
	TVector3d m_MinPoint;
	TVector3d m_MaxPoint;
};

struct TAABB3f
{
	TVector3f m_MinPoint;
	TVector3f m_MaxPoint;
};

struct TAABB2d
{
	TVector2d m_MinPoint;
	TVector2d m_MaxPoint;
};

struct TAABB2f
{
	TVector2f m_MinPoint;
	TVector2f m_MaxPoint;
};

#endif