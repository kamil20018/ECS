#include "Component.hpp"



// //we count components from 0
int Component::componentCount = -1;

Component::Component(){
    componentCount++;
}

std::string Component::getDescription(){
    return "this component has no description";
}

int PositionComponent::id = -1;
PositionComponent::PositionComponent(int x, int y): x(x), y(y) {};
void PositionComponent::debugPrint(){
    std::cout << getDescription() << std::endl;
}
std::string PositionComponent::getDescription(){
    return (std::stringstream() << "POSITION | x: " << x << ", y: " << y).str();
}

int SizeComponent::id = -1;
SizeComponent::SizeComponent(int width, int height): width(width), height(height) {};
void SizeComponent::debugPrint(){
    std::cout << getDescription() << std::endl;
}
std::string SizeComponent::getDescription(){
    return (std::stringstream() << "SIZE | width: " << width << ", height: " << height).str();
}

int HpComponent::id = -1;
HpComponent::HpComponent(int Hp): Hp(Hp){};
void HpComponent::debugPrint(){
    std::cout << getDescription() << std::endl;
}
std::string HpComponent::getDescription(){
    return (std::stringstream() << "HP | Hp: " << Hp).str();
}


int PoisonedComponent::id = -1;
PoisonedComponent::PoisonedComponent(int damage, int duration) : damage(damage), duration(duration){};
void PoisonedComponent::debugPrint(){
    std::cout << getDescription() << std::endl;
}

std::string PoisonedComponent::getDescription(){
    return (std::stringstream() << "POISONED | damage: " << damage << ", duration: " << duration).str();
}

int BodyColorComponent::id = -1;
BodyColorComponent::BodyColorComponent(sf::Color color) : color(color){};
void BodyColorComponent::debugPrint(){
    printf("Color component");
}