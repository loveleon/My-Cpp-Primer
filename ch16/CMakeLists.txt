cmake_minimum_required(VERSION 3.2)
project(ch16)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(. ./ex16_1_2_3 ./ex16_4 ./ex16_12_13)

#add_executable(ex16_1_2_3 ./ex16_1_2_3/main.cpp)
add_executable(ex16_4 ./ex16_4/main.cpp)
add_executable(ex16_12_13 ./ex16_12_13/main.cpp)
