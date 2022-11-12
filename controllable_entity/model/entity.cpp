
Player::Player (float x, float y, uint64_t hp = 1000, uint64_t dmg = 50) : x { x }, y { y }, hp { hp }, dmg { dmg }
{
    Player::count++;
}

Player::Player (sf::Vector2<float> pos, uint64_t hp = 1000, uint64_t dmg = 50)
{
    Player ( pos.x, pos.y, hp, dmg );
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
