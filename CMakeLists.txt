cmake_minimum_required(VERSION 3.21)
project(Hide_Geeks VERSION 0)

include(FetchContent)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hide_Geeks main.cpp)

FetchContent_Declare(sfml GIT_REPOSITORY https://github.com/SFML/SFML GIT_TAG 2f11710abc5aa478503a7ff3f9e654bd2078ebab)
FetchContent_MakeAvailable(sfml)
TARGET_LINK_LIBRARIES(Hide_Geeks sfml-system sfml-window sfml-graphics)
