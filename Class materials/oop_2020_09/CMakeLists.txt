cmake_minimum_required(VERSION 3.5)

project(Examples_09)

add_executable(vector vector.cpp)
set_target_properties(vector PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

add_executable(iterator iterator.cpp)
set_target_properties(iterator PROPERTIES
       CXX_STANDARD 14
       CXX_STANDARD_REQUIRED ON
       )

add_executable(unique_iterator unique_iterator.cpp)
set_target_properties(unique_iterator PROPERTIES
       CXX_STANDARD 14
       CXX_STANDARD_REQUIRED ON
       )

add_executable(back_insert back_insert.cpp)
set_target_properties(back_insert PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

add_executable(back_insert_iterator back_insert_iterator.cpp)
set_target_properties(back_insert_iterator PROPERTIES
                CXX_STANDARD 14
                CXX_STANDARD_REQUIRED ON
                )

add_executable(iostream iostream.cpp)
set_target_properties(iostream PROPERTIES
                CXX_STANDARD 14
                CXX_STANDARD_REQUIRED ON
                )

add_executable(random_access random_access.cpp)
set_target_properties(random_access PROPERTIES
                                CXX_STANDARD 14
                                CXX_STANDARD_REQUIRED ON
                                )