#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class TreeMinMax {
	int Mark;
	int Cur_Son=0;
	int Pos_I = 0, Pos_J=0, opredelitel;
	int** Dream_Game_Field;
	int Count_Sons;
	TreeMinMax** Array_Sons;
	friend class Game;
};


class Game {
private:
	std::string Tock_Count;
	int Counts_Tocken_White = 2, Counts_Tocken_Black = 2, Summ_Tockens;						// Количество белых фишек и черных
	int WIDTH_Screen = 1000, Height_Screen = 1000;											// Разрешение экрана
	int** Game_Field;																		// Игровое поле
	int** Dream_Game_Field;
	sf::CircleShape* Tocken = new sf::CircleShape[64];										// Фишки
	sf::CircleShape* Count_Tocken = new sf::CircleShape[2];
	sf::RectangleShape* Positions;
	sf::RectangleShape Window;
	sf::Text text[2];
	TreeMinMax* Root = nullptr;
	int Koef = 150, Count_position=0, Max_lvl_Tree=0;
	
	int Opredelitel_Player = 1, Opredelitel_Bot = 2;										// определитель =1 то все варанты для фишки человека, если = 2 то для бота
	int Cur_position_And_Eval[3], Best_Position_And_Eval[3], last_Eval = 0;
	int MIN=0, MAX=0;

public:
	void Game_Cycle();
	void Create_Field();
	void Count_Positions_For_Tockens(int**);
	void Create_Tockens();
	void Tutorial_Cycle();
	void Menu_Cycle();
	void End_Game_Menu();
	void Convert_Dream_Field_To_Field();
	void Convert_Field_To_Dream_Field();
	//void MiniMax(TreeMinMax* tree, int cur_lvl);
	int  MiniMax(int cur_lvl, int I, int J, int** Field, int);
	TreeMinMax* Create_MiniMax_Tree(TreeMinMax*, int cur_lvl, int opredelitel, int**, int, int);
	void Building_Objects_On_Array();
	int CovertIJ_to_I(int, int);
	int Min_Pos_On_Curlvl(TreeMinMax* tree, int);
	int Max_Pos_On_Curlvl(TreeMinMax* tree, int);
	void Add_Tocken_White(int x, int y);
	void Computer_Action(); 
	bool Check_Massive_Elemetnt(int i, int j, int**);
	int Count_Tockens(int**);
	void Read_Field_File();
	void Convert_Int_To_String(int);
	bool Check_End_Of_Line(int opredelitel, int i, int j, int I, int J, int**);
	void Change_Tockens_In_Massive(int opredelitel, int i, int j, int I, int J, int**);
	void Reverse_Change_Tockens_In_Massive(int opredelitel, int i, int j, int I, int J, int**);
	void Takeover_Tockens(int opredelitel, int i, int j, int**);
	void Reverse_Takeover_Tockens(int opredelitel, int i, int j, int**);
	int Evaluation(int**);
	int Count_Repainting_Tockens(int opredelitel, int i, int j, int I, int J);
	void Iterate_Elements_Massive_For_Line(int i, int j, int I, int J, int opredelitel, int**);
	void Adding_Place_To_Tockens(int Opredelitel, int**);   
	void Clear_Tree(TreeMinMax* tree);
	
};


