#pragma once
#include "LinkedStack.h"
#include <iostream>

template <typename T>
LinkedStack<T>::LinkedStack() {
	top_ = nullptr;
	size_ = 0;
}
template <typename T>
void LinkedStack<T>::Push(T item) {
	Node* new_node = new Node{ item, top_ };
	top_ = new_node;
	size_++;
}
template <typename T>
void LinkedStack<T>::Pop() {
	if (size_) {
		Node* temp = top_;
		top_ = top_->next;
		delete temp;
		size_--;
	}
}
template <typename T>
T LinkedStack<T>::GetTop() {
	return top_->data;
}
template<typename T>
unsigned int LinkedStack<T>::Size() {
	return size_;
}
template<typename T>
bool LinkedStack<T>::IsFull() {
	try {
		Node* n = new Node;
		delete n;
		return false; // Some memory is left, (not full)
	}
	// Out of memory (full)
	catch (const std::bad_alloc& err) {
		return true;
	}
}
template<typename T>
bool LinkedStack<T>::IsEmpty() {
	return size_ == 0;
}
