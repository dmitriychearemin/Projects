#include <iostream>
#include "Hash_Table.h"
#include <limits>





int main() {
	int opredelitel;
	Hash_Table* Table = new Hash_Table;
	
	Table->Tables[0] = Table->Create_Hash_Table(5, Table->Tables[0]);
	while (true) {

		std::cout << std::endl;
		std::cout << "1 - Add element in table of hand" << std::endl;
		std::cout << "2 - Add element in table of file" << std::endl;
		std::cout << "3 - Search Need element" << std::endl;
		std::cout << "4 - Show Table" << std::endl;
		std::cout << "5 - Delete need element" << std::endl;
		std::cout << "0 - Exit" << std::endl;

		std::cin >> opredelitel;

		switch (opredelitel)
		{

		case 1:
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			Table->Add_Element_Hand();
			break;

		case 2:
			Table->Read_Table_In_File();
			break;

		case 3:
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			Table->Search_Need_Element();
			break;

		case 4:
			Table->Show_Hash_Table(Table->Tables[0]);
			break;

		case 5:
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			Table->Delete_Need_Element();
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


