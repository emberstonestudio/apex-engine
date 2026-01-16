#pragma once

#include "Systems/layer_system.h"

class EditorLayer : public Core::Systems::Layer
{
    public:
        EditorLayer();
        ~EditorLayer();

        void OnUpdate(float deltaTime) override;
        void OnRender() override;
};