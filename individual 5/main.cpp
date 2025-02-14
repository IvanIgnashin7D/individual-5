//#include <iostream>
//
//
//struct Node {
//	std::string value_;
//	Node* next_;
//	Node(std::string value) : value_(value), next_(nullptr) {};
//};
//
//
//struct List {
//	Node* first_;
//	Node* last_;
//	List() : first_(nullptr), last_(nullptr) {};
//
//	bool is_empty() {
//		return first_ == nullptr;
//	}
//
//	void add(std::string value) {
//		Node* new_node = new Node(value);
//		if (is_empty()) {
//			first_ = new_node;
//			last_ = new_node;
//			return;
//		}
//		last_->next_ = new_node;
//		last_ = new_node;
//	}
//
	//void print() {
	//	if (is_empty()) return;
	//	Node* node = first_;
	//	std::cout << '[';
	//	while (node) {
	//		std::cout << node->value_ << ", ";
	//		node = node->next_;
	//	}
	//	std::cout << "]\n";
	//}
//
//	Node* find(std::string value) {
//		if (is_empty()) return nullptr;
//		Node* node = first_;
//		while (node && node->value_ != value)
//			node = node->next_;
//		return (node && node->value_ == value) ? node : nullptr;
//	}
//
//	void remove_first() {
//		if (is_empty()) return;
//		first_ = first_->next_;
//	}
//
//	void remove_last() {
//		if (is_empty()) return;
//		if (first_ == last_) {
//			remove_first();
//			return;
//		}
//		Node* node = first_;
//		while (node->next_ != last_)
//			node = node->next_;
//		node->next_ = nullptr;
//		delete last_;
//		last_ = node;
//	}
//
	//void remove(std::string value) {
	//	if (first_->value_ == value) {
	//		remove_first();
	//		return;
	//	}
	//	if (last_->value_ == value) {
	//		remove_last();
	//		return;
	//	}
	//	Node* slow = first_;
	//	Node* fast = slow->next_;
	//	while (fast && fast->value_ != value) {
	//		slow = fast;
	//		fast = fast->next_;
	//	}
	//	if (fast && fast->value_ == value) {
	//		slow->next_ = fast->next_;
	//		delete fast;
	//	}
	//}
//
//	Node* operator[] (int index) {
//		if (is_empty()) return nullptr;
//		Node* node = first_;
//		for (int i = 0; i < index; i++) {
//			node = node->next_;
//			if (!node) return nullptr;
//		}
//		return node;
//	}
//};
//
//
//int main() {
//	List list;
//	list.add("value number one");
//	list.add("value number two");
//	list.add("value number three");
//	list.print();
//
//	std::cout << list.find("value number one")->value_ << '\n';
//
//	list.remove_first();
//	list.remove_last();
//	list.print();
//
//	list.add("value number four");
//	list.add("value number five");
//	list.remove("value number four");
//	list.print();
//
//	list.add("value number six");
//	list.print();
//	std::cout << list[1]->value_<< '\n';
//}


#include <iostream>

#include "Dictionary.h"


template<typename Type>
Dictionary<Type>* getIntersection(Dictionary<Type>* d2) {

}


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
	dict1.clear();
	dict1.print();
	// В итоге в словаре dict: 1, 2, 4, 5

	Dictionary<int> dict2;
	dict2.insertItem(2, 20);
	dict2.insertItem(4, 40);
}