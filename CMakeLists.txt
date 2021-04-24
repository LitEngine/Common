cmake_minimum_required(VERSION 3.12)
project(LiteEngine.Common)
set(CMAKE_CXX_STANDARD 20)

set(
        HEADERS
        include/common/time_utils.hpp
        include/common/assert.hpp
        include/common/bit_utils.hpp
        include/common/logging.hpp
)

set(
        SOURCES
        src/time_utils.cpp
        src/logging.cpp
)

add_library(lite_engine_common ${HEADERS} ${SOURCES})
target_include_directories(lite_engine_common PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")


add_executable(lite_engine_common_example example.cpp)
target_link_libraries(lite_engine_common_example lite_engine_common)