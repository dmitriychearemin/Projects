#define _CRT_SECURE_NO_WARNINGS
#include "Hash_Table.h"
#include <iostream>
#include <string>


void Hash_Table::Add_Element_Hand() {

	char* Name= nullptr, *Country=nullptr, *Street=nullptr, *City=nullptr, *N_Home=nullptr;
	setlocale(LC_ALL, "Russian");

	std::cout << "¬ведите название компании: " << std::endl;
	Name = Enter_Data(Name);

	std::cout << "¬ведите страну где находитьс€ главный офис этой компании:   " << std::endl;
	Country = Enter_Data(Country);

	std::cout << "¬ведите город где находитьс€ главный офис этой компании:   " << std::endl;
	City =  Enter_Data(City);

	std::cout << "¬ведите улицу где находитьс€ главный офис этой компании:  " << std::endl;
	Street =  Enter_Data(Street);

	std::cout << "¬ведите дом в котором находитьс€ главный офис этой компании:  " << std::endl;
	N_Home=  Enter_Data(N_Home);

	Insert_Item_In_Table(Main_H_Table, Name, Country, City, Street, N_Home);
}

char* Hash_Table::Enter_Data(char* word) {
	
	int size=1;
	char c;

	word = (char*)malloc(sizeof(char));
	while ((c = getchar()) != '\n') {
		word[size-1] = c;
		size++;
		word = (char*)realloc(word, size);
	}
	word[size-1] = '\0';
	return word;
}

void Hash_Table::Delete_Need_Element() {

	char* Name=nullptr;
	
	std::cout << "¬ведите название компании, которую хотите удалить из таблицы: ";
	Name = Enter_Data(Name);

	//Name = search element

	//Delete_Item(item);

}

Hash_Table::Hash_Item* Hash_Table::Add_Hash_Item(char* key, char* Country, char* City, char* Street, char* N_Home) {

	Hash_Item* item = new Hash_Item;
	item->key_Name = new char[sizeof(key) + 1];					 //(char*)malloc(strlen(key) + 1); 
	item->Name_Company = new char[sizeof(key) + 1];				//(char*)malloc(strlen(key) + 1);
	item->Country = new char[sizeof(Country) + 1];				//(char*)malloc(strlen(Country) + 1);
	item->Street = new char[sizeof(Street) + 1];				//(char*)malloc(strlen(Street) + 1);
	item->City = new char[sizeof(City) + 1];					//(char*)malloc(strlen(City) + 1);
	item->N_Home = new char[sizeof(N_Home) + 1];				//(char*)malloc(strlen(City) + 1);
	item->next_item = nullptr;

	strcpy(item->key_Name, key);
	strcpy(item->Name_Company, key);
	strcpy(item->Country, Country);
	strcpy(item->Street, Street);
	strcpy(item->City, City);
	strcpy(item->N_Home, N_Home);

	return item;


}

Hash_Table::hash_table* Hash_Table::Create_Hash_Table(int size, hash_table* table ){
	
	table = new hash_table;
	table->Size = size;
	table->Count_Items = 0;
	table->items = new Hash_Item* [size];
	for (int i = 0; i < table->Size; i++) {
		table->items[i] = nullptr;
	}
		
	return table;
}

void Hash_Table::Insert_Item_In_Table(hash_table* table, char* key, char* Country, char* City, char* Street, char* N_Home){
	
	
	if (Checking_Fullness(Main_H_Table)==true) {
		Create_Hash_Table(Main_H_Table->Size * 2, Dop_H_Table);


		//  переброс из одной таблицы в другую
	}

	Hash_Item* item =  Add_Hash_Item(key, Country, City, Street, N_Home);
	 
	int index = Hash_Function_Multiply(item->key_Name,Main_H_Table);
	Hash_Item* current_item;
	current_item= table->items[index];
	 
	if (current_item == nullptr) {
		current_item = item;
		table->Count_Items++;
	}

	else {						//коллизии
		std::cout << current_item->next_item << " " << table->items[index]->next_item << std::endl;
		while (current_item != nullptr) {
			current_item = current_item->next_item;

		}



		current_item = item;
		table->Count_Items++;
	}
}
	

void Hash_Table::Show_Hash_Table(hash_table* table) {
	//system("cls");
	Hash_Item* current_item = nullptr;
	for (int i = 0; i < table->Size; i++) {
		if (table->items[i] != nullptr) {
			current_item = table->items[i];
			while (current_item != nullptr) {
				std::cout << i << " : " << current_item->Name_Company << " " << current_item->Country << " " << current_item->City << " " << current_item->Street << " " << current_item->N_Home << std::endl;
				current_item = current_item->next_item;
			}
		}
	}
}
void Hash_Table::Transfer_Table1_To_Table2(hash_table* table_main, hash_table* table_dop) {

	for (int i = 0; i < table_main->Size; i++) {
		table_main->items[i];
	}

}

void Hash_Table::Delete_Item(Hash_Item* item){
	free(item->key_Name);
	free(item->City);
	free(item->Country);
	free(item->N_Home);
	free(item->Street);
}

void Hash_Table::Delete_Hash_Table(hash_table* table){

	for (int i = 0; i < table->Size; i++) {
		Hash_Item* item = table->items[i];
		if (item != NULL)
			Delete_Item(item);
	}

	free(table->items);
	free(table);

}

unsigned long Hash_Table::Hash_Function_Multiply(char* key, hash_table* table) {
	
	float K = 0;

	float Int_Key = Convert_Mass_Char_To_Int(key);							
	float C = 0.8;
	int M =table->Size;											 // size tabble

	
	K = M * Remainder_Division(C*Int_Key,1);

	return K;
}

int Hash_Table::Convert_Mass_Char_To_Int(char* key) {

	int k = 0;
	for (int i = 0; key[i]; i++) {
		k += i * int(key[i]);
	}

	return k;
}

float Hash_Table::Remainder_Division(float a1, float b1) {
	float a = 0;

	a = a1 / b1 - int(a1 / b1);
	return a;
}

bool Hash_Table::Checking_Fullness(hash_table* table) {

	if ((table->Count_Items / table->Size) * 100 >= 70) {
		return true;
	}
	else {
		return false;
	}

}