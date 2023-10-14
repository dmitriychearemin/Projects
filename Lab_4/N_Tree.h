#pragma once



//Задача 12. Дано N - дерево.Найти в дереве самое широкое (узкое) поддерево имеющее заданную высоту.

class N_Tree {
	private:
		int Data;
		int Count_Cur_Pointers;
		N_Tree** Array_Pointers;
		friend class List_N_Tree;
};

class List_N_Tree {
	private:
		int Need_H, cur_I;
		int H_Tree, N_Count, MAX_WIDTH, MIN_WIDTH;
		int* Mass_El;
	public:
		N_Tree* Root;
		void Create_N_Tree();
		N_Tree* Add_Element(N_Tree*,int);
		void Print_N_Tree(N_Tree*);
		void Iterate_Tree(N_Tree*, int);
		void Search_Widths();
		void Read_Tree_In_File();
		bool Check_File_For_Symbols();
		int Check_For_Number();
		N_Tree* Add_Element_Of_File(N_Tree* tree, int cur_lvl);
};