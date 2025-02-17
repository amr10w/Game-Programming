/*#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    unsigned int width_window = 800.f;
    unsigned int height_window = 600.f;
    sf::RenderWindow window(sf::VideoMode(width_window, height_window), "SFML Works");

    sf::CircleShape CGreen(50.f);
    CGreen.setFillColor(sf::Color::Green);
    CGreen.setPosition(100.f, 100.f);
    float ix_CGreen = -0.03f;
    float iy_CGreen = 0.02f;

    sf::CircleShape CBlue(100.f);
    CBlue.setFillColor(sf::Color::Blue);
    CBlue.setPosition(200.f, 200.f);
    float ix_CBlue = 0.02f;
    float iy_CBlue = 0.04f;

    sf::CircleShape CPurple(75.f);
    CPurple.setFillColor(sf::Color(255, 0, 255));
    CPurple.setPosition(300.f, 300.f);
    float ix_CPurple = -0.02f;
    float iy_CPurple = -0.01f;

    sf::RectangleShape RRed(sf::Vector2f(50.f, 25.f));
    RRed.setFillColor(sf::Color::Red);
    RRed.setPosition(200.f, 200.f);
    float ix_RRed = 0.1f;
    float iy_RRed = 0.15f;

    sf::RectangleShape RGreen(sf::Vector2f(50.f, 100.f));
    RGreen.setFillColor(sf::Color::Green);
    RGreen.setPosition(300.f, 250.f);
    float ix_RGreen = -0.02f;
    float iy_RGreen = 0.02f;

    sf::RectangleShape RTeal(sf::Vector2f(100.f, 100.f));
    RTeal.setFillColor(sf::Color(0, 255, 255));
    RTeal.setPosition(25.f, 100.f);
    float ix_RTeal = -0.02f;
    float iy_RTeal = -0.02f;

    sf::Font myFont;
    if (!myFont.loadFromFile("KillerTech.ttf"))
    {
        std::cerr << "No File loaded, please check again\n";
        exit(-1);
    }
    sf::Text text("Sample Test", myFont, 18);
    text.setFillColor(sf::Color(255, 255, 255));
    text.setPosition(0, height_window - (float)text.getCharacterSize());


    while (window.isOpen())
    {
        //------------------------event-----------------------------------------------------------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        //------------------------event---------------------------------------

        //------------------------motion----------------------------------------
        CGreen.setPosition(CGreen.getPosition().x + ix_CGreen, CGreen.getPosition().y + iy_CGreen);
        CBlue.setPosition(CBlue.getPosition().x + ix_CBlue, CBlue.getPosition().y + iy_CBlue);
        CPurple.setPosition(CPurple.getPosition().x + ix_CPurple, CPurple.getPosition().y + iy_CPurple);
        RRed.setPosition(RRed.getPosition().x + ix_RRed, RRed.getPosition().y + iy_RRed);
        RGreen.setPosition(RGreen.getPosition().x + ix_RGreen, RGreen.getPosition().y + iy_RGreen);
        RTeal.setPosition(RTeal.getPosition().x + ix_RTeal, RTeal.getPosition().y + iy_RTeal);
        //------------------------motion----------------------------------------

        //-------------------------draw---------------------------------------------
        window.clear();
        window.draw(CGreen);
        window.draw(CBlue);
        window.draw(CPurple);
        window.draw(RRed);
        window.draw(RGreen);
        window.draw(RTeal);
        window.draw(text);
        window.display();
        //-------------------------draw---------------------------------------------

    }
    return 0;
}
*/