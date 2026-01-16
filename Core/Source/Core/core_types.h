#pragma once

#include <cstdint>

namespace Core
{
    struct WindowProperties 
    {
        const char* title = "Apex Engine";
        uint32_t width = 800;
        uint32_t height = 600;
        bool isVsync = true;
    };
}