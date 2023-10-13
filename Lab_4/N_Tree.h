#pragma once



//Задача 12. Дано N - дерево.Найти в дереве самое широкое(узкое) поддерево имеющее заданную высоту.

class N_Tree {
	private:
		int Data;
		int Count_Cur_Pointers;
		N_Tree** Array_Pointers;
		friend class List_N_Tree;
};

class List_N_Tree {
	private:
		
		int H_Tree, N_Count, MAX_WIDTH, MIN_WIDTH;

	public:
		N_Tree* Root;
		void Create_N_Tree();
		N_Tree* Add_Element(N_Tree*,int);
		void Print_N_Tree(N_Tree*);
};