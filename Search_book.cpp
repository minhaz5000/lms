#include "Menu.h"

void Search_book(int uid)
{
    RenderWindow window(VideoMode(window_x, window_y), "Library Management System", Style::Default);
    string arr[5];
    arr[0] = "Search By Title";
    arr[1] = "Search By Author";
    arr[2] = "Search By Genre";
    arr[3] = "Search By Publisher";
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
                        Search_book_func(uid, 0);
                        return;
                    }
                    else if (x == 1)
                    {
                        window.close();
                        Search_book_func(uid, 1);
                        return;
                    }
                    else if (x == 2)
                    {
                        window.close();
                        Search_book_func(uid, 2);
                        return;
                    }
                    else if (x == 3)
                    {
                        window.close();
                        Search_book_func(uid, 3);
                        return;
                    }
                    else if (x == 4)
                    {
                        window.close();
                        if (uid == -1)
                            Admin_panel();
                        else
                            Student_panel(uid);
                        return;
                    }
                }
            }
        }
        m.draw(window);
        window.display();
    }
}

