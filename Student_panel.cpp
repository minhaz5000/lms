#include "Menu.h"

void Student_panel(int uid)
{
    RenderWindow window(VideoMode(window_x, window_y), "Library Management System", Style::Default);
    string arr[6];
    arr[0] = "Search for a Book";
    arr[1] = "Browse Books";
    arr[2] = "Place Request for a Book";
    arr[3] = "Check Fines";
    arr[4] = "Back";

    Menu m(5, arr);

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
                         Search_book(uid);
                         return;
                     }
                     else if (x == 1)
                     {
                         window.close();
                         Show_book(uid);
                         return;
                     }
                     else if (x == 2)
                     {
                         window.close();
                         Place_Request(uid);
                         return;
                     }
                     else if (x == 3)
                     {
                         window.close();
                         Check_fine(uid);
                         return;
                     }
                     else if (x == 4)
                     {
                         window.close();
                         Student_menu();
                         return;
                     }
                }
            }
        }
        m.draw(window);
        window.display();
    }
}

