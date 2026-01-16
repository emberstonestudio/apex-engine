#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "core_types.h"

namespace Core
{
    class Window {

    public:
        Window(const WindowProperties& props);
        ~Window();

        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;
        Window(Window&&) = delete;
        Window& operator=(Window&&) = delete;

        void PollEvents() { glfwPollEvents(); }
        void SwapBuffers() const { return glfwSwapBuffers(m_Window); }
        bool ShouldClose() const { return glfwWindowShouldClose(m_Window); }

    private:
        void InitWindow();
        static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

        WindowProperties m_Properties;
        GLFWwindow* m_Window = nullptr;
    };
}