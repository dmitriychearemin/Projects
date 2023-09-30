#include "Matrix_CRS.h"
#include <iostream>
#include <fstream>
#include <string>

//------------------------------------------------------
// Конструктор

Matrix_CRS::Matrix_CRS() {
	N = nullptr;
	A = nullptr;
	LI = nullptr;
	LJ = nullptr;
	Razm = 0;
	Arr = nullptr;
}

//------------------------------------------------------
// Создание CRS матрицы вручную

void Matrix_CRS::Create_CRS_Matrix_Hand() {
	system("cls");
	bool k1=true, k2= true;
	while (k1) {
		std::cout << "How many lines in square matrix" << std::endl;
		Razm = Check_For_Number();
		if(Razm>0){
			k1 = false;
			while (k2) {
				std::cout << "How many non-zero elements in CRS Matrix?" << std::endl;
				Count_elements = Check_For_Number();
				if (Count_elements > 0 && Count_elements < (Razm*Razm)) {
					k2 = false;
					N = new int[Count_elements];
					for (int i = 0; i < Count_elements; i++) {
						N[i] = i;
					}
					A = new int[Count_elements];
					LJ = new int[Count_elements];
					LI = new int[Razm + 1];
					std::cout << "Enter Elements:" << std::endl; // Ввод элементов матрицы
					for (int i = 0; i < Count_elements; i++) {
						while (true) {
							std::cout << i << ":";
							A[i] = Check_For_Number();
							if (A[i] > 0) {
								break;
							}
						}
					}
					std::cout << std::endl;

					std::cout << "Enter coordinates Column :" << std::endl; // Ввод номеров столбцов
					for (int i = 0; i < Count_elements; i++) { 
						while (true) {
							std::cout << i << ":";
							LJ[i] = Check_For_Number();
							if (LJ[i] >= 0 && LJ[i] < Razm) {
								break;
							}
						}
					}
					std::cout << std::endl;

					std::cout << "Enter coordinates Lines  :" << std::endl; // Ввод номеров строк
					for (int i = 0; i < Razm; i++) { 
						while (true) {
							std::cout << i << ":";
							LI[i] = Check_For_Number();
							if (LI[i] >= 0 && LI[i] <= Count_elements ) {
								break;
							}
						}
					}
					LI[Razm] = Count_elements + 1;
					std::cout << std::endl;
				}
			}
		}
	}
	Convert_CRS_To_Matrix();
}

//-----------------------------------------------------
// Вывод CRS матрицы

