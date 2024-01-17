#pragma once

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

struct Component {
    Component();
    virtual std::string getDescription();
    static int componentCount;
};

struct PositionComponent : public Component {
    PositionComponent(int x, int y);
    static int id;
    int x;
    int y;
    void debugPrint();
    std::string getDescription() override;
};

struct SizeComponent : public Component {
    SizeComponent(int width, int height);
    static int id;
    int width;
    int height;
    void debugPrint();
    std::string getDescription() override;
};

struct HpComponent : public Component {
    HpComponent(int Hp);
    static int id;
    int Hp;
    void debugPrint();
    std::string getDescription() override;
};

struct PoisonedComponent : public Component {
    PoisonedComponent(int damage, int duration);
    static int id;
    int damage;
    int duration;
    void debugPrint();
    std::string getDescription() override;
}; 

struct BodyColorComponent : public Component {
    BodyColorComponent(sf::Color color);
    static int id;
    sf::Color color;
    void debugPrint();
};