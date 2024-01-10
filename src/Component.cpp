#include "Component.hpp"



// //we count components from 0
int Component::componentCount = -1;

Component::Component(){
    componentCount++;
}

int PositionComponent::id = -1;
PositionComponent::PositionComponent(int x, int y): x(x), y(y) {};
void PositionComponent::debugPrint(){
    printf("x: %d, y: %d", x, y);
}

int HpComponent::id = -1;
HpComponent::HpComponent(int Hp): Hp(Hp){};
void HpComponent::debugPrint(){
    printf("Hp: %d", Hp);
}

int PoisonedComponent::id = -1;
PoisonedComponent::PoisonedComponent(int damage, int duration) : damage(damage), duration(duration){};
void PoisonedComponent::debugPrint(){
    printf("Damage: %d, Duration: %d", damage, duration);
}

int BodyColorComponent::id = -1;
BodyColorComponent::BodyColorComponent(sf::Color color) : color(color){};
void BodyColorComponent::debugPrint(){
    printf("Color component");
}