import globals
import os, subprocess, sys

ret = -1

if globals.is_windows():
    BUILD_PATH = "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\Msbuild\\Current\\Bin\\MSBuild.exe" 

    ret = subprocess.call(["cmd.exe", "/c", BUILD_PATH, "{}.sln".format(globals.ENGINE_NAME), "/property:Configuration={}".format(globals.CONFIG)])

if globals.is_linux():
    # ret = subprocess.call(["make", "config={}".format(globals.CONFIG)])
    raise NotImplementedError("No linux implementation available")

if globals.is_mac():
    # ret = subprocess.call(["make", "config={}".format(globals.CONFIG)])
    raise NotImplementedError("No mac implementation available")

sys.exit(ret)