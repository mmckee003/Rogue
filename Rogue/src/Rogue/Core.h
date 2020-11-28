#pragma once

#ifdef ROGUE_PLATFORM_WINDOWS
	#ifdef ROGUE_BUILD_DLL
		#define ROGUE_API __declspec(dllexport)
	#else
		#define ROGUE_API __declspec(dllimport)
	#endif
#else
	#error Rogue only supports Windows!
#endif

#define BIT(x) (1 << x)