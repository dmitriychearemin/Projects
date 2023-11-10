#include <iostream>
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <stdlib.h>


//------------------------------------------------------------------------------------
// Игровой цикл

void Game::Game_Cycle() {
	bool k = true;
	int count = 0;
	sf::RenderWindow window(sf::VideoMode(WIDTH_Screen, Height_Screen), "Otello");
	sf::Clock clock;
	int a = 0;
	sf::Time elapsed = clock.restart();
	sf::Font font;
	if (!font.loadFromFile("arial_bolditalicmt.ttf"))
	{
		std::cout << "fdsgnjs";
	}
	text[0].setFont(font);
	text[1].setFont(font);

	Create_Tockens();
	Create_Field();
	Game_Field[2][3] = 2;
	Adding_Place_To_Tockens(Opredelitel_Player, Game_Field);
	Building_Objects_On_Array();

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

			if (k == true) {
				if (event.type == sf::Event::MouseButtonPressed) {
					if (event.key.code == sf::Mouse::Left) {
						Adding_Place_To_Tockens(1, Game_Field);
						Count_Positions_For_Tockens(Game_Field);
						Add_Tocken_White(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
						k = false;
					}
						
				}
			}

		}
		if (elapsed.asMicroseconds() > 300) {
			window.clear();
			sf::Time elapsed = clock.restart();
		}


		window.draw(Window);
		window.draw(BackGr);
		Adding_Place_To_Tockens(1, Game_Field);
		Count_Tockens(Game_Field);
		Building_Objects_On_Array();

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
		window.draw(Count_Tocken[0]);
		window.draw(Count_Tocken[1]);
		window.draw(text[0]);
		window.draw(text[1]);
		window.display();
		if (k == false) {
			Adding_Place_To_Tockens(2, Game_Field);
			Count_Positions_For_Tockens(Game_Field);
			if (Count_position > 0) {
				Computer_Action();
			}
			
			k = true;
		}

		if (Count_Tockens(Game_Field) == 64) {
			if (Counts_Tocken_Black > Counts_Tocken_White) {
				std::cout << " BOT WIN" << std::endl;
				text[0].setFont(font);
			}

			else {
				std::cout << " PLAYER WIN" << std::endl;
			}
			count++;
			if (count > 10) {
				End_Game_Menu();
				break;
			}
			
			
		}

		
		Adding_Place_To_Tockens(1, Game_Field);
		Count_Positions_For_Tockens(Game_Field);
		if (Count_position==0) {
			Adding_Place_To_Tockens(2, Game_Field);
			Count_Positions_For_Tockens(Game_Field);
			if (Count_position == 0) {
				if (Counts_Tocken_Black > Counts_Tocken_White) {
					std::cout << " BOT WIN" << std::endl;
				}

				else {
					std::cout << " PLAYER WIN" << std::endl;
				}
				count++;
				if (count > 10) {
					End_Game_Menu();
					break;
				}
			}
		}
		Count_Tockens(Game_Field);
		if (Counts_Tocken_White == 0) {
			std::cout << " BOT WIN" << std::endl;
			count++;
			if (count > 10) {
				End_Game_Menu();
				break;
			}
		}

	}
}

//----------------------------------------------------
// 
void Game::Menu_Cycle() {
	int position_X, position_Y;

	sf::RenderWindow window(sf::VideoMode(WIDTH_Screen, Height_Screen), "Otello");
	sf::RectangleShape BackGr(sf::Vector2f(1000, 1000));
	sf::Texture Menu_BackGround;
	sf::RectangleShape Start_Button(sf::Vector2f(300, 70));
	sf::Texture Start_But_Texture;
	sf::RectangleShape Guide_Button(sf::Vector2f(300, 70));
	sf::Texture Guide_But_Texture;

	Menu_BackGround.loadFromFile("Menu_Backgr.PNG");
	BackGr.setOrigin(500,500);
	BackGr.setPosition(WIDTH_Screen / 2, Height_Screen / 2);
	BackGr.setTexture(&Menu_BackGround);

	Start_But_Texture.loadFromFile("Play_Button.PNG");
	Start_Button.setOrigin(150, 35);
	Start_Button.setPosition(WIDTH_Screen / 2, Height_Screen / 2);
	Start_Button.setTexture(&Start_But_Texture);

	Guide_But_Texture.loadFromFile("Guide_Button.PNG");
	Guide_Button.setOrigin(150, 35);
	Guide_Button.setPosition(WIDTH_Screen / 2, Height_Screen / 2 + 100);
	Guide_Button.setTexture(&Guide_But_Texture);

	sf::Vector2i localPosition = sf::Mouse::getPosition(window);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.key.code == sf::Mouse::Left) {
					position_X = sf::Mouse::getPosition().x - 468;
					position_Y = sf::Mouse::getPosition().y - 76;
					std::cout << position_X << " " << position_Y << std::endl;
					if (position_X >= 350 && position_X <= 650 && position_Y >= 465 && position_Y <= 535) {
						Game_Cycle();
					}
					if (position_X >= 350 && position_X <= 650 && position_Y >= 565 && position_Y <= 635) {
						Tutorial_Cycle();
					}

				}

			}
		}
		window.draw(BackGr);
		window.draw(Start_Button);
		window.draw(Guide_Button);
		window.display();

	}
	
}

