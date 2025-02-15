#include <iostream>
#include "Dictionary.h"


int main() {
	Dictionary<int> dict1;
	dict1.insertItem(2, 20);
	dict1.insertItem(5, 50);
	dict1.insertItem(4, 40);
	dict1.insertItem(1, 10);
	dict1.insertItem(3, 30);
	dict1.print();
	std::cout << dict1.searchItem(3)->value_ << '\n';
	dict1.deleteItem(3);
	dict1.print();
	dict1.deleteItem(3);
	dict1.insertItem(4, 400);

	std::cout << '\n' <<  "-----------------" << '\n';
	Dictionary<int> dict2;
	dict2.insertItem(2, 20);
	dict2.insertItem(4, 40);
	dict2.print();

	std::cout << '\n' <<  "-----------------" << '\n';
	Dictionary<std::string> dict3;
	dict3.insertItem("aaa", "aaa");
	dict3.insertItem("ggg", "ggg");
	dict3.insertItem("ccc", "ccc");
	dict3.insertItem("bbb", "bbbb");
	dict3.print();
	dict3.clear();
	dict3.print();

	std::cout << '\n' <<  "-----------------" << '\n';
	Dictionary<int>* dict4 = getIntersection(&dict1, &dict2);
	dict4->print();
}