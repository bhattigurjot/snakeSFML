workspace "snakeSFML"
    startproject "snakeSFML"
    architecture "x64"

    configurations { "Debug", "Release" } 

tdir = "bin/%{cfg.buildcfg}/%{prj.name}"
odir = "bin_obj/%{cfg.buildcfg}/%{prj.name}"

-- External Dependencies
externals = {}
externals["SFML"] = "external/SFML"

project "snakeSFML"
    location "snakeSFML"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    targetdir(tdir)
    objdir(odir)
    files 
    {
        "%{prj.name}/include/**.h",
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp"
    }
    sysincludedirs 
    { 
        "%{externals.SFML}/include"
    }
    includedirs 
    { 
        "%{prj.name}/include"
    }
    flags { "FatalWarnings" }
    filter { "system:windows", "configurations:*" }
        systemversion "latest"
        defines { "SNAKESFML_PLATFORM_WINDOWS", "SFML_STATIC"}
        libdirs { "%{externals.SFML}/lib" }
        links { "opengl32.lib", "freetype.lib", "winmm.lib", "gdi32.lib", "openal32.lib", "flac.lib", "vorbisenc.lib", "vorbisfile.lib", "vorbis.lib", "ogg.lib", "ws2_32.lib" }
    filter { "system:linux", "configurations:*" }
        defines { "SNAKESFML_PLATFORM_LINUX"}
    filter { "system:macosx", "configurations:*" }
        xcodebuildsettings 
        {
            ["MACOSX_DEPLOYMENT_TARGET"] = "10.15",
            ["UseModernBuildSystem"] = "NO "
        }
        defines { "SNAKESFML_PLATFORM_MAC "}
    filter { "configurations:Debug" }
        defines { "SNAKESFML_CONFIG_DEBUG"}
        links { "sfml-audio-s-d.lib", "sfml-graphics-s-d.lib", "sfml-network-s-d.lib", "sfml-system-s-d.lib", "sfml-window-s-d.lib" }
        runtime "Debug"
        symbols "on"
    filter { "configurations:Release" }
        defines { "SNAKESFML_CONFIG_RELEASE"}
        links { "sfml-audio-s.lib", "sfml-graphics-s.lib", "sfml-network-s.lib", "sfml-system-s.lib", "sfml-window-s.lib" }
        runtime "Release"
        symbols "off"
        optimize "on"
    