#pragma once
#include <SFML/Graphics.hpp>

class Game {

	private:
		int Counts_Point_White=0, Counts_Point_Black=0;
		int WIDTH_Screen=1000, Height_Screen=1000;
		sf::Texture Background_Texture;

	public:
		void Game_Cycle();
		void Create_Field();



};