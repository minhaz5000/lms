#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>

#define MAX_MENU 3
// enum class Menu {Menu1, Menu2, Menu3, Menu4};
class Menu {
    private:
        int menu_selected;
        sf::Font font;
        sf::Text menu[MAX_MENU];

    public:
        Menu(double width, double height);

        void draw(sf::RenderWindow& window);
        void move_up();
        void move_down();

        int menu_pressed();

        ~Menu();
    };
