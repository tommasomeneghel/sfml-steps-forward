
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

#include "etc/entity.hpp"
#include "etc/utils.hpp"

int main(int argc, char const *argv[])
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    settings.sRgbCapable = false;

    //! constants are defined here
    const float movementMultiplier { 0.1f };

    bool error { false };

    sf::RenderWindow window{};
    window.create ( 
        sf::VideoMode ( 800, 600, 32U ), 
        "Placeholder", 
        sf::Style::Close | sf::Style::Titlebar );
    window.setPosition ( sf::Vector2i ( 0, 0 ) );
    window.setFramerateLimit ( 72 );

    sf::Color bgColor { sf::Color::Black };

    //! sprites and assets get declared here
    //! remember the format error = something.loadFromFile (...)
    std::vector<sf::Drawable*> entities{};

    sf::Event::JoystickMoveEvent mevt{};

    //! entities get declared here
    const sf::Vector2<float> windowCenter (400.0f, 300.0f);

    Player p(windowCenter, 1000, 50);

    sf::CircleShape p_circle;
    p_circle.setFillColor ( sf::Color::Blue );
    p_circle.setRadius ( 20.0f );
    p_circle.setPosition ( p.getPos() );
    entities.push_back ( &p_circle );

    sf::Uint64 frames { 0 };
    sf::Clock time{};

    if ( error ) { bgColor = sf::Color::Red; }

    sf::Event event{};

    while ( window.isOpen() )
    {
        while ( window.pollEvent ( event ) )
        {
            if ( event.type == sf::Event::Closed )
            {
                window.close();
            }

            if ( event.type == sf::Event::JoystickMoved )
            {
                mevt = event.joystickMove;
            }
        }

        frames += 1;

        //! code gets inserted here
        sf::Vector2<float> posa{p.getPos()};
        posa.x += sf::Joystick::getAxisPosition ( 0, sf::Joystick::Axis::X ) * movementMultiplier;
        posa.y += sf::Joystick::getAxisPosition ( 0, sf::Joystick::Axis::Y ) * movementMultiplier;
        adjust ( posa.x, posa.y, window, p_circle.getRadius() ); //modifies arguments
        p.setPos ( posa );
        p_circle.setPosition ( posa );

        window.clear ( bgColor );

        for ( sf::Drawable* d : entities ) window.draw ( *d );

        window.display();
    }

    return 0;
}
