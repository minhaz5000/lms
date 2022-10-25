#include "Menu.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/WindowStyle.hpp>

int main()
{
    sf::RenderWindow MENU(sf::VideoMode(900, 800), "Main Menu", sf::Style::Default);
    Menu main_menu(MENU.getSize().x, MENU.getSize().y);

    while (MENU.isOpen())
    {
        sf::Event event;
        while (MENU.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                MENU.close();
            }
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    main_menu.move_up();
                    break;
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    main_menu.move_down();
                    break;
                }
                if (event.key.code == sf::Keyboard::Return)
                {
               // sf::RenderWindow Admin(sf::VideoMode(1920, 1080), "Admin");
               // sf::RenderWindow Student(sf::VideoMode(1920, 1080), "Student");

                    int x = main_menu.menu_pressed();

                    if (x == 2)
                        MENU.close();
                }
            }
        }
    MENU.clear();
    main_menu.draw(MENU);
    MENU.display();
    }

    return 0;
}
