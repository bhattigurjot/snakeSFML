import globals
import os, subprocess, sys, pathlib

BIN_PATH = "{}\\bin".format(os.getcwd()) 
BIN_OBJ_PATH = "{}\\bin_obj".format(os.getcwd())
FILES_EXTENSIONS = (".vcxproj", ".sln")

ret = -1

def delete_dir(dir):
    return subprocess.call(["cmd.exe", "/c", 'rmdir', '/s', '/q', dir])

def delete_file(filePath):
    return subprocess.call(["cmd.exe", "/c", 'del', filePath])

def delete_project_files():
    err = -1
    for filepath in pathlib.Path(os.getcwd()).glob('**/*'):
        s = filepath.absolute().__str__()
        if s.endswith(FILES_EXTENSIONS):
            err = delete_file(s)
    return err

if globals.is_windows():
    ret = delete_dir(BIN_PATH)
    ret = delete_dir(BIN_OBJ_PATH)
    delete_project_files()

if globals.is_linux():
    # ret = subprocess.call(["{}/{}".format(EXEC_PATH, globals.PROJECT_NAME)])
    raise NotImplementedError("No linux implementation available")

if globals.is_mac():
    # ret = subprocess.call(["{}/{}".format(EXEC_PATH, globals.PROJECT_NAME)])
    raise NotImplementedError("No mac implementation available")

sys.exit(0)