cmake_minimum_required(VERSION 3.20.0)

# wxWidgets_ROOT_DIR      - Base wxWidgets directory
#                           (e.g., C:/wxWidgets-3.2.0).
set(wxWidgets_ROOT_DIR ../)
# wxWidgets_LIB_DIR       - Path to wxWidgets libraries
#                           (e.g., C:/wxWidgets-3.2.0/lib/vc_x64_lib).
set(wxWidgets_LIB_DIR ../lib/vc14x_x64_dll/)
# wxWidgets_CONFIGURATION - Configuration to use
#                           (e.g., msw, mswd, mswu, mswunivud, etc.)
# Configurations
# There are 8 different project configurations (all paths are relative to %WXWIN%):
# Name                      Setup.h Location    Output Files
# Win32 Release             lib\msw\wx          lib\msw.lib
# Win32 Debug               lib\mswd\wx         lib\mswd.lib
# Win32 Release DLL             lib\mswdll\wx       lib\wxmsw240.lib, lib\wxmsw240.exp, lib\wxmsw240.dll
# Win32 Debug DLL               lib\mswdlld\wx      lib\wxmsw240d.lib, lib\wxmsw240d.exp, lib\wxmsw240d.dll
# Win32 Release Unicode     lib\mswu\wx         lib\mswu.lib
# Win32 Debug Unicode       lib\mswud\wx            lib\mswud.lib
# Win32 Release Unicode DLL     lib\mswdllu\wx      lib\wxmsw240u.lib, lib\wxmsw240u.exp, lib\wxmsw240u.dll
# Win32 Debug Unicode DLL       lib\mswdllud\wx     lib\wxmsw240ud.lib, lib\wxmsw240ud.exp, lib\wxmsw240ud.dl
set(wxWidgets_CONFIGURATION mswu)
# wxWidgets_EXCLUDE_COMMON_LIBRARIES
#                         - Set to TRUE to exclude linking of
#                           commonly required libs (e.g., png tiff
#                           jpeg zlib regex expat).
set(wxWidgets_EXCLUDE_COMMON_LIBRARIES TRUE)

find_package(wxWidgets COMPONENTS core base OPTIONAL_COMPONENTS net)

## The following are set after the configuration is done for both windows and unix style:
# wxWidgets_FOUND            - Set to TRUE if wxWidgets was found.
message(${wxWidgets_FOUND})
# wxWidgets_INCLUDE_DIRS     - Include directories for WIN32
#                              i.e., where to find "wx/wx.h" and
#                              "wx/setup.h"; possibly empty for unices.
message(${wxWidgets_INCLUDE_DIRS})
# wxWidgets_LIBRARIES        - Path to the wxWidgets libraries.
message(${wxWidgets_LIBRARIES})
# wxWidgets_LIBRARY_DIRS     - compile time link dirs, useful for
#                              rpath on UNIX. Typically an empty string
#                              in WIN32 environment.
# message(${wxWidgets_LIBRARY_DIRS})
# wxWidgets_DEFINITIONS      - Contains defines required to compile/link
#                              against WX, e.g. WXUSINGDLL
message(${wxWidgets_DEFINITIONS})
# wxWidgets_DEFINITIONS_DEBUG- Contains defines required to compile/link
#                              against WX debug builds, e.g. __WXDEBUG__
message(${wxWidgets_DEFINITIONS_DEBUG})
# wxWidgets_CXX_FLAGS        - Include dirs and compiler flags for
#                              unices, empty on WIN32. Essentially
#                              "`wx-config --cxxflags`".
# message(${wxWidgets_CXX_FLAGS})
# wxWidgets_USE_FILE         - Convenience include file.
message(${wxWidgets_USE_FILE})

project(wx00)

if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()

# include_directories(${PROJECT_SOURCE_DIR}/../include)
# include_directories(${PROJECT_SOURCE_DIR}/../include/msvc)

add_executable(wx00 WIN32 helloworld.cpp)   # Must use WIN32
target_link_libraries(wx00 ${wxWidgets_LIBRARIES})
