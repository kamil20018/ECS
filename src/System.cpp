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

void System::debugPrint(){
    for(auto& [entityID, hpComponent]: scene->getComponents<HpComponent>()){
        std::cout << entityID << " hp: " << hpComponent->Hp << std::endl;
    }
}