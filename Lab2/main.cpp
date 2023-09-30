#include <iostream>
#include "Matrix_CRS.h"
#include <Windows.h>


int main() {
	int opredelitel;
	Matrix_CRS m1;

	while (true) {
		std::cout << "1 - Create Matrix in hand" << std::endl;
		std::cout << "2 - Create CRS Matrix in hand" << std::endl;
		std::cout << "3 - Read CRS Matrix in File " << std::endl;
		std::cout << "4 - Read Matrix in File " << std::endl;
		std::cout << "5 - Show CRS Matrix" << std::endl;
		std::cout << "6 - Show Matrix" << std::endl;
		std::cout << "7 - Calculate determinant" << std::endl;
		std::cout << "0 - exit" << std::endl;
		std::cin >> opredelitel;

		switch (opredelitel)
		{

			case 1:
			system("cls");
			m1.Create_Matrix_Hand();
			break;

			case 2:
				system("cls");
				m1.Create_CRS_Matrix_Hand();
				break;

			case 3:
				system("cls");
				m1.Read_CRS_Matrix_File();
				break;

			case 4:
				system("cls");
				m1.Read_Matrix_File();
				break;

			case 5:
				system("cls");
				m1.Show_CRS_Matrix();
				break;

			case 6:
				system("cls");
				m1.Show_Matrix();
				break;

			case 7:
				system("cls");
				m1.Calculate_Determinant();
				break;

			case 0:
				exit(0);
				break;

			default:
				std::cout << "Incorrect value, try again" << std::endl;
				break;
		}
	}
	
	m1.Clear_CRS_Matrix();
	m1.Clear_Matrix();

}


