#include "Simulation.h"

Simulation::Simulation(std::shared_ptr<Context> context): context(context){
    if(!ImGui::SFML::Init(*_window)){
        std::cout << "imgui sfml failed to init" << std::endl;
    }

    auto scene = std::make_shared<Scene>();
    System system(scene);

    for(int i = 0; i < 5; i++){
        EntityID dog = scene->createEntity();

        auto poison = std::make_shared<PoisonedComponent>(1, i + 1);
        auto hp = std::make_shared<HpComponent>(100);
        auto color = std::make_shared<BodyColorComponent>(sf::Color::Red);
        auto position = std::make_shared<PositionComponent>(i, i);

        (scene->addComponent(dog, poison))
            .addComponent(dog, hp)
            .addComponent(dog, color)
            .addComponent(dog, position);

        for(int i = 0; i < 6; i++){
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
    ImGui::Begin("title");
    ImGui::Text("nie pierdol");
    ImGui::End();
}

void Simulation::draw(){
    _window->clear();
    ImGui::SFML::Render(*_window);
    _window->display();
}