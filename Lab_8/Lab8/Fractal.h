#pragma once
#include <SFML/Graphics.hpp>

class Fractal {

	sf::CircleShape* circle;
	int m=0, n=0;

	int count = 0;
	int Gd=0, Gm=0;
	int Width = 1600, Height = 800;
	double x= Width/2, y=Height/2, r=0, r1 = 0, ks=3, kr=2;
				// начальные координатф 
				 // коэффициент уменьшения размера сателлитов }
				//отношение радиуса орбиты к размеру фигуры }
					//число сателлитов }
				//размер начальной фигуры 
					//глубина рекурсии 

public:
	void Enter_Data();
	void Mem_for_Figure();
	int  Check_For_Number();
	int Count_Figures();
	void Draw_Figure();
	void Fract(double x, double y, double r, double r1, int n);
};