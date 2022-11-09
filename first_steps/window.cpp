#include <SFML/Graphics.hpp>

int main(int argc, char const *argv[])
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    sf::RenderWindow window;
    window.create ( sf::VideoMode ( 800, 600 ), "HST" );
    window.setPosition ( sf::Vector2i ( 50, 50 ) );

    sf::RectangleShape rect;
    rect.setSize ( sf::Vector2f ( 100, 200 ) );
    rect.setPosition ( sf::Vector2f ( 0.0f, 0.0f ) );
    rect.setFillColor ( sf::Color::Green );
    bool clicked = false;

    sf::Clock timer;

    while ( window.isOpen () )
    {
        sf::Event latestEvent;

        while ( window.pollEvent ( latestEvent ) )
        {
            if ( latestEvent.type == sf::Event::Closed ) 
            {
                window.close();
            }

            if ( latestEvent.type == sf::Event::MouseButtonPressed )
            {
                clicked = true;
                timer.restart();
                rect.setFillColor ( sf::Color::Blue );
            }

            if ( latestEvent.type == sf::Event::MouseButtonReleased )
            {
                rect.setFillColor ( sf::Color::Red );
            }
        }
        if ( clicked && timer.getElapsedTime() > sf::milliseconds ( 2000 ) )
        {
            rect.setFillColor ( sf::Color::Yellow );
        }

        window.clear ();
        window.draw ( rect );
        window.display ();
    }

    return 0;
}