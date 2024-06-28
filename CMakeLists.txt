cmake_minimum_required(VERSION 3.20)

project(libgetopts
  VERSION 0.0.1
  DESCRIPTION "getopts project"
  LANGUAGES CXX
)

# Build guard in-source
if(${CMAKE_SOURCE_DIR} STREQUAL $(CMAKE_BINARY_DIR))
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif()

# Build getopts
#include(FetchContent)
#FetchContent_Declare(
#  getopts
#  GIT_REPOSITORY https://github.com/ponochi/getopts.git
#  GIT_TAG        origin/main
#)

#FetchContent_MakeAvailable(getopts)
# FetchContent_GetProperties(getopts)
# if(NOT getopts_POPULATED)
#   FetchContent_Populate(getopts)
#   add_subdirectory(${getopts_SOURCE_DIR} ${getopts_BINARY_DIR})
# endif()

add_subdirectory(lib/getopts/)
