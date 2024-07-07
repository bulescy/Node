aux_source_directory(. DIR_CORE)

add_subdirectory(node)
add_library(core ${DIR_CORE})
include_directories(./node)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(core PUBLIC node)
