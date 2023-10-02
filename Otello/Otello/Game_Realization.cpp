#include <iostream>
#include "Game.h"
#include <SFML/Graphics.hpp>

void Game::Game_Cycle() {
	sf::RenderWindow window(sf::VideoMode(WIDTH_Screen,Height_Screen), "Otello");
	
	sf::RectangleShape BackGr(sf::Vector2f(800, 800));
	sf::Texture Background_Texture;
	Background_Texture.loadFromFile("Background.PNG");
	BackGr.setOrigin(400, 400);
	BackGr.setPosition(WIDTH_Screen / 2, Height_Screen / 2);
	BackGr.setTexture(&Background_Texture);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(BackGr);
		window.display();
	}


}

void Game::Create_Field() {
	
	*Game_Field = new int[8];
	for (int i = 0; i < 8; i++) {
		Game_Field[i] = new int[8];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == 3 && j == 3) {
				Game_Field[i][j] = 1;
			}
			if (i == 3 && j == 4) {
				Game_Field[i][j] = 2;
			}
			if (i == 4 && j == 3) {
				Game_Field[i][j] = 2;
			}
			if (i == 4 && j == 4) {
				Game_Field[i][j] = 1;
			}
			else {
				Game_Field[i][j] = 0;
			}
		}
	}


}

void Update_Display() {
	


}