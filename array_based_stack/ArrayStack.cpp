// Mason DeWitt; mason.dewitt@nshu.edu; 2595261
// ArrayStack.cpp: Contains method definitons for an array-based stack

#include "ArrayStack.h"

ArrayStack::ArrayStack(int cap) {
	cap_ = cap;
	stack_ = new StudentInfo[cap];
	top_ = -1;
}
bool ArrayStack::full() {
	return top_ + 1 == cap_;
}
bool ArrayStack::empty() {
	return top_ == -1;
}
void ArrayStack::push(StudentInfo element) {
	stack_[++top_] = element;
}
StudentInfo ArrayStack::pop() {
	top_--;
	if (!empty()) {
		return stack_[top_];
	}
	return stack_[top_ + 1]; // Return previous top if stack is now empty
}
StudentInfo ArrayStack::top() {
	return stack_[top_];
}
int ArrayStack::size() {
	return top_ + 1;
}
