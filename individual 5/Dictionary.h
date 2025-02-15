#pragma once
#include <iostream>
//#include "main.cpp"
template<typename Type>
class Dictionary {
public:
	struct Node {
		Type value_;
		Type key_;
		Node* next_;
		Node(Type key, Type value) : key_(key), value_(value), next_(nullptr) {};
	};
	Node* first_;
	Node* last_;
	int length_;


	Dictionary() : first_(nullptr), last_(nullptr), length_(0) {}
	
	
	void insertItem(Type key, Type value) {
		Node* node = searchItem(key);
		if (node != nullptr && node->key_ == key) return;
		Node* new_node = new Node(key, value);
		if (!length_) {
			first_ = new_node;
			last_ = new_node;
			length_ += 1;
			return;
		}
		if (first_->key_ > key) {
			new_node->next_ = first_;
			first_ = new_node;
			length_ += 1;
			return;
		}
		node = first_;
		while (node != last_ && node->next_->key_ < key) node = node->next_;
		new_node->next_ = node->next_;
		node->next_ = new_node;
		last_ = new_node;
		length_ += 1;
	}


	void print() {
		if (!length_) return;
		Node* node = first_;
		std::cout << '{';
		while (node) {
			std::cout << node->key_ << " : " << node->value_ << ", ";
			node = node->next_;
		}
		std::cout << "}\n";
	}
	
	
	Node* searchItem(Type key) {
		if (!length_) 
			return nullptr;
		Node* node = first_;
		while (node && node->key_ != key)
			node = node->next_;
		return (node && node->key_ == key) ? node : nullptr;
	}


	void deleteItem(Type key) {
		if (!length_) return;
		if (first_->key_ == key) {
			delete first_;
			length_ -= 1;
			return;
		}
		if (first_ == last_){
			delete first_;
			length_ -= 1;
			return;
		}
		Node* slow = first_;
		Node* fast = slow->next_;
		while (fast && fast->key_ != key) {
			slow = fast;
			fast = slow->next_;
		}
		if (fast && fast->key_ == key) {
			slow->next_ = fast->next_;
			delete fast;
			length_ -= 1;
		}
	}

	void clear() {
		if (!length_) return;
		if (length_ == 1) {
			delete first_;
			length_ -= 1;
			return;
		}
		Node* slow = first_;
		Node* fast = slow->next_;
		while (fast) {
			delete slow;
			length_ -= 1;
			slow = fast;
			fast = fast->next_;
		}
		delete slow;
		length_ -= 1;
	}

	friend Dictionary<Type>* getIntersection(Dictionary<Type> d1, Dictionary<Type> d2);
};