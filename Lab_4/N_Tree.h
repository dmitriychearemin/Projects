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
		int Need_H, Cur_El_Mass, Razm_Mass;
		//bool K;
		int H_Tree, N_Count, MAX_WIDTH, MIN_WIDTH;
		int* Mass_El;

	public:
		N_Tree* Root=nullptr;
		void Create_N_Tree_Rand();
		N_Tree* Add_Element_Rand(N_Tree*, int);

		N_Tree* Add_Element_Of_Hand(N_Tree*,int);
		void Create_N_Tree_Of_Hand();
		
		void Read_Tree_In_File();
		N_Tree* Add_Element_Of_File(N_Tree*, int);

		//bool Full_Lvl_in_Tree(int cur_lvl, int need_lvl, N_Tree* tree);
		//void Check_Need_lvl_Full(int cur_lvl, int need_lvl, N_Tree* tree);

		void Print_N_Tree(N_Tree*);
		void Iterate_Tree(N_Tree*, int);
		void Search_Widths();
		
		bool Check_File_For_Symbols();
		int Check_For_Number();
		void Clear_Tree(N_Tree* tree);
};