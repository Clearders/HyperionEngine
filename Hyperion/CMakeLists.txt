cmake_minimum_required(VERSION 3.16)

project(Hyperion LANGUAGES C CXX)

file(GLOB_RECURSE HYPERION_SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)
file(GLOB_RECURSE HYPERION_HEADERS CONFIGURE_DEPENDS
    src/*.h
)

# Build GLAD from vendor and expose it as a reusable target
# Use top-level source dir to reference the workspace root (handles the space in path)
# This resolves to: <workspace-root>/vendor/GLAD/src/*.c (i.e. "Hyperion Engine/vendor/GLAD/src/*.c")
set(GLAD_DIR "${CMAKE_SOURCE_DIR}/vendor/GLAD/src")
if (EXISTS "${GLAD_DIR}/glad.c")
    set(GLAD_SOURCES "${GLAD_DIR}/glad.c")
else()
    file(GLOB_RECURSE GLAD_SOURCES CONFIGURE_DEPENDS
        "${GLAD_DIR}/*.c"
    )
endif()

if (NOT GLAD_SOURCES)
    message(FATAL_ERROR "No GLAD sources found in ${GLAD_DIR}. Make sure vendor/GLAD/src/glad.c exists or update the path in CMakeLists.txt")
endif()

add_library(glad STATIC ${GLAD_SOURCES})
# Provide a CMake alias so other code referencing glad::glad still works
add_library(glad::glad ALIAS glad)
target_include_directories(glad
    PUBLIC
        ${CMAKE_SOURCE_DIR}/vendor/GLAD/include
)
# Prefer C linker if a C compiler is available, otherwise fall back to C++ to avoid CMake internal variable errors
if (CMAKE_C_COMPILER)
    set_target_properties(glad PROPERTIES LINKER_LANGUAGE C)
elseif(CMAKE_CXX_COMPILER)
    set_target_properties(glad PROPERTIES LINKER_LANGUAGE CXX)
endif()

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG)

add_library(Hyperion SHARED
    ${HYPERION_SOURCES}
    ${HYPERION_HEADERS}
        src/Hyperion/Core/Window.h
        src/Platform/Windows/WindowsWindow.cpp
        src/Platform/Windows/WindowsWindow.h
        src/Hyperion/Core/KeyCodes.h
        src/Hyperion/Core/Layer.cpp
        src/Hyperion/Core/Layer.h
)

target_compile_features(Hyperion PUBLIC cxx_std_17)


target_include_directories(Hyperion
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if (WIN32)
    target_compile_definitions(Hyperion
        PUBLIC
            HYPERION_PLATFORM_WINDOWS
        PRIVATE
            HYPERION_BUILD_DLL
    )
endif()

target_link_libraries(Hyperion
    PUBLIC
        spdlog::spdlog
    PRIVATE
        glfw
        glad
        OpenGL::GL
)

# Enable PCH if desired (currently using header only); adapt if using compiler-specific options.
target_precompile_headers(Hyperion
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Hyperion/hyperionpch.h
)

set_target_properties(Hyperion PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/bin
)
