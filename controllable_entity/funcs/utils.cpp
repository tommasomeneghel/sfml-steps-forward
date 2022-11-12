#include <cmath>
#include <SFML/Graphics.hpp>

#include "../etc/utils.hpp"

inline double getRadians ( const double deg )
{
    return deg * M_PI / 180.0;
}

void adjust ( float &x, float &y, sf::RenderWindow &window, float circleradius = 0.0f )
{
    sf::Vector2<sf::Uint32> size = window.getSize();
    if ( x + 2 * circleradius > (float) size.x ) x = ((float) size.x) - 2 * circleradius;
    else if ( x < 0.0f ) x = 0.0f;
    if ( y + 2 * circleradius > (float) size.y ) y = ((float) size.y) - 2 * circleradius;
    else if ( y < 0.0f ) y = 0.0f;
}