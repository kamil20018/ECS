#pragma once

#include "Scene.hpp"

class System {
    public:
        System(std::shared_ptr<Scene> scene);
        void applyPoison();
        void debugPrint();
    private:
        std::shared_ptr<Scene> scene;
};