#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include "user.h"
#include <iostream>
#include <string>
#include "Database.h"

const int window_x = 1920;
const int window_y = 1080;

using namespace std;
using namespace sf;
// #define MAX_MENU 3
// enum class Menu {Menu1, Menu2, Menu3, Menu4};
class Menu {
private:
    int menu_selected;
    Font font;
    int menu_count;
    Text menu[32];
    RectangleShape background;
    Texture Maintexture;

public:
    Menu(int x, string* arr);

    void draw(RenderWindow& window);
    void move_up();
    void move_down();
    int menu_pressed();
    void set_menu_count(int x);
    int get_menu_count() const;
    void set_elements(string* arr);

    ~Menu();
};

void Main_menu();
void Admin_menu();
void Student_menu();
void Admin_login();
void Student_login(string st = "Student ID:");
void Student_register(string st = "Student ID:");
void Student_panel(int uid);
void Admin_panel();
void Add_Book();
void Show_book(int uid);
void Remove_book();
void Place_Request(int uid);
void Check_fine(int uid);
void Search_book(int uid);
void Search_book_func(int uid, int type);
void show(string *s, int cnt, int uid);
void Grant_Deny_Request();
void Show_student(int uid);
void Search_student();

extern Database db;