#include <iostream>
#include "Hash_Table.h"






int main() {

	Hash_Table Table;
	Table.Create_Hash_Table(5);
	
	//Table.Insert_Item_In_Table(Table.H_Table, );
	char str[] =  "Philips";

	char* s = str;

	//std::cout << Convert_Mass1_Char_To_Int(str);
	std::cout << Table.Hash_Function_Multiply(s);

}


