project(models VERSION 0.1 DESCRIPTION "Basic model implementation")

add_library(models SHARED
	src/model.cpp
)

set_target_properties(models PROPERTIES VERSION ${PROJECT_VERSION})

set_target_properties(models PROPERTIES SOVERSION 1)

set_target_properties(models PROPERTIES PUBLIC_HEADER include/model.h)

target_include_directories(models PRIVATE include)

target_include_directories(models PRIVATE src)
