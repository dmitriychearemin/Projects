#pragma once


class Array {
private:
	int* array = nullptr;
	int size;

public:
	void Enter_Mass_for_Hand();
	void Enter_Mass_for_Rand();
	void Read_Mass_of_File();
	void Show_Array();
	void Quicksort(int *, int size);
	void Delete_Array();
	void Sort();

	void Separate(int i, int j, int Main_El);
	bool Check_File_For_Symbols();
	int Check_For_Number();
};