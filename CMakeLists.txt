cmake_minimum_required (VERSION 2.8)

project(raspi)

# add a compilation subdirectory
add_subdirectory(core)

# add a header directory
# include_directories(./examples)


# generate an executable file
add_executable(test
    main.c
)



target_link_libraries(test core)
