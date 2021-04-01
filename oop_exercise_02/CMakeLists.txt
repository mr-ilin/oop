cmake_minimum_required(VERSION 3.0.0)

add_definitions(-std=c++11)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${oop_exercise_02_SOURCE_DIR})

project(oop_exercise_02 VERSION 0.1.0)

add_executable(oop_exercise_02 main.cpp bottle.cpp)
