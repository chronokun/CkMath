#include <Windows.h>
#include <cstdint>
#include <vector>
#include <cstdlib>
#include "math.h"
#include <iostream>

static int64_t s_TicksPerSecond;
static int64_t s_StartTicks;
static int64_t s_StopTicks;

static double s_dTicksPerSecond;

void InitTimer()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&s_TicksPerSecond);

	s_dTicksPerSecond = (double)s_TicksPerSecond;
}

void StartTimer()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&s_StartTicks);
}

void StopTimer()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&s_StopTicks);
}

double GetTime()
{
	return((double)(s_StopTicks - s_StartTicks) / s_dTicksPerSecond);
}

const double Random(const double _kdMin, const double _kdMax)
{
	const double kdValue = (double)rand() / (double)RAND_MAX;
	const double kdScale = _kdMax - _kdMin;
	const double kdResult = _kdMin + (kdValue * kdScale);
	return(kdResult);
}

static const size_t s_kInputSize = 10000000;

int main()
{
	InitTimer();

	std::vector<TVector4d> InputA(s_kInputSize);
	std::vector<TVector4d> InputB(s_kInputSize);

	std::vector<TVector4d> Output(s_kInputSize);

	for(size_t i = 0; i < s_kInputSize; ++i)
	{
		for(size_t j = 0; j < 4; ++j)
		{
			InputA[i].m_dV[j] = Random(-1.0, 1.0);
			InputB[i].m_dV[j] = Random(-1.0, 1.0);
		}
	}

	StartTimer();
	for(size_t i = 0; i < s_kInputSize; ++i)
	{
		Output[i] = math::Add(Output[i], InputA[i], InputB[i]);
	}
	StopTimer();

	double dMax = -2.0;
	for(size_t i = 0; i < s_kInputSize; ++i)
	{
		for(size_t j = 0; j < 4; ++j)
		{
			if(Output[i].m_dV[j] > dMax)
			{
				dMax = Output[i].m_dV[j];
			}
		}
	}

	const double kdTime = GetTime();

	std::cout << kdTime * 1000.0 << std::endl;

	return(0);
}