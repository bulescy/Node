aux_source_directory(. DIR_TEMPLATE)

add_library(template ${DIR_TEMPLATE})

target_include_directories(template PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

