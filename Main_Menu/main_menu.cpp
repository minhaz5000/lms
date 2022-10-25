#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/WindowStyle.hpp>

int main()
{
    sf::Texture logo;
    if (!logo.loadFromFile("../UI/resources/splash/sp.jpg"))
        exit(0);
    sf::Sprite sp;
    sp.setTexture(logo);
    sp.scale(0.2, 0.2);
    int logoWidth = sp.getGlobalBounds().width;
    int logoHeight = sp.getGlobalBounds().height;

    sf::RenderWindow window(sf::VideoMode(logoWidth, logoHeight), "SFML works!", sf::Style::None);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sp);
        window.display();
    }

    return 0;
}
