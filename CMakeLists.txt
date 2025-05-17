cmake_minimum_required(VERSION 3.10)
project(customWarning LANGUAGES CXX)

if(NOT TARGET colorPrint) 
add_subdirectory(colorPrint) 
endif()

add_library(customWarning INTERFACE)

target_link_libraries(customWarning INTERFACE colorPrint)

target_include_directories(customWarning INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})