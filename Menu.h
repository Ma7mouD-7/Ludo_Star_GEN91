#pragma once
#include "SFML/Graphics.hpp"
#define max_num 5 
class Menu
{
public:
	Menu(float width, float height);
	~Menu(); 

	void draw(sf::RenderWindow& window);
	void moveup();
	void movedown();
	

private:
	int selected;
	sf::Font font;
	sf::Text menu[max_num];
	
};

