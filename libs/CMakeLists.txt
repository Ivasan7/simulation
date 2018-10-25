project ( libs )

set (MODULE libs )
include_directories (
    libs/src
    libs/include
)
add_subdirectory ( src )