void Matrix_CRS::Show_CRS_Matrix() {

	std::cout << "CRS MATRIX" << std::endl;
	std::cout << "Numbering:";
	for (int i = 0; i < Count_elements; i++) {
		std::cout << N[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Elements: ";
	for (int i = 0; i < Count_elements; i++) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "LJ:       ";
	for (int i = 0; i < Count_elements; i++) {
		std::cout << LJ[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "LI:       ";
	for (int i = 0; i < Razm+1; i++) {
		std::cout << LI[i] <<" ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

//------------------------------------------------------
// Проверка файла на наличие символов

bool Matrix_CRS::Check_File_For_Symbols() {
	int  s = 0;
	std::string str;
	std::ifstream File;
	File.open("CRS_Matrix.txt");
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
}

//------------------------------------------------------
// Проверка на число

int Matrix_CRS::Check_For_Number() {
	int a = 0;
	std::cin >> a;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(128000, '\n');  //удаление значения предыдущего ввода из входного буфера
		std::cout << "You enter uncorrected data, try again" << std::endl;
	}
	else {
		return a;
	}
}

//------------------------------------------------------
// Вычисление определителя 

void Matrix_CRS::Calculate_Determinant() {
	
	determinant = Calculate_Determinant1(Arr, Razm);
	std::cout << "Determinant = " << determinant << std::endl;
}

int Matrix_CRS::Calculate_Determinant1(int** arr, int Cur_Razm) {
	int k = 1, d=0;
	int** dopmass;
		dopmass = new int*[Cur_Razm];
	for (int i = 0; i < Cur_Razm; i++) {
		dopmass[i] = new int[Cur_Razm];
	}

	if (Cur_Razm == 1) {
		d = arr[0][0];
		return(d);
	}

	if (Cur_Razm == 2) {
		d = arr[0][0] * arr[1][1] - (arr[0][1] * arr[1][0]);
		return(d);
	}

	if (Cur_Razm > 2) {
		for (int i = 0; i < Cur_Razm; i++) {
			Matr_Without_IJ(arr, dopmass, i, 0, Cur_Razm);
			d = d + k * arr[i][0] * Calculate_Determinant1(dopmass, Cur_Razm - 1);
			k = -k;
		}
		delete dopmass;
		return(d);
	}
	
}

//------------------------------------------------------
// Конвертация из CRS матрицы в обычную

void Matrix_CRS::Convert_CRS_To_Matrix() {
	
	Arr = new int*[Razm];
	for (int i = 0; i < Razm; i++) {
		Arr[i] = new int[Razm];
	}

	for (int i = 0; i < Razm; i++) {
		for (int j = 0; j < Razm; j++) {
			Arr[i][j] = Acess_To_Elements(i, j);
		}
	}
}

//------------------------------------------------------
// Доступ к элементу CRS матрицы

int Matrix_CRS::Acess_To_Elements(int i, int j) {

	int AA = 0; // значение искомого элемента
	int N1 = LI[i];
	int N2 = LI[i + 1];
	for (int k = N1; k < N2; k++)
	{
		if (LJ[k] == j)
		{
			AA = A[k];
			break;
		}
	}
	return AA;
}

//------------------------------------------------------
// Вывод матрицы на экран

void Matrix_CRS::Show_Matrix() {

	if (Arr != nullptr) {
		system("cls");
		std::cout << "Matrix: " << std::endl;
		for (int i = 0; i < Razm; i++) {
			std::cout << std::endl;
			for (int j = 0; j < Razm; j++) {

				std::cout << Arr[i][j] << " ";
			}
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	else {
		std::cout << "Matrix not create!!! " << std::endl;
	}
	std::cout << std::endl;
}

//------------------------------------------------------
// Чтение матрицы с файла

void Matrix_CRS::Read_CRS_Matrix_File() {
	int count = 0;
	int Count_A = 0, Count_LJ = 0, Count_LI = 0;
	if (Check_File_For_Symbols() != false) {
		std::ifstream File;
		File.open("CRS_Matrix.txt");

		if (File) {
			while (!File.eof()) {
				if (count == 0) {
					File >> Razm;
				}

				if (count == 1) {
					File >> Count_elements;
					N = new int[Count_elements];
					for (int i = 0; i < Count_elements; i++) {
						N[i] = i;
					}
					A = new int[Count_elements];
					LJ = new int[Count_elements];
					LI = new int[Razm + 1];
				}

				if(count>1) {
					if (Count_A < Count_elements) {
						File >> A[Count_A];
						Count_A++;
					}
					if (Count_A == Count_elements && Count_LJ < Count_elements) {
						File >> LJ[Count_LJ];
						Count_LJ++;
					}
					if (Count_LJ == Count_elements && Count_LI < Razm) {
						File >> LI[Count_LI];
						Count_LI++;
					}
				}
				count++;
			}
			LI[Razm] = Count_elements + 1;
			File.close();
			
		}

		else {
			std::cout << "File not exist" << std::endl;
		}

	}
	Convert_CRS_To_Matrix();
}

//------------------------------------------------------
// Возврат матрицы бех строки и столбца

void Matrix_CRS::Matr_Without_IJ(int** arr, int** dopmass, int I, int J, int Cur_Razm) {
	int dopi = 0, dopj;
	for (int i = 0; i < Cur_Razm-1; i++) {
		if (i == I) {
			dopi = 1;
		}
		dopj = 0;
		for (int j = 0; j < Cur_Razm - 1; j++) {
			if (j == J) {
				dopj = 1;
			}
			dopmass[i][j] = arr[i+dopi][j+dopj];
		}
	}
}

// -----------------------------------------------------
// Очистка памяти

void Matrix_CRS::Clear_Matrix() {
	if (Arr != nullptr) {
		for (int i = 0; i < Razm; i++) {
			delete[] Arr[i];
		}
		delete[] Arr;
	}
	Razm = 0;
	determinant = 0;
}

void Matrix_CRS::Clear_CRS_Matrix() {
	delete[] N;
	delete[] A;
	delete[] LI;
	delete[] LJ;
	Count_elements = 0;
	determinant = 0;
	
}

//------------------------------------------------------
// Создание матрицы вручную

void Matrix_CRS::Create_Matrix_Hand() {
	system("cls");
	bool k1 = true;
	bool k2 = true;
	while (k1) {
		std::cout << "How many lines in square matrix" << std::endl;
		Razm = Check_For_Number();
		if (Razm > 0) {
			Arr = new int* [Razm];
			for (int i = 0; i < Razm; i++) {
				Arr[i] = new int[Razm];
			}
			k1 = false;
			std::cout << "Enter Matrix:" << std::endl;
			for (int i = 0; i < Razm; i++) {
				std::cout << std::endl;
				std::cout << std::endl;
				for (int j = 0; j < Razm; j++) {
					k2 = true;
					while (k2 == true) {
						std::cout << "[" << i << "]" << "[" << j << "]:";
						Arr[i][j] = Check_For_Number();
						k2 = false;
					}
				}
			}
		}
	}

	Convert_Matrix_To_CRS();
}

//------------------------------------------------------
// Из матрицы в CRS матрицу

void Matrix_CRS::Convert_Matrix_To_CRS() {
	Clear_CRS_Matrix();
	int count_A_LJ = 0;										// Позиция элемента А и LJ 
	int count_LI = 0, Count_Empty_line = 0;
	int Count_Elements_In_String = 0;
	for (int i = 0; i < Razm; i++) {
		for (int j = 0; j < Razm; j++) {
			if (Arr[i][j] != 0) {
				Count_elements++;
			}
		}
	}
	N = new int[Count_elements];
	for (int i = 0; i < Count_elements; i++) {
		N[i] = i;
	}
	A = new int[Count_elements];
	LJ = new int[Count_elements];
	LI = new int[Razm + 1];

	for (int i = 0; i < Razm; i++) {
		Count_Elements_In_String = 0;
		for (int j = 0; j < Razm; j++) {
			if (Arr[i][j] != 0) {
				Count_Elements_In_String++;

				A[count_A_LJ] = Arr[i][j];
				LJ[count_A_LJ] = j;
				
				if (Count_Elements_In_String == 1) {
					LI[count_LI] = count_A_LJ;
						if (Count_Empty_line > 0) {
							for (int k = Count_Empty_line; k > 0; k--) {
								LI[count_LI-k] = count_A_LJ;
							}
						}
						Count_Empty_line=0;
						count_LI++;
				}
				count_A_LJ++;
			}
			if (j == Razm - 1 && Count_Elements_In_String == 0) {
				Count_Empty_line++;
				count_LI++;
			}
			
		}
	}
	LI[Razm] = Count_elements + 1;

}

//------------------------------------------------------
// Чтение матрицы из файла

void Matrix_CRS::Read_Matrix_File() {

	int count = 0;
	int i = 0, j = 0;
	if (Check_File_For_Symbols() != false) {
		std::ifstream File;
		File.open("Matrix.txt");

		if (File) {
			while (!File.eof()) {
				if (count == 0) {
					File >> Razm;
					Arr = new int* [Razm];
					for (int i = 0; i < Razm; i++) {
						Arr[i] = new int[Razm];
					}

				}
				else {
					if (i < Razm) {
						if (j < Razm) {
							File >> Arr[i][j];
							j++;
						}
					}
					
					if (j == Razm) {
						i++;
						j = 0;
					}
				}
				count++;
			}
			File.close();
		}
		else {
			std::cout << "File not exist" << std::endl;
		}

	}
	Convert_Matrix_To_CRS();

}