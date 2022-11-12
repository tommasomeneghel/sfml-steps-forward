#include <SFML/Graphics.hpp>
#include <stdint-gcc.h>

#include "../etc/entity.hpp"

uint64_t Player::count = 0;

Player::Player (float x, float y, uint64_t hp = 1000, uint64_t dmg = 50) : x { x }, y { y }, hp { hp }, dmg { dmg }
{
    Player::count++;
}

Player::Player (const sf::Vector2<float> &pos, uint64_t hp = 1000, uint64_t dmg = 50)
{
    Player ( pos.x, pos.y, hp, dmg );
}

Player::~Player ( )
{
    Player::count--;
}

sf::Vector2<float> Player::getPos() const
{
    return sf::Vector2<float> (this->x, this->y);
}

void Player::setPos( const sf::Vector2<float> pos ) 
{
    this->x = pos.x;
    this->y = pos.y;
}

uint64_t Player::getCount ( )
{
    return Player::count;
}
