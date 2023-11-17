#pragma once
#include <string>

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
		std::string key_Name;
		std::string Name_Company;
		std::string Country;
		std::string City;
		std::string Street;
		std::string N_Home;
	};

	struct List_Item {
		Hash_Item* item;
		List_Item* next_list;

	};

	struct hash_table {
		List_Item** Lists;
		int Size;
		int Count_Items;
	};

	Hash_Item* H_Item;
	hash_table** Tables;
	
	int Searching = 0;
	int convert = 0;
	int Koef = 1;

public:
	Hash_Table() {
		Tables = new hash_table* [2];
		Tables[0] = new hash_table;
		Tables[1] = new hash_table;
	}

	Hash_Item* Add_Hash_Item(std::string key, std::string Country, std::string City, std::string Street, std::string N_Home);
	hash_table* Create_Hash_Table(int size, hash_table*);
	void Insert_Item_In_Table(hash_table* table, std::string key, std::string Country, std::string City, std::string Street, std::string N_Home);
	void Delete_Item(Hash_Item* item);
	void Delete_Hash_Table(hash_table* table);
	unsigned long Hash_Function_Multiply(std::string key , hash_table* table);
	int Convert_Mass_Char_To_Int(std::string key);
	float Remainder_Division(float a1, float b1);
	bool Checking_Fullness(hash_table* table);
	void Add_Element_Hand();
	void Add_Element_In_List(List_Item* table_item, Hash_Item* item);
	void Delete_Need_Element();
	std::string Enter_Data(std::string);
	Hash_Item* HT_search(hash_table* table, std::string);
	void Show_Hash_Table(hash_table* table);
	void Search_Need_Element();
	void Convert_TABLE1_To_TABLE2(hash_table* table1, hash_table* table2);
	void Transfer_Pointer(List_Item* , std::string);
	void Transfer_Table1_To_Table2(hash_table* table1, hash_table* table2);
	void Rehashing(hash_table*);
	void Read_Table_In_File();
	List_Item* Delete_List(List_Item* head_list);
	//char* Convert_String_To_Char(std::string* str);

};