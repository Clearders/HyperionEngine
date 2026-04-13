#pragma once

#include <cstdlib>

#include <glad/glad.h>

#include "Hyperion/Core/Log.h"

namespace Hyperion
{
    inline const char* OpenGLErrorToString(GLenum error)
    {
        switch (error)
        {
        case GL_INVALID_ENUM: return "GL_INVALID_ENUM";
        case GL_INVALID_VALUE: return "GL_INVALID_VALUE";
        case GL_INVALID_OPERATION: return "GL_INVALID_OPERATION";
        case GL_STACK_OVERFLOW: return "GL_STACK_OVERFLOW";
        case GL_STACK_UNDERFLOW: return "GL_STACK_UNDERFLOW";
        case GL_OUT_OF_MEMORY: return "GL_OUT_OF_MEMORY";
        case GL_INVALID_FRAMEBUFFER_OPERATION: return "GL_INVALID_FRAMEBUFFER_OPERATION";
        default: return "GL_UNKNOWN_ERROR";
        }
    }

    inline void OpenGLClearErrors()
    {
        while (glGetError() != GL_NO_ERROR)
        {
        }
    }

    inline bool OpenGLLogErrors(const char* expr, const char* file, int line)
    {
        bool noError = true;
        for (GLenum error = glGetError(); error != GL_NO_ERROR; error = glGetError())
        {
            noError = false;
            HYPERION_CORE_ERROR("OpenGL error: {0} (0x{1:X}) in {2}:{3} after {4}", OpenGLErrorToString(error), static_cast<unsigned int>(error), file, line, expr);
        }
        return noError;
    }
} // Hyperion

#if defined(_DEBUG)
#define HYPERION_GL_CALL(expr) do { ::Hyperion::OpenGLClearErrors(); expr; if (!::Hyperion::OpenGLLogErrors(#expr, __FILE__, __LINE__)) { std::abort(); } } while (0)
#define HYPERION_GL_CHECKPOINT(tag) do { if (!::Hyperion::OpenGLLogErrors(tag, __FILE__, __LINE__)) { std::abort(); } } while (0)
#else
#define HYPERION_GL_CALL(expr) expr
#define HYPERION_GL_CHECKPOINT(tag) ((void)0)
#endif

