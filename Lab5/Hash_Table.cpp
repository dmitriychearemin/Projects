#define _CRT_SECURE_NO_WARNINGS
#include "Hash_Table.h"
#include <iostream>
#include <string>
#include <fstream>

void Hash_Table::Add_Element_Hand() {

	char* Name= nullptr, *Country=nullptr, *Street=nullptr, *City=nullptr, *N_Home=nullptr;
	

	std::cout << "Enter name company: " << std::endl;
	Name = Enter_Data(Name);

	std::cout << "Enter country:   " << std::endl;
	Country = Enter_Data(Country);

	std::cout << "Enter city:   " << std::endl;
	City =  Enter_Data(City);

	std::cout << "Enter street:  " << std::endl;
	Street =  Enter_Data(Street);

	std::cout << "Enter number home:  " << std::endl;
	N_Home=  Enter_Data(N_Home);

	Insert_Item_In_Table(Tables[0], Name, Country, City, Street, N_Home);
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
	
	std::cout << "Enter company: ";
	Name = Enter_Data(Name);

	int index = Hash_Function_Multiply(Name, Tables[0]);

	if (Tables[0]->items[index] != nullptr) {
		if (strcmp(Tables[0]->items[index]->key_Name, Name) == 0) {
			Delete_Item(Tables[0]->items[index]);
			Tables[0]->items[index] = Tables[0]->items[index]->next_item;
		}
		else {
			Tables[0]->items[index] = Transfer_Pointer(Tables[0]->items[index], Name);
		}
	}

	else {
		std::cout << "Table has not rhis company: " << std::endl;
	}
	
	Searching = 0;
}

void Hash_Table::Search_Need_Element() {
	char* Name = nullptr;
	int index=0;
	//setlocale(LC_ALL, "Russian");

	std::cout << "Enter company to search: " << std::endl;
	Name = Enter_Data(Name);

	Hash_Item* item;

	item = HT_search(Tables[0], Name);
	if (item != nullptr) {
		index = Hash_Function_Multiply(item->key_Name, Tables[0]);
		std::cout << index << " : " << item->Name_Company << " " << item->Country << " " << item->City << " " << item->Street << " " << item->N_Home << std::endl;
	}
	else {
		std::cout << "Table have not this company: " << std::endl;
	}

	
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
	table->items = new Hash_Item * [size];
	for (int i = 0; i < table->Size; i++) {
		table->items[i] = new Hash_Item;
		table->items[i] = nullptr;
	}
		
	return table;
}

void Hash_Table::Insert_Item_In_Table(hash_table* table, char* key, char* Country, char* City, char* Street, char* N_Home){
	
	
	if (Checking_Fullness(table) == true && convert == 0) {
		convert = 1;
		
		table->Size = table->Size * 2;								 // увеличиваем таблицу и выделяем память						
		table->items = (Hash_Item**)realloc(table->items, sizeof(Hash_Item*)* table->Size);
		
		for (int i = table->Size/2; i < table->Size; i++) {
			table->items[i] = new Hash_Item;
			table->items[i] = nullptr;
		}

		//Show_Hash_Table(table);
		convert = 0;
		
	}

	Hash_Item* item =  Add_Hash_Item(key, Country, City, Street, N_Home);
	 
	int index = Hash_Function_Multiply(item->key_Name,table);
	
	table->items[index] = Add_Element_In_List(table->items[index], item);
	//std::cout << table->items[index] << " ";
	table->Count_Items++;

}
	
Hash_Table::Hash_Item*  Hash_Table::HT_search(hash_table* table, char* key) {
	
	int index = Hash_Function_Multiply(key,table);

	Hash_Item* item = table->items[index];

	// Ensure that we move to a non NULL item
	if (item != nullptr) {
		while (item != nullptr) {
			if (strcmp(item->key_Name, key) == 0) {
				return item;
			}
			item = item->next_item;
		}
		
	}
	return nullptr;
}

void Hash_Table::Rehashing(hash_table* table) {
	Hash_Item* current_item = nullptr;

	for (int i = 0; i < table->Size; i++) {
		current_item = table->items[i];
		if (current_item != nullptr) {
			while (current_item != nullptr) {
				Insert_Item_In_Table(table, current_item->key_Name, current_item->Country, current_item->City, current_item->Street, current_item->N_Home);
				current_item = current_item->next_item;
			}
		}
	}

}

