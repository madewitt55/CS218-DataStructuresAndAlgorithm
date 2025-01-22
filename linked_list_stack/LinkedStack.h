#pragma once
#include <string>

struct StudentInfo {
	int id;
	int phone_number;
	std::string name;
	std::string address;
};

template<typename T>
class LinkedStack {
	struct Node {
		T data;
		Node* next; // Points to next node
	};

	private:
		Node* top_; // Node on top
		unsigned int size_; // Num items on 
	public:
		LinkedStack();
		void Push(T item); // Adds item to top
		void Pop(); // Removes top item
		T GetTop(); // Returns top item
		unsigned int Size(); // Returns num items
		bool IsFull(); 
		bool IsEmpty();
};

#include "LinkedStack.tpp"

