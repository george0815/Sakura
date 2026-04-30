cmake_minimum_required(VERSION 3.16)


project(sakura)

set (CMAKE_CXX_STANDARD 17)




#collect all surce file
file(GLOB_RECURSE SRC 
  "MAIN/*.cpp"
  "CORE/*.cpp"
)


add_executable(emulator $(SRC))


#include directories
target_include_directories(emulator PRIVATE CORE)
