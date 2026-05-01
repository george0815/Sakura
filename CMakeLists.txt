cmake_minimum_required(VERSION 3.16)


project(sakura)

set (CMAKE_CXX_STANDARD 17)




#collect all surce file
file(GLOB_RECURSE SRC CONFIGURE_DEPENDS 
  "MAIN/*.cpp"
  "CORE/*.cpp"
)


add_executable(sakura ${SRC})


#include directories
target_include_directories(sakura PRIVATE CORE)
