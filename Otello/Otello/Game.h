#pragma once
#include <SFML/Graphics.hpp>

class Game {
private:
	int Counts_Tocken_White = 2, Counts_Tocken_Black = 2;		// Количество белых фишек и черных
	int WIDTH_Screen = 1000, Height_Screen = 1000;				// Разрешение экрана
	int** Game_Field;											// Игровое поле
	sf::CircleShape* Tocken = new sf::CircleShape[64];			// Фишки
	sf::RectangleShape* Positions;
	int Koef = 150, Count_position=0;
	int Opredelitel_Player = 1, Opredelitel_Bot = 2;

public:
	void Game_Cycle();
	void Create_Field();
	void Count_Positions_For_Tockens();
	void Create_Tockens();
	void Building_Objects_On_Array();
	int CovertIJ_to_I(int, int);
	void Add_Tocken_White(int x, int y);
	void Computer_Action(); 
	bool Check_Massive_Elemetnt(int i, int j);
	void Count_Tockens();
	void Read_Field_File();
	bool Check_End_Of_Line(int opredelitel, int i, int j, int I, int J);
	void Change_Tockens_In_Massive(int opredelitel, int i, int j, int I, int J);
	void Takeover_Tockens(int opredelitel, int i, int j);
	int Evaluation(int opredelitel, int i, int j);
	int Count_Repainting_Tockens(int opredelitel, int i, int j, int I, int J);
	void Iterate_Elements_Massive_For_Line(int i, int j, int I, int J, int opredelitel);
	void Adding_Place_To_Tockens(int Opredelitel);               // определитель =1 то все варанты для фишки человека, если = 2 то для бота
};