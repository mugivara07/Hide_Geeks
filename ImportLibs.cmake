# set(${CMAKE_FIND_USE_PACKAGE_ROOT_PATH} FALSE)

# These libs should be installed manually

# Common libs for any platform
set(CMAKE_PREFIX_PATH ${PROJECT_SOURCE_DIR}/Lib/Common)

# Platform-dependent libs
if (UNIX AND NOT APPLE)
    set(CMAKE_PREFIX_PATH ${PROJECT_SOURCE_DIR}/Lib/Linux)
    find_package(X11 REQUIRED)
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ltbb")
elseif (WIN32)
    set(CMAKE_PREFIX_PATH ${PROJECT_SOURCE_DIR}/Lib/Windows)
    set(SFML_STATIC_LIBRARIES TRUE)
    MESSAGE(STATUS ${CMAKE_PREFIX_PATH})
elseif(APPLE)
    set(CMAKE_PREFIX_PATH ${PROJECT_SOURCE_DIR}/Lib/MacOS)
endif()

find_package(SFML 2.5.1 COMPONENTS system window graphics REQUIRED)
