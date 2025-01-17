// Mason DeWitt; mason.dewitt@nshu.edu; 2595261
// ArrayStack.h: Contains class definition and prototypes of methods for an
// array-based stack

#pragma once
#include <iostream>
#include <string>
using namespace std;

struct StudentInfo {
	int id;
	int phone_number;
	string name;
	string address;

};

class ArrayStack
{
	private:
		int top_; // Student on top of stack
		int cap_; // Max size
		StudentInfo *stack_; // Points to array


	public:
		ArrayStack(int cap); // Initialize by setting max size
		bool full(); // Returns true if array if full, false if not
		bool empty(); // Returns true if array is empty, false if not
		void push(StudentInfo element); // Adds student to top
		StudentInfo pop(); // Removes student at top and returns new top
		StudentInfo top(); // Returns student at top
		int size(); // Returns number of students
};

