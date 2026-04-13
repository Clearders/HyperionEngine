# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.

cmake_minimum_required(VERSION 3.16)

project(HyperionEngine LANGUAGES CXX)
set(CMAKE_CXX_STANDARD )

# 定义为一个静态库
add_library(stb_image STATIC stb_image.cpp)

# 这样链接 stb_image 的其他工程就能自动找到 stb_image.h 这个头文件
target_include_directories(stb_image PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})