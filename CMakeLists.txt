# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project("Clementine")

include_directories(".")

# 包含 boost 库
include_directories("D:/Program Files/Program/boost_1_73_0")
link_directories("D:/Program Files/Program/boost_1_73_0/stage/lib")

# 设置 lib 输出目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_subdirectory("clem")

link_directories("lib")

# add_subdirectory("examples")
