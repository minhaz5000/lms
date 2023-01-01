#include "Menu.h"

void Admin_menu()
{
    RenderWindow window(VideoMode(window_x, window_y), "Library Management System", Style::Default);
    string arr[2];
    arr[0] = "Login";
    arr[1] = "Back to Main Menu";
    Menu m(2, arr);

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
                        Admin_login();
                        //cout << pass;
                        return;
                    }
                    if (x == 1)
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

