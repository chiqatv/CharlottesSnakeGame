#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;
const int SPRITE_WIDTH = 48;
const int SPRITE_HEIGHT = 48;

sf::Vector2f DIRECTION_RIGHT = sf::Vector2f(24, 0);
sf::Vector2f DIRECTION_LEFT = sf::Vector2f(-24, 0);
sf::Vector2f DIRECTION_UP = sf::Vector2f(0, -24);
sf::Vector2f DIRECTION_DOWN = sf::Vector2f(0, 24);

sf::Vector2f CURRENT_DIRECTION = DIRECTION_RIGHT;

int main()
{

	sf::RenderWindow window(
		sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		"Snake", sf::Style::Fullscreen);

	window.setFramerateLimit(10);

	//Creating the title of the game
	sf::Text text;
	sf::Font font;

	(!font.loadFromFile("Cascadia.ttf"));
	//must download fonts. go online and download them and put them in the snake folder
	text.setFont(font);
	text.setString("Snake. Eat Fruit!");
	text.setCharacterSize(80);
	text.setFillColor(sf::Color::Green);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined | sf::Text::Italic);


	sf::RectangleShape snake;
	snake.setSize(sf::Vector2f(SPRITE_WIDTH, SPRITE_WIDTH));
	snake.setPosition(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2));
	snake.setFillColor(sf::Color::Green);

	sf::RectangleShape fruit;
	fruit.setSize(sf::Vector2f(SPRITE_WIDTH, SPRITE_HEIGHT));
	fruit.setPosition(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2));
	fruit.setFillColor(sf::Color::Red);
	
	
	while (window.isOpen())
	{

		//make the snake constantly move
		
		snake.move(CURRENT_DIRECTION);

		sf::Event event;
		while (window.pollEvent(event))

		{
			//Make the user able to close the window
			if (event.type == sf::Event::Closed)
				window.close();
			
			// check if the user presses the escape key
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}

			//Make the player be able to move the snake
				if (event.key.code == sf::Keyboard::Up)
				{
					CURRENT_DIRECTION = DIRECTION_UP;
				}

				if (event.key.code == sf::Keyboard::Down)
				{
					CURRENT_DIRECTION = DIRECTION_DOWN;
				}

				if (event.key.code == sf::Keyboard::Right)
				{
					CURRENT_DIRECTION = DIRECTION_RIGHT;
				}
					
				if (event.key.code == sf::Keyboard::Left)
				{
					CURRENT_DIRECTION = DIRECTION_LEFT;
				}

			}
		}


		//Clear the window with a colour. Clearing is mandatory before drawing anything!
		window.clear(sf::Color::Black);

		window.draw(text);
		window.draw(snake);
		window.draw(fruit);
			

		//ending the curent frame. Also mandatory!
		window.display();
	}

	
		return 0;
}