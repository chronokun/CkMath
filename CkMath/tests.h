//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

#pragma once

#ifndef __TESTS_H__
#define __TESTS_H__

// Local Includes
#include "tests_vector.h"
#include "tests_matrix.h"
#include "tests_quaternion.h"

// Typedefs
typedef const bool (*TestFuncType)(void);

// Structs
struct TFuncStrPair
{
	TestFuncType m_pFuncPtr;
	const char* m_kpcStr;
};

// Macros
#define TEST(f) {f, #f}

// Constants
static const TFuncStrPair s_kTestFunctions[] = {
	TEST(Test_Vector_ZeroVector),
	TEST(Test_Vector_ZeroVector),
	TEST(Test_Vector_Equal),
	TEST(Test_Vector_Add),
	TEST(Test_Vector_Subtract),
	TEST(Test_Vector_ScalarMultiply),
	TEST(Test_Vector_VectorMagnitude),
	TEST(Test_Vector_DotProduct),
	TEST(Test_Vector_CrossProduct),
	TEST(Test_Vector_Normalize),
	TEST(Test_Vector_Projection),
	TEST(Test_Vector_AngleBetween),
	TEST(Test_Vector_Distance),
	TEST(Test_Vector_ScalarTripleProduct),
	TEST(Test_Vector_VectorTripleProduct),

	TEST(Test_Matrix_Equal),
	TEST(Test_Matrix_ZeroMatrix),
	TEST(Test_Matrix_IdentityMatrix),
	TEST(Test_Matrix_Multiply),
	TEST(Test_Matrix_ScalarMultiply),
	TEST(Test_Matrix_VectorMultiply),
	TEST(Test_Matrix_Add),
	TEST(Test_Matrix_Transpose),
	TEST(Test_Matrix_GetElement),
	TEST(Test_Matrix_SetElement),
	TEST(Test_Matrix_Submatrix),
	TEST(Test_Matrix_FirstMinor),
	TEST(Test_Matrix_MatrixOfMinors),
	TEST(Test_Matrix_Determinant),
	TEST(Test_Matrix_Inverse),
	TEST(Test_Matrix_TranslationMatrix),
	TEST(Test_Matrix_ScalingMatrix),
	TEST(Test_Matrix_TransformationMatrix),
	TEST(Test_Matrix_RotationMatrix),
	TEST(Test_Matrix_AxisRotationMatrix),
	TEST(Test_Matrix_PerspectiveMatrix),
	TEST(Test_Matrix_OrthographicMatrix),

	TEST(Test_Quaternion_IdentityQuaternion)
};

#endif