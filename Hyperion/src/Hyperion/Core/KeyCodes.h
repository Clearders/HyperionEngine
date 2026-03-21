#pragma once

#include <cstdint>

namespace Hyperion
{
    // Platform-agnostic key code alias; maps to backend key codes (e.g., GLFW).
    using KeyCode = std::uint16_t;
}


/* Printable keys from glfw3.h */
#define HYPERION_KEY_SPACE              32
#define HYPERION_KEY_APOSTROPHE         39  /* ' */
#define HYPERION_KEY_COMMA              44  /* , */
#define HYPERION_KEY_MINUS              45  /* - */
#define HYPERION_KEY_PERIOD             46  /* . */
#define HYPERION_KEY_SLASH              47  /* / */
#define HYPERION_KEY_0                  48
#define HYPERION_KEY_1                  49
#define HYPERION_KEY_2                  50
#define HYPERION_KEY_3                  51
#define HYPERION_KEY_4                  52
#define HYPERION_KEY_5                  53
#define HYPERION_KEY_6                  54
#define HYPERION_KEY_7                  55
#define HYPERION_KEY_8                  56
#define HYPERION_KEY_9                  57
#define HYPERION_KEY_SEMICOLON          59  /* ; */
#define HYPERION_KEY_EQUAL              61  /* = */
#define HYPERION_KEY_A                  65
#define HYPERION_KEY_B                  66
#define HYPERION_KEY_C                  67
#define HYPERION_KEY_D                  68
#define HYPERION_KEY_E                  69
#define HYPERION_KEY_F                  70
#define HYPERION_KEY_G                  71
#define HYPERION_KEY_H                  72
#define HYPERION_KEY_I                  73
#define HYPERION_KEY_J                  74
#define HYPERION_KEY_K                  75
#define HYPERION_KEY_L                  76
#define HYPERION_KEY_M                  77
#define HYPERION_KEY_N                  78
#define HYPERION_KEY_O                  79
#define HYPERION_KEY_P                  80
#define HYPERION_KEY_Q                  81
#define HYPERION_KEY_R                  82
#define HYPERION_KEY_S                  83
#define HYPERION_KEY_T                  84
#define HYPERION_KEY_U                  85
#define HYPERION_KEY_V                  86
#define HYPERION_KEY_W                  87
#define HYPERION_KEY_X                  88
#define HYPERION_KEY_Y                  89
#define HYPERION_KEY_Z                  90
#define HYPERION_KEY_LEFT_BRACKET       91  /* [ */
#define HYPERION_KEY_BACKSLASH          92  /* \ */
#define HYPERION_KEY_RIGHT_BRACKET      93  /* ] */
#define HYPERION_KEY_GRAVE_ACCENT       96  /* ` */
#define HYPERION_KEY_WORLD_1            161 /* non-US #1 */
#define HYPERION_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define HYPERION_KEY_ESCAPE             256
#define HYPERION_KEY_ENTER              257
#define HYPERION_KEY_TAB                258
#define HYPERION_KEY_BACKSPACE          259
#define HYPERION_KEY_INSERT             260
#define HYPERION_KEY_DELETE             261
#define HYPERION_KEY_RIGHT              262
#define HYPERION_KEY_LEFT               263
#define HYPERION_KEY_DOWN               264
#define HYPERION_KEY_UP                 265
#define HYPERION_KEY_PAGE_UP            266
#define HYPERION_KEY_PAGE_DOWN          267
#define HYPERION_KEY_HOME               268
#define HYPERION_KEY_END                269
#define HYPERION_KEY_CAPS_LOCK          280
#define HYPERION_KEY_SCROLL_LOCK        281
#define HYPERION_KEY_NUM_LOCK           282
#define HYPERION_KEY_PRINT_SCREEN       283
#define HYPERION_KEY_PAUSE              284
#define HYPERION_KEY_F1                 290
#define HYPERION_KEY_F2                 291
#define HYPERION_KEY_F3                 292
#define HYPERION_KEY_F4                 293
#define HYPERION_KEY_F5                 294
#define HYPERION_KEY_F6                 295
#define HYPERION_KEY_F7                 296
#define HYPERION_KEY_F8                 297
#define HYPERION_KEY_F9                 298
#define HYPERION_KEY_F10                299
#define HYPERION_KEY_F11                300
#define HYPERION_KEY_F12                301
#define HYPERION_KEY_F13                302
#define HYPERION_KEY_F14                303
#define HYPERION_KEY_F15                304
#define HYPERION_KEY_F16                305
#define HYPERION_KEY_F17                306
#define HYPERION_KEY_F18                307
#define HYPERION_KEY_F19                308
#define HYPERION_KEY_F20                309
#define HYPERION_KEY_F21                310
#define HYPERION_KEY_F22                311
#define HYPERION_KEY_F23                312
#define HYPERION_KEY_F24                313
#define HYPERION_KEY_F25                314
#define HYPERION_KEY_KP_0               320
#define HYPERION_KEY_KP_1               321
#define HYPERION_KEY_KP_2               322
#define HYPERION_KEY_KP_3               323
#define HYPERION_KEY_KP_4               324
#define HYPERION_KEY_KP_5               325
#define HYPERION_KEY_KP_6               326
#define HYPERION_KEY_KP_7               327
#define HYPERION_KEY_KP_8               328
#define HYPERION_KEY_KP_9               329
#define HYPERION_KEY_KP_DECIMAL         330
#define HYPERION_KEY_KP_DIVIDE          331
#define HYPERION_KEY_KP_MULTIPLY        332
#define HYPERION_KEY_KP_SUBTRACT        333
#define HYPERION_KEY_KP_ADD             334
#define HYPERION_KEY_KP_ENTER           335
#define HYPERION_KEY_KP_EQUAL           336
#define HYPERION_KEY_LEFT_SHIFT         340
#define HYPERION_KEY_LEFT_CONTROL       341
#define HYPERION_KEY_LEFT_ALT           342
#define HYPERION_KEY_LEFT_SUPER         343
#define HYPERION_KEY_RIGHT_SHIFT        344
#define HYPERION_KEY_RIGHT_CONTROL      345
#define HYPERION_KEY_RIGHT_ALT          346
#define HYPERION_KEY_RIGHT_SUPER        347
#define HYPERION_KEY_MENU               348
#define HYPERION_KEY_LAST               HYPERION_KEY_MENU