void Hash_Table::Show_Hash_Table(hash_table* table) {
	system("cls");
	Hash_Item* current_item = nullptr;
	for (int i = 0; i < table->Size; i++) {
		current_item = table->items[i];
		if (current_item != nullptr) {
			while (current_item != nullptr) {
				std::cout << i << " : " << current_item->Name_Company << " " << current_item->Country << " " << current_item->City << " " << current_item->Street << " " << current_item->N_Home << std::endl;
				current_item = current_item->next_item;
			}
		}
	}
}

Hash_Table::Hash_Item* Hash_Table::Add_Element_In_List(Hash_Item* table_item, Hash_Item* item) {
	if (table_item == nullptr) {
		table_item = item;
		//std::cout<< table_item <<" " << item <<" ";
	}
	else {
		table_item->next_item = Add_Element_In_List(table_item->next_item, item);
	}
	return table_item;
}

void Hash_Table::Transfer_Table1_To_Table2(hash_table* table1_main, hash_table* table2_dop) {
	Hash_Item* current_item = nullptr;

	for (int i = 0; i < table1_main ->Size; i++) {
		current_item = table1_main -> items[i];
		if (current_item != nullptr) {
			while (current_item != nullptr) {
				Insert_Item_In_Table(table2_dop, current_item->key_Name, current_item->Country, current_item->City, current_item->Street, current_item->N_Home);
				current_item = current_item->next_item;
			}
		}
	}

}

void Hash_Table::Delete_Item(Hash_Item* item){
	free(item->key_Name);
	free(item->Name_Company);
	free(item->City);
	free(item->Country);
	free(item->N_Home);
	free(item->Street);
	//free item;
}

Hash_Table::Hash_Item* Hash_Table::Transfer_Pointer(Hash_Item* table_item, char* key) {

	if (table_item != nullptr && Searching==0) {
		if (table_item->next_item != nullptr) {
			if (strcmp(table_item->next_item->key_Name, key) == 0) {
				Delete_Item(table_item->next_item);
				Searching = 1;
				table_item->next_item = Transfer_Pointer(table_item->next_item->next_item, key);
			}
		}
		
		table_item->next_item = Transfer_Pointer(table_item->next_item, key);
	}
	return table_item;
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

	float a = Remainder_Division(table->Count_Items ,table->Size) * 100;
	if (a >= 70) {
		
		return true;
	}
	else {
		return false;
	}

}

void Hash_Table::Read_Table_In_File() {
	char* Name=nullptr, *Country = nullptr, * Street = nullptr, * City = nullptr, * N_Home = nullptr;
	std::ifstream File;
	std::string str;
	File.open("Hash_Table.txt");
	int opredelitel = 0;
	if (File) {
		while (!File.eof()) {

			str = " ";
			File >> str;
			if (opredelitel == 0) {
				int size = 1;
				Name = (char*)malloc(sizeof(char));
				while (str[size-1]) {
					Name[size - 1] = str[size-1];
					size++;
					Name = (char*)realloc(Name, size);
				}
				opredelitel = 1;
			}

			str = " ";
			File >> str;
			if (opredelitel == 1) {
				int size = 1;
				Country = (char*)malloc(sizeof(char));
				while (str[size - 1]) {
					Country[size - 1] = str[size - 1];
					size++;
					Country = (char*)realloc(Country, size);
				}
				opredelitel = 2;
			}

			str = " ";
			File >> str;
			if (opredelitel == 2) {
				int size = 1;
				City = (char*)malloc(sizeof(char));
				while (str[size - 1]) {
					City[size - 1] = str[size - 1];
					size++;
					City = (char*)realloc(City, size);
				}
				opredelitel = 3;
			}

			str = " ";
			File >> str;
			if (opredelitel == 3) {
				int size = 1;
				Street = (char*)malloc(sizeof(char));
				while (str[size - 1]) {
					Street[size - 1] = str[size - 1];
					size++;
					Street = (char*)realloc(Street, size);
				}
				opredelitel = 4;
			}

			str = " ";
			File >> str;
			if (opredelitel == 4) {
				int size = 1;
				N_Home = (char*)malloc(sizeof(char));
				while (str[size - 1]) {
					N_Home[size - 1] = str[size - 1];
					size++;
					N_Home = (char*)realloc(N_Home, size);
				}
				opredelitel = 0;
			}
			
			std::cout << Name << " " << Country << " " << City << " " << Street << " " << N_Home << std::endl;
			Insert_Item_In_Table(Tables[0], Name, Country, Street, City, N_Home);
			delete Name, Country, Street, City, N_Home;
		}
		File.close();
	}
	else {
		std::cout << "File not exist" << std::endl;
	}

}
