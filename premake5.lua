workspace "Rabbit"
    architecture "x64"
    startproject "Sandbox"
    
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Rabbit"
    location "Rabbit"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    buildoptions { "/utf-8" }
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "RB_PLATFORM_WINDOWS",
            "RB_BUILD_DLL"
        }
        
        postbuildcommands
        {
            ("{MKDIR} ../bin/" .. outputdir .. "/Sandbox"),
            ("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/")
        }
    
    filter "configurations:Debug"
        defines "RB_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "RB_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "RB_DIST"
        optimize "On"

    

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    buildoptions { "/utf-8" }
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Rabbit/vendor/spdlog/include",
        "Rabbit/src"
    }

    links
    {
        "Rabbit"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "RB_PLATFORM_WINDOWS"
        }
        
    filter "configurations:Debug"
        defines "RB_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "RB_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "RB_DIST"
        optimize "On"

    filter {"system:windows", "configurations:Release"}