#include "Level.h"

sf::Text text;
sf::Font font;
int x; int y;
int dragStartX; int dragStartY;
int dragEndX; int dragEndY;
int dragCompareX; int dragCompareY;
bool previousMouseLClick;

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	circle.setRadius(50);
	circle.setPosition(x, y);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(3.f);

}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "W was pressed. \n";
	}

	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	{
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);

		std::cout << "J, K and L were pressed together.";
	}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		exit(0);
	}

	

	if (!font.loadFromFile("font/arial.ttf"))
	{
		//Error
	}

	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);

	

	if (sf::Event::MouseMoved)
	{
		

		x = input->getMouseX();
		y = input->getMouseY();
		

		text.setString(std::to_string(x) + " " + std::to_string(y));
	}

	
	if (input->isMouseLDown() == true && previousMouseLClick == false)
	{
			dragStartX = input->getMouseX();
			dragStartY = input->getMouseY();

			std::cout << "Left mouse button held \n" << std::endl;
			std::cout << std::to_string(dragStartX) + " " + std::to_string(dragStartY) + "\n";
			previousMouseLClick = true;
	}
	if (input->isMouseLDown() == false && previousMouseLClick == true)
	{
			dragEndX = input->getMouseX();
			dragEndY = input->getMouseY();

			std::cout << "Left mouse button released \n" << std::endl;
			std::cout << std::to_string(dragEndX) + " " + std::to_string(dragEndY) + "\n";

			dragCompareX = dragEndX -= dragStartX;
			dragCompareY = dragEndY -= dragStartY;

			std::cout << "The distance between both locations is: ";
			std::cout << "X: " + std::to_string(dragCompareX) + "\n";
			std::cout << "Y: " + std::to_string(dragCompareY) + "\n";

			previousMouseLClick = false;
	}

	if (input->isMouseRDown() == true)
	{
		window->draw(circle);
	}
	

}

// Update game objects
void Level::update()
{

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(text);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}