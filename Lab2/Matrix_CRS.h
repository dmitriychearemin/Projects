#pragma once

class Matrix_CRS {

	private:
		int Count_elements, *N, * A, * LJ, * LI; // Matrix CRS
		int  Razm, **Arr, determinant;                                      // MAtrix

	public:
		Matrix_CRS();
		void Create_Matrix_Hand();
		void Create_CRS_Matrix_Hand();
		void Read_CRS_Matrix_File();
		void Read_Matrix_File();
		void Show_Matrix();
		void Show_CRS_Matrix();
		void Search_Determinant();
		bool Check_File_For_Symbols();
		int Check_For_Number();
		void Calculate_Determinant();
		int Calculate_Determinant1(int** arr, int Cur_Razm);
		void Convert_CRS_To_Matrix();
		void Convert_Matrix_To_CRS();
		int Acess_To_Elements(int i, int j);
		void Matr_Without_IJ(int** arr, int **dopmass, int I, int J, int Cur_Razm);
		void Clear_Matrix();
		void Clear_CRS_Matrix();
};