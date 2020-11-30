#pragma once

#include "Rogue/Core.h"

namespace Rogue
{
	class ROGUE_API MessageLog
	{
	public:
		MessageLog();
		~MessageLog();

		void Log(const char* msg);
	};
}
