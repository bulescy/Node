aux_source_directory(. DIR_FONTS)

add_library(fonts ${DIR_FONTS})

target_include_directories(fonts PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# target_link_libraries(eink73e PUBLIC bsp)

