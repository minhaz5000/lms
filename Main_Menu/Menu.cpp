#include "Menu.h"
#include <SFML/Graphics/Color.hpp>

Menu::Menu(double width, double height)
{
    if (!font.loadFromFile("../resources/fonts/IBM-Plex-Sans/IBMPlexSans-Regular.ttf"))
        std::cerr << "Font Load Error" << std::endl;
    //
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setString("Admin");
    menu[0].setCharacterSize(70);
    menu[0].setPosition(400, 200);
    //

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Student");
    menu[1].setCharacterSize(70);
    menu[1].setPosition(400, 300);
    //
    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setCharacterSize(70);
    menu[2].setPosition(400, 400);

    menu_selected = -1;
}

Menu::~Menu()
{

}
int Menu::menu_pressed()
{
    return menu_selected;
}

void Menu::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < MAX_MENU; ++i)
    {
        window.draw(menu[i]);
    }
}

void Menu::move_up()
{
    if (menu_selected - 1 >= 0)
    {
        menu[menu_selected].setFillColor(sf::Color::White);
        --menu_selected;

        if (menu_selected == -1)
        {
            menu_selected = MAX_MENU - 1;
        }
        menu[menu_selected].setFillColor(sf::Color::Blue);
    }
}
void Menu::move_down()
{
    if (menu_selected + 1 <= MAX_MENU)
    {
        menu[menu_selected].setFillColor(sf::Color::White);
        ++menu_selected;

        if (menu_selected == MAX_MENU)
        {
            menu_selected = 0;
        }
        menu[menu_selected].setFillColor(sf::Color::Blue);
    }
}

