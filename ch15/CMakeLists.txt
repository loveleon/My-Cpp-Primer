cmake_minimum_required(VERSION 3.2)
project(ch15)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(./ex15_3)
add_executable(ex15_03 ./ex15_3/main.cpp ./ex15_3/quote.cpp)
