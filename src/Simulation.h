#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>


#include "State.h"
#include "Game.h"
#include "Scene.hpp"
#include "Component.hpp"
#include "System.hpp"
#include "Constants.hpp"

class Simulation: public State {
    public:
        Simulation(std::shared_ptr<Context> context);
        void init() override;
        void processInput() override;
        void update() override;
        void draw() override;
    private:
        std::shared_ptr<Context> context;
        std::shared_ptr<Scene> scene;
        System system;

        sf::Clock deltaClock;
};