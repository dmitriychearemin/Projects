#include <iostream>
#include "List_Tree.h"



int main() {
	List_Tree TR1;
	int opredelitel=0;

	while (true)
	{
		std::cout <<  std::endl;
		std::cout << "1 - Create Binare Tree" << std::endl;
		std::cout << "2 - Read Binare Tree in File" << std::endl;
		std::cout << "3 - Search identical vertexes" << std::endl;
		std::cout << "4 - Show Tree on screen" << std::endl;
		std::cout << "0 - exit" << std::endl;
		std::cin >> opredelitel;

		switch (opredelitel)
		{
		case 1:
			system("cls");
			TR1.CreateTree();
			break;

		case 2:
			system("cls");
			TR1.Read_In_File();
			break;

		case 3:
			system("cls");
			TR1.Finding_Vertex();
			break;

		case 4:
			system("cls");
			TR1.Print_Tree(TR1.Root);
			break;

		case 0:
			exit(0);

		default:
			system("cls");
			std::cout << "Incorrect data, try again" << std::endl;
			break;
		}
	}
}