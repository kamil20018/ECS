#include <iostream>

#include "Game.h"

int main()
{

    Game game;
    game.run();
    
    return 0;
}

// void init(){

// }

// void processInputs(sf::RenderWindow &window){
//     sf::Event event;
//     while (window.pollEvent(event))
//     {
//         //ImGui::SFML::ProcessEvent(window, event);
//         ImGui::SFML::ProcessEvent(window, event);
//         if (event.type == sf::Event::Closed){
//             window.close();
//         }
//         else if (event.type == sf::Event::KeyPressed) {
//             switch (event.key.code) {
//                 case sf::Keyboard::Escape:
//                     window.close();
//                     break;
//             }
//         }
//     }
// }

// void update(sf::RenderWindow &window){
//     ImGui::SFML::Update(window, deltaClock.restart());
//     ImGui::Begin("title");
//     ImGui::Text("nie pierdol");
//     ImGui::End();
// }

// void draw(sf::RenderWindow &window){
//     ImGui::SFML::Render(window);
//     window.display();
// }