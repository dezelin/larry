project(tests)
cmake_minimum_required(VERSION 3.0)

# Collect all source files
set(SRC_LIST
    test_move.cpp
    test_noncopyable.cpp
    test_swap.cpp
)

# Add test targets
foreach(src ${SRC_LIST})
    get_filename_component(test_name ${src} NAME_WE)
    add_executable(${test_name} ${src})
    add_test(${test_name} ${test_name})
endforeach()

