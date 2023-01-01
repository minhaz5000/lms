#include "Menu.h"
#include "Book.h"


void Add_Book()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Login System");
    Font font;
    if (!font.loadFromFile("resources/fonts/IBM-Plex-Sans/IBMPlexSans-Bold.ttf"))
        std::cerr << "Font Load Error" << std::endl;
    RectangleShape background;
    Texture Maintexture;
    Database db;

    background.setSize(Vector2f(window_x, window_y));
    Maintexture.loadFromFile("resources/images/bg.jpg");
    background.setTexture(&Maintexture);

    string fields[5];
    fields[0] = "Book Name:";
    fields[1] = "Book Author:";
    fields[2] = "Book Publisher:";
    fields[3] = "Book Genre:";
    fields[4] = "";

    sf::Text inputText;
    inputText.setFont(font);
    inputText.setString(fields[0]);
    inputText.setCharacterSize(50);
    inputText.setFillColor(sf::Color::White);
    inputText.setOutlineColor(sf::Color::Black);
    inputText.setOutlineThickness(5);
    inputText.setPosition(sf::Vector2f(550 - fields[0].size(), 400));

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
    // errorMessage.setPosition(sf::Vector2f(600, 300));

     // Create the input field

    Book b;
    sf::Text inputField;
    inputField.setFont(font);
    inputField.setCharacterSize(50);
    inputField.setFillColor(sf::Color::White);
    inputField.setOutlineColor(sf::Color::Black);
    inputField.setOutlineThickness(5);
    inputField.setPosition(sf::Vector2f(900, 400));
    inputField.setString("");

    for (int i = 0; i < 4; ++i)
    {
        bool flag = false;
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
                    if (event.text.unicode == 27)
                    {
                        window.close();
                        Admin_panel();
                        return;
                    }
                    if (event.text.unicode == 13)
                    {
                        if (inputField.getString().getSize() > 0)
                        {
                            std::string str = inputField.getString();
                            
                            if (i == 0)
                            {
                                b.setName(str);
                            }
                            else if (i == 1)
                            {
                                b.setAuthor(str);
                                inputText.setPosition(sf::Vector2f(500, 400));
                            }
                            else if (i == 2)
                            {
                                b.setPublisher(str);
    
                            }
                            else if (i == 3)
                            {
                                b.setGenre(str);
                                window.close();
                                db.addBook(b);
                                db.writeBook("book.txt");
                                Add_Book();
                                return;
                            }
                            flag = true;
                            inputField.setString("");
                            inputText.setString(fields[i + 1]);
                            break;
            
                        }
                        // else
                        // {
                        //     window.draw(errorMessage);
                        // }
                    }
                    else if (event.text.unicode == 27)
                    {
                        window.close();
                        Admin_panel();
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
            if (flag == true)
            {
                flag = false;
                break;
            }
            window.clear();
            window.draw(background);
            window.draw(inputText);
            // window.draw(passwordInput);
            window.draw(inputField);
            // window.draw(loginButton);
            window.display();
        }
    }
}

