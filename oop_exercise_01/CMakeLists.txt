cmake_minimum_required(VERSION 3.0.0)
add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(CMAKE_BUILD_TYPE Debug)

project(oop_exercise_01 VERSION 1.0.0)

add_executable(oop_exercise_01.out main.cpp)
