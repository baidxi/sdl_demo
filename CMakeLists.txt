cmake_minimum_required(VERSION 3.28)
project(sdl_ui)

set(CMAKE_CXX_STANDARD 17)
find_package(PkgConfig)

pkg_check_modules(SDL sdl SDL_image SDL_ttf REQUIRED)

if (SDL_FOUND)
    message(STATUS "SDL version:" ${SDL_VERSION})
    include_directories(${SDL_INCLUDE_DIRS})
    link_directories(${SDL_LIBRARY_DIRS})
endif ()

add_executable(sdl_ui main.cpp
        sdl_ui.cpp
        sdl_ui.h)
target_link_libraries(sdl_ui ${SDL_LIBRARIES})