void Game::Tutorial_Cycle() {
	sf::RenderWindow window(sf::VideoMode(WIDTH_Screen, Height_Screen), "Otello");
	sf::RectangleShape BackGr(sf::Vector2f(1000, 1000));
	sf::Texture Guide_Menu_BackGround;
	Guide_Menu_BackGround.loadFromFile("Guide_Menu_Backgr.PNG");
	BackGr.setOrigin(500, 500);
	
	
	BackGr.setPosition(WIDTH_Screen / 2, Height_Screen / 2);
	BackGr.setTexture(&Guide_Menu_BackGround);
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();



		}
		window.draw(BackGr);
		window.display();

	}

}

void Game::End_Game_Menu() {

	sf::RenderWindow window(sf::VideoMode(WIDTH_Screen, Height_Screen), "Otello");
	sf::RectangleShape BackGr(sf::Vector2f(1000, 1000));
	sf::Texture End_Menu_BackGround;
	End_Menu_BackGround.loadFromFile("Menu_Backgr.PNG");
	BackGr.setOrigin(500, 500);

	text[0].setCharacterSize(100);
	text[0].setFillColor(sf::Color::Red);
	text[0].setStyle(sf::Text::Bold | sf::Text::Style::Bold);
	text[0].setPosition(250,500);
	Count_Tockens(Game_Field);

	if (Counts_Tocken_Black > Counts_Tocken_White) {
		text[0].setString("Bot Win");

	}
	else {
		text[0].setString("Player Win");
	}

	BackGr.setPosition(WIDTH_Screen / 2, Height_Screen / 2);
	BackGr.setTexture(&End_Menu_BackGround);
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();



		}
		window.draw(BackGr);
		window.draw(text[0]);
		window.display();

	}


}

//------------------------------------------------------------------------------------
// Создание игрового поля

void Game::Create_Field() {

	Game_Field = new int* [8];
	Dream_Game_Field = new int* [8];
	for (int i = 0; i < 8; i++) {
		Game_Field[i] = new int[8];
		Dream_Game_Field[i] = new int[8];
	}

	for (int i = 0; i < 64; i++) {
		Tocken[i].setPosition(0, 0);
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

	Window.setSize(sf::Vector2f(1000, 1000));
	Window.setPosition(0, 0);
	Window.setFillColor(sf::Color::Magenta);

	text[0].setCharacterSize(25);
	text[1].setCharacterSize(25);
	text[0].setFillColor(sf::Color::Red);
	text[1].setFillColor(sf::Color::Red);
	text[0].setStyle(sf::Text::Bold | sf::Text::Underlined);
	text[1].setStyle(sf::Text::Bold | sf::Text::Underlined);
	text[0].setPosition(140, 35);
	text[1].setPosition(290, 35);
}

//------------------------------------------------------------------------------------
// Отрисовка объектов

void Game::Count_Positions_For_Tockens(int** Game_Field) {
	Count_position = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (Game_Field[i][j] == 3 || Game_Field[i][j] == 4)
				Count_position++;
		}
	}
}

//------------------------------------------------------------------------------------
// Графический вывод изображение по массиву поля

void Game::Building_Objects_On_Array() {
	int Count = 0;
	Count_Positions_For_Tockens(Game_Field);
	Positions = new sf::RectangleShape[Count_position];
	if (Count_position != 0) {
		for (int i = 0; i < Count_position; i++) {
			Positions[i].setSize(sf::Vector2f(40, 40));
			Positions[i].setOrigin(20, 20);
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (Game_Field[i][j] == 1) {
				Tocken[CovertIJ_to_I(i, j)].setFillColor(sf::Color::White);
				Tocken[CovertIJ_to_I(i, j)].setPosition(Koef + (Koef - 50) * j, Koef + (Koef - 50) * i);
			}
			else if (Game_Field[i][j] == 2) {
				Tocken[CovertIJ_to_I(i, j)].setFillColor(sf::Color::Black);
				Tocken[CovertIJ_to_I(i, j)].setPosition(Koef + (Koef - 50) * j, Koef + (Koef - 50) * i);

			}
			else if (Game_Field[i][j] == 3) {
				Positions[Count].setFillColor(sf::Color::Green);
				Positions[Count].setPosition(Koef + (Koef - 50) * j, Koef + (Koef - 50) * i);
				Count++;
			}
		}
	}

	Count_Tocken[0].setFillColor(sf::Color::White);
	Count_Tocken[1].setFillColor(sf::Color::Black);
	Count_Tocken[0].setPosition(150, 50);
	Count_Tocken[1].setPosition(300, 50);
	Count_Tockens(Game_Field);
	Convert_Int_To_String(Counts_Tocken_White);
	text[0].setString(Tock_Count);
	Convert_Int_To_String(Counts_Tocken_Black);
	text[1].setString(Tock_Count);
}

//------------------------------------------------------------------------------------
// Перевод из двумерного массива  в одномерный 

int Game::CovertIJ_to_I(int i, int j) {
	int I = 0;
	if (i != 0) {
		I = i * 8 + j;
	}
	else {
		I = j;
	}
	return I;
}

//------------------------------------------------------------------------------------
// Создание объектов и приведение их к параметрам, фишки, поля куда можно поставить фишку

void Game::Create_Tockens() {

	for (int i = 0; i < 64; i++) {
		Tocken[i].setRadius(40);
		Tocken[i].setOrigin(40, 40);
	}

	Count_Tocken[0].setRadius(40);
	Count_Tocken[0].setOrigin(40, 40);
	Count_Tocken[1].setRadius(40);
	Count_Tocken[1].setOrigin(40, 40);

}

//------------------------------------------------------------------------------------
// Добавление фишки на экран

