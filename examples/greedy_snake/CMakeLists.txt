# Copyright 2020 SMS
# License(Apache-2.0)

cmake_minimum_required (VERSION 3.8)

# 创建 可执行文件
add_executable(greedy_snake "main.cpp")
target_link_libraries(greedy_snake xinput.lib clementine.lib)
