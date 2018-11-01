set ( LIBRARY_NAME simulation)
set ( HEADER_PATH ${CMAKE_SOURCE_DIR}/libs/include/simulation )
set ( EXTERNAL_HEADER_PATH ${CMAKE_SOURCE_DIR}/libs/include/models )
include_directories (
    ${HEADER_PATH}
    ${EXTERNAL_HEADER_PATH}
)

set( HEADER_FILES
    ${HEADER_PATH}/simulation.h
    )

set( SOURCE_FILES
    simulation.cpp
)
add_library( simulation SHARED
    ${HEADER_FILES}
    ${SOURCE_FILES}
)
target_include_directories(
    simulation PUBLIC
    ${HEADER_PATH}
)

set(target_added_libraries models)

target_link_libraries(simulation models)
