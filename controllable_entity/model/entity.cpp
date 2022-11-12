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
    ~Player();
public: // getters
    sf::Vector2<float> getPos() const;
public: // setters
    void setPos ( const sf::Vector2<float> pos );
};

Player::Player (float x, float y, uint64_t hp, uint64_t dmg) : x { x }, y { y }, hp { hp }, dmg { dmg }
{
    Player::count++;
}

Player::~Player ( )
{
    Player::count--;
}


inline sf::Vector2<float> Player::getPos() const
{
    return sf::Vector2<float> (this->x, this->y);
}

inline void Player::setPos( const sf::Vector2<float> pos ) 
{
    this->x = pos.x;
    this->y = pos.y;
}

inline uint64_t Player::getCount ( )
{
    return Player::count;
}


// class Player
// {

// public:
//     Player();
//     ~Player();
// public:
//     void setPosX(float x);
//     void setPosY(float y);
//     void setHp(uint64_t hp);
//     void setDmg(uint64_t dmg);
//     float getPosX();
//     float getPosY();
//     uint64_t getHp();
//     uint64_t getDmg();
// private:
//     static uint64_t s_Count;
// private:
//     float m_X;
//     float m_Y;
//     uint64_t m_Hp;
//     uint64_t m_Dmg;
// };

// Player::Player(float m_X, float m_Y, uint64_t m_Hp, uint64_t m_Dmg) : m_X { m_X }, m_Y { m_Y }, m_Hp { m_Hp }, m_Dmg { m_Dmg }
// {
//     Player::s_Count += 1;
// }

// Player::~Player()
// {
//     Player::s_Count -= 1;
// }

// Player::setPosX(float x)
