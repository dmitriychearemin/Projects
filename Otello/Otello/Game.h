#pragma once
#include <SFML/Graphics.hpp>

class Game {
<<<<<<< HEAD
private:
	int Counts_Tocken_White = 2, Counts_Tocken_Black = 2;		// Количество белых фишек и черных
	int WIDTH_Screen = 1000, Height_Screen = 1000;				// Разрешение экрана
	int** Game_Field;											// Игровое поле
	sf::CircleShape* Tocken = new sf::CircleShape[64];			// Фишки
	sf::RectangleShape* Positions;
	int Koef = 150, Count_position=0;

public:
	void Game_Cycle();
	void Create_Field();
	void Count_Positions_For_Tockens();
	void Create_Tockens();
	void Building_On_Array();
	int CovertIJ_to_I(int, int);
=======
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
>>>>>>> 405dfe728d0b92e008b66133f3311a90376fd233
};