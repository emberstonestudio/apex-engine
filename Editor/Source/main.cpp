#include "Core/application.h"
#include "Core/window.h"

int main()
{
    Core::WindowProperties props{};
    Core::Application app(props);

    app.Run();
}