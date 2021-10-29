
workspace "GeekPizza"
	architecture "x64"

configurations{
"Debug",
"Release"
}
outputDirectory = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--ENGINE-///////////////////////////////////////////////////

project "GeekPizza"
	location "GeekPizza" --Choose folder GeekPizza
	kind "SharedLib" --dynamic library specification (engine)
	language "C++"
	targetdir ("bin/" .. outputDirectory .. "/%{prj.name}") -- .. var .. == appending
	objdir ("bin-int/" .. outputDirectory .. "/%{prj.name}") -- obj files

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"
	}

	includedirs 
	{
		"%{prj.name}/thirdParty/spdlog/include"
	}
	
	-- filters are for platform bound configurations
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines
		{
			"GP_PLATFORM_WINDOWS",
			"GP_BUILD_DLL",
			"SPDLOG_COMPILED_LIB"
		}
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDirectory .. "/testGame") --relpath == relative path
		}

		filter "configurations:Debug"
			defines "GP_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "GP_RELEASE"
			optimize "On"


			--example of system platform and configuration specification filter
	--	filter { "system:windows", "configurations:Release"}
		--	buildoptions "/MT"
--ENDOFENGINE---------------------------------------------------

--APP///////////////////////////////////////////////////
project "testGame"
		location "testGame"
		kind "ConsoleApp"
		language "C++"

	targetdir ("bin/" .. outputDirectory .. "/%{prj.name}") -- .. var .. == appending
	objdir ("bin-int/" .. outputDirectory .. "/%{prj.name}") -- obj files

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"
	}

	includedirs
	{
		"GeekPizza/thirdParty/spdlog/include", 
		"GeekPizza" --proj name here is "testGame" so type GeekPizza instead of %{prj.name}
	}
	links
	{
		"GeekPizza"
	}
	
	-- filters are for platform bound configurations
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines
		{
			"GP_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "GP_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "GP_RELEASE"
			optimize "On"


