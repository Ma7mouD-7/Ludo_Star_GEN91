#include "Menu.h"
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;


Menu::Menu(float width, float height) {
	if (!font.loadFromFile("arial.ttf")) {
		cout << "Erro" << endl;
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setStyle(sf::Text::Bold);
	menu[0].setString("START");
	menu[0].setOutlineColor(sf::Color::White);
	menu[0].setOutlineThickness(5);
	menu[0].setCharacterSize(60);
	menu[0].setPosition(sf::Vector2f(50.0f, 50.0f));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Red);
	menu[1].setStyle(sf::Text::Bold);
	menu[1].setString("How To Play");
	menu[1].setOutlineColor(sf::Color::White);
	menu[1].setOutlineThickness(7);
	menu[1].setCharacterSize(60);
	menu[1].setPosition(sf::Vector2f(50.0f , 200.0f));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Red);
	menu[2].setStyle(sf::Text::Bold);
	menu[2].setString("Developers");
	menu[2].setOutlineColor(sf::Color::White);
	menu[2].setOutlineThickness(7);
	menu[2].setCharacterSize(60);
	menu[2].setPosition(sf::Vector2f(50.0f , 350.0f));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::Red);
	menu[3].setStyle(sf::Text::Bold);
	menu[3].setString("Setting");
	menu[3].setOutlineColor(sf::Color::White);
	menu[3].setOutlineThickness(7);
	menu[3].setCharacterSize(60);
	menu[3].setPosition(sf::Vector2f(50.0f, 500.0f));

	menu[4].setFont(font);
	menu[4].setFillColor(sf::Color::Red);
	menu[4].setStyle(sf::Text::Bold);
	menu[4].setString("EXIT");
	menu[4].setOutlineColor(sf::Color::White);
	menu[4].setOutlineThickness(7);
	menu[4].setCharacterSize(60);
	menu[4].setPosition(sf::Vector2f(50.0f ,650.0f ));
	
	selected = -1;
}
Menu::~Menu() {
}

void Menu::draw(sf::RenderWindow& window) {
	for (int i = 0; i < max_num; i++) {
		window.draw(menu[i]);
	}
}
void Menu::moveup() {
	if (selected - 1 >= 0) {
		menu[selected].setFillColor(sf::Color::Red);
			selected--;
			menu[selected].setFillColor(sf::Color::Cyan);
	}
}void Menu::movedown() {
	if (selected +1 <max_num ) {
		menu[selected].setFillColor(sf::Color::Red);
		selected++;
		menu[selected].setFillColor(sf::Color::Cyan);
	}
}

