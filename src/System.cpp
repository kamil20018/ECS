#include "System.hpp"

System::System(std::shared_ptr<Scene> scene) : scene(scene) {};


void System::applyPoison(){
    std::cout << "applyPoison" << std::endl;
    
    std::vector<EntityID> removables;

    //poision removes hp
    for(auto& [entityID, poisonedComponent]: scene->getComponents<PoisonedComponent>()){
        if(scene->entityHasComponent<HpComponent>(entityID)){
            std::cout << entityID << " has Poisoned Component, damage: " << poisonedComponent->damage << " duration: " << poisonedComponent->duration << std::endl;
            scene->getComponent<HpComponent>(entityID)->Hp -= poisonedComponent->damage;
        }
        //if something w/o hp got poisoned we want to remove the poisoned effect anyway
        poisonedComponent->duration--;
        if(poisonedComponent->duration == 0){
            removables.push_back(entityID);
        }
    }

    for(auto removable: removables){
        scene->removeComponent<PoisonedComponent>(removable);
    }
}

void System::drawComponents(sf::Vector2i mousePos){

    for(auto& [entityID, position]: scene->getComponents<PositionComponent>()){
        if(scene->entityHasComponent<SizeComponent>(entityID)){
            auto size = scene->getComponent<SizeComponent>(entityID);
            if(position->x * TILE_SIZE < mousePos.x && mousePos.x < position->x * TILE_SIZE + size->width &&
                position->y * TILE_SIZE < mousePos.y && mousePos.y < position->y * TILE_SIZE + size->height
            ){

                if(ImGui::Begin("Debug component list", NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse)){
                auto components = scene->getEntityComponents(entityID);
                for(int i = 0; i < MAX_COMPONENTS; i++){
                    bool hasComponent = (*components)[i];
                    if(hasComponent){
                        ImGui::Text(scene->getDescription(entityID, i).c_str());
                    }
                }
                
                }ImGui::End();
                return;
            }
        }
    }
}

void System::drawEntities(std::shared_ptr<sf::RenderWindow> window){
    for(auto& [entityID, bodyColor]: scene->getComponents<BodyColorComponent>()){
        if(scene->entityHasComponent<PositionComponent>(entityID) && scene->entityHasComponent<SizeComponent>(entityID)){
            auto position = scene->getComponent<PositionComponent>(entityID);
            auto size = scene->getComponent<SizeComponent>(entityID);
            sf::RectangleShape rectangle(sf::Vector2f(size->width, size->height));
            rectangle.setFillColor(bodyColor->color);
            rectangle.setPosition(position->x * TILE_SIZE, position->y * TILE_SIZE);
            window->draw(rectangle);
        }
    }
}

void System::debugPrint(){
    for(auto& [entityID, hpComponent]: scene->getComponents<HpComponent>()){
        std::cout << entityID << " hp: " << hpComponent->Hp << std::endl;
    }
}