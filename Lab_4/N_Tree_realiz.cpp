#include <iostream>
#include "N_tree.h"
#include <cstdlib>
#include <ctime>



void List_N_Tree::Create_N_Tree() {
	int cur_lvl = 0;
	std::cout << "Enter count N of Tree" << std::endl;
	std::cin >> N_Count;
	std::cout << "Enter H of Tree" << std::endl;
	std::cin >> H_Tree;
	Root = Add_Element(Root, cur_lvl);
}

N_Tree* List_N_Tree::Add_Element(N_Tree* tree, int cur_lvl) {

	if (cur_lvl == H_Tree) {
		return(tree);
	}

	srand(time(NULL));

	tree->Data = rand() % 100;
	tree->Count_Cur_Pointers = rand() % N_Count;
	tree->Array_Pointers = new N_Tree* [tree->Count_Cur_Pointers];

	if (cur_lvl < H_Tree - 1) {
		for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
			tree = Add_Element(tree->Array_Pointers[i], cur_lvl + 1);
		}
	}

	else {
		for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
			tree->Array_Pointers[i] = nullptr;
		}
	}
	return(tree);
}


void List_N_Tree::Print_N_Tree(N_Tree* tree) {
	if (tree != nullptr) {
		std::cout << tree->Data << "  ";
		for (int i = 0; i < tree->Count_Cur_Pointers; i++) {
			Print_N_Tree(tree->Array_Pointers[i]);
		}
	}
}