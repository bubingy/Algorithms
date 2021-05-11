# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Algorithms")

include_directories("src/Sort")
include_directories("src/Utils")

add_executable("sort" src/example.cxx)