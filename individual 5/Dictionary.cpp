#include "Dictionary.h"


template<class Type>
void Dictionary<Type>::append(Type key, Type value)
{
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

template<class Type>	
Dictionary<Type>::Node* Dictionary<Type>::find(Type key) 
{
	if (!length_) return nullptr;
	Node* node = first_;
	while (node && node->key_ != key)
		node = node->next_;
	return (node && node->key_ == key) ? node : nullptr;
}
