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


	if((cur_lvl < H_Tree)) {
		tree = new N_Tree;
		tree->Data = 1 + rand() % 100;
		tree->Count_Cur_Pointers =1 + rand() % N_Count;
		std::cout << tree->Data << " " << tree->Count_Cur_Pointers << " " << cur_lvl << std::endl;
		tree->Array_Pointers = new N_Tree* [tree->Count_Cur_Pointers];

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