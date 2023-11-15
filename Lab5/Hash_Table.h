#pragma once

//Адрес Компании(Страна, Город, Улица, Дом), функция умножения, Метод цепочек 
//Реализовать алгоритмы поиска, вставки, удаления элементов таблицы и распечатки таблицы
//и метод ре-хэширования таблицы при увеличении размера данных

/*class Hash_Item {

	char* key;

	char* Country;
	char* City;
	char* Street;
	char* N_Home;
	
	friend class Hash_Table;
};
*/


class Hash_Table {
public:
	struct Hash_Item {
		char* key_Name;
		char* Name_Company;
		char* Country;
		char* City;
		char* Street;
		char* N_Home;
		Hash_Item* next_item;
	};

	struct hash_table {
		Hash_Item** items;
		int Size;
		int Count_Items;
	};

	Hash_Item* H_Item;
	hash_table* Main_H_Table;
	hash_table* Dop_H_Table;
	int Searching = 0;

public:

	Hash_Item* Add_Hash_Item(char* key, char* Country, char* City, char* Street, char* N_Home);
	hash_table* Create_Hash_Table(int size, hash_table*);
	void Insert_Item_In_Table(hash_table* table,char* key, char* Country, char* City, char* Street, char* N_Home);
	void Delete_Item(Hash_Item* item);
	void Delete_Hash_Table(hash_table* table);
	unsigned long Hash_Function_Multiply(char* key , hash_table* table);
	int Convert_Mass_Char_To_Int(char* key);
	float Remainder_Division(float a1, float b1);
	bool Checking_Fullness(hash_table* table);
	void Add_Element_Hand();
	Hash_Item* Add_Element_In_List(Hash_Item* table_item, Hash_Item* item);
	void Delete_Need_Element();
	char* Enter_Data(char*);
	Hash_Item* HT_search(hash_table* table, char* key);
	void Show_Hash_Table(hash_table* table);
	void Search_Need_Element();
	Hash_Item* Transfer_Pointer(Hash_Item* , char* );
	void Transfer_Table1_To_Table2(hash_table* table1, hash_table* table2);
};