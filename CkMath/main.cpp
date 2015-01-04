//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

#include "util.h"
#include <vector>
#include "math.h"
#include <iostream>
#include "tests.h"
#include <cstdlib>

int main()
{
	std::cout << "Running Tests...\n\n";

	const size_t kTestFuncCount = sizeof(s_kpTestFunctions) / sizeof(TestFuncType);
	for(size_t i = 0; i < kTestFuncCount; ++i)
	{
		std::cout << s_kpTestFunctions[i]();
	}

	getchar();

	return(0);
}