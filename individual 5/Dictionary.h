#pragma once
#include <iostream>
template<class Type>
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
		last_->next_ = new_node;
		last_ = new_node;
		length_ += 1;
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

};
