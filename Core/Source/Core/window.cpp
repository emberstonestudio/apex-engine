#include "window.h"
#include <cassert>

Core::Window::Window(const WindowProperties& props) : m_Properties(props)
{
    InitWindow();
}

Core::Window::~Window()
{
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void Core::Window::InitWindow()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(m_Properties.width, m_Properties.height, m_Properties.title, nullptr, nullptr);
    assert(m_Window && "Failed to create window");

    glfwMakeContextCurrent(m_Window);

    assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));

    glfwSetWindowUserPointer(m_Window, this);
    glfwSetFramebufferSizeCallback(m_Window, FramebufferSizeCallback);
    m_Properties.isVsync ? glfwSwapInterval(1) : glfwSwapInterval(0);

    glViewport(0, 0, m_Properties.width, m_Properties.height);
}

void Core::Window::FramebufferSizeCallback(GLFWwindow* window, int width, int height) 
{
    const auto win = static_cast<Window*>(glfwGetWindowUserPointer(window));
    assert(win);

    win->m_Properties.width = width;
    win->m_Properties.height = height;
    glViewport(0, 0, width, height);
}
