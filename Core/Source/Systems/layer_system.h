#pragma once
#include <memory>
#include <vector>
#include <algorithm>

namespace Core::Systems
{
    class Layer {
    public:
        Layer() = default;
        virtual ~Layer() = default;
        virtual void OnUpdate(float deltaTime) = 0;
        virtual void OnRender() = 0;
    };

    class LayerStack {
    public:
        LayerStack() = default;
        ~LayerStack() = default;

        // Push by moving a unique_ptr
        template<typename T>
        void PushLayer(std::unique_ptr<T> layer) {
            static_assert(std::is_base_of_v<Layer, T>, "Pushed layer must derive from Layer");
            m_LayerStack.emplace_back(std::move(layer));
        }

        // Helper to push with construction
        template<typename T, typename... Args>
        void EmplaceLayer(Args&&... args) {
            static_assert(std::is_base_of_v<Layer, T>, "Pushed layer must derive from Layer");
            m_LayerStack.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
        }

        // Pop by raw pointer comparison
        void PopLayer(Layer* layer) {
            auto it = std::find_if(m_LayerStack.begin(), m_LayerStack.end(),
                [layer](const std::unique_ptr<Layer>& ptr) {
                    return ptr.get() == layer;
                });
            
            if (it != m_LayerStack.end()) {
                m_LayerStack.erase(it);
            }
        }

        // Update all layers
        void OnUpdate(float deltaTime) {
            for (auto& layer : m_LayerStack) {
                layer->OnUpdate(deltaTime);
            }
        }

        // Render all layers
        void OnRender() {
            for (auto& layer : m_LayerStack) {
                layer->OnRender();
            }
        }

    private:
        std::vector<std::unique_ptr<Layer>> m_LayerStack;
    };
}