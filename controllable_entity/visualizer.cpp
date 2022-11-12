
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

#include "model/entity.cpp"
#include "etc/utils.cpp"
#include "etc/statics.cpp"

int main(int argc, char const *argv[])
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    settings.sRgbCapable = false;

    bool error { false };

    sf::RenderWindow window{};
    window.create ( 
        sf::VideoMode ( 800, 600, 32U ), 
        "Placeholder", 
        sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize );
    window.setPosition ( sf::Vector2i ( 0, 0 ) );
    window.setFramerateLimit ( 72 );

    sf::Color prev = sf::Color::Black, bgColor = sf::Color::Black;

    //! sprites and assets get declared here
    //! remember the format error = something.loadFromFile (...)
    sf::Event::JoystickMoveEvent mevt{};

    std::vector<sf::Drawable*> entities{};

    //! entities get declared here
    const sf::Vector2<float> centerpoint (100, 100);

    Player p(100, 100, 1000, 50);
    Player q(300, 100, 1000, 50);

    sf::CircleShape p_circle;
    p_circle.setFillColor ( sf::Color::Blue );
    p_circle.setRadius ( 20.0f );
    p_circle.setPosition ( p.getPos() );
    entities.push_back ( &p_circle );

    sf::CircleShape q_circle;
    q_circle.setFillColor ( sf::Color(0xff, 0x8f, 0x00, 0xff) );
    q_circle.setRadius ( 20.0f );
    q_circle.setPosition ( q.getPos() );
    entities.push_back ( &q_circle );

    sf::CircleShape mirror;
    mirror.setOrigin ( 0.0f, 0.0f );
    mirror.setFillColor (sf::Color::Transparent );
    mirror.setOutlineColor ( sf::Color::Green );
    mirror.setOutlineThickness ( 1.5f );
    mirror.setPosition ( p.getPos() );
    mirror.setRadius ( 20.0f );
    entities.push_back ( &mirror );

    sf::CircleShape second;
    second.setOrigin ( 0.0f, 0.0f );
    second.setFillColor (sf::Color::Transparent );
    second.setOutlineColor ( sf::Color::Cyan );
    second.setOutlineThickness ( 1.5f );
    second.setPosition ( q.getPos() );
    second.setRadius ( 20.0f );
    entities.push_back ( &second );

    sf::Uint64 frames { 0 };
    sf::Clock time{};

    if ( error ) { bgColor = sf::Color(0x0f0f0fff); }

    sf::Event event{};

    while ( window.isOpen() )
    {
        while ( window.pollEvent ( event ) )
        {
            if ( event.type == sf::Event::Closed )
            {
                window.close();
            }

            if ( event.type == sf::Event::JoystickConnected )
            {
                prev = bgColor;
                bgColor = sf::Color(0x30, 0x30, 0x30, 0xff);
            }

            if ( event.type == sf::Event::JoystickDisconnected )
            {
                bgColor = prev;
            }

            if ( event.type == sf::Event::JoystickMoved )
            {
                mevt = event.joystickMove;
            }
        }

        frames += 1;

        //! code gets inserted here
        sf::Vector2<float> posa{};
        sf::Vector2<float> posb{};
        if (sf::Joystick::isConnected (0)) 
        {
            posa.x = centerpoint.x          + sf::Joystick::getAxisPosition ( 0, sf::Joystick::Axis::X ) * 0.2f;
            posa.y = centerpoint.y          + sf::Joystick::getAxisPosition ( 0, sf::Joystick::Axis::Y ) * 0.2f;
            posb.x = centerpoint.x + 200.0f + sf::Joystick::getAxisPosition ( 0, sf::Joystick::Axis::U ) * 0.2f;
            posb.y = centerpoint.y          + sf::Joystick::getAxisPosition ( 0, sf::Joystick::Axis::V ) * 0.2f;
        } 
        else 
        {
            float rad = getRadians ( time.getElapsedTime().asSeconds() * 90.0f );
            posa.x = centerpoint.x          + std::cos(rad) * 20.0f;
            posa.y = centerpoint.y          + std::sin(rad) * 20.0f;
            posb.x = centerpoint.x + 200.0f + std::cos(-rad + M_PI ) * 20.0f; // synchronized but inverted rotation
            posb.y = centerpoint.y          + std::sin(-rad + M_PI ) * 20.0f;
        }
        p.setPos ( posa );
        p_circle.setPosition (posa);
        q.setPos ( posb );
        q_circle.setPosition (posb);

        window.clear ( bgColor );

        for ( sf::Drawable* d : entities ) window.draw ( *d );

        window.display();
    }

    return 0;
}
