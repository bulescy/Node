aux_source_directory(. DIR_BSP)

add_subdirectory(raspi5)
add_library(bsp ${DIR_BSP})

target_include_directories(bsp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# target_link_libraries(driver PUBLIC demo template)

