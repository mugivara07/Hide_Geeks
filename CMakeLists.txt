cmake_minimum_required(VERSION 3.20)


project(Hide_Geeks VERSION 0)
include(ImportLibs.cmake)
include(FetchContent)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hide_Geeks main.cpp)

TARGET_LINK_LIBRARIES(Hide_Geeks sfml-system sfml-window sfml-graphics)

