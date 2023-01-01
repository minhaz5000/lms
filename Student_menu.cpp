#include "Menu.h"

void Student_menu()
{
    RenderWindow window(VideoMode(window_x, window_y), "Library Management System", Style::Default);
    string arr[3];
    arr[0] = "Register";
    arr[1] = "Login";
    arr[2] = "Back to Main Menu";
    Menu m(3, arr);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (event.type == Event::KeyReleased)
            {
                if (event.key.code == Keyboard::Up)
                {
                    m.move_up();
                    break;
                }
                if (event.key.code == Keyboard::Down)
                {
                    m.move_down();
                    break;
                }
                if (event.key.code == Keyboard::Return)
                {
                    int x = m.menu_pressed();
                    if (x == 0)
                    {
                        window.close();
                        Student_register();
                        return;

                    }
                    if (x == 1)
                    {
                        window.close();
                        Student_login();
                        return;
                    }
                    if (x == 2)
                    {
                        window.close();
                        Main_menu();
                        return;
                    }
                }
            }
        }
        m.draw(window);
        window.display();
    }
}

