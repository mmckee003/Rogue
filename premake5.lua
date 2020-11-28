workspace "Rogue"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder --
IncludeDir = {}
IncludeDir["GLFW"] = "Rogue/vendor/GLFW/include"

-- Includes GLFW premake5.lua
include "Rogue/vendor/GLFW"

project "Rogue"
	location "Rogue"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "roguepch.h"
	pchsource "Rogue/src/roguepch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}
	
	links {
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"ROGUE_PLATFORM_WINDOWS",
			"ROGUE_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
			defines "ROGUE_DEBUG"
			symbols "On"

	filter "configurations:Release"
			defines "ROGUE_RELEASE"
			optimize "On"

	filter "configurations:Dist"
			defines "ROGUE_DIST"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Rogue/vendor/spdlog/include",
		"Rogue/src"
	}

	links{
		"Rogue"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"ROGUE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
			defines "ROGUE_DEBUG"
			symbols "On"

	filter "configurations:Release"
			defines "ROGUE_RELEASE"
			optimize "On"

	filter "configurations:Dist"
			defines "ROGUE_DIST"
			optimize "On"