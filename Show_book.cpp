#include "Menu.h"

void Show_book(int uid)
{
    RenderWindow window(VideoMode(window_x, window_y), "Library Management System", Style::Default);
    Database db;
    vector <Book> b;
    b = db.getBooks();
    int cnt = b.size();
    string s[512];
    for (int i = 0; i < cnt; ++i)
    {
        s[i] = to_string(b[i].getID()) + ". " + b[i].getName() + ", " + b[i].getAuthor();
        cout << s[i] << endl;
    }
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
                else if (event.key.code == Keyboard::Escape)
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
        m.draw(window);
        window.display();
    }
}