void Game::Add_Tocken_White(int x, int y) {
	int I = 0, J = 0;
	x = x - 468;
	y = y - 76;
	std::cout << x << " " << y << std::endl;
	//std::cout << Positions[0].getPosition().x << " " << Positions[0].getPosition().y << std::endl;
	//std::cout << Positions[1].getPosition().x << " " << Positions[1].getPosition().y << std::endl;


	for (int i = 0; i < Count_position; i++) {
		if ((Positions[i].getPosition().x - 49) < x && (Positions[i].getPosition().x + 49) > x && (Positions[i].getPosition().y - 49) < y && (Positions[i].getPosition().y + 49) > y) {

			J = (Positions[i].getPosition().x - Koef) / (Koef - 50);
			I = (Positions[i].getPosition().y - Koef) / (Koef - 50);
			Game_Field[I][J] = 1;
			break;
		}
	}
	Takeover_Tockens(Opredelitel_Player, I, J, Game_Field);
	Building_Objects_On_Array();

}

//------------------------------------------------------------------------------------
// Определение позиций куда можно поставить фишку

void Game::Adding_Place_To_Tockens(int opredelitel, int** Game_Field) {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (Game_Field[i][j] == 3 || Game_Field[i][j] == 4) {
				Game_Field[i][j] = 0;
			}
		}
	}

	if (opredelitel == 1) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (Game_Field[i][j] == 1) {
					if (Check_Massive_Elemetnt(i - 1, j - 1, Game_Field) == true && Game_Field[i - 1][j - 1] == 2) {
						Iterate_Elements_Massive_For_Line(i - 1, j - 1, i, j, opredelitel, Game_Field);
					}
					if (Check_Massive_Elemetnt(i, j - 1, Game_Field) == true && Game_Field[i][j - 1] == 2) {
						Iterate_Elements_Massive_For_Line(i, j - 1, i, j, opredelitel, Game_Field);
					}
					if (Check_Massive_Elemetnt(i + 1, j - 1, Game_Field) == true && Game_Field[i + 1][j - 1] == 2) {
						Iterate_Elements_Massive_For_Line(i + 1, j - 1, i, j, opredelitel, Game_Field);
					}
					if (Check_Massive_Elemetnt(i - 1, j, Game_Field) == true && Game_Field[i - 1][j] == 2) {
						Iterate_Elements_Massive_For_Line(i - 1, j, i, j, opredelitel, Game_Field);
					}
					if (Check_Massive_Elemetnt(i + 1, j, Game_Field) == true && Game_Field[i + 1][j] == 2) {
						Iterate_Elements_Massive_For_Line(i + 1, j, i, j, opredelitel, Game_Field);
					}
					if (Check_Massive_Elemetnt(i - 1, j + 1, Game_Field) == true && Game_Field[i - 1][j + 1] == 2) {
						Iterate_Elements_Massive_For_Line(i - 1, j + 1, i, j, opredelitel, Game_Field);
					}
					if (Check_Massive_Elemetnt(i, j + 1, Game_Field) == true && Game_Field[i][j + 1] == 2) {
						Iterate_Elements_Massive_For_Line(i, j + 1, i, j, opredelitel, Game_Field);
					}
					if (Check_Massive_Elemetnt(i + 1, j + 1, Game_Field) == true && Game_Field[i + 1][j + 1] == 2) {
						Iterate_Elements_Massive_For_Line(i + 1, j + 1, i, j, opredelitel, Game_Field);
					}
				}
			}
		}
	}

	if (opredelitel == 2) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (Game_Field[i][j] == 2) {
					if (Check_Massive_Elemetnt(i - 1, j - 1, Game_Field) == true && Game_Field[i - 1][j - 1] == 1) {
						Iterate_Elements_Massive_For_Line(i - 1, j - 1, i, j, opredelitel, Game_Field);
					}
					if (Check_Massive_Elemetnt(i, j - 1, Game_Field) == true && Game_Field[i][j - 1] == 1) {
						Iterate_Elements_Massive_For_Line(i, j - 1, i, j, opredelitel, Game_Field);
					}
					if (Check_Massive_Elemetnt(i + 1, j - 1, Game_Field) == true && Game_Field[i + 1][j - 1] == 1) {
						Iterate_Elements_Massive_For_Line(i + 1, j - 1, i, j, opredelitel, Game_Field);
					}
					if (Check_Massive_Elemetnt(i - 1, j, Game_Field) == true && Game_Field[i - 1][j] == 1) {
						Iterate_Elements_Massive_For_Line(i - 1, j, i, j, opredelitel, Game_Field);
					}
					if (Check_Massive_Elemetnt(i + 1, j, Game_Field) == true && Game_Field[i + 1][j] == 1) {
						Iterate_Elements_Massive_For_Line(i + 1, j, i, j, opredelitel, Game_Field);
					}
					if (Check_Massive_Elemetnt(i - 1, j + 1, Game_Field) == true && Game_Field[i - 1][j + 1] == 1) {
						Iterate_Elements_Massive_For_Line(i - 1, j + 1, i, j, opredelitel, Game_Field);
					}
					if (Check_Massive_Elemetnt(i, j + 1, Game_Field) == true && Game_Field[i][j + 1] == 1) {
						Iterate_Elements_Massive_For_Line(i, j + 1, i, j, opredelitel, Game_Field);
					}
					if (Check_Massive_Elemetnt(i + 1, j + 1, Game_Field) == true && Game_Field[i + 1][j + 1] == 1) {
						Iterate_Elements_Massive_For_Line(i + 1, j + 1, i, j, opredelitel, Game_Field);
					}
				}
			}
		}
	}
}

