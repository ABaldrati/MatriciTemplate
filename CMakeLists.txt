cmake_minimum_required(VERSION 3.7)
project(MatriciTemplate)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES main.cpp MatrixTemplate.h UtilsMatrixTemplate.h)
add_executable(MatriciTemplate ${SOURCE_FILES})
add_library(core ${SOURCE_FILES})
target_link_libraries(MatriciTemplate core)