#include <iostream>
#include "N_tree.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

void List_N_Tree::Create_N_Tree_Rand() {
	int cur_lvl = 0;
	std::cout << "Enter count N of Tree" << std::endl;
	std::cin >> N_Count;
	std::cout << "Enter H of Tree" << std::endl;
	std::cin >> H_Tree;
	Root = Add_Element_Rand(Root, cur_lvl);
}

N_Tree* List_N_Tree::Add_Element_Rand(N_Tree* tree, int cur_lvl) {

	if ((cur_lvl < H_Tree)) {
		tree = new N_Tree;
		tree->Data = 1 + rand() % 100;
		tree->Count_Cur_Pointers = 1 + rand() % N_Count;
		std::cout << tree->Data << " " << tree->Count_Cur_Pointers << " " << cur_lvl << std::endl;
		tree->Array_Pointers = new N_Tree * [tree->Count_Cur_Pointers];

		if (cur_lvl == H_Tree - 1) {
			for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
				tree->Array_Pointers[i] = nullptr;

			}
		}
		else {
			for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
				tree->Array_Pointers[i] = Add_Element_Rand(tree->Array_Pointers[i], cur_lvl + 1);
			}
		}
	}
	return (tree);
}

void List_N_Tree::Create_N_Tree_Of_Hand() {
	int cur_lvl = 0;
	Cur_I = 0;
	Root = nullptr;
	std::cout << "Enter count N of Tree" << std::endl;
	std::cin >> N_Count;
	std::cout << "Enter counts elements in Tree" << std::endl;
	std::cin >> Counts_Elements;
	Root = Add_Element_Of_Hand(Root, cur_lvl);


}

N_Tree* List_N_Tree::Add_Element_Of_Hand(N_Tree* tree, int cur_lvl) {

	if (tree == nullptr && Cur_I < Counts_Elements && (cur_lvl==0 || Check_Need_lvl_Full(0, cur_lvl-1,Root) != false)) {
		tree = new N_Tree;
		if (Cur_I == 0) {
			Root = tree;
		}
		std::cout << "Enter next element:";
		std::cin >> tree->Data;
		Cur_I++;
		tree->Count_Cur_Pointers = N_Count;
		std::cout << tree->Data << " " << tree->Count_Cur_Pointers << " " << cur_lvl << std::endl;
		tree->Array_Pointers = new N_Tree * [tree->Count_Cur_Pointers];

		for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
			tree->Array_Pointers[i] = nullptr;
		}
	}

	if (Cur_I < Counts_Elements && Check_Need_lvl_Full(0, cur_lvl, Root) != false) {
		for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
			tree->Array_Pointers[i] = Add_Element_Of_Hand(tree->Array_Pointers[i], cur_lvl + 1);
		}
	}

	if (Cur_I < Counts_Elements && tree != Root) {
		std::cout << "Ret";
		return (tree);
	}

	if (tree == Root && Cur_I < Counts_Elements) {
		cur_lvl = 0;
		while (Cur_I < Counts_Elements) {
			tree = Add_Element_Of_Hand(Root, cur_lvl);
		}
	}
	
	if (Cur_I >= Counts_Elements) {
		return (Root);
	}

}

bool List_N_Tree::Check_Need_lvl_Full(int cur_lvl, int need_lvl, N_Tree* tree) {

	if (need_lvl == 0) {
		return true;
	}

	if (tree!= nullptr) {
		for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
			if (tree->Array_Pointers[i] == nullptr && cur_lvl + 1 == need_lvl) {
				return false;
			}
			Check_Need_lvl_Full(cur_lvl + 1, need_lvl, tree->Array_Pointers[i]);
		}
	}
	
}

void List_N_Tree::Print_N_Tree(N_Tree* tree) {
	if (tree != nullptr) {
		std::cout << tree->Data << "  ";
		for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
			Print_N_Tree(tree->Array_Pointers[i]);
		}
	}
}


void  List_N_Tree::Search_Widths() {
	MAX_WIDTH = Root->Count_Cur_Pointers;
	MIN_WIDTH = Root->Count_Cur_Pointers;
	std::cout << std::endl;
	std::cout << "Need lvl Tree = " << std::endl;
	std::cin >> Need_H;

	Iterate_Tree(Root, 0);
	std::cout << std::endl;
	std::cout << "Minimum width on" << Need_H << "lvl = " << MIN_WIDTH << std::endl;
	std::cout << "Maximum width on" << Need_H << "lvl = " << MAX_WIDTH << std::endl;
}

void List_N_Tree::Iterate_Tree(N_Tree* tree, int cur_lvl) {
	if (tree != nullptr) {
		if (cur_lvl == Need_H) {
			if (tree->Count_Cur_Pointers > MAX_WIDTH) {
				MAX_WIDTH = tree->Count_Cur_Pointers;
			}
			if (tree->Count_Cur_Pointers < MIN_WIDTH) {
				MIN_WIDTH = tree->Count_Cur_Pointers;
			}
		}
		for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
			Iterate_Tree(tree->Array_Pointers[i],cur_lvl+1);
		}
	}
}

/*void List_N_Tree::Read_Tree_In_File() {
	std::ifstream File;
	
	int Razm = 0, Count_Cycles=0;
	if (Check_File_For_Symbols()==true) {
		File.open("N_Tree.txt");

		while (!File.eof()) {
			if (Count_Cycles == 0) {
				File >> N_Count;
				File >> H_Tree;
				for (int i = 1; i < H_Tree + 1; i++) {
					Razm += N_Count ^ H_Tree;
				}
				for (int i = 0; i < H_Tree; i++) {
					Mass_El = new int[Razm];
				}
				for (int i = 0; i < Razm; i++) {
					Mass_El = new int[Razm];
				}

			}
			



			//Root = Add_Element_Of_File(Root, 0);

		}
		File.close();
	}

}

*/

bool List_N_Tree::Check_File_For_Symbols() {
	int  s = 0;
	std::string str;
	std::ifstream File;
	File.open("Binare_Tree.txt");
	while (!File.eof()) {
		File >> str;
		try {
			s = std::stoi(str);
		}
		catch (...) {
			std::cout << "You enter not only number. Check file and delete symbols" << std::endl;
			return false;
		}
	}
	File.close();
	return true;
}

// ----------------------------------------------------
// Проверка введеных данных на число

int List_N_Tree::Check_For_Number() {
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

//---------------------------------------------------------
// 
/*N_Tree* List_N_Tree::Add_Element_Of_File(N_Tree* tree, int cur_lvl) {

	if ((cur_lvl < H_Tree) and Mass_El[cur_I]!=0) {
		tree = new N_Tree;
		tree->Data = 1 + rand() % 100;
		tree->Count_Cur_Pointers = 1 + rand() % N_Count;
		std::cout << tree->Data << " " << tree->Count_Cur_Pointers << " " << cur_lvl << std::endl;
		tree->Array_Pointers = new N_Tree * [tree->Count_Cur_Pointers];

		if (cur_lvl == H_Tree - 1) {
			for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
				tree->Array_Pointers[i] = nullptr;

			}
		}
		else {
			for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
				tree->Array_Pointers[i] = Add_Element(tree->Array_Pointers[i], cur_lvl + 1);
			}
		}
	}
	return (tree);
}
*/