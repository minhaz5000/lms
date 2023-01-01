#include "Menu.h"

void Main_menu()
{
    RenderWindow window(VideoMode(window_x, window_y), "Library Management System", Style::Default);
    string arr1[3];
    arr1[0] = "Admin";
    arr1[1] = "Student";
    arr1[2] = "Exit";
    Menu m(3, arr1);

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
                        Admin_menu();
                        return;
                    }
                    if (x == 1)
                    {
                        window.close();
                        Student_menu();
                        return;
                    }
                    if (x == 2)
                        window.close();
                }
            }
        }
        m.draw(window);
        window.display();
    }
}

