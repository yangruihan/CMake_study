cmake_minimum_required (VERSION 2.6)
project (Tutorial)
include (CTest)
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# set install path
# same as
# cmake -DCMAKE_INSTALL_PREFIX=.
set (CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR})

# dose this system provide the log and exp functions
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)

# cmake xx -DUSE_MMATH=ON
option(USE_MMATH
       "Use tutorial provided math implementation" ON)

# configure a header file to pass some of the CMake settings to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
    "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

# add the binary tree to the search path for include files so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

if (USE_MMATH)
    include_directories("{PROJECT_SOURCE_DIR}/include")
    add_subdirectory (include)
    set (EXTRA_LIBS ${EXTRA_LIBS} MMath)
endif (USE_MMATH)

add_executable (Tutorial hello.cpp)
target_link_libraries (Tutorial ${EXTRA_LIBS})

install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
         DESTINATION include)

# use `make test` to active test case
add_test (TutorialRuns Tutorial)

# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include (CPack)
