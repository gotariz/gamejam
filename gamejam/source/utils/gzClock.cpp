#include "gzClock.h"

gzClock::gzClock()
{
	old_time = clock();
}

float gzClock::getCurrentTimeSeconds()
{
	return static_cast<float>(clock()) / static_cast<float>(CLOCKS_PER_SEC);
}

unsigned gzClock::getCurrentTimeMilliseconds()
{
	return (static_cast<float>(clock()) / static_cast<float>(CLOCKS_PER_SEC)) * 1000.f;
}








