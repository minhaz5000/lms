#include "Menu.h"

void Admin_panel()
{
    RenderWindow window(VideoMode(window_x, window_y), "Library Management System", Style::Default);
    string arr[8];
    arr[0] = "Search for a Book";
    arr[1] = "Search Student";
    arr[2] = "Grant/Deny Book Request";
    arr[3] = "Add Book";
    arr[4] = "Remove Book";
    arr[5] = "Display the List of Books";
    arr[6] = "Back";

    Menu m(8, arr);

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
                        Search_book(-1);
                        return;
                    }
                    else if (x == 1)
                    {
                        window.close();
                        Search_student();
                        return;
                    }
                    else if (x == 2)
                    {
                        window.close();
                        Grant_Deny_Request();
                        return;
                    }
                    else if (x == 3)
                     {
                         window.close();
                         Add_Book();
                         return;
                     }
                     else if (x == 4)
                     {
                         window.close();
                         Remove_book();
                         return;
                     }
                     else if (x == 5)
                     {
                         window.close();
                         Show_book(-1);
                         return;
                     }
                     else if (x == 6)
                     {
                         window.close();
                         Admin_menu();
                         return;
                     }
                }
            }
        }
        m.draw(window);
        window.display();
    }
}

