import globals
import os, subprocess, sys

EXEC_PATH = "{}/bin/{}/{}".format(os.getcwd(), globals.CONFIG, globals.PROJECT_NAME) 

ret = -1

if globals.is_windows():
    ret = subprocess.call(["{}/{}".format(EXEC_PATH, globals.PROJECT_NAME)])

if globals.is_linux():
    # ret = subprocess.call(["{}/{}".format(EXEC_PATH, globals.PROJECT_NAME)])
    raise NotImplementedError("No linux implementation available")

if globals.is_mac():
    # ret = subprocess.call(["{}/{}".format(EXEC_PATH, globals.PROJECT_NAME)])
    raise NotImplementedError("No mac implementation available")

sys.exit(0)