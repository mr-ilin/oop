cmake_minimum_required(VERSION 3.5)

project(Examples_12)


add_executable(lsp_1 lsp_1.cpp)
set_target_properties(lsp_1 PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

add_executable(lsp_2 lsp_2.cpp)
set_target_properties(lsp_2 PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

add_executable(tda tda.cpp)
set_target_properties(tda PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

add_executable(cqs_1 cqs_1.cpp)
set_target_properties(cqs_1 PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

add_executable(cqs_2 cqs_2.cpp)
set_target_properties(cqs_2 PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

add_executable(isp_1 isp_1.cpp)
set_target_properties(isp_1 PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

add_executable(isp_2 isp_2.cpp)
set_target_properties(isp_2 PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

add_executable(dip_1 dip_1.cpp)
set_target_properties(dip_1 PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

add_executable(dip_2 dip_2.cpp)
set_target_properties(dip_2 PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)