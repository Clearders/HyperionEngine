#pragma once

#include <iostream>
#include <algorithm>
#include <functional>
#include <memory>
#include <utility>
#include <sstream>
#include <fstream>

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <thread>
#include <chrono>

#ifdef HYPERION_PLATFORM_WINDOWS
    #include <Windows.h>
#endif

// Graphics loaders
#if defined(HYPERION_RENDER_API_OpenGL)
    #include <glad/glad.h>
    #include <GLFW/glfw3.h>
#elif defined(HYPERION_RENDER_API_Vulkan)
    #include <volk.h>
    #include <GLFW/glfw3.h>
#endif
