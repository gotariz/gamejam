#pragma once

#include <time.h>

class gzClock
{
	public:
		gzClock();
		virtual ~gzClock(){}

		float		getCurrentTimeSeconds();
		unsigned	getCurrentTimeMilliseconds();

	protected:
		clock_t old_time;
};

