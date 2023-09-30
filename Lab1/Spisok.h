#pragma once


class Spisok{
	int Element;
	class Spisok* next;
	friend class List;
	Spisok() { next = nullptr, Element = 0; } // Конструктор списка 

};

class List{
	private:
		int Count_Elements;
		Spisok* head;
		
	public:
		List() { head = nullptr; }            //Конструктор листа
		Spisok* Create_Spisok_Random();
		int Check_For_Number();
		void Show_Spisok();
		void Change_Spisok();
		void Clear_Spisok();
		bool Check_File_For_Symbols();
		Spisok* Read_Spisok_In_File();
		Spisok* Enter_Spisok_Hand();

};


