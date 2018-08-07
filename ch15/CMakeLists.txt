cmake_minimum_required(VERSION 3.2)
project(ch15)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(./ex15_3 ./ex15_5 ./ex15_7 ./ex15_9)
#add_executable(ex15_03 ./ex15_3/main.cpp ./ex15_3/quote.cpp)
#add_executable(ex15_05 ./ex15_5/main.cpp ./ex15_5/quote.cpp ./ex15_5/bulk_quote.cpp)
add_executable(ex15_07 ./ex15_7/main.cpp ./ex15_7/quote.cpp ./ex15_7/bulk_quote.cpp ./ex15_7/limit_quote.cpp)
add_executable(ex15_09 ./ex15_9/main.cpp ./ex15_9/quote.cpp ./ex15_9/bulk_quote.cpp ./ex15_9/limit_quote.cpp)
