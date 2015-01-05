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

	TEST(Test_Matrix_Equal)
};

#endif