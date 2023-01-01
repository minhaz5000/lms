#include "Menu.h"

void Grant_Deny_Request()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Login System");
    Font font;
    if (!font.loadFromFile("resources/fonts/IBM-Plex-Sans/IBMPlexSans-Bold.ttf"))
        std::cerr << "Font Load Error" << std::endl;
    RectangleShape background;
    Texture Maintexture;
    Database db;
    vector<pair<int, int>> r = db.requestHistory();
    int cnt = r.size();
    string s[100];
    for (int i = 0; i < cnt; ++i)
    {
        s[i] = to_string(i + 1) + ". " +  to_string(r[i].first) + ": " + to_string(r[i].second);
    }
    Menu m(cnt, s);
    background.setSize(Vector2f(window_x, window_y));
    Maintexture.loadFromFile("resources/images/bg.jpg");
    background.setTexture(&Maintexture);

    // Create the username and password input fields

    // sf::Text passwordInput;
    // passwordInput.setFont(font);
    // passwordInput.setCharacterSize(70);
    // passwordInput.setFillColor(sf::Color::Black);
    // passwordInput.setPosition(sf::Vector2f(710, 500));

    // Create the login button
    // sf::Text loginButton;
    // loginButton.setFont(font);
    // loginButton.setString("Login");
    // loginButton.setCharacterSize(35);
    // loginButton.setFillColor(sf::Color::White);
    // loginButton.setOutlineColor(sf::Color::Black);
    // loginButton.setOutlineThickness(2.0f);
    // loginButton.setPosition(sf::Vector2f(915, 500));
    // sf::Rect<float> loginButtonRect(loginButton.getPosition().x, loginButton.getPosition().y, loginButton.getGlobalBounds().width, loginButton.getGlobalBounds().height);

    // Create the error message
    // sf::Text errorMessage;
    // errorMessage.setFont(font);
    // inputText.setString("No Password Entered!");
    // errorMessage.setCharacterSize(35);
    // errorMessage.setFillColor(sf::Color::Red);
    // errorMessage.setPosition(sf::Vector2f(600, 300))

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            
            else if (event.type == Event::KeyReleased)
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
                if (event.key.code == Keyboard::A)
                {
                    int x = m.menu_pressed();
                    db.acceptRequest(x + 1);
                    db.writeRequest("request.txt");
                    window.close();
                    Grant_Deny_Request();
                    return;
                }
                else if (event.key.code == Keyboard::D)
                {
                    int x = m.menu_pressed();
                    db.denyRequest(x + 1);
                    db.writeRequest("request.txt");
                    window.close();
                    Grant_Deny_Request();
                    return;
                }
                else if (event.key.code == Keyboard::Escape)
                {
                    window.close();
                    Admin_panel();
                    return;
                }
            }
        }
        window.clear();
        window.draw(background);
        // window.draw(passwordInput);
        m.draw(window);
        // window.draw(loginButton);
        window.display();
    }

}