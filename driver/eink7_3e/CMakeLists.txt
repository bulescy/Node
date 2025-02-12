aux_source_directory(. DIR_EINK_7_3E)

add_library(eink73e ${DIR_EINK_7_3E})

target_include_directories(eink73e PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                           ../../bsp/raspi5)

target_link_libraries(eink73e PUBLIC bsp raspi5)

