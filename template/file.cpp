
#include <SFML/Graphics.hpp>

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

    sf::Color bgColor = sf::Color::Black;

    std::vector<sf::Drawable*> entities{};

    sf::Uint64 frames = 0;

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
        }

        frames += 1;

        window.clear ( bgColor );

        for ( sf::Drawable* d : entities ) window.draw ( *d );

        window.display();
    }

    return 0;
}
