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

#ifdef ROGUE_ENABLE_ASSERTS
	#define ROGUE_ASSERT(x, ...) { if(!(x)) { ROGUE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ROGUE_CORE_ASSERT(x, ...) { if(!(x)) { ROGUE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ROGUE_ASSERT(x, ...)
	#define ROGUE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)