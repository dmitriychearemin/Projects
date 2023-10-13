#include <iostream>
#include "N_Tree.h"


int main() {
	List_N_Tree Tr1;
	int opredelitel=0;
	srand(time(NULL));

	while (true) {
		std::cout << "1 - Create random N-ary Tree" << std::endl;
		std::cout << "2 - Read  N-ary Tree of file" << std::endl;
		std::cout << "3 - Show Tree" << std::endl;
		std::cout << "4 - Search Min Width and Max Width" << std::endl;
		std::cout << "0 - Exit" << std::endl;

		switch (opredelitel)
		{

		case 1:
			Tr1.Create_N_Tree();
			break;

		case 2:

			break;

		case 3:
			Tr1.Print_N_Tree(Tr1.Root);
			break;

		case 4:
			Tr1.Search_Widths();
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
