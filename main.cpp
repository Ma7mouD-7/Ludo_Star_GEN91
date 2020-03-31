#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
using namespace std;
using namespace sf;
int main() {
    RenderWindow window(VideoMode(1270,800), "gameing");
    Menu menu(window.getSize().x, window.getSize().y);
    Texture texture;
    texture.loadFromFile("555.JPG");
   Sprite sprite(texture);
   while (window.isOpen()) {
       Event event;
       while (window.pollEvent(event)) {
           switch (event.type)
           {
           case Event::KeyReleased:
               switch (event.key.code) {
               case Keyboard::Up:
                   menu.moveup();
                   break;
               case Keyboard::Down:
                   menu.movedown();
                   break;
               }
               break;
           case Event::Closed:
               window.close();
               break;
           }
           window.clear();
           window.draw(sprite);
           menu.draw(window);
           window.display();
       }

   }
    return 0;
}







