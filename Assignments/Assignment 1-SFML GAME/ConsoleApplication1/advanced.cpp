#include <iostream>
#include <vector>
#include <fstream>

#include <SFML/Graphics.hpp>
unsigned int width_window = 1050;
unsigned int height_window = 720;
class shape
{
	std::string m_name;
	float m_x_pos;
	float m_y_pos;
	float m_ix;
	float m_iy;
	int m_r;
	int m_g;
	int m_b;
	float m_radius = 50;
	float m_width = 50;
	float m_height = 50;
	sf::CircleShape c;
	sf::RectangleShape rec;
	sf::Text text;

public:
	//constarctor circle 
	shape(std::string name, float x_pos, float y_pos, float ix, float iy, int r, int g, int b, float radius)
		:m_name(name), m_x_pos(x_pos), m_y_pos(y_pos), m_ix(ix), m_iy(iy), m_r(r), m_g(g), m_b(b), m_radius(radius)

	{
		c.setRadius(m_radius);
		c.setFillColor(sf::Color(r, g, b));
		c.setPosition(x_pos, y_pos);
		//default text
		text.setString(m_name);
		text.setCharacterSize(12);
		text.setFillColor(sf::Color(255, 255, 255));
	}
	shape(std::string name, float x_pos, float y_pos, float ix, float iy, int r, int g, int b, float width, float height)
		:m_name(name), m_x_pos(x_pos), m_y_pos(y_pos), m_ix(ix), m_iy(iy), m_r(r), m_g(g), m_b(b), m_width(width), m_height(height)

	{
		rec.setSize(sf::Vector2f(m_width, m_height));
		rec.setFillColor(sf::Color(r, g, b));
		rec.setPosition(x_pos, y_pos);
		//default text
		text.setString(m_name);
		text.setFillColor(sf::Color(255, 255, 255));
		text.setCharacterSize(12);

	}
	//return sf:: circle 
	sf::CircleShape& get_circle()
	{
		return c;
	}
	//return sf:: retangle 
	sf::RectangleShape& get_rectangle()
	{
		return rec;
	}
	sf::Text& get_text()
	{
		return text;
	}
	//set font and Center text in circle
	void Cset_text(sf::Font& font_name)
	{
		text.setFont(font_name);
		// Center text in circle
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.width / 2, textRect.height / 2);
		text.setPosition(c.getPosition().x + m_radius, c.getPosition().y + m_radius);
	}
	//set font and Center text in rectangles
	void Rset_text(sf::Font& font_name)
	{
		text.setFont(font_name);
		// Center text in rectangle
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.width / 2, textRect.height / 2);
		text.setPosition(rec.getPosition().x + m_width * 0.5, rec.getPosition().y + m_height * 0.5);
	}
	void set_ix(float ix)
	{
		m_ix = ix;
	}
	void set_iy(float iy)
	{
		m_iy = iy;
	}
	float get_ix() const
	{
		return m_ix;
	}
	float get_iy() const
	{
		return m_iy;
	}

	//move the circle 
	void C_movement()
	{
		if (c.getPosition().x< 0 || c.getPosition().x + 2 * m_radius > width_window)
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
	//move the rectangle  
	void R_movement()
	{
		if (rec.getPosition().x< 0 || rec.getPosition().x + m_width > width_window)
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
//load from file 
void C_loadfromfile(std::string file, std::vector <shape>& circles)
{
	std::ifstream fin(file);
	std::string name = " ";
	float xpos = 0, ypos = 0, ix = 0, iy = 0, ridus = 0;
	int r = 0, g = 0, b = 0;

	if (!fin) {
		std::cerr << "Error: Could not open file for rectangles: " << file << std::endl;
		return;
	}
	while (fin >> name >> xpos >> ypos >> ix >> iy >> r >> g >> b >> ridus)
	{


		circles.push_back(shape(name, xpos, ypos, ix, iy, r, g, b, ridus));
	}




}
//load from file 
void R_loadfromfile(std::string file, std::vector <shape>& rectangles)
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
	//window dicribtion 
	sf::RenderWindow window(sf::VideoMode(width_window, height_window), "SFML Works");
	//window.setFramerateLimit(60);

	//load shapes from file 
	std::vector <shape> circles;
	std::vector <shape> rectangles;
	C_loadfromfile("circles1.txt", circles);
	R_loadfromfile("recs.txt", rectangles);
	for (int x = 0; x < 25; x++)
	{
		for (int y = 0; y < 15; y++)
		{

			rectangles.push_back(shape(" ", 20 * x, 20 * y, 0.1, 0.3, 10 * x, 10 * y, 2, 15, 15));


		}
	}


	sf::Font myfont;
	if (!myfont.loadFromFile("KillerTech.ttf"))
	{
		std::cerr << "No font exist, please cheak again\n";
		exit(-1);
	}
	sf::Text text_sample("Sample Test", myfont, 18);
	text_sample.setFillColor(sf::Color(255, 255, 255));
	text_sample.setPosition(0, height_window - text_sample.getCharacterSize());
	for (auto& i : circles)
	{
		i.Cset_text(myfont);

	}


	for (auto& i : rectangles)
	{
		i.Rset_text(myfont);
	}

	while (window.isOpen())
	{
		//-----------------------------events-----------------
		sf::Event event;
		while (window.pollEvent(event))
		{
			//to close SFML window 
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				std::cout << "the key is " << event.key.code << "\n";
				if (event.key.code == sf::Keyboard::A)
				{
					circles[0].set_ix(-circles[0].get_ix());

				}
				if (event.key.code == sf::Keyboard::S)
				{
					circles[0].set_iy(-circles[0].get_iy());

				}
				if (event.key.code == sf::Keyboard::Z)
				{
					circles[3].set_ix(-circles[3].get_ix());

				}
				if (event.key.code == sf::Keyboard::X)
				{
					circles[3].set_iy(-circles[3].get_iy());

				}
				if (event.key.code == sf::Keyboard::Q)
				{
					circles[1].set_iy(-circles[1].get_iy());
					for (auto& i : circles)
					{
						i.set_iy(-i.get_iy());
						i.set_ix(-i.get_ix());
					}

				}
			}

		}

		//move circles
		for (auto& i : circles)
		{
			i.C_movement();
		}

		//move rectangles
		for (auto& i : rectangles)
		{
			i.R_movement();
		}

		window.clear();
		//draw circles and texts 
		for (auto& i : circles)
		{
			window.draw(i.get_circle());
			window.draw(i.get_text());
		}

		//draw rectangles and texts 
		for (auto& i : rectangles)
		{
			window.draw(i.get_rectangle());
			window.draw(i.get_text());
		}

		window.draw(text_sample);

		window.display();
	}
}




