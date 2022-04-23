import globals
import subprocess, sys

ret = -1

if globals.is_windows():
    ret = subprocess.call(["cmd.exe", "/c", "premake\\premake5", "vs2022"])
    
if globals.is_linux():
    ret = subprocess.call(["premake/premake5.linux", "gmake2"])

if globals.is_linux():
    ret = subprocess.call(["premake/premake5", "gmake2"])
    if ret == 0:
        subprocess.call(["premake/premake5", "xcode4"])

sys.exit(ret)