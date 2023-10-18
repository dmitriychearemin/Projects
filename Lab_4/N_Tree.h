#pragma once



//������ 12. ���� N - ������.����� � ������ ����� ������� (�����) ��������� ������� �������� ������.

class N_Tree {
	private:
		int Data;
		int Count_Cur_Pointers;
		N_Tree** Array_Pointers;
		friend class List_N_Tree;
};

class List_N_Tree {
	private:
		int Need_H, Counts_Elements, Cur_I;
		int H_Tree, N_Count, MAX_WIDTH, MIN_WIDTH;
		//int* Mass_El;
	public:
		N_Tree* Root;
		void Create_N_Tree_Rand();
		N_Tree* Add_Element_Rand(N_Tree*, int);

		N_Tree* Add_Element_Of_Hand(N_Tree*,int);
		void Create_N_Tree_Of_Hand();
		
		bool Check_Need_lvl_Full(int cur_lvl, int need_lvl, N_Tree* tree);

		void Print_N_Tree(N_Tree*);
		void Iterate_Tree(N_Tree*, int);
		void Search_Widths();
		void Read_Tree_In_File();
		bool Check_File_For_Symbols();
		int Check_For_Number();
};