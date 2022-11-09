#include <SFML/Graphics.hpp>
#include <vector>


int main(int argc, char const *argv[])
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    settings.sRgbCapable = false;

    bool error { false };

    sf::RenderWindow window{};
    window.create ( 
        sf::VideoMode ( 800, 600, 32U ), 
        "FPS Visualizer", 
        sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize );
    window.setPosition ( sf::Vector2i ( 0, 0 ) );

    sf::Color bgColor = sf::Color::Black;

    std::vector<sf::Drawable*> entities{};

    sf::Font fpsFont {};
    error = fpsFont.loadFromFile ( "fonts/Monocraft.otf" );

    sf::Text fpsText {};
    fpsText.setFont ( fpsFont );
    fpsText.setString ( "placeholder" );
    fpsText.setCharacterSize ( 50 );
    fpsText.setFillColor ( sf::Color::Blue );
    fpsText.setPosition ( sf::Vector2f { 20.0f, 20.0f } );
    entities.push_back ( &fpsText );

    sf::Texture treeImage{};
    error = treeImage.loadFromFile ( "assets/wise_magical_tree.jpeg" );

    sf::Sprite wiseMagicalTree{};
    wiseMagicalTree.setTexture ( treeImage );
    sf::FloatRect bounds = wiseMagicalTree.getLocalBounds ();
    wiseMagicalTree.setOrigin ( sf::Vector2f ( bounds.width / 2.0f, bounds.height / 2.0f ) );
    wiseMagicalTree.setPosition ( sf::Vector2f { 400.0f, 400.0f } );
    wiseMagicalTree.setScale ( sf::Vector2f ( 0.5f, 0.5f ) );
    entities.push_back ( &wiseMagicalTree );

    sf::Clock rep{};
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

        wiseMagicalTree.setRotation ( rep.getElapsedTime().asSeconds() * 360.0f );

        if ( rep.getElapsedTime().asSeconds() >= 1.0f )
        {
            rep.restart();
            fpsText.setString ( std::to_string ( frames ) );
            frames = 0;
        }

        window.clear ( bgColor );

        for ( sf::Drawable* d : entities ) window.draw ( *d );

        window.display();
    }

    return 0;
}
