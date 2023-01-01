#include "Menu.h"

void Check_fine(int uid)
{
    RenderWindow window(VideoMode(window_x, window_y), "Library Management System", Style::Default);
    Database db;
    string s[1] = { "Fine: " + to_string(db.getFIne(uid)) + "$" };
    Menu m(1, s);
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
               /* if (event.key.code == Keyboard::Up)
                {
                    m.move_up();
                    break;
                }
                if (event.key.code == Keyboard::Down)
                {
                    m.move_down();
                    break;
                }*/
                if (event.key.code == Keyboard::Escape)
                {
                    window.close();
                    Student_panel(uid);
                    return;
                }
            }
        }
        m.draw(window);
        window.display();
    }
}

