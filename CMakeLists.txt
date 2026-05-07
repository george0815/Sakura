cmake_minimum_required(VERSION 3.16)


project(sakura)

set (CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)


#collect all surce file
file(GLOB_RECURSE SRC CONFIGURE_DEPENDS 
  "MAIN/*.cpp"
  "CORE/*.cpp"
)


add_executable(sakura ${SRC})

target_link_libraries(sakura SDL2::SDL2)


#include directories
target_include_directories(sakura PRIVATE CORE)
