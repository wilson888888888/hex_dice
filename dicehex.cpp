#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <utility>
#include <time.h>
#include <sstream>

int main(){
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "hexagons and dice", sf::Style::Fullscreen, settings);
	sf::Font font;
	int iter = 0;
	if(!font.loadFromFile("font.ttf"))
		std::cout << "you need the font file to get the pretty font get your shit together man";
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(18);
	text.setColor(sf::Color(149, 102, 113));
	sf::Vector2f die[6];
	die[0] = sf::Vector2f(400, 200);
	die[1] = sf::Vector2f(800, 200);
	die[2] = sf::Vector2f(1000, 546);
	die[3] = sf::Vector2f(800, 893);
	die[4] = sf::Vector2f(400, 893);
	die[5] = sf::Vector2f(200, 546);
	sf::ConvexShape hex;
	hex.setPointCount(6);
	hex.setFillColor(sf::Color(149, 102, 113));
	for(int i = 0; i < 6; i++){
		hex.setPoint(i, die[i]);
	}
	window.clear(sf::Color(42, 56, 67));
	srand(time(NULL));
	int roll = rand() % 6;
	sf::Vector2f current (die[roll].x, die[roll].y);
	sf::CircleShape point(1);
	sf::RectangleShape lazy_clear(sf::Vector2f(1000, 100));
	lazy_clear.setPosition(0, 0);
	point.setFillColor(sf::Color(42, 56, 67));
	lazy_clear.setFillColor(sf::Color(42, 56, 67));
	window.draw(hex);
	std::ostringstream convert;
	while(window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();			
		}
		point.setPosition(current);
		roll = rand() % 6;
		current = sf::Vector2f((current.x + die[roll].x) / 2, (current.y + die[roll].y) / 2);
		convert.str("");
		convert.clear();
		convert << "Iterations: " << iter ++;
		text.setString(convert.str());
		window.draw(lazy_clear);
		window.draw(text);
		window.draw(point);
		window.display();
	}
	return 0;
}
