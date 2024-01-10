#include <iostream>

#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

#include "Scene.hpp"
#include "Component.hpp"
#include "System.hpp"

constexpr size_t WINDOW_WIDTH = 800;
constexpr size_t WINDOW_HEIGHT = 600;

constexpr size_t FRAMERATE_LIMIT = 60;

sf::Clock deltaClock;

void init();
void draw(sf::RenderWindow &window);
void processInputs(sf::RenderWindow &window);
void update(sf::RenderWindow &window);

int main()
{

    auto scene = std::make_shared<Scene>();

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

    }
    System system(scene);

    for(int i = 0; i < 6; i++){
        system.debugPrint();    
        system.applyPoison();
    }


    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "ECS");
    if(!ImGui::SFML::Init(window)){
        std::cout << "imgui sfml failed to init" << std::endl;
    }

    window.setFramerateLimit(FRAMERATE_LIMIT);
    window.setPosition(sf::Vector2i(
            sf::VideoMode::getDesktopMode().width / 2 - WINDOW_WIDTH / 2,
            sf::VideoMode::getDesktopMode().height / 2 - WINDOW_HEIGHT / 2)
        );

    init();
    
    while (window.isOpen())
    {
        processInputs(window);
        update(window);        
        window.clear();
        draw(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}

void init(){

}

void processInputs(sf::RenderWindow &window){
    sf::Event event;
    while (window.pollEvent(event))
    {
        //ImGui::SFML::ProcessEvent(window, event);
        ImGui::SFML::ProcessEvent(window, event);
        if (event.type == sf::Event::Closed){
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Escape:
                    window.close();
                    break;
            }
        }
    }
}

void update(sf::RenderWindow &window){
    ImGui::SFML::Update(window, deltaClock.restart());
    ImGui::Begin("title");
    ImGui::Text("nie pierdol");
    ImGui::End();
}

void draw(sf::RenderWindow &window){
    ImGui::SFML::Render(window);
    window.display();
}