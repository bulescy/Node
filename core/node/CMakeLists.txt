aux_source_directory(. DIR_NODE)

add_subdirectory(demo)
add_subdirectory(template)
add_subdirectory(picture)
add_library(node ${DIR_NODE})
 
target_include_directories(node PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(node PUBLIC demo template picture)

