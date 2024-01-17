#pragma once

#include "Scene.hpp"
#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "imgui.h"
#include "imgui-SFML.h"

class System {
    public:
        System(std::shared_ptr<Scene> scene);
        void applyPoison();
        void drawEntities(std::shared_ptr<sf::RenderWindow> window);
        void drawComponents(sf::Vector2i mousePos);
        void debugPrint();
    private:
        std::shared_ptr<Scene> scene;
};