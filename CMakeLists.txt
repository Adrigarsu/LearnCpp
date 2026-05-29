cmake_minimum_required(VERSION 4.1)
project(LearnC)

set(CMAKE_CXX_STANDARD 20)

add_executable(project1 project1/main.cpp)
add_executable(project2 project2/main.cpp)
add_executable(project3 project3/main.cpp
        project3/mathlib/basic.cpp
        project3/mathlib/basic.h
        project3/mathlib/stats.cpp
        project3/mathlib/stats.h
        project3/mathlib/trig.cpp
        project3/mathlib/trig.h)
