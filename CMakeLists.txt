cmake_minimum_required(VERSION 3.14)
project(color_nodes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES main.cpp
        Game.cpp
        Game.h)
add_executable(color_nodes ${SOURCE_FILES})
include_directories(/usr/local/include)


find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(color_nodes sfml-system sfml-window sfml-graphics sfml-audio sfml-network)