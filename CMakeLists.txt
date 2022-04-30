cmake_minimum_required(VERSION 3.20)


project(Hide_Geeks VERSION 0)
include(ImportLibs.cmake)
include(FetchContent)

set(CMAKE_CXX_STANDARD 17)

#file(GLOB_RECURSE SOURCE_FILES project/src/*.cpp project/src/*.c)
#file(GLOB_RECURSE HEADER_FILES project/include/*.h project/include/*.hpp)
#
#add_executable(Hide_Geeks ${SOURCE_FILES} ${HEADER_FILES})

add_executable(Hide_Geeks project/src/main.cpp project/src/Game.cpp project/src/Player.cpp )

TARGET_LINK_LIBRARIES(Hide_Geeks sfml-system sfml-window sfml-graphics)
TARGET_INCLUDE_DIRECTORIES(Hide_Geeks PUBLIC project/include)

