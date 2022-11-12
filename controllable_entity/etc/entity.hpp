#ifndef __entity_h
#define __entity_h 1
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
    Player(const sf::Vector2<float> &pos, uint64_t hp, uint64_t dmg);
    ~Player();
public: // getters
    sf::Vector2<float> getPos() const;
public: // setters
    void setPos ( const sf::Vector2<float> pos );
};

#endif // __entity_h