//------------------------------------------------------------------------------------
// Подсчёт числа фишек чёрного и белого цветов

int Game::Count_Tockens(int** Game_Field) {
	Counts_Tocken_Black = 0, Counts_Tocken_White = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (Game_Field[i][j] == 1) {
				Counts_Tocken_White++;
			}
			if (Game_Field[i][j] == 2) {
				Counts_Tocken_Black++;
			}
		}
	}
	return Counts_Tocken_Black + Counts_Tocken_White;
}

//------------------------------------------------------------------------------------
// Все методы работы компьютера

void Game::Computer_Action() {
	Convert_Field_To_Dream_Field();
	for (int i = 0; i < 3; i++) {
		Cur_position_And_Eval[i] = 0;
		
	}
	Best_Position_And_Eval[2] = -9999;
	Best_Position_And_Eval[0] = 0;
	Best_Position_And_Eval[1] = 0;
	int g = 0;
	Clear_Tree(Root);

	if ((64 - Count_Tockens(Game_Field)) >= 6) {
		Max_lvl_Tree = 6;
	}
	else {
		Max_lvl_Tree = 64 - Count_Tockens(Game_Field);
	}

	

	Root = Create_MiniMax_Tree(Root, 0, 1, Dream_Game_Field, 0, 0);
	g = MiniMax(Root, 0);
	
		Adding_Place_To_Tockens(2, Game_Field);
		Count_Positions_For_Tockens(Game_Field);
		if (Count_position==1) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if(Game_Field[i][j]==4){
						Game_Field[i][j] = 2;
						Takeover_Tockens(Opredelitel_Bot, i, j, Game_Field);
					}
				}
			}
		}
		else {
			for (int i = 0; i < Root->Count_Sons; i++) {

				if (Best_Position_And_Eval[2] < Root->Array_Sons[i]->Mark) {
					Best_Position_And_Eval[2] = Root->Array_Sons[i]->Mark;
					Best_Position_And_Eval[0] = Root->Array_Sons[i]->Pos_I;
					Best_Position_And_Eval[1] = Root->Array_Sons[i]->Pos_J;;

				}
			}
		}

		Adding_Place_To_Tockens(2, Game_Field);
		if ((Best_Position_And_Eval[0] == 0 && Best_Position_And_Eval[1] == 0)) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (Game_Field[i][j] == 4) {
						Game_Field[i][j] = 2;
						Takeover_Tockens(Opredelitel_Bot, i, j, Game_Field);
						break;
					}
				}
			}
		}
		else {
			Game_Field[Best_Position_And_Eval[0]][Best_Position_And_Eval[1]] = 2;
			Takeover_Tockens(Opredelitel_Bot, Best_Position_And_Eval[0], Best_Position_And_Eval[1], Game_Field);
		}

	Adding_Place_To_Tockens(Opredelitel_Player, Game_Field);
	Building_Objects_On_Array();
}

//------------------------------------------------------------------------------------
// Проверка элемента массива на существование

bool Game::Check_Massive_Elemetnt(int i, int j, int** Game_Field) {
	if (i < 0 || i > 7 || j < 0 || j > 7) {
		return false;
	}
	return true;
}

//------------------------------------------------------------------------------------
// Перебор элементов по определённой линии

void Game::Iterate_Elements_Massive_For_Line(int i, int j, int I, int J, int opredelitel, int** Game_Field) {

	int KI = i - I, KJ = j - J;
	while (Check_Massive_Elemetnt(i + KI, j + KJ, Game_Field)) {
		if (opredelitel == 1) {
			if (Game_Field[i + KI][j + KJ] == 0) {
				Game_Field[i + KI][j + KJ] = 3;
				break;
			}
		}
		if (opredelitel == 2) {
			if (Game_Field[i + KI][j + KJ] == 0) {
				Game_Field[i + KI][j + KJ] = 4;
				break;
			}
		}
		if (Game_Field[i + KI][j + KJ] == opredelitel || Game_Field[i + KI][j + KJ] == 4 || Game_Field[i + KI][j + KJ] == 3) {
			break;
		}
		i = i + KI;
		j = j + KJ;
	}
}

//------------------------------------------------------------------------------------
// Переворот фишек в зависимости от хода

