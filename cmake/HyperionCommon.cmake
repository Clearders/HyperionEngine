# Common CMake helpers for Hyperion targets

function(hyperion_configure_target target_name)
    if (NOT TARGET ${target_name})
        message(FATAL_ERROR "Target ${target_name} not defined")
    endif()

    # Unity/jumbo builds toggle
    set_property(TARGET ${target_name} PROPERTY UNITY_BUILD $<BOOL:${HYPERION_ENABLE_UNITY}>)

    if (MSVC)
        target_compile_options(${target_name} PRIVATE
            /permissive-
            /W4
            $<$<CONFIG:Release>:/O2>
            $<$<BOOL:${HYPERION_ENABLE_WARNINGS_AS_ERRORS}>:/WX>
            $<$<BOOL:${HYPERION_ENABLE_LTO}>:/GL>
        )
        target_link_options(${target_name} PRIVATE
            $<$<CONFIG:Debug>:/DEBUG:FASTLINK>
            $<$<BOOL:${HYPERION_ENABLE_LTO}>:/LTCG>
        )
    else()
        target_compile_options(${target_name} PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            $<$<BOOL:${HYPERION_ENABLE_WARNINGS_AS_ERRORS}>:-Werror>
            $<$<BOOL:${HYPERION_ENABLE_LTO}>:-flto>
        )
        target_link_options(${target_name} PRIVATE $<$<BOOL:${HYPERION_ENABLE_LTO}>:-flto>)
    endif()

    if (HYPERION_ENABLE_SANITIZERS AND CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(${target_name} PRIVATE -fsanitize=address,undefined)
        target_link_options(${target_name} PRIVATE -fsanitize=address,undefined)
    endif()
endfunction()

