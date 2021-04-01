cmake_minimum_required(VERSION 3.5)

project(Examples_16)

find_package(Threads)

add_executable(braces braces.cpp)
set_target_properties(braces PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
target_link_libraries(braces ${CMAKE_THREAD_LIBS_INIT})

add_executable(initializer_list initializer_list.cpp)
set_target_properties(initializer_list PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
target_link_libraries(initializer_list ${CMAKE_THREAD_LIBS_INIT})


add_executable(function_chain function_chain.cpp)
set_target_properties(function_chain PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
target_link_libraries(function_chain ${CMAKE_THREAD_LIBS_INIT})

add_executable(cartesian_product cartesian_product.cpp)
set_target_properties(cartesian_product PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
target_link_libraries(cartesian_product ${CMAKE_THREAD_LIBS_INIT})

add_executable(structured_bindings structured_bindings.cpp)
set_target_properties(structured_bindings PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
target_link_libraries(structured_bindings ${CMAKE_THREAD_LIBS_INIT})

add_executable(compress compress.cpp)
set_target_properties(compress PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
target_link_libraries(compress ${CMAKE_THREAD_LIBS_INIT})





