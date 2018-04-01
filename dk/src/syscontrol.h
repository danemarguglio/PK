#pragma once
#ifdef PC
#include <SDL.h>
#include <cstdint>
typedef uint32_t u32;
typedef uint8_t u8;
#else
#include "switch.h"
#endif