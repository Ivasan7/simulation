set ( LIBRARY_NAME models)
set ( HEADER_PATH ${CMAKE_SOURCE_DIR}/libs/include/models )
include_directories (
    ${HEADER_PATH}
)

set( HEADER_FILES
    ${HEADER_PATH}/model.h
)

set( SOURCE_FILES
    model.cpp
)
add_library( models SHARED 
    ${HEADER_FILES} 
    ${SOURCE_FILES}
    )
target_include_directories(
    models PUBLIC
    ${HEADER_PATH}
    )
