#pragma once

#include "core_types.h"
#include <memory>

namespace Core
{
    class Window;

    class Application {

    public:
        Application(const WindowProperties& props);
        ~Application();

        Application(const Application&) = delete;
        Application& operator=(const Application&) = delete;
        Application(Application&&) = delete;
        Application& operator=(Application&&) = delete;

        void Run();

    private:
        void Update(float deltaTime);
        void Render();

        std::unique_ptr<Window> m_Window;
        float m_DeltaTime = 0.0f;
    };
}