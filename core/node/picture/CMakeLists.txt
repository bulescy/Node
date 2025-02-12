aux_source_directory(. DIR_PICTURE)

add_library(picture ${DIR_PICTURE})

target_include_directories(picture PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                           ../../../bsp/raspi5
                           ../../../lib/EinkGUI
                           ../../../driver/eink7_3e)

target_link_libraries(picture PUBLIC eink73e einkgui raspi5)
