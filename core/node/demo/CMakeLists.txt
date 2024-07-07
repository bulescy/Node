aux_source_directory(. DIR_DEMO)

add_library(demo ${DIR_DEMO})

target_include_directories(demo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

