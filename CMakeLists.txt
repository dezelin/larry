project(containers)
cmake_minimum_required(VERSION 3.0)

# C++11 compiler support
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
    message(FATAL_ERROR "No C++11 compiler has been found.")
endif()
    
# Add additional compiler options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

aux_source_directory(. SRC_LIST)

# List of include directories
set(INC_LIST
    ${containers_SOURCE_DIR}
    ${containers_SOURCE_DIR}/include
)

include_directories(${INC_LIST})

add_executable(${PROJECT_NAME} ${SRC_LIST})

# List of subdirectories with tests
set(TEST_LIST
    ${containers_SOURCE_DIR}/common/misc/tests
)

enable_testing()

foreach(subdir ${TEST_LIST})
    add_subdirectory(${subdir})
endforeach()