void Game::Takeover_Tockens(int opredelitel, int i, int j, int** Game_Field) {

	if (opredelitel == 1) {
		if (Check_Massive_Elemetnt(i - 1, j - 1, Game_Field) == true && Game_Field[i - 1][j - 1] == 2 && Check_End_Of_Line(opredelitel, i - 1, j - 1, i, j, Game_Field) == true) {
			Change_Tockens_In_Massive(opredelitel, i - 1, j - 1, i, j, Game_Field);
		}
		if (Check_Massive_Elemetnt(i, j - 1, Game_Field) == true && Game_Field[i][j - 1] == 2 && Check_End_Of_Line(opredelitel, i, j - 1, i, j, Game_Field) == true) {
			Change_Tockens_In_Massive(opredelitel, i, j - 1, i, j, Game_Field);
		}
		if (Check_Massive_Elemetnt(i + 1, j - 1, Game_Field) == true && Game_Field[i + 1][j - 1] == 2 && Check_End_Of_Line(opredelitel, i + 1, j - 1, i, j, Game_Field) == true) {
			Change_Tockens_In_Massive(opredelitel, i + 1, j - 1, i, j, Game_Field);
		}
		if (Check_Massive_Elemetnt(i - 1, j, Game_Field) == true && Game_Field[i - 1][j] == 2 && Check_End_Of_Line(opredelitel, i - 1, j, i, j, Game_Field) == true) {
			Change_Tockens_In_Massive(opredelitel, i - 1, j, i, j, Game_Field);
		}
		if (Check_Massive_Elemetnt(i + 1, j, Game_Field) == true && Game_Field[i + 1][j] == 2 && Check_End_Of_Line(opredelitel, i + 1, j, i, j, Game_Field) == true) {
			Change_Tockens_In_Massive(opredelitel, i + 1, j, i, j, Game_Field);
		}
		if (Check_Massive_Elemetnt(i - 1, j + 1, Game_Field) == true && Game_Field[i - 1][j + 1] == 2 && Check_End_Of_Line(opredelitel, i - 1, j + 1, i, j, Game_Field) == true) {
			Change_Tockens_In_Massive(opredelitel, i - 1, j + 1, i, j, Game_Field);
		}
		if (Check_Massive_Elemetnt(i, j + 1, Game_Field) == true && Game_Field[i][j + 1] == 2 && Check_End_Of_Line(opredelitel, i, j + 1, i, j, Game_Field) == true) {
			Change_Tockens_In_Massive(opredelitel, i, j + 1, i, j, Game_Field);
		}
		if (Check_Massive_Elemetnt(i + 1, j + 1, Game_Field) == true && Game_Field[i + 1][j + 1] == 2 && Check_End_Of_Line(opredelitel, i + 1, j + 1, i, j, Game_Field) == true) {
			Change_Tockens_In_Massive(opredelitel, i + 1, j + 1, i, j, Game_Field);
		}
	}

	if (opredelitel == 2) {
		if (Check_Massive_Elemetnt(i - 1, j - 1, Game_Field) == true && Game_Field[i - 1][j - 1] == 1 && Check_End_Of_Line(opredelitel, i - 1, j - 1, i, j, Game_Field) == true) {
			Change_Tockens_In_Massive(opredelitel, i - 1, j - 1, i, j, Game_Field);
		}
		if (Check_Massive_Elemetnt(i, j - 1, Game_Field) == true && Game_Field[i][j - 1] == 1 && Check_End_Of_Line(opredelitel, i, j - 1, i, j, Game_Field) == true) {
			Change_Tockens_In_Massive(opredelitel, i, j - 1, i, j, Game_Field);
		}
		if (Check_Massive_Elemetnt(i + 1, j - 1, Game_Field) == true && Game_Field[i + 1][j - 1] == 1 && Check_End_Of_Line(opredelitel, i + 1, j - 1, i, j, Game_Field) == true) {
			Change_Tockens_In_Massive(opredelitel, i + 1, j - 1, i, j, Game_Field);
		}
		if (Check_Massive_Elemetnt(i - 1, j, Game_Field) == true && Game_Field[i - 1][j] == 1 && Check_End_Of_Line(opredelitel, i - 1, j, i, j, Game_Field) == true) {
			Change_Tockens_In_Massive(opredelitel, i - 1, j, i, j, Game_Field);
		}
		if (Check_Massive_Elemetnt(i + 1, j, Game_Field) == true && Game_Field[i + 1][j] == 1 && Check_End_Of_Line(opredelitel, i + 1, j, i, j, Game_Field) == true) {
			Change_Tockens_In_Massive(opredelitel, i + 1, j, i, j, Game_Field);
		}
		if (Check_Massive_Elemetnt(i - 1, j + 1, Game_Field) == true && Game_Field[i - 1][j + 1] == 1 && Check_End_Of_Line(opredelitel, i - 1, j + 1, i, j, Game_Field) == true) {
			Change_Tockens_In_Massive(opredelitel, i - 1, j + 1, i, j, Game_Field);
		}
		if (Check_Massive_Elemetnt(i, j + 1, Game_Field) == true && Game_Field[i][j + 1] == 1 && Check_End_Of_Line(opredelitel, i, j + 1, i, j, Game_Field) == true) {
			Change_Tockens_In_Massive(opredelitel, i, j + 1, i, j, Game_Field);
		}
		if (Check_Massive_Elemetnt(i + 1, j + 1, Game_Field) == true && Game_Field[i + 1][j + 1] == 1 && Check_End_Of_Line(opredelitel, i + 1, j + 1, i, j, Game_Field) == true) {
			Change_Tockens_In_Massive(opredelitel, i + 1, j + 1, i, j, Game_Field);
		}
	}
}

//------------------------------------------------------------------------------------
// Проверка линии на ограничение фишкой 
bool Game::Check_End_Of_Line(int opredelitel, int i, int j, int I, int J, int** Game_Field) {

	int KI = i - I, KJ = j - J;

	if (opredelitel == 1) {
		while ((Check_Massive_Elemetnt(i + KI, j + KJ, Game_Field) == true && (Game_Field[i][j] == 2))) {
			if (Game_Field[i + KI][j + KJ] == opredelitel) {
				return true;
			}
			i = i + KI;
			j = j + KJ;
		}
	}

	if (opredelitel == 2) {
		while ((Check_Massive_Elemetnt(i + KI, j + KJ, Game_Field) == true && (Game_Field[i][j] == 1))) {
			if (Game_Field[i + KI][j + KJ] == opredelitel) {
				return true;
			}
			i = i + KI;
			j = j + KJ;
		}
	}
	return false;
}

//------------------------------------------------------------------------------------
// Из числа в строку

void Game::Convert_Int_To_String(int i)
{
	Tock_Count = std::to_string(i);
}

