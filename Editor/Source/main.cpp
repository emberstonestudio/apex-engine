#include "Core/application.h"
#include "Core/window.h"
#include "editor_layer.h"

int main()
{
    Core::WindowProperties props{};
    Core::Application app(props);

    app.GetLayerStack().EmplaceLayer<EditorLayer>();
    app.Run();
}