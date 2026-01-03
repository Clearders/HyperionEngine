cmake_minimum_required(VERSION 3.16)

project(Hyperion LANGUAGES CXX)

file(GLOB_RECURSE HYPERION_SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)
file(GLOB_RECURSE HYPERION_HEADERS CONFIGURE_DEPENDS
    src/*.h
)

find_package(OpenGL REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG)

add_library(Hyperion SHARED
    ${HYPERION_SOURCES}
    ${HYPERION_HEADERS}
        src/Hyperion/Core/Window.h
        src/Platform/Windows/WindowsWindow.cpp
        src/Platform/Windows/WindowsWindow.h
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
        glad::glad
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
