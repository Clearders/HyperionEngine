//
// Created by 13191 on 2026/2/13.
//

#include <../../Hyperion/src/Hyperion/hyperionpch.h>

// 使用 CUSTOM 加载器模式，防止 imgui_impl_opengl3.cpp 尝试使用其内部加载器
#define IMGUI_IMPL_OPENGL_LOADER_CUSTOM

// 显式包含 glad 和 glfw 头文件，确保 OpenGL 函数和类型对于后端是可见的
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "imgui_impl_glfw.cpp"
#include "imgui_impl_opengl3.cpp"