cmake_minimum_required (VERSION 3.7)
set (CMAKE_CXX_STANDARD 17)

project (image-convert)

include_directories (${CMAKE_HOME_DIRECTORY}/src)
include_directories (${CMAKE_HOME_DIRECTORY}/lib)
add_executable (
    image-convert
    src/main.cpp
)
