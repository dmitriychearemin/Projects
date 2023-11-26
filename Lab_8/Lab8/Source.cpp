#include <iostream>
#include <SFML/Graphics.hpp>
#include "Fractal.h"

int main() {
 
	Fractal fr;

	fr.Draw_Figure();
    /*int count = 2;
    sf::CircleShape* circle;
    circle = new sf::CircleShape [2];
    for (int i = 0; i < count; i++)
    {
        circle[i].setFillColor(sf::Color::Green);
    }
    circle[0].setRadius(90);
    circle[0].setOrigin(90 / 2, 90 / 2);
    circle[0].setPosition(100, 100);
    circle[1].setRadius(45);
    circle[1].setOrigin(45 / 2, 45 / 2);
    circle[1].setPosition(300, 300);
    
    sf::RenderWindow window(sf::VideoMode(1600, 900), "NICE!");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(circle[0]);

        window.draw(circle[1]);

        window.display();
    }*/



}