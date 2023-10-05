#include <iostream>
#include "Game.h"
#include <SFML/Graphics.hpp>

//------------------------------------------------------------------------------------
// Игровой цикл

void Game::Game_Cycle() {
	sf::RenderWindow window(sf::VideoMode(WIDTH_Screen,Height_Screen), "Otello");
	sf::Clock clock;
	sf::Time elapsed = clock.restart();
	Create_Tockens();
	Create_Field();
	Building_Objects_On_Array();
	Adding_Place_To_Tockens(Opredelitel_Player);
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
					Add_Tocken(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
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

//------------------------------------------------------------------------------------
// Создание игрового поля

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

//------------------------------------------------------------------------------------
// Отрисовка объектов

void Game::Count_Positions_For_Tockens() {
	Count_position = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Count_position++;
		}
	}
}

//------------------------------------------------------------------------------------
// Графический вывод изображение по массиву поля

void Game::Building_Objects_On_Array() {
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

//------------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------------
// Создание объектов и приведение их к параметрам, фишки, поля куда можно поставить фишку

void Game::Create_Tockens() {
	for (int i = 0; i < 64; i++) {
		Tocken[i].setRadius(40);
		Tocken[i].setOrigin(40,40);
	}
}

//------------------------------------------------------------------------------------
// Добавление фишки на экран

void Game::Add_Tocken(int x, int y) {
	int I=0, J=0;
	x = x - 468;
	y = y - 76;
	std::cout << x << " " << y << std::endl;
	std::cout << Positions[0].getPosition().x << " " << Positions[0].getPosition().y << std::endl;
	std::cout << Positions[1].getPosition().x << " " << Positions[1].getPosition().y << std::endl;


	for (int i = 0; i < Count_position; i++) {
		if ((Positions[i].getPosition().x - 49) < x && (Positions[i].getPosition().x + 49) > x && (Positions[i].getPosition().y - 49) < y && (Positions[i].getPosition().y + 49) > y) {
			
			I = (Positions[i].getPosition().x - Koef) / (Koef - 50);
			J = (Positions[i].getPosition().y - Koef) / (Koef - 50);
			Game_Field[I][J] = 1;
			break;
		}
	}
	Building_Objects_On_Array();
}

//------------------------------------------------------------------------------------
// Определение позиций куда можно поставить фишку

void Game::Adding_Place_To_Tockens(int opredelitel) {
	
	for (int i = 0; i < 8; i++){
		for (int j= 0; j < 8; j++){
			if (Game_Field[i][j] == 3 || Game_Field[i][j] == 4) {
				Game_Field[i][j] = 0;
			}
		}
	}

	if (opredelitel==1) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (Game_Field[i][j] == 1) {
					if (Check_Massive_Elemetnt(i - 1, j - 1) == true && Game_Field[i-1][j-1] == 2) {
						Iterate_Elements_Massive_For_Line(i - 1, j - 1, i, j, opredelitel);
					}
					if (Check_Massive_Elemetnt(i, j - 1) == true && Game_Field[i][j - 1] == 2) {
						Iterate_Elements_Massive_For_Line(i , j - 1, i, j, opredelitel);
					}
					if (Check_Massive_Elemetnt(i + 1, j - 1) == true && Game_Field[i - 1][j - 1] == 2) {
						Iterate_Elements_Massive_For_Line(i + 1, j - 1, i, j, opredelitel);
					}
					if (Check_Massive_Elemetnt(i - 1, j) == true && Game_Field[i - 1][j - 1] == 2) {
						Iterate_Elements_Massive_For_Line(i - 1, j - 1, i, j, opredelitel);
					}
					if (Check_Massive_Elemetnt(i + 1, j ) == true && Game_Field[i - 1][j - 1] == 2) {
						Iterate_Elements_Massive_For_Line(i + 1, j, i, j, opredelitel);
					}
					if (Check_Massive_Elemetnt(i - 1, j + 1) == true && Game_Field[i - 1][j - 1] == 2) {
						Iterate_Elements_Massive_For_Line(i - 1, j + 1, i, j, opredelitel);
					}
					if (Check_Massive_Elemetnt(i , j + 1) == true && Game_Field[i - 1][j - 1] == 2) {
						Iterate_Elements_Massive_For_Line(i , j + 1, i, j, opredelitel);
					}
					if (Check_Massive_Elemetnt(i + 1, j + 1) == true && Game_Field[i - 1][j - 1] == 2) {
						Iterate_Elements_Massive_For_Line(i + 1, j + 1, i, j, opredelitel);
					}
				}
			}
		}
	}

	if (opredelitel == 2) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (Game_Field[i][j] == 2) {
					if (Check_Massive_Elemetnt(i - 1, j - 1) == true && Game_Field[i - 1][j - 1] == 1) {
						Iterate_Elements_Massive_For_Line(i - 1, j - 1, i, j, opredelitel);
					}
					if (Check_Massive_Elemetnt(i, j - 1) == true && Game_Field[i][j - 1] == 1) {
						Iterate_Elements_Massive_For_Line(i, j - 1, i, j, opredelitel);
					}
					if (Check_Massive_Elemetnt(i + 1, j - 1) == true && Game_Field[i - 1][j - 1] == 1) {
						Iterate_Elements_Massive_For_Line(i + 1, j - 1, i, j, opredelitel);
					}
					if (Check_Massive_Elemetnt(i - 1, j) == true && Game_Field[i - 1][j - 1] == 1) {
						Iterate_Elements_Massive_For_Line(i - 1, j - 1, i, j, opredelitel);
					}
					if (Check_Massive_Elemetnt(i + 1, j) == true && Game_Field[i - 1][j - 1] == 1) {
						Iterate_Elements_Massive_For_Line(i + 1, j, i, j, opredelitel);
					}
					if (Check_Massive_Elemetnt(i - 1, j + 1) == true && Game_Field[i - 1][j - 1] == 1) {
						Iterate_Elements_Massive_For_Line(i - 1, j + 1, i, j, opredelitel);
					}
					if (Check_Massive_Elemetnt(i, j + 1) == true && Game_Field[i - 1][j - 1] == 1) {
						Iterate_Elements_Massive_For_Line(i, j + 1, i, j, opredelitel);
					}
					if (Check_Massive_Elemetnt(i + 1, j + 1) == true && Game_Field[i - 1][j - 1] == 1) {
						Iterate_Elements_Massive_For_Line(i + 1, j + 1, i, j, opredelitel);
					}
				}
			}
		}
	}
	

}

//------------------------------------------------------------------------------------
// Все методы работы компьютера

void Game::Computer_Action() {


}

//------------------------------------------------------------------------------------
// Проверка элемента массива на существование

bool Game::Check_Massive_Elemetnt(int i, int j) {
	if (i < 0 || i > 7 || j < 0 || j > 7) {
		return false;
	}
	return true;
}

//------------------------------------------------------------------------------------
// Перебор элементов по определённой линии

void Game::Iterate_Elements_Massive_For_Line(int i, int j, int I, int J, int opredelitel) {
	
	int KI = i - I, KJ = j - J;
	while (i + KI > 0 || i + KI < 7 || j + KJ > 0 || j + KJ < 7) {
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
		if (Game_Field[i + KI][j + KJ] == opredelitel) {
			break;
		}
		i = i + KI;
		j = j + KJ;
	}
}