//------------------------------------------------------------------------------------
// Проверка линии на ограничение фишкой 

void Game::Change_Tockens_In_Massive(int opredelitel, int i, int j, int I, int J, int** Game_Field) {

	int KI = i - I, KJ = j - J;

	if (opredelitel == 1) {
		while (Check_Massive_Elemetnt(i, j, Game_Field) == true) {
			if (Game_Field[i][j] == 1) {
				break;
			}
			if (Game_Field[i][j] == 2) {
				Game_Field[i][j] = 1;
			}
			i = i + KI;
			j = j + KJ;
		}
	}

	if (opredelitel == 2) {
		while (Check_Massive_Elemetnt(i, j, Game_Field) == true) {
			if (Game_Field[i][j] == 2) {
				break;
			}
			if (Game_Field[i][j] == 1) {
				Game_Field[i][j] = 2;
			}
			i = i + KI;
			j = j + KJ;
		}
	}

}

//------------------------------------------------------------------------------------
// Оценочная функция 

int Game::Evaluation(int opredelitel, int i, int j, int** Game_Field) {
	int Rating_Pos = 0;
	int Count_Repainting_Tock = 0;
	Count_Tockens(Game_Field);

	if (opredelitel == 2) {
		Rating_Pos = (Counts_Tocken_Black - Counts_Tocken_White);
	}

	if (opredelitel == 1) {
		Rating_Pos = (Counts_Tocken_Black - Counts_Tocken_White);
	}

	if (Counts_Tocken_Black + Counts_Tocken_White == 64) {

		if (Counts_Tocken_Black > Counts_Tocken_White) {
			return 9999;
		}
		if (Counts_Tocken_Black <= Counts_Tocken_White) {
			return -9999;
		}
	}

	if (Counts_Tocken_Black == 0) {
		return -9999;
	}
	if (Counts_Tocken_White == 0) {
		return 9999;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (Game_Field[i][j] == opredelitel)
				if ((i == 0 || i == 7) && (j == 0 || j == 7)) {
					if (opredelitel == 1) {
						Rating_Pos = Rating_Pos - 3;
					}
					else {
						Rating_Pos = Rating_Pos + 3;
					}
				}
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (Game_Field[i][j] == opredelitel)
				if (i == 0 || i == 7 || j == 0 || j == 7) {
					if (opredelitel == 1) {
						Rating_Pos = Rating_Pos -2;
					}
					else {
						Rating_Pos = Rating_Pos + 2;
					}
				}
		}
	}

	return Rating_Pos;


	/*if (Check_Massive_Elemetnt(i - 1, j - 1, Game_Field) == true && Game_Field[i - 1][j - 1] != opredelitel && Check_End_Of_Line(opredelitel, i - 1, j - 1, i, j, Game_Field) == true && Game_Field[i - 1][j - 1] != 3 && Game_Field[i - 1][j - 1] != 4 && Game_Field[i - 1][j - 1] != 0) {
		Count_Repainting_Tock += Count_Repainting_Tockens(opredelitel, i - 1, j - 1, i, j);
	}
	if (Check_Massive_Elemetnt(i, j - 1, Game_Field) == true && Game_Field[i][j - 1] != opredelitel && Check_End_Of_Line(opredelitel, i, j - 1, i, j, Game_Field) == true && Game_Field[i][j - 1] != 3 && Game_Field[i][j - 1] != 4 && Game_Field[i][j - 1] != 0) {
		Count_Repainting_Tock += Count_Repainting_Tockens(opredelitel, i, j - 1, i, j);
	}
	if (Check_Massive_Elemetnt(i + 1, j - 1, Game_Field) == true && Game_Field[i + 1][j - 1] != opredelitel && Check_End_Of_Line(opredelitel, i + 1, j - 1, i, j, Game_Field) == true && Game_Field[i + 1][j - 1] != 3 && Game_Field[i + 1][j - 1] != 4 && Game_Field[i + 1][j - 1] != 0) {
		Count_Repainting_Tock += Count_Repainting_Tockens(opredelitel, i + 1, j - 1, i, j);
	}

	if (Check_Massive_Elemetnt(i - 1, j, Game_Field) == true && Game_Field[i - 1][j] != opredelitel && Check_End_Of_Line(opredelitel, i - 1, j, i, j, Game_Field) == true && Game_Field[i - 1][j] != 3 && Game_Field[i - 1][j] != 4) {
		Count_Repainting_Tock += Count_Repainting_Tockens(opredelitel, i - 1, j, i, j);
	}

	if (Check_Massive_Elemetnt(i + 1, j, Game_Field) == true && Game_Field[i + 1][j] != opredelitel && Check_End_Of_Line(opredelitel, i + 1, j, i, j, Game_Field) == true && Game_Field[i + 1][j] != 3 && Game_Field[i + 1][j] != 4) {
		Count_Repainting_Tock += Count_Repainting_Tockens(opredelitel, i + 1, j, i, j);
	}

	if (Check_Massive_Elemetnt(i - 1, j + 1, Game_Field) == true && Game_Field[i - 1][j + 1] != opredelitel && Check_End_Of_Line(opredelitel, i - 1, j + 1, i, j, Game_Field) == true && Game_Field[i - 1][j + 1] != 3 && Game_Field[i - 1][j + 1] != 4 && Game_Field[i - 1][j + 1] != 0) {
		Count_Repainting_Tock += Count_Repainting_Tockens(opredelitel, i - 1, j + 1, i, j);
	}
	if (Check_Massive_Elemetnt(i, j + 1, Game_Field) == true && Game_Field[i][j + 1] != opredelitel && Check_End_Of_Line(opredelitel, i, j + 1, i, j, Game_Field) == true && Game_Field[i][j + 1] != 3 && Game_Field[i][j + 1] != 4 && Game_Field[i][j + 1] != 0) {
		Count_Repainting_Tock += Count_Repainting_Tockens(opredelitel, i, j + 1, i, j);
	}
	if (Check_Massive_Elemetnt(i + 1, j + 1, Game_Field) == true && Game_Field[i + 1][j + 1] != opredelitel && Check_End_Of_Line(opredelitel, i + 1, j + 1, i, j, Game_Field) == true && Game_Field[i + 1][j + 1] != 3 && Game_Field[i + 1][j + 1] != 4 && Game_Field[i + 1][j + 1] != 0) {
		Count_Repainting_Tock += Count_Repainting_Tockens(opredelitel, i + 1, j + 1, i, j);
	}

	if (Counts_Tocken_Black + Counts_Tocken_White >= 63) {
		if (opredelitel == 1) {
			Counts_Tocken_White += Count_Repainting_Tock;
			Counts_Tocken_Black -= Count_Repainting_Tock;
		}

		if (opredelitel == 2) {
			Counts_Tocken_Black += Count_Repainting_Tock;
			Counts_Tocken_White -= Count_Repainting_Tock;
		}

		if (Counts_Tocken_Black > Counts_Tocken_White) {
			return 9999;
		}
		if (Counts_Tocken_Black <= Counts_Tocken_White) {
			return -9999;
		}
	}



	if ((i == 0 || i == 7) && (j == 0 || j == 7)) {
		/*if (opredelitel == 2) {

		}
		else {
			Rating_Pos = Rating_Pos - 8;
		}

		Rating_Pos = Rating_Pos + 8;
	}

	else if (i == 0 || i == 7 || j == 0 || j == 7) {
		Rating_Pos = Rating_Pos - 8;

	}

	/*else if (i == 1 || i == 6 || j == 1 || j == 6) {
		Rating_Pos -= 8;
	}

	if (opredelitel == 2) {
		Rating_Pos += 2 * (Counts_Tocken_Black - Counts_Tocken_White);
	}

	if (opredelitel == 1) {
		Rating_Pos += 2 * (Counts_Tocken_White - Counts_Tocken_Black);
	}


	if (opredelitel == 1) {
		Rating_Pos -= 2 * Count_Repainting_Tock;
	}

	if(opredelitel == 2) {
		Rating_Pos += 2 * Count_Repainting_Tock;
	}

	return Rating_Pos;
	*/
}

