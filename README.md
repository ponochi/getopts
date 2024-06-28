GetOpts is linux getopt like command line arguments parser.
---
Simple command line argumens perser.

Language: C++

Install:
```
git clone git@github.com:ponochi/getopts.git <new project name>
```
or
```
cd [project name]
git submodule add https://github.com/ponochi/getopts.git
```

Include GetOpts:
```main.cpp:c++
int main(int argc, char** argv) {
  GetOpts *go = new GetOpts();

  std::vector<std::array<std::string, 2>> longOpts;
  std::vector<std::array<std::string, 2>> shortOpts;

  go->parseArgs(argc, argv);

  longOpts  = go->getLongOpts();
  shortOpts = go->getShortOpts();

  for (const auto& elem : longOpts)
  {
       std::cout << elem[0] << " " << elem[1] << std::endl;
  }
  
  for (const auto& elem : shortOpts)
  {
       std::cout << elem[0] << " " << elem[1] << std::endl;
  }

  delete go;

  return 0;
}
```

Sample <PROJECT_ROOT_DIR>/CMakeLists.txt
```CMakeLists.txt:cmake
cmake_minimum_required(VERSION 3.20)

project(layd
  VERSION 0.0.1
  DESCRIPTION "layd project"
  LANGUAGES CXX
)

# Build guard in-source
if(${CMAKE_SOURCE_DIR} STREQUAL $(CMAKE_BINARY_DIR))
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif()

include_directories(include)

add_executable(layd layd.cpp
               common/utils.cpp
               common/info.cpp)

add_subdirectory(getopts)
add_subdirectory(common)

target_link_libraries(layd PRIVATE getopts)
```

Build:
```
mkdir -p build
cd ./build
cmake ..
make
```

Usage app include GetOpts:
```
$ ./app --opt1 <value1> --opt2 -abc <value>
$ ./app -abc <value> --opt1 --opt2
$ ./app --opt1 <value1> -abc --opt2
```

History:
  Ver.0.0.1     <2024/06/28>
