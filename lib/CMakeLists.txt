aux_source_directory(. DIR_LIB3RD)

add_subdirectory(Fonts)
add_subdirectory(EinkGUI)
add_library(lib_3rd ${DIR_LIB3RD})

target_include_directories(lib_3rd PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# target_link_libraries(driver PUBLIC demo template)

