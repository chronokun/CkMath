//
//	Author:	Michael Cameron
//	Email:	chronokun@hotmail.com
//

#pragma once

#ifndef __UTIL_H__
#define __UTIL_H__


#include <Windows.h>
#include <cstdint>
#include <cstdlib>

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

const float Random(const float _kfMin, const float _kfMax)
{
	const float kfValue = (float)rand() / (float)RAND_MAX;
	const float kfScale = _kfMax - _kfMin;
	const float kfResult = _kfMin + (kfValue * kfScale);
	return(kfResult);
}

#endif