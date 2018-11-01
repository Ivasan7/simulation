cmake_minimum_required(VERSION 3.10.0)
project (simulator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(BOOST_ROOT ${PROJECT_SOURCE_DIR}/extLibs/boost_1_66_0)
find_package(Boost 1.66.0)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(simulator main.cpp)

add_subdirectory(libs)

target_link_libraries(simulator models simulation ${Boost_LIBRARIES})
