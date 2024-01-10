#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

#include "State.h"
#include "Game.h"
#include "Scene.hpp"
#include "Component.hpp"
#include "System.hpp"

constexpr size_t WINDOW_WIDTH = 800;
constexpr size_t WINDOW_HEIGHT = 600;

constexpr size_t FRAMERATE_LIMIT = 60;

class Simulation: public State {
    public:
        Simulation(std::shared_ptr<Context> context);
        void init() override;
        void processInput() override;
        void update() override;
        void draw() override;
    private:
        std::shared_ptr<Context> context;
        sf::Clock deltaClock;
};