aux_source_directory(. DIR_CORE)

add_library(core ${DIR_CORE})

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

