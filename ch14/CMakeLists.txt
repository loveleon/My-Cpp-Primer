cmake_minimum_required(VERSION 3.2)
project(ch14)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")

set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
add_executable(ex14_2 ex14_2.cpp ex14_2_test.cpp)
#add_executable(ex14_5 ex14_5.cpp ex14_5_test.cpp)
add_executable(ex14_7 ex14_7.cpp ex14_7_test.cpp)

