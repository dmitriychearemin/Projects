#include <iostream>
#include "N_tree.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <math.h>
#include <stdlib.h>

// --------------------------------------------------------
// Создание рандомного дерева

void List_N_Tree::Create_N_Tree_Rand() {
	int cur_lvl = 0;
	Root = nullptr;
	std::cout << "Enter count N of Tree" << std::endl;
	N_Count = Check_For_Number();
	std::cout << "Enter H of Tree" << std::endl;
	H_Tree = Check_For_Number();
	Root = Add_Element_Rand(Root, cur_lvl);
}

// --------------------------------------------------------
// Добавление рандомных элементов в дерево
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

// --------------------------------------------------------
// Создание дерева в ручную

void List_N_Tree::Create_N_Tree_Of_Hand() {
	int cur_lvl = 0, element= 0;
	
	std::cout << "Enter count N of Tree" << std::endl;
	N_Count = Check_For_Number();
	std::cout << "Enter  Max H of Tree" << std::endl;
	H_Tree = Check_For_Number();
	Root = Add_Element_Of_Hand(Root, cur_lvl);

}

// --------------------------------------------------------
// Добавление элементов через ручной ввод

N_Tree* List_N_Tree::Add_Element_Of_Hand(N_Tree* tree, int cur_lvl) {

	/*if (tree == nullptr && Cur_I < Counts_Elements && (cur_lvl == 0 || Check_Need_lvl_Full(0, cur_lvl - 1, Root) != false)) {
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
		return (tree);
	}

	if (tree == Root && Cur_I < Counts_Elements) {
		while (Cur_I < Counts_Elements) {
			tree = Add_Element_Of_Hand(tree, 0);
		}
	}

	if (Cur_I >= Counts_Elements) {
		return (Root);
	}
	*/
	/*if (tree == nullptr && (cur_lvl == 0 || Full_Lvl_in_Tree(0, cur_lvl - 1, Root) == true)) {
		tree = new N_Tree;
		tree->Data = element;
		K = false;
		tree->Count_Cur_Pointers = N_Count;
		std::cout << tree->Data << " " << tree->Count_Cur_Pointers << " " << cur_lvl << std::endl;
		tree->Array_Pointers = new N_Tree * [tree->Count_Cur_Pointers];
		for (int i = 0; i < N_Count; i++) {
			tree->Array_Pointers[i] = nullptr;
		}
		return tree;
	}

	else if (Full_Lvl_in_Tree(0, cur_lvl, Root) == true) {
		for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
			if (K != false) {
				tree->Array_Pointers[i] = Add_Element_Of_Hand(tree->Array_Pointers[i], cur_lvl + 1, element);
			}
		}
	}
	return tree;*/

	if (cur_lvl < H_Tree) {
		tree = new N_Tree;
		std::cout << "Enter element on lvl " << cur_lvl+1 << " : ";
		tree->Data = Check_For_Number();;
		tree->Count_Cur_Pointers = rand() % (N_Count-1)  + 2;
		tree->Array_Pointers = new N_Tree * [tree->Count_Cur_Pointers];

		if (cur_lvl == H_Tree - 1) {
			for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
				tree->Array_Pointers[i] = nullptr;

			}
		}
		else {
			for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
				tree->Array_Pointers[i] = Add_Element_Of_Hand(tree->Array_Pointers[i], cur_lvl + 1);
			}
		}
	}
	return (tree);

}


/*bool List_N_Tree::Full_Lvl_in_Tree(int cur_lvl, int need_lvl, N_Tree* tree) {
	
	if (need_lvl == 0) {
		return true;
	}

	Check_Need_lvl_Full(cur_lvl, need_lvl, tree);

	if (Summ_El_On_Lvl == pow(Counts_Elements, (need_lvl + 1))) {
		return true;
	}

	return false;
}
*/
/*void List_N_Tree::Check_Need_lvl_Full(int cur_lvl, int need_lvl, N_Tree* tree) {

	

	if (tree != nullptr ) {
		if (cur_lvl == need_lvl) {

		}

		for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
			if (tree->Array_Pointers[i] == nullptr && cur_lvl + 1 == need_lvl) {
				std::cout << "Fals";
				return false;
			}
			Check_Need_lvl_Full(cur_lvl + 1, need_lvl, tree->Array_Pointers[i]);
		}
	}

	
}
*/

