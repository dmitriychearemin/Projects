#include <iostream>
#include "Arr_For_Sorting.h"






int main() {
	Array arr;
	int opredelitel = 0;
	srand(time(NULL));

	while (true) {

		std::cout << std::endl;
		std::cout << "1 - Create random Array" << std::endl;
		std::cout << "2 - Create  Array of hand" << std::endl;
		std::cout << "3 - Read array of File" << std::endl;
		std::cout << "4 - Show Array" << std::endl;
		std::cout << "5 - Sort array" << std::endl;
		std::cout << "0 - Exit" << std::endl;

		opredelitel= arr.Check_For_Number();

		switch (opredelitel)
		{

		case 1:
			arr.Enter_Mass_for_Rand();
			break;

		case 2:
			arr.Enter_Mass_for_Hand();
			break;

		case 3:
			arr.Read_Mass_of_File();
			break;

		case 4:
			system("cls");
			arr.Show_Array();
			break;

		case 5:
			arr.Sort();
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

