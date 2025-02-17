/*
#include <iostream>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>

unsigned int width_window = 1000;
unsigned int height_window = 720;

class shape
{
    std::string m_name;
    float m_x_pos,m_y_pos,m_ix,m_iy,m_radius = 50,m_width = 50, m_height = 50;
    int m_r,m_g,m_b;
    sf::CircleShape c;
    sf::RectangleShape rec;
    sf::Text text;

public:
    // Constructor for circle shapes
    shape(std::string name, float x_pos, float y_pos, float ix, float iy, int r, int g, int b, float radius)
        : m_name(name), m_x_pos(x_pos), m_y_pos(y_pos), m_ix(ix), m_iy(iy), m_r(r), m_g(g), m_b(b), m_radius(radius)
    {
        c.setRadius(m_radius);
        c.setFillColor(sf::Color(r, g, b));
        c.setPosition(x_pos, y_pos);

        // Set default text
        text.setString(m_name);
        text.setCharacterSize(12);
        text.setFillColor(sf::Color(255, 255, 255));
    }

    // Constructor for rectangle shapes
    shape(std::string name, float x_pos, float y_pos, float ix, float iy, int r, int g, int b, float width, float height)
        : m_name(name), m_x_pos(x_pos), m_y_pos(y_pos), m_ix(ix), m_iy(iy), m_r(r), m_g(g), m_b(b), m_width(width), m_height(height)
    {
        rec.setSize(sf::Vector2f(m_width, m_height));
        rec.setFillColor(sf::Color(r, g, b));
        rec.setPosition(x_pos, y_pos);

        // Set default text
        text.setString(m_name);
        text.setFillColor(sf::Color(255, 255, 255));
        text.setCharacterSize(12);
    }

    // Get circle shape
    sf::CircleShape& get_circle()
    {
        return c;
    }

    // Get rectangle shape
    sf::RectangleShape& get_rectangle()
    {
        return rec;
    }

    // Get text
    sf::Text& get_text()
    {
        return text;
    }

    // Set font and center text in circle
    void Cset_text(sf::Font& font_name)
    {
        text.setFont(font_name);
        // Center text in circle
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.width / 2, textRect.height / 2);
        text.setPosition(c.getPosition().x + m_radius, c.getPosition().y + m_radius);
    }

    // Set font and center text in rectangles
    void Rset_text(sf::Font& font_name)
    {
        text.setFont(font_name);
        // Center text in rectangle
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.width / 2, textRect.height / 2);
        text.setPosition((float)rec.getPosition().x + m_width * 0.5, (float)rec.getPosition().y + m_height * 0.5);
    }

    // Move the circle
    void C_movement()
    {
        if (c.getPosition().x < 0 || c.getPosition().x + 2 * m_radius > width_window)
        {
            m_ix = -m_ix;
        }
        if (c.getPosition().y < 0 || c.getPosition().y + 2 * m_radius > height_window)
        {
            m_iy = -m_iy;
        }
        c.setPosition(c.getPosition().x + m_ix, c.getPosition().y + m_iy);
        text.setPosition(text.getPosition().x + m_ix, text.getPosition().y + m_iy);
    }

    // Move the rectangle
    void R_movement()
    {
        if (rec.getPosition().x < 0 || rec.getPosition().x + m_width > width_window)
        {
            m_ix = -m_ix;
        }
        if (rec.getPosition().y < 0 || rec.getPosition().y + m_height > height_window)
        {
            m_iy = -m_iy;
        }
        rec.setPosition(rec.getPosition().x + m_ix, rec.getPosition().y + m_iy);
        text.setPosition(text.getPosition().x + m_ix, text.getPosition().y + m_iy);
    }
};

// Load circle shapes from a file
void C_loadfromfile(std::string file, std::vector<shape>& circles)
{
    std::ifstream fin(file);
    std::string name = " ";
    float xpos = 0, ypos = 0, ix = 0, iy = 0, radius = 0;
    int r = 0, g = 0, b = 0;

    if (!fin) {
        std::cerr << "Error: Could not open file for circles: " << file << std::endl;
        return;
    }

    while (fin >> name >> xpos >> ypos >> ix >> iy >> r >> g >> b >> radius)
    {
        circles.push_back(shape(name, xpos, ypos, ix, iy, r, g, b, radius));
    }
}

// Load rectangle shapes from a file
void R_loadfromfile(std::string file, std::vector<shape>& rectangles)
{
    std::ifstream fin(file);
    std::string name;
    float x_pos = 0, y_pos = 0, ix = 0, iy = 0, width = 0, height = 0;
    int r = 0, g = 0, b = 0;

    if (!fin) {
        std::cerr << "Error: Could not open file for rectangles: " << file << std::endl;
        return;
    }

    while (fin >> name >> x_pos >> y_pos >> ix >> iy >> r >> g >> b >> width >> height)
    {
        rectangles.push_back(shape(name, x_pos, y_pos, ix, iy, r, g, b, width, height));
    }
}

int main()
{
    // Create window with specific size
    sf::RenderWindow window(sf::VideoMode(width_window, height_window), "SFML Works");
    // window.setFramerateLimit(60);

    // Load shapes from files
    std::vector<shape> circles;
    std::vector<shape> rectangles;
    C_loadfromfile("circles1.txt", circles);
    R_loadfromfile("recs.txt", rectangles);

    // Load font for text
    sf::Font myfont;
    if (!myfont.loadFromFile("KillerTech.ttf"))
    {
        std::cerr << "No font exists, please check again\n";
        exit(-1);
    }
    sf::Text text_sample("Sample Text", myfont, 18);
    text_sample.setFillColor(sf::Color(255, 255, 255));
    text_sample.setPosition(0.f, (float)height_window - text_sample.getCharacterSize());

    // Set font and position for text on shapes
    for (auto& i : circles)
    {
        i.Cset_text(myfont);
    }
    for (auto& i : rectangles)
    {
        i.Rset_text(myfont);
    }

    // Main loop to handle events and rendering
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window if the event is a window close request
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Move circles
        for (auto& i : circles)
        {
            i.C_movement();
        }

        // Move rectangles
        for (auto& i : rectangles)
        {
            i.R_movement();
        }

        // Clear window and draw shapes and texts
        window.clear();
        for (auto& i : circles)
        {
            window.draw(i.get_circle());
            window.draw(i.get_text());
        }
        for (auto& i : rectangles)
        {
            window.draw(i.get_rectangle());
            window.draw(i.get_text());
        }
        window.draw(text_sample);

        // Display the drawn contents
        window.display();
    }
}*/
