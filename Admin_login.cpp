#include "Menu.h"

void Admin_login()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Login System");
    Font font;
    if (!font.loadFromFile("resources/fonts/IBM-Plex-Sans/IBMPlexSans-Bold.ttf"))
        std::cerr << "Font Load Error" << std::endl;
    RectangleShape background;
    Texture Maintexture;

    background.setSize(Vector2f(window_x, window_y));
    Maintexture.loadFromFile("resources/images/bg.jpg");
    background.setTexture(&Maintexture);

    sf::Text passwordText;
    passwordText.setFont(font);
    passwordText.setString("Password:");
    passwordText.setCharacterSize(35);
    passwordText.setFillColor(sf::Color::White);
    passwordText.setOutlineColor(sf::Color::Black);
    passwordText.setOutlineThickness(5);
    passwordText.setPosition(sf::Vector2f(600, 400));

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
    // passwordText.setString("No Password Entered!");
    // errorMessage.setCharacterSize(35);
    // errorMessage.setFillColor(sf::Color::Red);
    // errorMessage.setPosition(sf::Vector2f(600, 300));

     // Create the input field
    sf::Text inputField;
    inputField.setFont(font);
    inputField.setCharacterSize(50);
    inputField.setFillColor(sf::Color::White);
    inputField.setOutlineColor(sf::Color::Black);
    inputField.setOutlineThickness(5);
    inputField.setPosition(sf::Vector2f(800, 400));
    inputField.setString("");
    std::string str;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::TextEntered)
            {
                // Handle backspace
                if (event.text.unicode == 8 && inputField.getString().getSize() > 0)
                {
                    str.pop_back();
                    string ast(str.size(), '*');
                    inputField.setString(ast);
                }
                if (event.text.unicode == 13)
                {
                    if (inputField.getString().getSize() > 0)
                    {
                        Admin obj;
                        if (obj.verify(str))
                        {
                            window.close();
                            Admin_panel();
                            return;
                        }
                    }
                    // else
                    // {
                    //     window.draw(errorMessage);
                    // }
                }
                else if (event.text.unicode == 27)
                {
                    window.close();
                    Admin_menu();
                    return;
                }
                // Ignore other non-printable characters
                else if (event.text.unicode < 32 || event.text.unicode > 126)
                {
                    continue;
                }
    
                // Append the character to the input field
                else
                {
                    str += static_cast<char>(event.text.unicode);
                    string ast(str.size(), '*');
                    inputField.setString(ast);
                }
            }

        }
        window.clear();
        window.draw(background);
        window.draw(passwordText);
        // window.draw(passwordInput);
        window.draw(inputField);
        // window.draw(loginButton);
        window.display();
    }
}

