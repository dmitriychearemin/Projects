#pragma once
#include <SFML/Graphics.hpp>

class Game {
	private:
		int Counts_Point_White=2, Counts_Point_Black=2;		// ���������� ����� ������� � ������ ������
		int WIDTH_Screen=1000, Height_Screen=1000;          // ���������� ������
		int** Game_Field;                                   // ������� ����
		sf::CircleShape* Tocken = new sf::CircleShape[64];  // �����


	public:
		void Game_Cycle();
		void Create_Field();
		void Update_Display();
		void 

};