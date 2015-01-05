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
typedef const char* (*TestFuncType)(void);

static const TestFuncType s_kpTestFunctions[] = {
	Test_Vector_ZeroVector,
	Test_Vector_Equal,
	Test_Vector_Add
};

#endif