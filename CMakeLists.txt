cmake_minimum_required(VERSION 3.12)
project(Common)
set(CMAKE_CXX_STANDARD 20)

set(
        HEADERS
        include/lit/common/time_utils.hpp
        include/lit/common/assert.hpp
        include/lit/common/logging.hpp
)

set(
        SOURCES
        src/common/time_utils.cpp
        src/common/logging.cpp
)

add_library(common ${HEADERS} ${SOURCES})
target_include_directories(common PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(common_example example.cpp)
target_link_libraries(common_example common)