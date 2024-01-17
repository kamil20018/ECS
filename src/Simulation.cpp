#include "Simulation.h"

Simulation::Simulation(std::shared_ptr<Context> context): context(context), scene(std::make_shared<Scene>()), system(scene){
    if(!ImGui::SFML::Init(*_window)){
        std::cout << "imgui sfml failed to init" << std::endl;
    }

    for(int i = 0; i < 5; i++){
        EntityID dog = scene->createEntity();

        auto position = std::make_shared<PositionComponent>(i, i);
        auto size = std::make_shared<SizeComponent>(TILE_SIZE, TILE_SIZE);
        auto hp = std::make_shared<HpComponent>(100);
        auto color = std::make_shared<BodyColorComponent>(sf::Color::Red);
        auto poison = std::make_shared<PoisonedComponent>(1, i + 1);

        (scene->addComponent(dog, poison))
            .addComponent(dog, size)
            .addComponent(dog, hp)
            .addComponent(dog, color)
            .addComponent(dog, position);

        for(int i = 0; i < 3; i++){
            system.debugPrint();    
            system.applyPoison();
        }

    }
}

void Simulation::init()
{

}

void Simulation::processInput(){
    sf::Event event;
    while (_window->pollEvent(event))
    {
        //ImGui::SFML::ProcessEvent(window, event);
        ImGui::SFML::ProcessEvent(*_window, event);
        if (event.type == sf::Event::Closed){
            _window->close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Escape:
                    _window->close();
                    break;
            }
        }
    }
}

void Simulation::update(){
    ImGui::SFML::Update(*_window, deltaClock.restart());
}

void Simulation::draw(){
    _window->clear();
    system.drawEntities(_window);
    system.drawComponents(sf::Mouse::getPosition(*_window));
    ImGui::SFML::Render(*_window);
    _window->display();
}