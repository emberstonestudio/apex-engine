#include "application.h"
#include "window.h"

Core::Application::Application(const WindowProperties& props)
{
    m_Window = std::make_unique<Window>(props);
    m_LayerStack = std::make_unique<Systems::LayerStack>();
}

Core::Application::~Application() = default;

void Core::Application::Run()
{
    float lastTime = static_cast<float>(glfwGetTime());

    while (!m_Window->ShouldClose())
    {
        float currentTime = static_cast<float>(glfwGetTime());
        m_DeltaTime = currentTime - lastTime;
        lastTime = currentTime;

        Update(m_DeltaTime);
        Render();
    }
}

void Core::Application::Update(float deltaTime)
{
    m_Window->PollEvents();
    m_LayerStack->OnUpdate(deltaTime);
}

void Core::Application::Render()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    m_LayerStack->OnRender();

    m_Window->SwapBuffers();
}