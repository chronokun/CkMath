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

	const size_t kTestFuncCount = sizeof(s_kTestFunctions) / sizeof(TFuncStrPair);
	size_t PassCount{0};
	for(size_t i{0}; i < kTestFuncCount; ++i)
	{
		if(s_kTestFunctions[i].m_pFuncPtr())
		{
			std::cout << "__PASS__ ";
			PassCount++;
		}
		else
		{
			std::cout << "!!FAIL!! ";
		}
		std::cout << s_kTestFunctions[i].m_kpcStr << std::endl;
	}

	std::cout << "\n\n" << (kTestFuncCount - PassCount) << " tests failed." << std::endl;

	getchar();

	return(0);
}