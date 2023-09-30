#pragma once

class Tree {

	Tree* Left_son, * Right_son;
	int data, level;
	friend class List_Tree;
	Tree() { Left_son = nullptr, data=0, level = 0, Right_son = nullptr; }
};


class List_Tree {
	private:
		
		int Razm_Tree;
		int *Arr_Data, *Arr_Count, Razm_Arr, I;
	public:
		Tree* Root;
		List_Tree() { Arr_Data = nullptr, Arr_Count = nullptr; }
		void CreateTree();
		Tree* Add_Element(int El, Tree *tree);
		void Print_Tree(Tree* tree);
		void Enumeration_Tree(Tree* tree);
		void Update_Massive(int a);
		int Check_Massive_For_Num(int a);
		void Finding_Vertex();
		void Read_In_File();
		void Clear_Mem(Tree *tree);
		bool Check_File_For_Symbols();
		int Check_For_Number();

};