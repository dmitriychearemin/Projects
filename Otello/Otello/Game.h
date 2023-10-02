#pragma once
#include <SFML/Graphics.hpp>

class Game {
	private:
		int Counts_Point_White=2, Counts_Point_Black=2;		// Количество фишек черного и белого цветов
		int WIDTH_Screen=1000, Height_Screen=1000;          // Разрешение экрана
		int** Game_Field;                                   // Игровое поле
		sf::CircleShape* Tocken = new sf::CircleShape[64];  // Фишки


	public:
		void Game_Cycle();
		void Create_Field();
		void Update_Display();
		void 

};