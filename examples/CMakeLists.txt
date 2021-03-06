cmake_minimum_required(VERSION 2.6)
project(examples)

include_directories(..)

if (NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type selected, default to Release")
  set(CMAKE_BUILD_TYPE "Release")
endif()

if(UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Werror -pedantic -fno-rtti ")
  message(STATUS "CMAKE_CXX_COMPILER_VERSION = ${CMAKE_CXX_COMPILER_VERSION}")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG ")
  set(CMAKE_CXX_FLAGS_RELWITHDEBINFO  "-O2 -g -DNDEBUG")
  set(CMAKE_CXX_FLAGS_DEBUG  "-O0 -g")
elseif(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /GR- /W3 /wd4503 /wd4307 /EHsc /D_CRT_SECURE_NO_WARNINGS /D_SCL_SECURE_NO_WARNINGS")
  set(CMAKE_CXX_FLAGS_RELEASE "/O2 /DNDEBUG")
  set(CMAKE_CXX_FLAGS_DEBUG  "/Od /D_DEBUG")
  set(CMAKE_CXX_FLAGS_RELWITHDEBINFO  "/Yd /O2 /DNDEBUG")
else(UNIX)

endif(UNIX)

add_subdirectory(testing)
add_subdirectory(aop)
