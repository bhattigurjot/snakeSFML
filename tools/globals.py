import sys, platform
import enum

ENGINE_NAME = "snakeSFML"
PROJECT_NAME = "snakeSFML"
VERSION_MAJOR = 1
VERSION_MINOR = 0

class Platform_Type(enum.Enum):
    WINDOWS = "windows"
    LINUX = "linux"
    MAC = "darwin"

class Build_Type(enum.Enum):
    DEBUG = "Debug"
    RELEASE = "Release"

PLATFORM = sys.platform
CONFIG = Build_Type.DEBUG.value

for x in platform.uname():
    if "windows" in x.lower():
        PLATFORM = Platform_Type.WINDOWS
        break

def is_windows():
    return PLATFORM == Platform_Type.WINDOWS

def is_linux():
    return PLATFORM == Platform_Type.LINUX

def is_mac():
    return PLATFORM == Platform_Type.MAC
