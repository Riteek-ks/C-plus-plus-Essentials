cmake_minimum_required(VERSION 3.29.3)
project(projectcmake)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory(calculator)
add_executable(projectcmake source.cpp)
target_link_libraries(projectcmake PUBLIC calculator)
target_include_directories(projectcmake PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/calculator"
                          )