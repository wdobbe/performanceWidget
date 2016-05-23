project(performanceWidget)

cmake_minimum_required(VERSION 3.2)

#Pretty colors
SET(CMAKE_COLOR_MAKEFILE ON)

get_property(LIB64 GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS)
if ("${LIB64}" STREQUAL "TRUE")
    set(LIBSUFFIX 64)
else()
    set(LIBSUFFIX "")
endif()

#Set Qt config and find required Qt libraries
#Qt5 versions earlier than 5.5.1 might work, but this is untested
SET (QT_MIN_VERSION "5.5.0")

if ( NOT QT_PREFIX )
    find_package(Qt5Core ${QT_MIN_VERSION} REQUIRED NO_CMAKE_ENVIRONMENT_PATH NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
    find_package(Qt5Gui ${QT_MIN_VERSION} REQUIRED NO_CMAKE_ENVIRONMENT_PATH NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
    find_package(Qt5Widgets ${QT_MIN_VERSION} REQUIRED NO_CMAKE_ENVIRONMENT_PATH NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
else ()
    SET(CMAKE_PREFIX_PATH "${QT_PREFIX}/lib${LIBSUFFIX}/cmake")
    message(STATUS "QT_PREFIX has been set, will look for Qt in directory ${CMAKE_PREFIX_PATH}")
    find_package(Qt5Core ${QT_MIN_VERSION} REQUIRED)
    find_package(Qt5Gui  ${QT_MIN_VERSION} REQUIRED)
    find_package(Qt5Widgets ${QT_MIN_VERSION} REQUIRED)
    get_target_property(QtCore_location Qt5::Core LOCATION)
    message(STATUS "Qt at custom location: ${QtCore_location} will be used." )
endif()

# Find includes in corresponding build directories (necessary for Qt)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOMOC_RELAXED_MODE ON)
set(CMAKE_AUTORCC ON)

if (CMAKE_HOST_UNIX OR MINGW)
    set( CMAKE_THREAD_PREFER_PTHREAD TRUE )
    find_package(Threads REQUIRED )
    set( GCC_EXTRA_COMPILE_OPTIONS "${GCC_EXTRA_COMPILE_OPTIONS} -pthread" )
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # Strict standard, no compiler specific extensions

# Set compiler dependent compile options
if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    # using Clang, AppleClang or g++
    if (NOT CMAKE_HOST_WIN32)
        set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
    endif()
    if( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug" )
        set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0" )
    endif()
endif()

if (MSVC)
    #suppress suggestion to use checked iterators, because they are a Microsoft extension
    #also suppress suggestion to use strcpy_s because it is Microsoft specific
    add_definitions(-D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_WARNINGS)
endif()

add_subdirectory(dataQuery)
add_subdirectory(painters)
add_subdirectory(widgets)

qt5_wrap_ui(PERFWIDGET_MAINWIN_UI mainwindow.ui)
add_executable(oswidget ${PERFWIDGET_MAINWIN_UI} main.cpp mainwindow.cpp)
target_link_libraries(oswidget perfwidgets perfpainters perfdataquery Qt5::Core Qt5::Widgets)

message( "=> PerformanceWidget configure done. Run 'make' to start building....")

