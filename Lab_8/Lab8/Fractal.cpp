#include "Fractal.h"
#include <iostream>
#include <SFML/Graphics.hpp>

void Fractal::Enter_Data() {
    std::cout << " Enter depth :";
    n = Check_For_Number();
    std::cout << " Enter count Elements :";
    m = Check_For_Number();
    std::cout << " Enter start radius :";
    r = Check_For_Number();

}

int Fractal::Count_Figures() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += std::pow(m, n);
    }
    //std::cout << count;
    return count;
    
}


int  Fractal::Check_For_Number() {
    int a = 0;
    while (true) {
        std::cin >> a;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(128000, '\n');  //удаление значения предыдущего ввода из входного буфера
            std::cout << "You enter uncorrected data, try again" << std::endl;
        }
        else {
            return a;
            break;
        }
    }
}

void Fractal::Mem_for_Figure() {
    int count = Count_Figures();
    circle = new sf::CircleShape[count];
    for (int i = 0; i < count; i++)
    {
        circle[i].setFillColor(sf::Color::White);
    }

}


void Fractal::Fract(double x, double y, double r, double r1, int n) {


   double x1, y1;

       //{ от фигуры размером r с центром x, y рекурсивно строится m фигур - сателлитов
       // размером r = r / ks равномерно по периметру на расстоянии r1 = kr * r   
   if (n<5) {
       
   }

    if (n > 0){
        circle[count].setRadius(r);
        circle[count].setOrigin(r, r);
        circle[count].setPosition(x, y);
        count += 1;

        r1 = kr * r; //{ расстояние до фигур - сателлитов }

        for (int i = 0; i < m; i++) {               //{ рекурсивные вызовы }
            x1 = x + r1 * cos(2 * 3.14 * i / m); //{ координаты центра i - го сателлита }
            y1 = y + r1 * sin(2 * 3.14 * i / m);
            
            Fract(x1, y1, r / ks, r1, n - 1);

        }
    }
    
}

void Fractal::Draw_Figure() {
    
    int Count = 0;
   
    Enter_Data();
    Mem_for_Figure();
    Count = Count_Figures();
    Fract(x,y,r,0,n);
    sf::RenderWindow window(sf::VideoMode(1600, 900), "NICE!");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (int i = 0; i < Count; i++) {
            window.draw(circle[i]);
        }
        
        window.display();
    }




}