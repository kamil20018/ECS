#pragma once

#include <stdio.h>
#include <SFML/Graphics.hpp>


struct Component {
    Component();
    static int componentCount;
};

struct PositionComponent : public Component {
    PositionComponent(int x, int y);
    static int id;
    int x;
    int y;
    void debugPrint();
};

struct HpComponent : public Component {
    HpComponent(int Hp);
    static int id;
    int Hp;
    void debugPrint();
};

struct PoisonedComponent : public Component {
    PoisonedComponent(int damage, int duration);
    static int id;
    int damage;
    int duration;
    void debugPrint();
};

struct BodyColorComponent : public Component {
    BodyColorComponent(sf::Color color);
    static int id;
    sf::Color color;
    void debugPrint();
};