#include "Arr_For_Sorting.h"
#include <iostream>
#include <string>
#include <fstream>


// ���� ������� �������
void Array::Enter_Mass_for_Hand()
{
	Delete_Array();
	std::cout << "Enter razm massive";
	size = Check_For_Number();
	array = new int[size];
	for (int i = 0; i < size; i++) {
		std::cout << "Enter element " << i+1 << ": ";
		array[i] = Check_For_Number();
	}
	system("cls");
}

// �������� ���������� �������
void Array::Enter_Mass_for_Rand() {
	Delete_Array();

	std::cout << "Enter size massive" << std::endl;
	size = Check_For_Number();

	array = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 10000;
	}

}

// ����� ������� �� �����
void Array::Show_Array() {

	for (int i = 0; i < size; i++) {
		std::cout << "Element[" << i + 1 << "] = " << array[i] << std::endl;
	}

}

// ������ ������� � �����
void Array::Read_Mass_of_File() {
	
	size = 1;
	int i = 0;
	Delete_Array();
	array = new int[size];
	std::ifstream File;
	if (Check_File_For_Symbols() == true) {
		File.open("Array.txt");
		while (!File.eof()) {
			File >> array[i];
			size++;
			i++;
			array = (int*)realloc(array, size * sizeof(int));
		}
		File.close();
	}
	

}

// �������� ����� �� ������� ��������
bool Array::Check_File_For_Symbols() {
	int  s = 0;
	std::string str;
	std::ifstream File;
	File.open("Array.txt");
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


// ������� ����������
void Array::Quicksort(int * mass, int size) {
	
	
		int i = 0, j = size - 1;
		int mid = mass[size / 2];    //������� ������� �������
		do
		{
			while (mass[i] < mid) i++;    //���� �����
			while (mass[j] > mid) j--;    //���� ������
			if (i <= j)					  //����� �������� �������
			{
				int tmp = mass[i];
				mass[i] = mass[j];
				mass[j] = tmp;
				i++; j--;
			}
		} while (i <= j);
		//����������� ������
		if (j > 0)
			Quicksort(mass, j + 1);//����� ����� �������
		if (i < size)
			Quicksort(&mass[i], size - i);//������ �����
	

}

//������ ���������� � ������������ ��������� �������
void Array::Sort() {
	system("cls");
	std::cout << "Array bedore sorted:" << std::endl;
	Show_Array();
	std::cout << std::endl;
	if (size >= 2) {
		std::cout << "Sorted massive:" << std::endl;
		Quicksort(array, size);
		Show_Array();
	}
	else {
		std::cout << "Array doesnt need sort" << std::endl;
	}
}

// �������� �������� ������ �� �����
int  Array::Check_For_Number() {
int a = 0;
	while (true) {
		std::cin >> a;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(128000, '\n');  //�������� �������� ����������� ����� �� �������� ������
			std::cout << "You enter uncorrected data, try again" << std::endl;
		}
		else {
			return a;
			break;
		}
	}
}

// �������� �������
void Array::Delete_Array() {

	if ( array != NULL) {
		free (array);
	}
	array = nullptr;
}