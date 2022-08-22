# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Algorithms")

include_directories("src/Sort")
include_directories("src/Utils")
include_directories("src/Tree")
include_directories("src/DynamicProgram")
include_directories("src/Graph")
include_directories("src/Others")


set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable("Algorithms" src/example.cxx)
