#pragma once
#include <iostream>
template<typename Type>
class Dictionary {
	struct Node {
		Type value_;
		Type key_;
		Node* next_;
		Node(Type key, Type value) : key_(key), value_(value), next_(nullptr) {};
	};

public:
	Node* first_;
	Node* last_;
	int length;
	Dictionary() : first_(nullptr), last_(nullptr), lenght(0) {}

	void append();

};
