cmake_minimum_required(VERSION 3.16)

project(Sandbox LANGUAGES CXX)

add_executable(Sandbox Sandbox.cpp)

target_compile_features(Sandbox PUBLIC cxx_std_17)
target_include_directories(Sandbox PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(Sandbox PRIVATE HYPERION_DLL)

hyperion_configure_target(Sandbox)

target_link_libraries(Sandbox PRIVATE Hyperion)

set_target_properties(Sandbox PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
