cmake_minimum_required (VERSION 2.6)
project (Tutorial)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
    "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

# add the binary tree to the search path for include files so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# cmake xx -DUSE_MMATH=ON
option(USE_MMATH
       "Use tutorial provided math implementation" ON)

if (USE_MMATH)
    include_directories("{PROJECT_SOURCE_DIR}/include")
    add_subdirectory (include)
    set (EXTRA_LIBS ${EXTRA_LIBS} MMath)
endif (USE_MMATH)

add_executable (Tutorial hello.cpp)
target_link_libraries (Tutorial ${EXTRA_LIBS})

# set install path
# same as
# cmake -DCMAKE_INSTALL_PREFIX=.
set (CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR})

install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
         DESTINATION include)
