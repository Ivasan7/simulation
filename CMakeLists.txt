

cmake_minimum_required(VERSION 3.10.0)
project (simulation)
add_executable(simulation main.cpp)
target_link_libraries(simulation models)
add_subdirectory(libs)
