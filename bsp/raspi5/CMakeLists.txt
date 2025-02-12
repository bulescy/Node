aux_source_directory(. DIR_RASPI5)

add_library(raspi5 ${DIR_RASPI5})

target_include_directories(raspi5 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(raspi5 PUBLIC lgpio)

