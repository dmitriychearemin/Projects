#pragma once
#include <SFML/Graphics.hpp>

class Game {
	private:
		int Counts_Point_White=2, Counts_Point_Black=2;		// Êîëè÷åñòâî ôèøåê ÷åðíîãî è áåëîãî öâåòîâ
		int WIDTH_Screen=1000, Height_Screen=1000;          // Ðàçðåøåíèå ýêðàíà
		int** Game_Field;                                   // Èãðîâîå ïîëå
		sf::CircleShape* Tocken = new sf::CircleShape[64];  // Ôèøêè
  int Koef = 150;

	public:
		void Game_Cycle();
		void Create_Field();
		void Update_Display();
		void Create_Tocken();
  void Building_On_Array();
};