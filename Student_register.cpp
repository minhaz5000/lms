#include "Menu.h"

void Student_register(string st)
{
    static int r = 0;
    static int id = 0;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Student Register");
    Font font;
    if (!font.loadFromFile("resources/fonts/IBM-Plex-Sans/IBMPlexSans-Bold.ttf"))
        std::cerr << "Font Load Error" << std::endl;
    RectangleShape background;
    Texture Maintexture;

    background.setSize(Vector2f(window_x, window_y));
    Maintexture.loadFromFile("resources/images/bg.jpg");
    background.setTexture(&Maintexture);

    sf::Text studentText;
    studentText.setFont(font);
    studentText.setString(st);
    studentText.setCharacterSize(50);
    studentText.setFillColor(sf::Color::White);
    studentText.setOutlineColor(sf::Color::Black);
    studentText.setOutlineThickness(5);
    studentText.setPosition(sf::Vector2f(600, 400));

    Database db;

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
    // studentText.setString("No Password Entered!");
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
    inputField.setPosition(sf::Vector2f(900, 400));
    inputField.setString("");

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
                    sf::String str = inputField.getString();
                    str.erase(str.getSize() - 1);
                    inputField.setString(str);
                }
                if (event.text.unicode == 13)
                {
                    if (inputField.getString().getSize() > 0)
                    {
                        std::string str = inputField.getString();
                        window.close();
                        if (r == 0)
                        {
                            id = stoi(str);
                            ++r;
                            Student_register("Password:");
                        }
                        else
                        {
                            addStudent(id, str);
                            Student_menu();
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
                    Student_menu();
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
                    inputField.setString(inputField.getString() + static_cast<char>(event.text.unicode));
                }
            }

        }
        window.clear();
        window.draw(background);
        window.draw(studentText);
        // window.draw(passwordInput);
        window.draw(inputField);
        // window.draw(loginButton);
        window.display();
    }
}

