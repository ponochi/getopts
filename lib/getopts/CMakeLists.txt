option(GETOPTS_BUILD_SHARED_LIBS "build getopts as a shared add_library" ON)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--no-undefined")

if (GETOPTS_BUILD_SHARED_LIBS)
  add_library(getopts SHARED getopts.cpp)
else()
  add_library(getopts STATIC getopts.cpp)
endif()

target_sources(getopts
  PRIVATE
  getopts.cpp
)

target_compile_features(getopts
  PRIVATE
  cxx_std_11
)

target_include_directories(getopts
  PUBLIC ${PROJECT_SOURCE_DIR}/include/getopts
)

include(GNUInstallDirs)
install(TARGETS getopts
  ARCHIVE DESTINATION $(CMAKE_INSTALL_LIBDIR)
  LIBRARY DESTINATION $(CMAKE_INSTALL_LIBDIR)
)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING PATTERN "*.hpp"
)

