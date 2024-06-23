cmake_minimum_required (VERSION 2.8)

project(raspi)

# add a compilation subdirectory
# add_subdirectory(core)

# add a header directory
# include_directories(./examples)

# add src file
aux_source_directory(./core SOURCE_FILES)

include_directories(./core)



# generate an executable file
add_executable(test
    main.c
    ${SOURCE_FILES}
)



# target_link_libraries(test core)
