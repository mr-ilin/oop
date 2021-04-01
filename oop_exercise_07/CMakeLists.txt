cmake_minimum_required(VERSION 3.5)

project(oop_exercise_04)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(oop_exercise_07 main.cpp 
                point.hpp point.cpp 
                figure.hpp  
                hexagon.hpp hexagon.cpp 
                triangle.hpp triangle.cpp 
                octagon.hpp octagon.cpp 
                document.hpp document.cpp 
                figure_factory.hpp figure_factory.cpp
                command.hpp command.cpp 
                editor.hpp  editor.cpp
                )
set_target_properties(oop_exercise_07 PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )
