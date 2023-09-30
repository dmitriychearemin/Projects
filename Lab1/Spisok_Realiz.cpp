#include "Spisok.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

//--------------------------------------------------
// Создание рандомного списка

Spisok* List::Create_Spisok_Random() {
	int i = 0;
	Spisok* cur;
	bool k = true;
	while (k) {
		std::cout << "List will random. How many elements need?" << std::endl;
		Count_Elements = Check_For_Number();
		if (Count_Elements > 0) {
			k = false;
			head = new Spisok;
			head->Element = rand() % 10;
			cur = head;
			i++;
			while (i < Count_Elements) {
				cur->next = new Spisok;
				cur = cur->next;
				cur->Element = rand() % 10;
				i++;
			}
			cur->next = nullptr;
			return head;
		}
	}
}

//----------------------------------------------------
// Вывод списка на экран

void List::Show_Spisok() {
	Spisok* cur = head;
	int i=0;
	std::cout << "Your List " << std::endl;
	while (cur->next != nullptr) {
		std::cout << cur->Element << " ";
		cur = cur->next;
	}
	std::cout << cur->Element << " " << std::endl;
	std::cout << std::endl;

}

//----------------------------------------------------
// Алгоритм изменения списка 

void List::Change_Spisok() {
	Spisok* cur = head, *dop = cur->next;
	int i = 0;
	std::cout << "Changing elements in List." << std::endl;
	while (i<Count_Elements) {
		if (dop->Element > cur->Element) {
			cur->Element = dop->Element;
		}
		else{
			if (dop->next == nullptr) {
				cur->Element = 0;
			}
			while (dop->next) {
				dop = dop->next;
				if (dop->Element > cur->Element) {
					cur->Element = dop->Element;
					break;
				}	
				if (dop->next == nullptr) {
					cur->Element = 0;
				}
			}
		}
		cur = cur->next;
		dop = cur;
		if (dop->next == nullptr) {
			cur->Element = 0;
			break;
		}
		dop = cur->next;
		i++;
	}
}

//------------------------------------------------------
// Очистка памяти

void List::Clear_Spisok() {
	Spisok* cur = head;
	int i = 0;
	while (head->next!= nullptr) {
		head = head->next;
		delete cur, cur->Element;
		cur = head;
		i++;
	}
}

//------------------------------------------------------
// Проверка на число

int List::Check_For_Number() {
	int a=0;
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
// Чтение с файла и создание нового списка

Spisok* List::Read_Spisok_In_File() {
	if (Check_File_For_Symbols() != false) {
		std::ifstream File;
		int count = 0;
		Spisok* cur = nullptr;
		head = new Spisok;
		cur = head;
		File.open("Spisok.txt");
		if (File) {
			while (!File.eof()) {
				if (count == 0) {
					File >> head->Element;
					Count_Elements++;
				}
				else {
					cur->next = new Spisok;
					cur = cur->next;
					File >> cur->Element;
					Count_Elements++;
				}
				count++;
			}

			File.close();
			return head;
		}
		else {
			std::cout << "File not exist" << std::endl;
		}
	}
}

//-------------------------------------------------
// Ввод списка вручную

Spisok* List::Enter_Spisok_Hand() {
	int i = 0;
	Spisok* cur;
	bool k = true;
	while (k) {
		std::cout << "How many elements need?" << std::endl;
		Count_Elements = Check_For_Number();
		if (Count_Elements > 0) {
			k = false;
			head = new Spisok;
			std::cout << "Elements List:" << std::endl;
			while (true) {
				std::cout << i+1 << ": ";
				head->Element = Check_For_Number();
				if (head->Element >= 0 && head->Element <=9) {
					break;
				}
			}
			cur = head;
			i++;
			while (i < Count_Elements) {
				cur->next = new Spisok;
				cur = cur->next;
				while (true) {
					std::cout << i+1 << ": ";
					cur->Element = Check_For_Number();
					if (cur->Element >= 0 && cur->Element <= 9) {
						break;
					}
				}
				i++;
			}
			cur->next = nullptr;
			return head;
		}
	}


}

//-------------------------------------------------
// Проверка файла на наличие символов

bool List::Check_File_For_Symbols() {
	int  s = 0;
	std::string str;
	std::ifstream File;
	File.open("Spisok.txt");
	while (!File.eof()) {
		File >> str;
		try {
			s = std::stoi(str);
		}
		catch(...) {
			std::cout << "You enter not only number. Check file and delete symbols" << std::endl;
			return false;
		}
		
	}
	File.close();
}