//------------------------------------------------------------------------------------
// Подсчёт количества фишек, которые перекрасятся

int Game::Count_Repainting_Tockens(int opredelitel, int i, int j, int I, int J) {
	int KI = i - I, KJ = j - J;
	float Count = 0;

	if (opredelitel == 1) {
		while ((Check_Massive_Elemetnt(i, j, Game_Field) == true && (Game_Field[i][j] == 2))) {
			Count += 2;
			i = i + KI;
			j = j + KJ;
		}
	}

	if (opredelitel == 2) {
		while ((Check_Massive_Elemetnt(i, j, Game_Field) == true && (Game_Field[i][j] == 1))) {
			Count += 2;
			i = i + KI;
			j = j + KJ;
		}
	}
	return Count;


}

//------------------------------------------------------------------------------------
// запись поля с файла

/*void Game::Read_Field_File() {
	std::ifstream File;
	File.open("Field.txt");
	Game_Field = new int* [8];
	for (int i = 0; i < 8; i++) {
		Game_Field[i] = new int[8];
	}
	while (!File.eof()) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				File >> Game_Field[i][j];
			}
		}

	}
	File.close();


	Adding_Place_To_Tockens(Opredelitel_Bot);
	for (int i = 0; i < 8; i++) {
		std::cout << std::endl;
		for (int j = 0; j < 8; j++) {
			std::cout << Game_Field[i][j]<< " ";
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (Game_Field[i][j] == 4) {
				std::cout << Evaluation(Opredelitel_Bot, i, j) << std::endl;
			}
		}
	}

}
*/

//------------------------------------------------------------------------------------
// Функция минимакс

/*void Game::MiniMax(TreeMinMax* tree, int cur_lvl) {

	if (tree != nullptr) {

		if (cur_lvl == 1) {
			Cur_position_And_Eval[0] = tree->Pos_I;
			Cur_position_And_Eval[1] = tree->Pos_J;
			Cur_position_And_Eval[2] = tree->Mark;
		}

		Count_Tockens(tree->Dream_Game_Field);


		if (cur_lvl == Max_lvl_Tree - 1) {
			if (tree->opredelitel == 2) {
				if (Best_Position_And_Eval[2] < tree->Mark) {
					Best_Position_And_Eval[2] = tree->Mark;
					Best_Position_And_Eval[0] = Cur_position_And_Eval[0];
					Best_Position_And_Eval[1] = Cur_position_And_Eval[1];
				}
			}
		}
		
		for (int i = 0; i < tree->Count_Sons; i++) {
			MiniMax(tree->Array_Sons[i], cur_lvl + 1);
		}
		
	}

}
*/

