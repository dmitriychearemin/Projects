#include <iostream>
#include "Game.h"
#include <SFML/Graphics.hpp>

void Game::Game_Cycle() {
	sf::RenderWindow window(sf::VideoMode(WIDTH_Screen,Height_Screen), "Otello");
	sf::Clock clock;
	sf::Time elapsed = clock.restart();
	Create_Tockens();
	Create_Field();
	Building_On_Array();
	sf::Vector2i localPosition = sf::Mouse::getPosition(window); //позиция мыши

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

			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.key.code == sf::Mouse::Left) {

				}	
			}
				
		}
		if (elapsed.asMicroseconds() > 300) {
			window.clear();
			sf::Time elapsed = clock.restart();
		}
		

		window.draw(BackGr);

		for (int i = 0; i < Count_position; i++) {
			if (Positions[i].getPosition().x != 0) {
				window.draw(Positions[i]);
			}
		}
		for (int i = 0; i < 64; i++) {
			if (Tocken[i].getPosition().x != 0) {
				window.draw(Tocken[i]);
			}
		}

		window.display();
	}


}

void Game::Create_Field() {
	
	Game_Field = new int* [8];
	for (int i = 0; i < 8; i++) {
		Game_Field[i] = new int[8];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == 3 && j == 3) {
				Game_Field[i][j] = 1;
			}
			else if (i == 3 && j == 4) {
				Game_Field[i][j] = 2;
			}
			else if (i == 4 && j == 3) {
				Game_Field[i][j] = 2;
			}
			else if (i == 4 && j == 4) {
				Game_Field[i][j] = 1;
			}
			else {
				Game_Field[i][j] = 0;
			}
		}
	}
	
}

<<<<<<< HEAD
//-----------------------------------------------------------------------------
// Отрисовка объектов
=======
void Game::Update_Display() {
	
>>>>>>> 405dfe728d0b92e008b66133f3311a90376fd233

void Game::Count_Positions_For_Tockens() {
	Count_position = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Count_position++;
		}
	}
}

<<<<<<< HEAD
//------------------------------------------------------------------------------
// Графический вывод изображение по массиву поля

void Game::Building_On_Array() {
	int Count = 0;
	Count_Positions_For_Tockens();
	Positions = new sf::RectangleShape[Count_position];
	if (Count_position !=0) {
		for (int i = 0; i < Count_position; i++) {
			Positions[i].setSize(sf::Vector2f(40, 40));
			Positions[i].setOrigin(20, 20);
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (Game_Field[i][j] == 1) {
				Tocken[CovertIJ_to_I(i, j)].setFillColor(sf::Color::White);
				Tocken[CovertIJ_to_I(i, j)].setPosition(Koef + (Koef - 50) * i, Koef + (Koef - 50) * j);
			}
			else if (Game_Field[i][j] == 2) {
				Tocken[CovertIJ_to_I(i, j)].setFillColor(sf::Color::Black);
				Tocken[CovertIJ_to_I(i, j)].setPosition(Koef + (Koef-50) * i,Koef + (Koef-50) * j);
			
			}
			else if (Game_Field[i][j] == 3) {
				Positions[Count].setFillColor(sf::Color::Green);
				Positions[Count].setPosition(Koef + (Koef - 50) * i, Koef + (Koef - 50) * j);
				Count++;
			}
		}
	}
}

//-------------------------------------------------------------------------------
// Перевод из массива двумерного в одномерный 

int Game::CovertIJ_to_I(int i, int j) {
	int I=0;
	if (i != 0) {
		I = i * 8 + j;
	}
	else {
		I = j;
	}
	return I;
}

//-------------------------------------------------------------------------------
// Создание объектов и приведение их к параметрам, фишки, поля куда можно поставить фишку

void Game::Create_Tockens() {
	for (int i = 0; i < 64; i++) {
		Tocken[i].setRadius(40);
		Tocken[i].setOrigin(40,40);
	}
}
=======
}

void Game::Building_On_Array(){
   for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
         if(Game_Field[i][j]==1){
                  Tocken[ConvertIJ_to_I(i,j)].setColor(White);
         }
      }
   }
}

int CovertIJ_to_I(int i, int j){
   if(i!=0){
      I= i*8+j;
   }
   else{
      I=j;
   }
   return I;
}
>>>>>>> 405dfe728d0b92e008b66133f3311a90376fd233
