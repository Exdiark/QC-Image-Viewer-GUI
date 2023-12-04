
# Image Viewer GUI for Windows 32/64 bit systems

_________________

## < -- Setup for Visual Studio -- >

1. Download [wxWidgets v 3.2.4](https://www.wxwidgets.org/downloads/"wxWidgetsv3.2.4")
2. Extract files to some directory (save path)
3. Open vc_17.sln in VS
4. Batch build wxwidgets for all release configs
5. Open Image Viewer in VS (create project from existing code)
6. Open project properties and go to C/C++ -> General -> Additional Include Directories, add .../wxWidgets-3.2.4/include and .../wxWidgets-3.2.4/include/msvc
7. Under Linker -> General -> Additional Library Directories, add .../wxWidgets-3.2.4/lib/vc_lib and .../wxWidgets-3.2.4/lib/vc_x64_lib
	(Note: You may have to remove vc_x64_lib for x86 configuration)
8. Under Configuration Properties -> Advanced -> Character Set, Use Unicode Character Set
_________________