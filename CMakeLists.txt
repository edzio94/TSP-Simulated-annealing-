cmake_minimum_required(VERSION 3.6)
project(TSPANNEALING)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static-libgcc -static-libstdc++")

set(SOURCE_FILES main.cpp)
set(SOURCE_FILES main.cpp FileReader/FileLoader.cpp FileReader/FileLoader.h TSP/TSPAnnealing.cpp TSP/TSPAnnealing.h Menu/MenuTSPManager.cpp Menu/MenuTSPManager.h TimeTest/TimeTest.cpp TimeTest/TimeTest.h)
add_executable(TSPANNEALING ${SOURCE_FILES})