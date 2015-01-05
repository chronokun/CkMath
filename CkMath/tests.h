//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

#pragma once

#ifndef __TESTS_H__
#define __TESTS_H__

// Local Includes
#include "tests_vector.h"

// Typedefs
typedef const bool (*TestFuncType)(void);

// Structs
struct TFuncStrPair
{
	TestFuncType m_pFuncPtr;
	const char* m_kpcStr;
};
#define TEST(f) {f, #f}
static const TFuncStrPair s_kTestFunctions[] = {
	TEST(Test_Vector_ZeroVector),
	TEST(Test_Vector_ZeroVector),
	TEST(Test_Vector_Equal),
	TEST(Test_Vector_Add),
	TEST(Test_Vector_Subtract),
	TEST(Test_Vector_ScalarMultiply),
	TEST(Test_Vector_VectorMagnitude)
};

#endif