// --------------------------------------------------------
// Вывод дерева
void List_N_Tree::Print_N_Tree(N_Tree* tree) {
	if (tree != nullptr) {
		std::cout << tree->Data << "  ";
		for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
			Print_N_Tree(tree->Array_Pointers[i]);
		}
	}
}

// --------------------------------------------------------
// Очистка дерева
void List_N_Tree::Clear_Tree(N_Tree* tree) {

	if (tree == nullptr) {
		return;
	}

	for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
		Clear_Tree(tree->Array_Pointers[i]);
	}
	delete tree;

}  


// --------------------------------------------------------
// Поиск самых широких и самых узких деревьев
void  List_N_Tree::Search_Widths() {
	MAX_WIDTH = Root->Count_Cur_Pointers;
	MIN_WIDTH = Root->Count_Cur_Pointers;
	std::cout << std::endl;
	std::cout << "Need lvl Tree = " << std::endl;
	while (true) {
		Need_H = Check_For_Number();
		if (Need_H <= H_Tree && Need_H >= 1) {
			break;
		}
	}
	Need_H -= 1;

	Iterate_Tree(Root, 0);
	std::cout << std::endl;
	std::cout << "Minimum width on " << Need_H + 1 << " lvl = " << MIN_WIDTH << std::endl;
	std::cout << "Maximum width on " << Need_H + 1 << " lvl = " << MAX_WIDTH << std::endl;
}

// --------------------------------------------------------
// Перебор дерева для нахождение максимальной и минимальной вершин де
void List_N_Tree::Iterate_Tree(N_Tree* tree, int cur_lvl) {
	if (tree != nullptr) {
		if (cur_lvl == Need_H-1) {
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

// --------------------------------------------------------
// Проверка файла на наличие символов

bool List_N_Tree::Check_File_For_Symbols() {
	int  s = 0;
	std::string str;
	std::ifstream File;
	File.open("N_Tree.txt");
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

// --------------------------------------------------------
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
// Чтение дерева с файла
void List_N_Tree::Read_Tree_In_File() {
	if (Razm_Mass > 0) {
		delete [] Mass_El;
	}
	int  Cur_I = 0;
	Cur_El_Mass = 0;
	Razm_Mass = 0;
	if (Check_File_For_Symbols() != false) {
		std::ifstream File;
		File.open("N_Tree.txt");
		if (File) {
			while (!File.eof()) {
				if (Cur_I == 0) {
					File >> N_Count;
					File >> H_Tree;
					for (int i = 1; i < H_Tree + 1; i++) {
						Razm_Mass += pow(N_Count, i);
					}
					Mass_El = new int[Razm_Mass];
				}
				File >> Mass_El[Cur_I];
				
				Cur_I++;
			}
			File.close();
			for (Cur_I; Cur_I < Razm_Mass; Cur_I++) {
				
				Mass_El[Cur_I]=0;
			}

			Root = Add_Element_Of_File(Root, 0);
		}
		else {
			std::cout << "File not exist" << std::endl;
		}
	}
}

//---------------------------------------------------------
// Добавление элементов в дерево из файла

N_Tree* List_N_Tree::Add_Element_Of_File(N_Tree* tree, int cur_lvl) {

	if ((cur_lvl < H_Tree)) {
		tree = new N_Tree;
		if (Cur_El_Mass < Razm_Mass) {
			tree->Data = Mass_El[Cur_El_Mass];
			Cur_El_Mass++;
		}
		else {
			tree->Data = 0;
		}
		
		tree->Count_Cur_Pointers = rand() % (N_Count - 1) + 2;
		//std::cout << tree->Data << " " << tree->Count_Cur_Pointers << " " << cur_lvl << std::endl;
		tree->Array_Pointers = new N_Tree * [tree->Count_Cur_Pointers];

		if (cur_lvl == H_Tree - 1 || tree->Data==0) {
			for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
				tree->Array_Pointers[i] = nullptr;

			}
		}
		else {
			for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
				tree->Array_Pointers[i] = Add_Element_Of_File(tree->Array_Pointers[i], cur_lvl + 1);
			}
		}
	}
	return (tree);
}
