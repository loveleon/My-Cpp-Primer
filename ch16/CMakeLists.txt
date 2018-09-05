cmake_minimum_required(VERSION 3.2)
project(ch16)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(. ./ex16_1_2_3 ./ex16_4 ./ex16_12_13 ./ex16_14_15 ./ex16_16 ./ex16_19_20 ./ex16_21_22
                    ./ex16_24 ./ex16_28 ./ex16_29)

#add_executable(ex16_1_2_3 ./ex16_1_2_3/main.cpp)
#add_executable(ex16_4 ./ex16_4/main.cpp)
#add_executable(ex16_12_13 ./ex16_12_13/main.cpp)
#add_executable(ex16_14_15 ./ex16_14_15/main.cpp)
#add_executable(ex16_16 ./ex16_16/main.cpp)
add_executable(ex16_19 ./ex16_19_20/main.cpp)

aux_source_directory(./ex16_21_22/ SRC_EX16_21)
add_executable(ex16_21 ${SRC_EX16_21})

aux_source_directory(./ex16_24 SRC_EX16_24)
add_executable(ex16_24 ${SRC_EX16_24})

aux_source_directory(./ex16_28 SRC_EX16_28)
add_executable(ex16_28 ${SRC_EX16_28})

aux_source_directory(./ex16_29 SRC_EX16_29)
add_executable(ex16_29 ${SRC_EX16_29})
