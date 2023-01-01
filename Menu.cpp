#include "Menu.h"
#include <SFML/Graphics/Color.hpp>
using namespace std;
using namespace sf;

Database db;


Menu::Menu(int x, string* arr)
{
    if (!font.loadFromFile("resources/fonts/IBM-Plex-Sans/IBMPlexSans-Bold.ttf"))
        std::cerr << "Font Load Error" << std::endl;
    background.setSize(Vector2f(window_x, window_y));
    Maintexture.loadFromFile("resources/images/bg.jpg");
    background.setTexture(&Maintexture);
    set_menu_count(x);
    set_elements(arr);
}

void Menu::set_elements(string* arr)
{
    for (int i = 0; i < menu_count; ++i)
    {
        menu[i].setFont(font);
        menu[i].setFillColor(Color::White);
        menu[i].setString(arr[i]);
        menu[i].setOutlineColor(sf::Color::Black);
        menu[i].setOutlineThickness(5);
        menu[i].setCharacterSize(40);
        menu[i].setPosition((window_x - arr[i].size()) / 2 - 100, window_y / 2 - ((menu_count / 2) - i) * 75);
    }

    menu_selected = -1;
}

Menu::~Menu()
{

}
int Menu::menu_pressed()
{
    return menu_selected;
}

void Menu::set_menu_count(int x)
{
    menu_count = x;
}

int Menu::get_menu_count() const
{
    return menu_count;
}

void Menu::draw(RenderWindow& window)
{
    window.clear();
    window.draw(background);
    for (int i = 0; i < menu_count; ++i)
    {
        window.draw(menu[i]);
    }
}

void Menu::move_up()
{
    if (menu_selected - 1 >= 0)
    {
        menu[menu_selected].setFillColor(Color::White);
        --menu_selected;

        if (menu_selected == -1)
        {
            menu_selected = menu_count - 1;
        }
        menu[menu_selected].setFillColor(Color::Red);
    }
}
void Menu::move_down()
{
    if (menu_selected + 1 <= menu_count)
    {
        menu[menu_selected].setFillColor(Color::White);
        ++menu_selected;

        if (menu_selected == menu_count)
        {
            menu_selected = 0;
        }
        menu[menu_selected].setFillColor(Color::Red);
    }
}

