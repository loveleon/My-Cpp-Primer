cmake_minimum_required(VERSION 3.2)
project(ch18)

include_directories(.)

set(CMAKE_CXX_STANDARD  11)
SET(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE  "$ENV{CXXFLAGS} -O3 -Wall")

#excuable
add_executable(ex18_3 ex18_3.cpp)