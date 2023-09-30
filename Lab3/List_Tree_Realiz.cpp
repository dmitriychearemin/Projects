#include <iostream>
#include "List_Tree.h"
#include <fstream>
#include <string>

//----------------------------------------------------------
// Создание дерева

void List_Tree::CreateTree() {
	Clear_Mem(Root);
	int El=0;
	bool k = true;
	Root = new Tree;
	std::cout << "Enter Number Root" << std::endl;
	Root->data = Check_For_Number();
	std::cout << "Enter count Vertexes (Elements)" << std::endl;
	Razm_Tree = Check_For_Number();
	
	for (int i = 0; i < Razm_Tree; i++) {
		std::cout << "Enter Element" << std::endl;
	    El = Check_For_Number();
		Root = Add_Element(El, Root);
	}
	Razm_Tree++;
}

//----------------------------------------------------------
// Добавление элементов

Tree* List_Tree::Add_Element(int El, Tree* tree) {
	if (tree == nullptr) {
		tree = new Tree;
		tree->data = El;
		tree->Left_son = nullptr;
		tree->Right_son = nullptr;
	}
	else if (El < tree->data) {
		tree->Left_son = Add_Element(El, tree->Left_son);
	}
	else {
		tree->Right_son = Add_Element(El, tree->Right_son);
	}
	return (tree);
}

//---------------------------------------------------------
// Вывод дерева на экран

void List_Tree::Print_Tree(Tree* tree) {
	if (tree != nullptr) {
		std::cout << tree->data << "  ";
		Print_Tree(tree->Left_son);
		Print_Tree(tree->Right_son);
	}
}

//------------------------------------------------------------
// Перебор дерева

void List_Tree::Enumeration_Tree(Tree *tree) {

	if (tree != nullptr) {
		Update_Massive(tree->data);
		Enumeration_Tree(tree->Left_son);
		Enumeration_Tree(tree->Right_son);
	}

}

//------------------------------------------------------------
// Обновление массива

void List_Tree::Update_Massive(int a) {
	if (Check_Massive_For_Num(a) != I) {
		Arr_Count[Check_Massive_For_Num(a)]++;
	}
	else {
		Razm_Arr++;
		Arr_Count = (int*)realloc(Arr_Count, Razm_Arr * sizeof(int*));
		Arr_Data = (int*)realloc(Arr_Data, Razm_Arr * sizeof(int*));
		
		Arr_Count[I] = 1;
		Arr_Data[I] = a;
		
	}
	I++;
}

//------------------------------------------------------------
// Проверка массива на наличие в нём нужного числа

int List_Tree::Check_Massive_For_Num(int a) {
	for (int i = 0; i < Razm_Arr; i++) {
		if (Arr_Data[i] == a) {
			return i;
		}
	}
	return I;
}

//------------------------------------------------------------
// Нахождение вершин

void List_Tree::Finding_Vertex() {
	std::cout << std::endl;
	I = 0;
	Enumeration_Tree(Root);
	for (int i = 0; i < Razm_Arr; i++) {
		if (Arr_Count[i] > 1) {
			std::cout << "Vertex " << Arr_Data[i] << " - " << Arr_Count[i] << " Counts" << std::endl;
		}
	}
}

//------------------------------------------------------------
// Чтение дерева из файла

void List_Tree::Read_In_File() {
	if (Check_File_For_Symbols() != false) {
		Clear_Mem(Root);
		Root = new Tree;
		std::ifstream File;
		int a = 0;
		File.open("Binare_Tree.txt");
		if (File) {
			while (!File.eof()) {
				File >> a;
				Root = Add_Element(a, Root);

			}
			File.close();
		}
		else {
			std::cout << "File not exist" << std::endl;

		} 
	}

}

//------------------------------------------------------------
// Очистка памяти

void List_Tree::Clear_Mem(Tree *tree) {

	if (tree != nullptr) {
		Clear_Mem(tree->Left_son);
		Clear_Mem(tree->Right_son);
		delete tree;
	}

}

//------------------------------------------------------
// Проверка файла на наличие символов

bool List_Tree::Check_File_For_Symbols() {
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

int List_Tree::Check_For_Number() {
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