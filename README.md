# skeletonCPP
This is a skeleton Premake project for C++ and SFML.
Make sure to update name of the project in following places:
- tools/version.py
- tools/globals.py
- premake5.lua

NOTE: Make sure to add premake5.exe (download from premake website) to premake folder if it is not there

(Windows) To use project, run commands in terminal :
- To generate solution: `cli.bat gensln`
- To build: `cli.bat build`
- To run: `cli.bat run`
- You can also combine all of them: `cli.bat gensln build run`

##Add SFML static libraries to external directory.
- include/SFML/{all sfml headers}
- lib/{all static libs}

##To compile SFML for static libs:
- Download 'SourceCode' from https://www.sfml-dev.org/download.php
- Download cmake from https://cmake.org/download/
- Open cmake-gui
- Select source code folder for sfml
- Select build binaries folder
- Unselect BUILD_SHARED_LIBS
- Select SFML_USE_STATIC_STD_LIBS
- Select other SFML_BUILD_{xx} for whatever you need
- Press Configure, select the generator for the project (VS for example)
- After making sure there are no errors, press Generate
- Open VS solution project, build all
- Files will be generated in lib/{Debug/Release} folder(s) 
