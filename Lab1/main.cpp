#include <iostream>
#include "Spisok.h"
#include <time.h>
#include <stdlib.h>
#include <fstream>

int main() {
	int opredelitel;
	srand(time(NULL));
	List list1;
	Spisok* head;
	while (true) {
		std::cout << "1 - Create random List" << std::endl;
		std::cout << "2 - Read List in File" << std::endl;
		std::cout << "3 - Enter List to Hands" << std::endl;
		std::cout << "0 - Close program" << std::endl;
		std::cin >> opredelitel;
		switch (opredelitel) {

		case 1:
			system("cls");
			head = list1.Create_Spisok_Random();
			list1.Show_Spisok();
			list1.Change_Spisok();
			list1.Show_Spisok();
			list1.Clear_Spisok();
			break;

		case 2:
			system("cls");
			head = list1.Read_Spisok_In_File();
			if (list1.Check_File_For_Symbols() != false) {
				list1.Show_Spisok();
				list1.Change_Spisok();
				list1.Show_Spisok();
				list1.Clear_Spisok();
			}
			break;

		case 3:
			system("cls");
			head = list1.Enter_Spisok_Hand();
			list1.Show_Spisok();
			list1.Change_Spisok();
			list1.Show_Spisok();
			list1.Clear_Spisok();
			break;

		case 0:
			exit(0);
			break;

		default:
			std::cout << "Uncorrect value" << std::endl;
			break;
		}
	}
}
