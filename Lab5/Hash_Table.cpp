#define _CRT_SECURE_NO_WARNINGS
#include "Hash_Table.h"
#include <iostream>



void Hash_Table::Add_Element_Hand() {

	char* Name, *Country, *Street, *City, *N_Home;
	setlocale(LC_ALL, "Russian");

	std::cout << "¬ведите название компании: ";
	std::cin >> Name;

	std::cout << "¬ведите страну где находитьс€ главный офис этой компании:   ";
	std::cin >> Country;

	std::cout << "¬ведите город где находитьс€ главный офис этой компании:   ";
	std::cin >> Street;

	std::cout << "¬ведите улицу где находитьс€ главный офис этой компании:  ";
	std::cin >> City;

	std::cout << "¬ведите дом в котором находитьс€ главный офис этой компании:  ";
	std::cin >> N_Home;


	Insert_Item_In_Table(H_Table, Name, Country, City, Street, N_Home);
}

void Hash_Table::Delete_Need_Element() {

	char* Name;
	
	std::cout << "¬ведите название компании, которую хотите удалить из таблицы: ";
	std::cin >> Name;

	//Name = search element

	Delete_Item(item);

}

Hash_Table::Hash_Item* Hash_Table::Add_Hash_Item(char* key, char* Country, char* City, char* Street, char* N_Home) {

	Hash_Item* item = new Hash_Item;
	item->key_Name = (char*)malloc(strlen(key) + 1);
	item->Name_Company = (char*)malloc(strlen(key) + 1);
	item->Country = (char*)malloc(strlen(Country) + 1);
	item->Street = (char*)malloc(strlen(Street) + 1);
	item->City = (char*)malloc(strlen(City) + 1);
	item->N_Home = (char*)malloc(strlen(City) + 1);


	strcpy(item->key_Name, key);
	strcpy(item->Name_Company, key);
	strcpy(item->Country, Country);
	strcpy(item->Street, Street);
	strcpy(item->City, City);
	strcpy(item->N_Home, N_Home);

	return item;


}

Hash_Table::hash_table* Hash_Table::Create_Hash_Table(int size){
	
	hash_table* table = new hash_table;
	table->Size = size;
	table->Count_Items = 0;
	table->items = (Hash_Item**)calloc(table->Size, sizeof(Hash_Item*));
	for (int i = 0; i < table->Size; i++)
		table->items[i] = nullptr;
	return table;
}

void Hash_Table::Insert_Item_In_Table(hash_table* table, char* key, char* Country, char* City, char* Street, char* N_Home){
	
	Hash_Item* item =  Add_Hash_Item(key, Country, City, Street, N_Home);




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

unsigned long Hash_Table::Hash_Function_Multiply(char* key) {
	
	float K = 0;

	float Int_Key = Convert_Mass_Char_To_Int(key);							
	float C = 0.35;
	float M = 4;											 // size tabble

	
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