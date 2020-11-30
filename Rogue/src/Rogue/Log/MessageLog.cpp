#include "roguepch.h"

#include "MessageLog.h"

namespace Rogue
{
	MessageLog::MessageLog()
	{

	}

	MessageLog::~MessageLog()
	{

	}

	void MessageLog::Log(const char* msg)
	{
		std::cout << msg << "\n";
	}
}