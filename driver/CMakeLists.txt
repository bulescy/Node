aux_source_directory(. DIR_DRIVER)

add_subdirectory(eink7_3e)
add_library(driver ${DIR_DRIVER})

target_include_directories(driver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# target_link_libraries(driver PUBLIC demo template)

