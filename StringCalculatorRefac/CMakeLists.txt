cmake_minimum_required(VERSION 3.29.3)
project(letscheck)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory(stringCalculator)
add_executable(letscheck source.cpp)
target_link_libraries(letscheck PUBLIC stringCalculator)
target_include_directories(letscheck PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/stringCalculator"
                          )