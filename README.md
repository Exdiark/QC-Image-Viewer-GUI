Image Viewer GUI for Windows 64 bit systems

=======================================================================================================================================

< -- Setup for Visual Studio -- >

1. Download wxWidgets v 3.2.4 from https://www.wxwidgets.org/downloads/
2. Extract files to some directory (save path)
3. Open vc_17.sln in VS
4. Batch build wxwidgets for all release configs
5. Open Image Viewer in VS (create project from existing code)
6. Open project properties and go to C/C++
7. Under additional include directories, add .../wxWidgets-3.2.4/include and .../wxWidgets-3.2.4/include/msvc
8. Under Linker -> General, add .../wxWidgets-3.2.4/lib/vc_lib and .../wxWidgets-3.2.4/lib/vc_lib_x86 to Additional Library Directories

=======================================================================================================================================