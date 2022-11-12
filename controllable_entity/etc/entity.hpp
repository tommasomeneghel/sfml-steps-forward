#pragma once

#include <SFML/Graphics.hpp>
#include <stdint-gcc.h>

struct Player
{
private:
    static uint64_t count;
public:
    static uint64_t getCount();
public:
    float x, y;
    uint64_t hp, dmg;
public: 
    Player(float x, float y, uint64_t hp, uint64_t dmg);
    Player(sf::Vector2<float> pos, uint64_t hp, uint64_t dmg);
    ~Player();
public: // getters
    sf::Vector2<float> getPos() const;
public: // setters
    void setPos ( const sf::Vector2<float> pos );
};

uint64_t Player::count = 0;

#include "../model/entity.cpp"