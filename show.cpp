#include "Menu.h"

void show(string *s, int cnt, int uid)
{
    RenderWindow window(VideoMode(window_x, window_y), "Library Management System", Style::Default);
    
    Menu m(cnt, s);
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
                /*if (event.key.code == Keyboard::Up)
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
                    Search_book(uid);
                    return;
                }
            }
        }
        m.draw(window);
        window.display();
    }
}

