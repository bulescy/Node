aux_source_directory(. DIR_EINKGUI)

add_library(einkgui ${DIR_EINKGUI})

target_include_directories(einkgui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                           ../../bsp/raspi5)

target_link_libraries(einkgui PUBLIC m)

