cmake_minimum_required(VERSION 3.5)

project(Examples_11)

add_executable(srp_1 srp_1.cpp)
set_target_properties(srp_1 PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

add_executable(srp_2 srp_2.cpp)
set_target_properties(srp_2 PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

add_executable(srp_3 srp_3.cpp)
set_target_properties(srp_3 PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

add_executable(srp_4 srp_4.cpp)
set_target_properties(srp_4 PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

add_executable(ocp_1 ocp_1.cpp)
set_target_properties(ocp_1 PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

add_executable(ocp_2_template ocp_2_template.cpp)
set_target_properties(ocp_2_template PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

add_executable(ocp_3_crtp ocp_3_crtp.cpp)
set_target_properties(ocp_3_crtp PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

add_executable(ocp_4_strategy ocp_4_strategy.cpp)
set_target_properties(ocp_4_strategy PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)