int Game::MiniMax(TreeMinMax* tree, int cur_lvl) {
	if (tree != nullptr) {
		if (tree->Mark == 9999 || tree->Mark == -9999 || cur_lvl == Max_lvl_Tree) {
			return tree->Mark;
		}

		if (cur_lvl > 0) {
			if (tree->opredelitel == 1) {
				int Min = 9999;
				for (int i = 0; i < tree->Count_Sons; i++) {
					MiniMax(tree->Array_Sons[i], cur_lvl + 1);
				}

				tree->Mark = Min_Pos_On_Curlvl(tree, Min);

			}

			if (tree->opredelitel == 2) {
				int Max = -9999;
				for (int i = 0; i < tree->Count_Sons; i++) {
					MiniMax(tree->Array_Sons[i], cur_lvl + 1);
				}
				tree->Mark = Max_Pos_On_Curlvl(tree, Max);
			}
		}

	}

	return tree->Mark;
}

//-----------------------------------------------------------
// Минимальная из оценок на следующем уровне

int Game::Min_Pos_On_Curlvl(TreeMinMax* tree, int MIN) {

	if (tree != nullptr) {
		for (int i = 0; i < tree->Count_Sons; i++) {
			if (MIN > tree->Array_Sons[i]->Mark) {
				MIN = tree->Array_Sons[i]->Mark;
				Best_Position_And_Eval[0] = tree->Array_Sons[i]->Pos_I;
				Best_Position_And_Eval[1] = tree->Array_Sons[i]->Pos_J;
			}
		}
	}
	return MIN;
}

//-----------------------------------------------------------
// Максимальная из оценок на следующем уровне

int Game::Max_Pos_On_Curlvl(TreeMinMax* tree, int MAX) {

	if (tree != nullptr) {
		for (int i = 0; i < tree->Count_Sons; i++) {
			if (MAX < tree->Array_Sons[i]->Mark) {
				MAX = tree->Array_Sons[i]->Mark;
				Best_Position_And_Eval[0] = tree->Array_Sons[i]->Pos_I;
				Best_Position_And_Eval[1] = tree->Array_Sons[i]->Pos_J;
			}
		}
	}

	return MAX;
}

//------------------------------------------------------------------------------------
// Перевод из возможного, придуманного поля в текущее игровое поле

void Game::Convert_Dream_Field_To_Field() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Game_Field[i][j] = Dream_Game_Field[i][j];
		}
	}

}

//------------------------------------------------------------------------------------
// Перевод из текущего игрового поля в возможное, придуманное поле

void Game::Convert_Field_To_Dream_Field() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Dream_Game_Field[i][j] = Game_Field[i][j];
		}
	}
}

//------------------------------------------------------------------------------------
// Создание дерева минимакса

TreeMinMax* Game::Create_MiniMax_Tree(TreeMinMax* tree, int cur_lvl, int opredelitel, int** Field, int I, int J) {

	if (cur_lvl < Max_lvl_Tree && Count_Tockens(Field) <= 64) {
		tree = new TreeMinMax;
		tree->opredelitel = opredelitel;
		tree->Dream_Game_Field = new int* [8];
		for (int i = 0; i < 8; i++) {
			tree->Dream_Game_Field[i] = new int[8];
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				tree->Dream_Game_Field[i][j] = Field[i][j];
				if (tree->Dream_Game_Field[i][j] == 3 || tree->Dream_Game_Field[i][j] == 4) {
					tree->Dream_Game_Field[i][j] = 0;
				}
			}
		}

		if (cur_lvl != 0) {
			tree->Dream_Game_Field[I][J] = tree->opredelitel;
			Takeover_Tockens(tree->opredelitel, I, J, tree->Dream_Game_Field);
			tree->Pos_I = I;
			tree->Pos_J = J;
			tree->Mark = Evaluation(tree->opredelitel, I, J, tree->Dream_Game_Field);
			
		}

		Count_Tockens(tree->Dream_Game_Field);
		if (tree->opredelitel == 1) {
			opredelitel = 2;
		}
		else if (tree->opredelitel == 2) {
			opredelitel = 1;
		}

		Adding_Place_To_Tockens(opredelitel, tree->Dream_Game_Field);
		Count_Positions_For_Tockens(tree->Dream_Game_Field);
		tree->Count_Sons = Count_position;

		if (tree->Count_Sons == 0) {
			return tree;
		}

		tree->Array_Sons = new TreeMinMax * [tree->Count_Sons];
		tree->Cur_Son = 0;

		//std::cout << tree->Mark << " " << tree->Count_Sons << " " << cur_lvl; 
		
 
		if (cur_lvl == Max_lvl_Tree-1 || tree->Mark == 9999 || tree->Mark == -9999){ //Count_Tockens(tree->Dream_Game_Field) == 64) {
			for (int i = 0; i < tree->Count_Sons; i++) {
				tree->Array_Sons[i] = nullptr;
			}
			
			return tree;
		}

		else {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (tree->Dream_Game_Field[i][j] == 3 || tree->Dream_Game_Field[i][j] == 4) {
						if (tree->Cur_Son < tree->Count_Sons) {
							tree->Array_Sons[tree->Cur_Son] = Create_MiniMax_Tree(tree->Array_Sons[tree->Cur_Son], cur_lvl + 1, opredelitel, tree->Dream_Game_Field, i, j);
							tree->Cur_Son = tree->Cur_Son + 1;
						}
					}
				}
			}
		}
	}

	return (tree);
}


void Game::Clear_Tree(TreeMinMax* tree) {

	if (tree == nullptr) {
		return;
	}

	for (int i = 0; i < tree->Count_Sons; i++) {
		
		Clear_Tree(tree->Array_Sons[i]);
	}
	//std::cout << "Clear" << std::endl;
	delete tree;

}